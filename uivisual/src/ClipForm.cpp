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

#include "ClipForm.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

ClipForm::ClipForm(void)
	: __pRed(null)
	, __pYellow(null)
	, __pGreen(null)
	, __pLabel(null)
{
}

ClipForm::~ClipForm(void)
{
}

result
ClipForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Clip");

	Rectangle clientRect = GetClientAreaBounds();

	__pLabel = new (std::nothrow) Label();
	__pLabel->Construct(Rectangle(50, clientRect.height - 125, clientRect.width - 100, 100), L"Clip Off");
	AddControl(__pLabel);

	__pRed = new (std::nothrow) VisualElement();
	__pRed->Construct();
	__pRed->SetName(L"Red");
	__pRed->SetBounds(FloatRectangle(clientRect.x + 75.0f, clientRect.y + 75.0f, 375.0f, 375.0f));
	__pRed->SetShowState(true);
	_pFormElement->AttachChild(__pRed);

	Canvas* pCanvas = __pRed->GetCanvasN();
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_RED), FloatRectangle(0.0f, 0.0f, 375.0f, 375.0f));
	delete pCanvas;

	__pYellow = new (std::nothrow) VisualElement();
	__pYellow->Construct();
	__pYellow->SetName(L"Yellow");
	__pYellow->SetBounds(FloatRectangle(75.0f, 75.0f, 375.0f, 375.0f));
	__pYellow->SetShowState(true);
	__pRed->AttachChild(__pYellow);

	pCanvas = __pYellow->GetCanvasN();
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_YELLOW), FloatRectangle(0.0f, 0.0f, 375.0f, 375.0f));
	delete pCanvas;

	__pGreen = new (std::nothrow) VisualElement();
	__pGreen->Construct();
	__pGreen->SetName(L"Green");
	__pGreen->SetBounds(FloatRectangle(75.0f, 75.0f, 375.0f, 375.0f));
	__pGreen->SetShowState(true);
	__pYellow->AttachChild(__pGreen);

	pCanvas = __pGreen->GetCanvasN();
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_GREEN), FloatRectangle(0.0f, 0.0f, 375.0f, 375.0f));
	delete pCanvas;

	return r;
}

void
ClipForm::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_CLIP:
		ChangeClip();
		break;

	default:
		break;
	}
}

void
ClipForm::InitializeFooter(void)
{
	FooterItem  item;
	item.Construct(ID_FOOTER_BUTTON_CLIP);
	item.SetText(L"Clip");

	Footer* pFooter = Form::GetFooter();
	pFooter->AddItem(item);
	pFooter->AddActionEventListener(*this);
}

void
ClipForm::ChangeClip(void)
{
	__pRed->SetClipChildrenEnabled(!__pRed->IsClipChildrenEnabled());

	String text(L"Clip ");
	if (__pRed->IsClipChildrenEnabled())
	{
		text.Append(L"On");
	}
	else
	{
		text.Append(L"Off");
	}

	__pLabel->SetText(text);
	__pLabel->Draw();
}
