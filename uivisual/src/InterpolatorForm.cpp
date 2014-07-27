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

#include "InterpolatorForm.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

InterpolatorForm::InterpolatorForm(void)
	: __pRect(null)
{
}

InterpolatorForm::~InterpolatorForm(void)
{
}

result
InterpolatorForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Interpolator");

	Rectangle clientRect = GetClientAreaBounds();

	__pRect = new (std::nothrow) VisualElement();
	__pRect->Construct();
	__pRect->SetName(L"Bounds");
	__pRect->SetBounds(FloatRectangle((clientRect.width - 150) / 2.0f, clientRect.y, 150.0f, 150.0f));
	__pRect->SetShowState(true);
	__pRect->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect);

	Canvas* pCanvas = __pRect->GetCanvasN();
	pCanvas->Clear();
	pCanvas->FillRoundRectangle(Color::GetColor(COLOR_ID_GREY), Rectangle(0, 0, 150, 150), Dimension(15, 15));
	delete pCanvas;

	return r;
}

void
InterpolatorForm::Play(void)
{
	VisualElementPropertyAnimation* pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"bounds");
	FloatRectangle rectf = __pRect->GetBounds();
	pAnimation->SetStartValue(Variant(rectf));
	rectf.Translate(0.0f, GetClientAreaBounds().height - 150.0f);
	pAnimation->SetEndValue(Variant(rectf));
	pAnimation->SetDuration(1000);
	pAnimation->SetEndValueApplied(false);
	pAnimation->SetValueInterpolator(this);

	const IVisualElementAnimationTimingFunction* pTimingFunction = VisualElementAnimation::GetTimingFunctionByName(L"EaseIn");
	pAnimation->SetTimingFunction(pTimingFunction);

	__pRect->AddAnimation(L"bounds", *pAnimation);
	
	delete pAnimation;
}

void
InterpolatorForm::Stop(void)
{
	__pRect->RemoveAllAnimations();
}

result
InterpolatorForm::Interpolate(float progress, const Variant& startValue, const Variant& endValue, Variant& value) const
{
	if (startValue.GetType() == VARIANT_TYPE_FLOAT_RECTANGLE)
	{
		const FloatRectangle& start = startValue.ToFloatRectangle();
		const FloatRectangle& end = endValue.ToFloatRectangle();

		float left = start.x * progress + end.x * (1.0f - progress);
		float top = start.y * progress + end.y * (1.0f - progress);
		float width = start.width * progress + end.width * (1.0f - progress);
		float height = start.height * progress + end.height * (1.0f - progress);

		value = FloatRectangle(left, top, width, height);

		return E_SUCCESS;
	}
	else
	{
		return E_INVALID_ARG;
	}
}
