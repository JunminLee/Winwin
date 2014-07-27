//
// Tizen C++ SDK
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <FSystem.h>
#include "GalleryImageViewForm.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Runtime;
using namespace Tizen::Graphics;
using namespace Tizen::System;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

GalleryImageViewForm::GalleryImageViewForm(GalleryImageManager* pImgManager, int index)
{
	for (int i = 0; i < GALLERY_IMAGE_COUNT; i++)
	{
		__pElement[i] = null;
	}
	__pVisualElement = null;

	for (int i = 0; i < PIECE_COUNT; i++)
	{
		__pOldPiece[i] = null;
		__pNewPiece[i] = null;
	}

	Frame* pFrame = UiApp::GetInstance()->GetFrameAt(0);
	if (pFrame != null)
	{
		__pPreviousForm = pFrame->GetCurrentForm();
	}
	else
		__pPreviousForm = null;

	__pTimer = null;
	__pImgManager = pImgManager;
	__currentIndex = index;
	__isSlideShowPlaying = false;
	__isSlideShowPaused = false;
	__transactionId = 0;
}

GalleryImageViewForm::~GalleryImageViewForm(void)
{
}

bool
GalleryImageViewForm::Initialize(void)
{
	Construct(FORM_STYLE_NORMAL | FORM_STYLE_FOOTER | FORM_STYLE_INDICATOR);
	SetName(L"GalleryImageView");

	InitializeFooter();
	SetFormBackEventListener(this);
	AddTouchEventListener(*this);

	return true;
}

result
GalleryImageViewForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	__pVisualElement = new (std::nothrow) VisualElement();
	__pVisualElement->Construct();
	__pVisualElement->SetName(L"VisualElement");
	__pVisualElement->SetBounds(FloatRectangle(0.0f, 0.0f, 0.0f, 0.0f));
	__pVisualElement->SetClipChildrenEnabled(false);
	__pVisualElement->SetShowState(true);
	__pVisualElement->SetImplicitAnimationEnabled(false);
	GetVisualElement()->AttachChild(__pVisualElement);
	__clientRect = GetClientAreaBounds();

	__pElement[__currentIndex] = CreateImageView(__currentIndex, __clientRect);

	return r;
}

result
GalleryImageViewForm::OnTerminating(void)
{
	if (__transactionId > 0)
	{
		AnimationTransaction::Stop(__transactionId);
		__transactionId = 0;
	}

	for (int i = 0; i < GALLERY_IMAGE_COUNT; i++)
	{
		if (__pElement[i])
		{
			__pElement[i]->Destroy();
			__pElement[i] = null;
		}
	}

	for (int i = 0; i < PIECE_COUNT; i++)
	{
		if (__pOldPiece[i])
		{
			__pOldPiece[i]->Destroy();
			__pOldPiece[i] = null;
		}

		if (__pNewPiece[i])
		{
			__pNewPiece[i]->Destroy();
			__pNewPiece[i] = null;
		}
	}
	
	if (__pVisualElement)
	{
		__pVisualElement->Destroy();
		__pVisualElement = null;
	}

	if (__pTimer)
	{
		__pTimer->Cancel();
		delete __pTimer;
		__pTimer = null;
	}

	return E_SUCCESS;
}

void
GalleryImageViewForm::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_SLIDESHOW:
		{
			SendUserEvent(GalleryImageManager::REQUEST_ID_SLIDE_SHOW_START, null);
		}
		break;
	default:
		break;
	}
}

void
GalleryImageViewForm::OnFormBackRequested(Form& source)
{
	if (__isSlideShowPlaying == true)
	{
		if (__pPreviousForm != null)
		{
			ArrayList* pList = new (std::nothrow) ArrayList();
			pList->Add(*this);
			pList->Add(*(new (std::nothrow) Integer(__currentIndex)));

			__pPreviousForm->SendUserEvent(GalleryImageManager::REQUEST_ID_GALLERY_VIEW, pList);
		}
	}
	else
	{
		CreateAnimationForDestroy();
	}
}

void
GalleryImageViewForm::OnUserEventReceivedN(RequestId requestId, IList* pArgs)
{
	switch(requestId)
	{
	case GalleryImageManager::REQUEST_ID_SLIDE_SHOW_START:
		{
			if (__isSlideShowPlaying == false)
			{
				Footer* pFooter = Form::GetFooter();
				pFooter->SetItemEnabled(0, false);
				pFooter->Draw();

				__isSlideShowPlaying = true;
				StartTimerForSlideShow();
			}
		}
		break;

	case GalleryImageManager::REQUEST_ID_SLIDE_SHOW_PAUSE:
		{
			if (__isSlideShowPlaying == true)
			{
				__isSlideShowPlaying = false;
				__isSlideShowPaused = true;

				if (__pTimer)
				{
					__pTimer->Cancel();
				}

				if (__transactionId != 0)
					AnimationTransaction::Stop(__transactionId);
			}
		}
		break;

	case GalleryImageManager::REQUEST_ID_SLIDE_SHOW_RESTART:
		{
			if (__isSlideShowPaused == true)
			{
				__isSlideShowPlaying = true;
				__isSlideShowPaused = false;

				StartTimerForSlideShow();
			}
		}
		break;
	}
}

void
GalleryImageViewForm::InitializeFooter(void)
{
	Footer* pFooter = Form::GetFooter();

	pFooter->SetStyle(FOOTER_STYLE_BUTTON_TEXT);
	pFooter->SetBackButton();
	pFooter->AddActionEventListener(*this);

	FooterItem  footerItem1;
	footerItem1.Construct(ID_FOOTER_BUTTON_SLIDESHOW);
	footerItem1.SetText(L"Slide Show");

	pFooter->AddItem(footerItem1);
}

void
GalleryImageViewForm::OnTouchReleased (const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
	bool	right = false;
	int distanceX = currentPosition.x - touchInfo.GetStartPosition().x;
	int newIndex;

	if (__isSlideShowPlaying == true)
		return;

	if (distanceX < 0 )
	{
		right = true;
		distanceX = -(distanceX);
	}

	if (touchInfo.IsFlicked())
	{
		int movingDistance;
		Rectangle newRect(__clientRect);

		if (right)
		{
			if (__currentIndex == GALLERY_IMAGE_COUNT - 1)
			{
				VisualElementPropertyAnimation* pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
				pAnimation->SetPropertyName(L"bounds");
				pAnimation->SetStartValue(FloatRectangle(__clientRect.width * 0.1f, __clientRect.height * 0.1f, __clientRect.width * 0.8f, __clientRect.height * 0.8f));
				pAnimation->SetEndValue(__pElement[__currentIndex]->GetBounds());
				pAnimation->SetVisualElementAnimationStatusEventListener(this);

				const IVisualElementAnimationTimingFunction* pTimingFunction = VisualElementAnimation::GetTimingFunctionByName(L"EaseElasticOut");
				pAnimation->SetTimingFunction(pTimingFunction);

				__pElement[__currentIndex]->AddAnimation(*pAnimation);
				delete pAnimation;

				return;
			}
			else
			{

				newRect.SetPosition(__clientRect.width, __clientRect.y);
				newIndex = __currentIndex + 1;
				if (__pElement[newIndex] == null)
				{
					__pElement[newIndex] = CreateImageView(newIndex, newRect);
				}

				movingDistance = -__clientRect.width;
			}
		}
		else
		{
			if (__currentIndex == 0)
			{
				VisualElementPropertyAnimation* pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
				pAnimation->SetPropertyName(L"bounds");
				pAnimation->SetStartValue(FloatRectangle(__clientRect.width * 0.1f, __clientRect.height * 0.1f, __clientRect.width * 0.8f, __clientRect.height * 0.8f));
				pAnimation->SetEndValue(__pElement[__currentIndex]->GetBounds());
				pAnimation->SetVisualElementAnimationStatusEventListener(this);

				const IVisualElementAnimationTimingFunction* pTimingFunction = VisualElementAnimation::GetTimingFunctionByName(L"EaseElasticOut");
				pAnimation->SetTimingFunction(pTimingFunction);

				__pElement[__currentIndex]->AddAnimation(*pAnimation);
				delete pAnimation;

				return;
			}
			else
			{
				newRect.SetPosition(-__clientRect.width, __clientRect.y);
				newIndex = __currentIndex - 1;
				if (__pElement[newIndex] == null)
				{
					__pElement[newIndex] = CreateImageView(newIndex, newRect);
				}

				movingDistance = __clientRect.width;
			}
		}

		__pElement[__currentIndex]->SetImplicitAnimationEnabled(true);
		__pElement[newIndex]->SetImplicitAnimationEnabled(true);

		FloatRectangle endRect = __pElement[__currentIndex]->GetBounds();
		endRect.Translate((float)movingDistance, 0.0f);
		__pElement[__currentIndex]->SetBounds(endRect);

		endRect = __pElement[newIndex]->GetBounds();
		endRect.Translate((float)movingDistance, 0.0f);
		__pElement[newIndex]->SetBounds(endRect);

		__pElement[__currentIndex]->SetImplicitAnimationEnabled(false);
		__pElement[newIndex]->SetImplicitAnimationEnabled(false);

		__currentIndex = newIndex;
	}
}

void
GalleryImageViewForm::OnVisualElementAnimationFinished(const VisualElementAnimation& animation, const String& keyName, VisualElement& target, bool completedNormally)
{
	if (completedNormally)
	{
		if (keyName == L"Destroy")
		{
			if (__pPreviousForm != null)
			{
				ArrayList* pList = new (std::nothrow) ArrayList();
				pList->Add(*this);
				pList->Add(*(new (std::nothrow) Integer(__currentIndex)));

				__pPreviousForm->SendUserEvent(GalleryImageManager::REQUEST_ID_GALLERY_VIEW, pList);
			}
		}
	}
}

void
GalleryImageViewForm::OnAnimationTransactionStopped(int transactionId)
{
	if (transactionId == __transactionId)
	{
		if (__pElement[__currentIndex])
		{
			__pElement[__currentIndex]->SetImplicitAnimationEnabled(false);
			__pElement[__currentIndex]->SetOpacity(1.0f);
		}

		for (int i = 0; i < PIECE_COUNT; i++)
		{
			if (__pOldPiece[i])
			{
				__pOldPiece[i]->Destroy();
				__pOldPiece[i] = null;
			}

			if (__pNewPiece[i])
			{
				__pNewPiece[i]->Destroy();
				__pNewPiece[i] = null;
			}
		}

		__transactionId = 0;
	}
}

void
GalleryImageViewForm::OnAnimationTransactionFinished(int transactionId)
{
	if (transactionId == __transactionId)
	{
		if (__pElement[__currentIndex])
		{
			__pElement[__currentIndex]->SetImplicitAnimationEnabled(false);
			__pElement[__currentIndex]->SetOpacity(1.0f);
		}

		for (int i = 0; i < PIECE_COUNT; i++)
		{
			if (__pOldPiece[i])
			{
				__pOldPiece[i]->Destroy();
				__pOldPiece[i] = null;
			}

			if (__pNewPiece[i])
			{
				__pNewPiece[i]->Destroy();
				__pNewPiece[i] = null;
			}
		}

		__transactionId = 0;

		if (__isSlideShowPlaying == true)
			StartTimerForSlideShow();
	}
}

void
GalleryImageViewForm::OnTimerExpired(Timer& timer)
{
	PlaySlideShow();
}

void
GalleryImageViewForm::StartTimerForSlideShow(void)
{
	if (__pTimer == null)
	{
		__pTimer = new (std::nothrow) Timer;
		if (__pTimer == null)
		{
			return;
		}

		result r = __pTimer->Construct(*this);
		if (IsFailed(r))
		{
			return;
		}
	}

	__pTimer->Start(500);

	return;
}

VisualElement*
GalleryImageViewForm::CreateImageView(int index, Rectangle rect)
{
	Rectangle imgRect;

	__pImgManager->GetCenterAlighBounds(index, Rectangle(0, 0, rect.width, rect.height), imgRect, GalleryImageManager::SCALE_STYLE_FIT);

	Bitmap* pBitmap = __pImgManager->GetScaledBitmapN(index, imgRect.width, imgRect.height);

	VisualElement* pElement = new (std::nothrow) VisualElement();
	pElement->Construct();
	pElement->SetBounds(FloatRectangle(rect.x, rect.y, rect.width, rect.height));
	pElement->SetShowState(true);
	pElement->SetImplicitAnimationEnabled(false);
	__pVisualElement->AttachChild(pElement);

	Canvas* pCanvas = pElement->GetCanvasN();
	pCanvas->Clear();
	pCanvas->DrawBitmap(Point(imgRect.x, imgRect.y), *pBitmap);

	delete pCanvas;
	delete pBitmap;

	return pElement;
}

void
GalleryImageViewForm::CreateAnimationForDestroy(void)
{
	VisualElementPropertyAnimation*	pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"bounds");
	pAnimation->SetStartValue(__pElement[__currentIndex]->GetBounds());
	pAnimation->SetEndValue(FloatRectangle(0.0f, __clientRect.height / 2.0f - 1.0f, __clientRect.width, 2.0f));
	pAnimation->SetDuration(300);

	__pElement[__currentIndex]->AddAnimation(*pAnimation);
	delete pAnimation;

	pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"opacity");
	pAnimation->SetStartValue(1.0f);
	pAnimation->SetEndValue(0.0f);
	pAnimation->SetDuration(300);
	pAnimation->SetVisualElementAnimationStatusEventListener(this);

	__pElement[__currentIndex]->AddAnimation(L"Destroy", *pAnimation);
	delete pAnimation;
}

void
GalleryImageViewForm::PlaySlideShow(void)
{
	int newIndex = __currentIndex + 1;

	if (newIndex == GALLERY_IMAGE_COUNT)
		newIndex = 0;

	__pElement[__currentIndex]->SetOpacity(0.0f);

	if (__pElement[newIndex] == null)
	{
		__pElement[newIndex] = CreateImageView(newIndex, __clientRect);
		__pElement[newIndex]->SetOpacity(0.0f);
	}
	else
	{
		__pElement[newIndex]->SetBounds(FloatRectangle(__clientRect.x, __clientRect.y, __clientRect.width, __clientRect.height));
	}

	VisualElementSurface* pOldSurface = __pElement[__currentIndex]->GetSurfaceN();
	VisualElementSurface* pNewSurface = __pElement[newIndex]->GetSurfaceN();
	FloatRectangle effectRect = Tizen::Graphics::CoordinateSystem::AlignToDevice(__pElement[__currentIndex]->GetBounds());

	FloatDimension pieceDimension = Tizen::Graphics::CoordinateSystem::AlignToDevice(
			FloatDimension(effectRect.width / PIECE_COL, effectRect.height / PIECE_ROW));

	float pieceW[PIECE_COL];
	float pieceH[PIECE_ROW];

	for (int i = 0; i < PIECE_COL; i++)
	{
		pieceW[i] = pieceDimension.width;
	}

	for (int i = 0; i < PIECE_ROW; i++)
	{
		pieceH[i] = pieceDimension.height;
	}

	if (pieceDimension.width * PIECE_COL < effectRect.width)
	{
		pieceW[PIECE_COL - 1] = effectRect.width - pieceDimension.width * (PIECE_COL - 1);
	}

	if (pieceDimension.height * PIECE_ROW < effectRect.height)
	{
		pieceH[PIECE_ROW - 1] = effectRect.height - pieceDimension.height * (PIECE_ROW - 1);
	}

	float positionX = effectRect.x;
	float positionY = effectRect.y;

	for (int y = 0; y < PIECE_ROW; y++)
	{
		for (int x = 0; x < PIECE_COL; x++)
		{
			int index = y * PIECE_COL + x;

			__pOldPiece[index] = new (std::nothrow) VisualElement();
			__pOldPiece[index]->Construct();
			__pOldPiece[index]->SetImplicitAnimationEnabled(false);
			__pOldPiece[index]->SetSurface(pOldSurface);
			__pOldPiece[index]->SetContentBounds(FloatRectangle((positionX - effectRect.x) / effectRect.width, (positionY - effectRect.y) / effectRect.height, pieceW[x] / effectRect.width, pieceH[y] / effectRect.height));
			__pOldPiece[index]->SetBounds(FloatRectangle(positionX, positionY, pieceW[x], pieceH[y]));
			__pOldPiece[index]->SetShowState(true);
			__pVisualElement->AttachChild(__pOldPiece[index]);

			__pNewPiece[index] = new (std::nothrow) VisualElement();
			__pNewPiece[index]->Construct();
			__pNewPiece[index]->SetImplicitAnimationEnabled(false);
			__pNewPiece[index]->SetSurface(pNewSurface);
			__pNewPiece[index]->SetContentBounds(__pOldPiece[index]->GetContentBounds());
			__pNewPiece[index]->SetBounds(__pOldPiece[index]->GetBounds());
			__pNewPiece[index]->SetShowState(true);
			__pNewPiece[index]->SetOpacity(0.0f);
			__pVisualElement->AttachChild(__pNewPiece[index]);

			positionX += pieceW[x];
		}

		positionX = effectRect.x;
		positionY +=  pieceH[y];
	}

	delete pOldSurface;
	delete pNewSurface;

	long long tick;
	long delay = 0;
	long duration = 1200;
	bool check[PIECE_COUNT] = {0, };

	AnimationTransaction::Begin(__transactionId);
	AnimationTransaction::SetCurrentTransactionEventListener(this);

	for (int index = 0; index < PIECE_COUNT; index++)
	{
		SystemTime::GetTicks(tick);
		Math::Srand((int)tick + index);
		int random = Math::Rand() % PIECE_COUNT;

		while (check[random] == true)
		{
			if (++random == PIECE_COUNT)
				random = 0;
		}

		AnimationTransaction::Begin();
		AnimationTransaction::SetVisualElementAnimationDelay(delay);
		AnimationTransaction::SetVisualElementAnimationDuration(duration);

		VisualElementPropertyAnimation* pOldAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pOldAnimation->SetPropertyName(L"opacity");
		pOldAnimation->SetStartValue(1.0f);
		pOldAnimation->SetEndValue(0.0f);

		VisualElementPropertyAnimation* pNewAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pNewAnimation->SetPropertyName(L"opacity");
		pNewAnimation->SetStartValue(0.0f);
		pNewAnimation->SetEndValue(1.0f);

		__pOldPiece[random]->AddAnimation(*pOldAnimation);
		__pNewPiece[random]->AddAnimation(*pNewAnimation);

		delete pOldAnimation;
		delete pNewAnimation;

		AnimationTransaction::Commit();

		check[random] = true;
		delay += 150;
		duration -= 50;
	}

	AnimationTransaction::Commit();

	__currentIndex = ((__currentIndex+1) % GALLERY_IMAGE_COUNT);
}
