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

#include "TransactionForm.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

TransactionForm::TransactionForm(void)
	: __pRect1(null)
	, __pRect2(null)
	, __pRect3(null)
	, __pRect4(null)
	, __pRect5(null)
	, __pRect6(null)
	, __pLabel(null)
	, __pListener1(null)
	, __pListener2(null)
	, __pListener3(null)
	, __transactionId(0)
{
}

TransactionForm::~TransactionForm(void)
{
	if (__pListener1)
	{
		delete __pListener1;
		__pListener1 = null;
	}

	if (__pListener2)
	{
		delete __pListener2;
		__pListener2 = null;
	}

	if (__pListener3)
	{
		delete __pListener3;
		__pListener3 = null;
	}
}

result
TransactionForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Transaction");

	Canvas* pCanvas = null;

	Rectangle clientRect = GetClientAreaBounds();
	float offset = 75.0f;

	__pLabel = new (std::nothrow) Label();
	__pLabel->Construct(Rectangle(50, clientRect.height - 125, clientRect.width - 100, 100), L"");
	AddControl(__pLabel);

	__pRect1 = new (std::nothrow) VisualElement();
	__pRect1->Construct();
	__pRect1->SetName(L"Rect1");
	__pRect1->SetBounds(FloatRectangle(clientRect.x + offset,clientRect.y + offset, __buttonSize, __buttonSize));
	__pRect1->SetShowState(true);
	__pRect1->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect1);

	pCanvas = __pRect1->GetCanvasN();
	pCanvas->FillRectangle(Color(255, 0, 0), FloatRectangle(0, 0, __buttonSize, __buttonSize));
	delete pCanvas;

	__pRect2 = new (std::nothrow) VisualElement();
	__pRect2->Construct();
	__pRect2->SetName(L"Rect2");
	__pRect2->SetBounds(FloatRectangle(clientRect.x + clientRect.width - __buttonSize - offset, clientRect.y + offset, __buttonSize, __buttonSize));
	__pRect2->SetShowState(true);
	__pRect2->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect2);

	pCanvas = __pRect2->GetCanvasN();
	pCanvas->FillRectangle(Color(0, 255, 255), FloatRectangle(0, 0, __buttonSize, __buttonSize));
	delete pCanvas;
	__pRect2->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_LOWEST);

	__pRect3 = new (std::nothrow) VisualElement();
	__pRect3->Construct();
	__pRect3->SetName(L"Rect3");
	__pRect3->SetBounds(FloatRectangle(clientRect.x + offset, clientRect.y + __buttonSize + offset * 2, __buttonSize, __buttonSize));
	__pRect3->SetShowState(true);
	__pRect3->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect3);

	pCanvas = __pRect3->GetCanvasN();
	pCanvas->FillRectangle(Color(0, 0, 255), FloatRectangle(0, 0, __buttonSize, __buttonSize));
	delete pCanvas;
	__pRect3->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_LOWEST);

	__pRect4 = new (std::nothrow) VisualElement();
	__pRect4->Construct();
	__pRect4->SetName(L"Rect4");
	__pRect4->SetBounds(FloatRectangle(clientRect.x + clientRect.width - __buttonSize - offset, clientRect.y + __buttonSize + offset * 2, __buttonSize, __buttonSize));
	__pRect4->SetShowState(true);
	__pRect4->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect4);

	pCanvas = __pRect4->GetCanvasN();
	pCanvas->FillRectangle(Color(255, 255, 0), FloatRectangle(0, 0, __buttonSize, __buttonSize));
	delete pCanvas;

	__pRect5 = new (std::nothrow) VisualElement();
	__pRect5->Construct();
	__pRect5->SetName(L"Rect5");
	__pRect5->SetBounds(FloatRectangle(clientRect.x + offset, clientRect.y + __buttonSize * 2 + offset * 3, __buttonSize, __buttonSize));
	__pRect5->SetShowState(true);
	__pRect5->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect5);

	pCanvas = __pRect5->GetCanvasN();
	pCanvas->FillRectangle(Color(0, 255, 0), FloatRectangle(0, 0, __buttonSize, __buttonSize));
	delete pCanvas;

	__pRect6 = new (std::nothrow) VisualElement();
	__pRect6->Construct();
	__pRect6->SetName(L"Rect6");
	__pRect6->SetBounds(FloatRectangle(clientRect.x + clientRect.width - __buttonSize - offset, clientRect.y + __buttonSize * 2 + offset * 3, __buttonSize, __buttonSize));
	__pRect6->SetShowState(true);
	__pRect6->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect6);

	pCanvas = __pRect6->GetCanvasN();
	pCanvas->FillRectangle(Color(255, 0, 255), FloatRectangle(0, 0, __buttonSize, __buttonSize));
	delete pCanvas;
	__pRect6->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_LOWEST);

	__pListener1 = new (std::nothrow) MyEventListener1(__pLabel);
	__pListener2 = new (std::nothrow) MyEventListener2(__pLabel);
	__pListener3 = new (std::nothrow) MyEventListener3(__pLabel);

	return r;
}

void
TransactionForm::Play(void)
{
	if (AnimationTransaction::GetStatus(__transactionId) == ANIMATION_TRANSACTION_STATUS_STOPPED)
	{
		__pLabel->SetText(L"");
		__pLabel->Draw();

		FloatRectangle rectf1 = __pRect1->GetBounds();
		FloatRectangle rectf2 = __pRect2->GetBounds();
		FloatRectangle rectf3 = __pRect3->GetBounds();
		FloatRectangle rectf4 = __pRect4->GetBounds();
		FloatRectangle rectf5 = __pRect5->GetBounds();
		FloatRectangle rectf6 = __pRect6->GetBounds();

		__pRect1->SetBounds(rectf1);
		__pRect2->SetBounds(rectf2);
		__pRect3->SetBounds(rectf3);
		__pRect4->SetBounds(rectf4);
		__pRect5->SetBounds(rectf5);
		__pRect6->SetBounds(rectf6);

		AnimationTransaction::Begin(__transactionId);
		AnimationTransaction::SetVisualElementAnimationDuration(1500);
		AnimationTransaction::SetVisualElementAnimationDelay(3000);
		AnimationTransaction::SetVisualElementAnimationAutoReverseEnabled(true);
		AnimationTransaction::SetCurrentTransactionEventListener(__pListener1);

		VisualElementPropertyAnimation* pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pAnimation->SetPropertyName(L"bounds");
		pAnimation->SetStartValue(rectf1);
		pAnimation->SetEndValue(rectf2);
		__pRect1->AddAnimation(L"rect1", *pAnimation);
		delete pAnimation;

		pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pAnimation->SetPropertyName(L"bounds");
		pAnimation->SetStartValue(rectf2);
		pAnimation->SetEndValue(rectf1);
		__pRect2->AddAnimation(L"rect2", *pAnimation);
		delete pAnimation;

		AnimationTransaction::Begin();
		AnimationTransaction::SetVisualElementAnimationDelay(1500);
		AnimationTransaction::SetCurrentTransactionEventListener(__pListener2);

		pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pAnimation->SetPropertyName(L"bounds");
		pAnimation->SetStartValue(rectf3);
		pAnimation->SetEndValue(rectf4);
		__pRect3->AddAnimation(L"rect3", *pAnimation);
		delete pAnimation;

		pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pAnimation->SetPropertyName(L"bounds");
		pAnimation->SetStartValue(rectf4);
		pAnimation->SetEndValue(rectf3);
		__pRect4->AddAnimation(L"rect4", *pAnimation);
		delete pAnimation;

		AnimationTransaction::Begin();
		AnimationTransaction::SetVisualElementAnimationDelay(0);
		AnimationTransaction::SetCurrentTransactionEventListener(__pListener3);

		pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pAnimation->SetPropertyName(L"bounds");
		pAnimation->SetStartValue(rectf5);
		pAnimation->SetEndValue(rectf6);
		__pRect5->AddAnimation(L"rect5", *pAnimation);
		delete pAnimation;

		pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pAnimation->SetPropertyName(L"bounds");
		pAnimation->SetStartValue(rectf6);
		pAnimation->SetEndValue(rectf5);
		__pRect6->AddAnimation(L"rect6", *pAnimation);
		delete pAnimation;

		AnimationTransaction::Commit();
		AnimationTransaction::Commit();
		AnimationTransaction::Commit();
	}
}

void
TransactionForm::Stop(void)
{
	__pRect1->RemoveAllAnimations();
	__pRect2->RemoveAllAnimations();
	__pRect3->RemoveAllAnimations();
	__pRect4->RemoveAllAnimations();
	__pRect5->RemoveAllAnimations();
	__pRect6->RemoveAllAnimations();
}

void
MyEventListener1::OnAnimationTransactionFinished(int transactionId)
{
	__pLabel->SetText(L"first transaction finished!");
	__pLabel->Draw();
}

void
MyEventListener2::OnAnimationTransactionFinished(int transactionId)
{
	__pLabel->SetText(L"second transaction finished!");
	__pLabel->Draw();
}

void
MyEventListener3::OnAnimationTransactionFinished(int transactionId)
{
	__pLabel->SetText(L"third transaction finished!");
	__pLabel->Draw();
}
