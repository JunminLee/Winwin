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

#include "EventListenerForm.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

EventListenerForm::EventListenerForm(void)
	: __pRed(null)
	, __pYellow(null)
	, __pListener(null)
	, __pLabel(null)
	, __bAttached(false)
{
}

EventListenerForm::~EventListenerForm(void)
{
	if (__pRed != null)
	{
		__pRed->SetVisualElementEventListener(null);
	}

	if (__pListener != null)
	{
		delete __pListener;
		__pListener = null;
	}
}

result
EventListenerForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Event listener");

	Rectangle clientRect = GetClientAreaBounds();

	__pLabel = new (std::nothrow) Label();
	__pLabel->Construct(Rectangle(50, clientRect.height - 125, clientRect.width - 100, 100), L"Detached with opacity 1.0");
	AddControl(__pLabel);

	float redSize = 375.f;

	__pRed = new (std::nothrow) VisualElement();
	__pRed->Construct();
	__pRed->SetName(L"Red");
	__pRed->SetBounds(FloatRectangle((clientRect.width - redSize) / 2.0f, clientRect.y + (clientRect.height - redSize) / 2.0f, redSize, redSize));
	__pRed->SetShowState(true);
	_pFormElement->AttachChild(__pRed);

	Canvas* pCanvas = __pRed->GetCanvasN();
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_RED), FloatRectangle(0.0f, 0.0f, 375.0f, 375.0f));
	delete pCanvas;

	float yellowSize = 150.f;

	__pYellow = new (std::nothrow) VisualElement();
	__pYellow->Construct();
	__pYellow->SetName(L"Yellow");
	__pYellow->SetBounds(FloatRectangle((clientRect.width - yellowSize) / 2.0f, clientRect.y + 50.0f, yellowSize, yellowSize));
	__pYellow->SetShowState(true);
	__pYellow->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pYellow);

	pCanvas = __pYellow->GetCanvasN();
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_YELLOW), FloatRectangle(0.0f, 0.0f, 375.0f, 375.0f));
	delete pCanvas;

	__pListener = new MyEventListener(__pLabel, __pYellow->GetBounds());
	__pRed->SetVisualElementEventListener(__pListener);

	return r;
}

void
EventListenerForm::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_ATTACH_DETACH:
		{
			if (__bAttached == true)
			{
				__pRed->DetachChild(__pYellow);
				_pFormElement->AttachChild(__pYellow);
				__bAttached = false;
			}
			else
			{
				_pFormElement->DetachChild(__pYellow);
				__pRed->AttachChild(__pYellow);
				__bAttached = true;
			}
		}
		break;

	default:
		break;
	}
}

void
EventListenerForm::InitializeFooter(void)
{
	FooterItem item;
	item.Construct(ID_FOOTER_BUTTON_ATTACH_DETACH);
	item.SetText(L"Attach/Detach");

	Footer* pFooter = Form::GetFooter();
	pFooter->AddItem(item);
	pFooter->AddActionEventListener(*this);
}

void
MyEventListener::OnChildAttached(VisualElement& parent, VisualElement& child)
{
	FloatRectangle attachRect(50.0f, 50.0f, __bounds.width, __bounds.height);
	child.SetBounds(attachRect);
	child.SetOpacity(0.5f);

	__pLabel->SetText(L"Attached with opacity 0.5");
	__pLabel->Draw();
}

void
MyEventListener::OnChildDetached(VisualElement& parent, VisualElement& child)
{
	child.SetBounds(__bounds);
	child.SetOpacity(1.0f);

	__pLabel->SetText(L"Detached with opacity 1.0");
	__pLabel->Draw();
}
