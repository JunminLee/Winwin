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

#include "ZorderForm.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

ZorderForm::ZorderForm(void)
	: __pRed(null)
	, __pYellow(null)
	, __pGreen(null)
	, __pLabel(null)
{
}

ZorderForm::~ZorderForm(void)
{
}

result
ZorderForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Z-order & hit test");

	Rectangle clientRect = GetClientAreaBounds();

	__pLabel = new (std::nothrow) Label();
	__pLabel->Construct(Rectangle(50, clientRect.height - 125, clientRect.width - 100, 100), L"Hit Test : None");
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
	__pYellow->SetBounds(FloatRectangle(clientRect.x + 150.0f, clientRect.y + 150.0f, 375.0f, 375.0f));
	__pYellow->SetShowState(true);
	_pFormElement->AttachChild(__pYellow);

	pCanvas = __pYellow->GetCanvasN();
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_YELLOW), FloatRectangle(0.0f, 0.0f, 375.0f, 375.0f));
	delete pCanvas;

	__pGreen = new (std::nothrow) VisualElement();
	__pGreen->Construct();
	__pGreen->SetName(L"Green");
	__pGreen->SetBounds(FloatRectangle(clientRect.x + 225.0f, clientRect.y + 225.0f, 375.0f, 375.0f));
	__pGreen->SetShowState(true);
	__pGreen->SetContentProvider(this);
	_pFormElement->AttachChild(__pGreen);

	__pGreen->InvalidateRectangle(null);

	AddTouchEventListener(*this);

	return r;
}

void
ZorderForm::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_ZORDER:
		ChangeZorder();
		break;

	default:
		break;
	}
}

void
ZorderForm::InitializeFooter(void)
{
	FooterItem item;
	item.Construct(ID_FOOTER_BUTTON_ZORDER);
	item.SetText(L"Change Z-order");

	Footer* pFooter = Form::GetFooter();
	pFooter->AddItem(item);
	pFooter->AddActionEventListener(*this);
}

void
ZorderForm::OnTouchPressed (const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
	VisualElement* pTarget = _pFormElement->GetChildAt(FloatPoint(currentPosition.x, currentPosition.y));
	String labelString(L"Hit Test: ");

	if (pTarget)
	{
		if (pTarget->GetName()==L"Red")
		{
			labelString.Append(L"Red rectangle pressed");
		}
		else if (pTarget->GetName()==L"Yellow")
		{
			labelString.Append(L"Yellow rectangle pressed");
		}
		else if (pTarget->GetName()==L"Green")
		{
			labelString.Append(L"Green rectangle pressed");
		}
		else
		{
			labelString.Append(L"None");
		}
	}
	else
	{
		labelString.Append(L"None");
	}

	__pLabel->SetText(labelString);
	__pLabel->Draw();
}

void
ZorderForm::ChangeZorder(void)
{
	if (__pRed->GetZOrderGroup() > __pGreen->GetZOrderGroup())
	{
		__pRed->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_LOWEST);
		__pYellow->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_NORMAL);
		__pGreen->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_HIGHEST);
	}
	else
	{
		__pGreen->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_LOWEST);
		__pYellow->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_NORMAL);
		__pRed->SetZOrderGroup(VisualElement::Z_ORDER_GROUP_HIGHEST);
	}
}

bool
ZorderForm::PrepareDraw(VisualElement& target)
{
	return true;
}

void
ZorderForm::DrawContent(VisualElement& target, Canvas& canvas)
{
	if (target.GetName() == L"Green")
	{
		canvas.SetBackgroundColor(Color(0, 0, 0, 63));
		canvas.SetForegroundColor(Color::GetColor(COLOR_ID_GREEN));
		canvas.Clear();
		canvas.DrawRectangle(Rectangle(0, 0, 375, 375));
		canvas.FillRectangle(Color::GetColor(COLOR_ID_GREEN), FloatRectangle(150.0f, 150.0f, 75.0f, 75.0f));
	}
}

HitTestResult
ZorderForm::HitTest(VisualElement& target, const FloatPoint& point)
{
	if ((point.x >= 150.0f && point.x <= 225.0f) && (point.y >= 150.0f && point.y <= 225.0f))
	{
		return HIT_TEST_MATCH;
	}
	else
	{
		return HIT_TEST_NOWHERE;
	}
}
