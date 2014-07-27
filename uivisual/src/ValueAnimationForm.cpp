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

#include "ValueAnimationForm.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

ValueAnimationForm::ValueAnimationForm(void)
	: __pCircle(null)
	, __pLabel(null)
{
}

ValueAnimationForm::~ValueAnimationForm(void)
{
}

result
ValueAnimationForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Value animation");

	Rectangle clientRect = GetClientAreaBounds();

	__pLabel = new (std::nothrow) Label();
	__pLabel->Construct(Rectangle(50, clientRect.height - 125, clientRect.width - 100, 100), L"Diameter: 300");
	AddControl(__pLabel);

	__pCircle = new (std::nothrow) VisualElement();
	__pCircle->Construct();
	__pCircle->SetName(L"Circle");
	__pCircle->SetBounds(FloatRectangle(60, 225, 300, 300));
	__pCircle->SetShowState(true);
	__pCircle->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pCircle);

	Canvas* pCanvas = __pCircle->GetCanvasN();
	pCanvas->SetBackgroundColor(GetBackgroundColor());
	pCanvas->Clear();
	pCanvas->FillEllipse(Color::GetColor(COLOR_ID_GREY), Rectangle(0, 0, 300, 300));
	delete pCanvas;

	return r;
}

void
ValueAnimationForm::Play(void)
{
	VisualElementValueAnimation* pAnimation = new (std::nothrow) VisualElementValueAnimation();
	pAnimation->SetStartValue(Variant(300));
	pAnimation->SetEndValue(Variant(600));
	pAnimation->SetDuration(2000);
	pAnimation->SetVisualElementAnimationTickEventListener(this);
	pAnimation->SetRepeatCount(2);
	pAnimation->SetEndValueApplied(false);
	pAnimation->SetVisualElementAnimationStatusEventListener(this);
	__pCircle->AddAnimation(L"Value", *pAnimation);

	delete pAnimation;
}

void
ValueAnimationForm::Stop(void)
{
	__pCircle->RemoveAllAnimations();
}

void
ValueAnimationForm::OnTickOccurred(const VisualElementAnimation& animation, const String& keyName, VisualElement& target, const Variant& currentValue)
{
	if (target.GetName() != L"Circle" || keyName != L"Value")
	{
		return;
	}

	__pCircle->SetBounds(FloatRectangle(60, 225, currentValue.ToInt(),currentValue.ToInt()));

	String str(L"Diameter: ");
	str.Append(currentValue.ToInt());

	__pLabel->SetText(str);
	__pLabel->Draw();
}

void
ValueAnimationForm::OnVisualElementAnimationFinished(const VisualElementAnimation& animation, const String& keyName, VisualElement& target, bool completedNormally)
{
	const VisualElementValueAnimation* pAnimation = dynamic_cast<const VisualElementValueAnimation*>(&(animation));
	if (completedNormally)
	{
		if (pAnimation->IsEndValueApplied() == false)
		{
			Variant startValue = pAnimation->GetStartValue();
			target.SetBounds(FloatRectangle(60, 225, startValue.ToInt(), startValue.ToInt()));
		}

		__pLabel->SetText(L"Diameter: 300");
		__pLabel->Draw();
	}
}
