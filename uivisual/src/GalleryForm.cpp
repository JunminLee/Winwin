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

#include "GalleryForm.h"
#include "GalleryImageViewForm.h"
#include "SceneRegister.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Base::Utility;
using namespace Tizen::Base::Collection;
using namespace Tizen::Graphics;
using namespace Tizen::System;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

GalleryForm::GalleryForm(void)
{
	for (int i = 0; i < GALLERY_IMAGE_COUNT; i++)
	{
		__pElement[i] = null;
	}

	__pImgManager = new (std::nothrow) GalleryImageManager();

	__pTimingFunction = null;

	__viewNumber = 0;
	__touchedIndex = 0;

	__isAnimatingImageView = false;
}

GalleryForm::~GalleryForm(void)
{
	for (int i = 0; i < GALLERY_IMAGE_COUNT; i++)
	{
		if (__pElement[i])
		{
			__pElement[i]->Destroy();
			__pElement[i] = null;
		}
	}

	if (__pImgManager)
	{
		delete __pImgManager;
		__pImgManager = null;
	}

	if (__pTimingFunction)
	{
		delete __pTimingFunction;
		__pTimingFunction = null;
	}
}

bool
GalleryForm::Initialize()
{
	Construct(FORM_STYLE_NORMAL | FORM_STYLE_FOOTER | FORM_STYLE_INDICATOR);
	SetFormBackEventListener(this);
	Footer* pFooter = Form::GetFooter();
	pFooter->SetStyle(FOOTER_STYLE_BUTTON_TEXT);
	pFooter->SetBackButton();

	InitializeFooter();

	_pFormElement = GetVisualElement();

	return true;
}

result
GalleryForm::OnInitializing(void)
{
	AddTouchEventListener(*this);

	CreateGallery();

	return E_SUCCESS;
}

void
GalleryForm::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_VIEW:
		ChangeView();
		break;

	case ID_FOOTER_BUTTON_SLIDESHOW:
		SendUserEvent(GalleryImageManager::REQUEST_ID_IMAGE_VIEW_SLIDE_SHOW, null);
		break;

	default:
		break;
	}
}

void
GalleryForm::OnFormBackRequested(Form& source)
{
	SceneManager::GetInstance()->GoBackward(BackwardSceneTransition(SCENE_MAIN_MENU));
}

void
GalleryForm::OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs)
{
	Frame* pFrame = static_cast< Frame* >(GetParent());
	if (pFrame == null)
	{
		return;
	}

	switch(requestId)
	{
	case GalleryImageManager::REQUEST_ID_GALLERY_VIEW:
		{
			pFrame->SetCurrentForm(this);
			Integer* pInt = static_cast< Integer* >(pArgs->GetAt(1));
			int index = pInt->ToInt();
			delete pInt;

			CreateAnimationForReenter(index);

			Form* pForm = static_cast<Form*>(pArgs->GetAt(0));
			pFrame->RemoveControl(pForm);
		}
		break;

	case GalleryImageManager::REQUEST_ID_IMAGE_VIEW:
		{
			Integer* pInt = static_cast< Integer* >(pArgs->GetAt(0));
			int index = pInt->ToInt();
			delete pInt;

			CreateImageView(index, false);

			__pElement[index]->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_NORMAL + index);
			__pElement[index]->SetProperty(L"transform.rotation.z", 0.0f);
			__pElement[index]->SetImplicitAnimationEnabled(true);
		}
		break;

	case GalleryImageManager::REQUEST_ID_IMAGE_VIEW_SLIDE_SHOW:
		{
			CreateImageView(0, true);
		}
		break;
	}

	if (pArgs != null)
	{
		delete pArgs;
	}
}

void
GalleryForm::CreateImageView(int index, bool slideShow)
{
	Frame* pFrame = static_cast< Frame* >(GetParent());
	if (pFrame == null)
	{
		return;
	}

	Form* pForm = pFrame->GetCurrentForm();
	if (pForm != null && pForm->GetName() == L"GalleryImageView")
	{
		return;
	}

	if (__isAnimatingImageView == false)
	{
		GalleryImageViewForm* pImageViewForm = new (std::nothrow) GalleryImageViewForm(__pImgManager, index);
		pImageViewForm->Initialize();
		pFrame->AddControl(pImageViewForm);
		pFrame->SetCurrentForm(pImageViewForm);
		pImageViewForm->Draw();

		if (slideShow == true)
		{
			pImageViewForm->SendUserEvent(GalleryImageManager::REQUEST_ID_SLIDE_SHOW_START, null);
		}
		else
		{
			FloatRectangle rect = __pElement[index]->GetBounds();
			DrawImage(index, true);
			__pElement[index]->SetBounds(rect);

			for (int i = 0; i < GALLERY_IMAGE_COUNT; i++)
			{
				__pElement[i]->SetOpacity(1.0f);
			}
		}
	}
}

void
GalleryForm::InitializeFooter(void)
{
	FooterItem item1;
	item1.Construct(ID_FOOTER_BUTTON_VIEW);
	item1.SetText(L"Change\nView");

	FooterItem item2;
	item2.Construct(ID_FOOTER_BUTTON_SLIDESHOW);
	item2.SetText(L"Slide Show");

	Footer* pFooter = Form::GetFooter();
	pFooter->AddItem(item1);
	pFooter->AddItem(item2);
	pFooter->AddActionEventListener(*this);
}

void
GalleryForm::OnTouchReleased (const Control& source, const Point& currentPosition, const TouchEventInfo& touchInfo)
{
	VisualElement* pTarget = _pFormElement->GetChildAt(FloatPoint(currentPosition.x, currentPosition.y));
	if(pTarget)
	{
		String name = pTarget->GetName();
		if (name.Contains(L"img"))
		{
			int index = reinterpret_cast< int >(pTarget->GetUserData());
			CreateAnimationForImageView(index);
		}
	}
}

void
GalleryForm::OnVisualElementAnimationStarted(const VisualElementAnimation& animation, const String& keyName, VisualElement& target)
{
	if (keyName == L"ImageView")
	{
		__isAnimatingImageView = true;
	}
}

void
GalleryForm::OnVisualElementAnimationFinished(const VisualElementAnimation& animation, const String& keyName, VisualElement& target, bool completedNormally)
{
	if (keyName == L"ImageView")
	{
		int index = reinterpret_cast< int >(target.GetUserData());
		__isAnimatingImageView = false;

		if (completedNormally)
		{
			ArrayList* pList = new (std::nothrow) ArrayList();
			pList->Add(*(new (std::nothrow) Integer(index)));

			SendUserEvent(GalleryImageManager::REQUEST_ID_IMAGE_VIEW, pList);
		}
	}
}

void
GalleryForm::CreateGallery(void)
{
	String name;

	for(int index = 0; index < GALLERY_IMAGE_COUNT; index++)
	{
		__pElement[index] = new (std::nothrow) VisualElement();
		__pElement[index]->Construct();
		__pElement[index]->SetShowState(true);
		_pFormElement->AttachChild(__pElement[index]);

		name.Format(10, L"img%d", index);
		__pElement[index]->SetName(name);
		__pElement[index]->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_NORMAL + index);
		__pElement[index]->SetUserData((void*)index);

		DrawImage(index, true);
	}

	ChangeView();
}

void
GalleryForm::CreateAnimationForImageView(int index)
{
	if (__isAnimatingImageView)
	{
		return;
	}

	__pElement[index]->SetImplicitAnimationEnabled(false);

	FloatRectangle rect = __pElement[index]->GetBounds();
	DrawImage(index, false);
	__pElement[index]->SetBounds(rect);

	AnimationTransaction::Begin();

	VisualElementPropertyAnimation* pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"bounds");

	Rectangle clientRect = GetClientAreaBounds();
	Rectangle endRect;

	__pImgManager->GetCenterAlighBounds(index, Rectangle(0, 0, clientRect.width, clientRect.height), endRect, GalleryImageManager::SCALE_STYLE_FIT);

	pAnimation->SetStartValue(__pElement[index]->GetBounds());
	pAnimation->SetEndValue(FloatRectangle(endRect.x + clientRect.x, endRect.y + clientRect.y, endRect.width, endRect.height));
	pAnimation->SetEndValueApplied(false);
	pAnimation->SetDuration(1000);
	pAnimation->SetVisualElementAnimationStatusEventListener(this);

	__pTimingFunction = new ExpOutTimingFunction();
	__pTimingFunction->SetScaleValue(2);

	pAnimation->SetTimingFunction(__pTimingFunction);

	__pElement[index]->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_HIGHEST -100 + index);
	__pElement[index]->AddAnimation(L"ImageView", *pAnimation);
	delete pAnimation;

	pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"transform.rotation.z");
	pAnimation->SetStartValue(0.0f);
	pAnimation->SetEndValue(360.0f);
	pAnimation->SetDuration(1000);
	pAnimation->SetTimingFunction(__pTimingFunction);

	__pElement[index]->AddAnimation(*pAnimation);
	delete pAnimation;

	pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"opacity");
	pAnimation->SetStartValue(1.0f);
	pAnimation->SetEndValue(0.0f);
	pAnimation->SetDuration(1000);
	pAnimation->SetTimingFunction(__pTimingFunction);

	for (int i = 0; i < GALLERY_IMAGE_COUNT; i++)
	{
		if (i != index)
			__pElement[i]->AddAnimation(*pAnimation);
	}

	delete pAnimation;

	AnimationTransaction::Commit();
	__touchedIndex = index;
}

void
GalleryForm::CreateAnimationForReenter(int index)
{
	VisualElement* pPresentation = const_cast< VisualElement* >(__pElement[__touchedIndex]->AcquirePresentationInstance());
	pPresentation->SetBounds(__pElement[__touchedIndex]->GetBounds());

	VisualElementPropertyAnimation*	pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"bounds");

	FloatRectangle startRect = __pElement[index]->GetBounds();
	startRect.SetBounds(startRect.x, startRect.y + startRect.height / 2.0f - 1.0f, startRect.width, 2.0f);
	pAnimation->SetStartValue(startRect);
	pAnimation->SetEndValue(__pElement[index]->GetBounds());

	__pElement[index]->AddAnimation(*pAnimation);
	delete pAnimation;

	pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"opacity");
	pAnimation->SetStartValue(0.0f);
	pAnimation->SetEndValue(1.0f);
	pAnimation->SetDuration(300);

	__pElement[index]->AddAnimation(*pAnimation);
	__pElement[__touchedIndex]->ReleasePresentationInstance();
	delete pAnimation;
}

void
GalleryForm::ChangeView(void)
{
	if(__isAnimatingImageView)
	{
		for( int index = 0 ; index < GALLERY_IMAGE_COUNT ; index++)
		{
			__pElement[index]->RemoveAllAnimations();
			__pElement[index]->SetOpacity(1.0f);
		}
		__pElement[__touchedIndex]->SetImplicitAnimationEnabled(true);
		DrawImage(__touchedIndex,true);
	}

	switch(__viewNumber)
	{
	case 0:
		TileView();
		break;

	case 1:
		StackView();
		break;
	}

	if (__viewNumber++ == 1)
		__viewNumber = 0;
}

void
GalleryForm::TileView(void)
{
	int offset = 14, gridCount = 4;
	int x, y, width, height, index = 0;

	Rectangle clientRect = GetClientAreaBounds();

	width = height = (clientRect.width - offset*(gridCount + 1))/gridCount;

	for (int i = 0; i < gridCount; i++)
	{
		for (int j = 0; j < gridCount; j++)
		{
			if (index >= GALLERY_IMAGE_COUNT)
				break;

			x = clientRect.x + offset * (j + 1) + width * j;
			y = clientRect.y + offset * (i + 1) + height * i;

			__pElement[index]->SetProperty(L"transform.rotation.z", Variant(0.0f));
			__pElement[index]->SetBounds(FloatRectangle(x, y, width, height));

			index++;
		}
	}
}

void
GalleryForm::StackView(void)
{
	int offsetY = 40;
	float width, height;

	Rectangle clientRect = GetClientAreaBounds();

	width = (float)clientRect.width / 1.5f;
	height = (float)clientRect.width / 2.0f;

	for (int index = 0; index < GALLERY_IMAGE_COUNT; index++)
	{
		long long tick;
		SystemTime::GetTicks(tick);
		Math::Srand((int)tick + index);

		int offsetX = 0;
		int type = index % 3;

		switch(type)
		{
		case 0:
			offsetX = Math::Rand() % 30;
			__pElement[index]->SetProperty("transform.rotation.z", Variant(-3.0f));
			break;
		case 1:
			offsetX = 30 + (Math::Rand() % 30);
			__pElement[index]->SetProperty("transform.rotation.z", Variant(0.0f));
			break;
		case 2:
			offsetX = -30 - (Math::Rand() % 30);
			__pElement[index]->SetProperty("transform.rotation.z", Variant(3.0f));
			break;
		}

		__pElement[index]->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_NORMAL + index);
		__pElement[index]->SetBounds(FloatRectangle(clientRect.x + (clientRect.width - width) / 2.0f + offsetX, clientRect.y + offsetY * (index + 1), width, height));
	}
}

void
GalleryForm::DrawImage(int index, bool border)
{
	Bitmap* pBitmap = __pImgManager->GetBitmap(index);
	if (pBitmap)
	{
		Canvas* pCanvas;
		if (border)
		{
			float offset = 4.0f;
			float width = pBitmap->GetWidth() + offset * 4;
			float height = pBitmap->GetHeight() + offset * 4;

			__pElement[index]->SetBounds(FloatRectangle(0.0f, 0.0f, width, height));

			pCanvas = __pElement[index]->GetCanvasN();
			pCanvas->SetBackgroundColor(Color::GetColor(COLOR_ID_GREY));
			pCanvas->Clear();

			width -= offset * 2;
			height -= offset * 2;

			pCanvas->FillRectangle(Color(0xCCFFFFFF), FloatRectangle(offset, offset, width, height));
			pCanvas->DrawBitmap(Point(offset * 2, offset * 2), *pBitmap);
		}
		else
		{
			__pElement[index]->SetBounds(FloatRectangle(0.0f, 0.0f, pBitmap->GetWidth(), pBitmap->GetHeight()));
			pCanvas = __pElement[index]->GetCanvasN();
			pCanvas->DrawBitmap(Point(0, 0), *pBitmap);
		}

		delete pCanvas;
	}
}

