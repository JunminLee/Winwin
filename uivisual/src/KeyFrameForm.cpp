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

#include "KeyFrameForm.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

KeyFrameForm::KeyFrameForm(void)
	: __pRect(null)
{
}

KeyFrameForm::~KeyFrameForm(void)
{	
}

result
KeyFrameForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Key frame");

	__clientRect = GetClientAreaBounds();

	__pRect = new (std::nothrow) VisualElement();
	__pRect->Construct();
	__pRect->SetName(L"KeyFrame");
	__pRect->SetBounds(FloatRectangle(__clientRect.x, __clientRect.y, __buttonSize, __buttonSize));
	__pRect->SetShowState(true);
	_pFormElement->AttachChild(__pRect);

	Canvas* pCanvas = __pRect->GetCanvasN();
	pCanvas->Clear();
	pCanvas->FillRoundRectangle(Color::GetColor(COLOR_ID_GREY), Rectangle(0, 0, __buttonSize, __buttonSize), Dimension(15, 15));
	delete pCanvas;

	return r;
}

void
KeyFrameForm::Play(void)
{
	VisualElementPropertyAnimation*	pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetAutoReverseEnabled(true);
	pAnimation->SetPropertyName(L"bounds");
	pAnimation->SetStartValue(Variant(FloatRectangle(__clientRect.x, __clientRect.y, __buttonSize, __buttonSize)));
	pAnimation->SetEndValue(Variant(FloatRectangle(__clientRect.x + __clientRect.width - __buttonSize, __clientRect.y + __clientRect.height - __buttonSize, __buttonSize, __buttonSize)));
	pAnimation->SetDuration(4000);

	const IVisualElementAnimationTimingFunction* pTimingFunction = VisualElementAnimation::GetTimingFunctionByName(L"Linear");
	pAnimation->SetTimingFunction(pTimingFunction);

	pAnimation->AddKeyFrame(0.2f, FloatRectangle(__clientRect.x + __clientRect.width - __buttonSize, __clientRect.y + __buttonSize, __buttonSize, __buttonSize), null);

	pTimingFunction = VisualElementAnimation::GetTimingFunctionByName(L"EaseIn");
	pAnimation->AddKeyFrame(0.4f, FloatRectangle(__clientRect.x, __clientRect.y + __buttonSize * 2, __buttonSize, __buttonSize), pTimingFunction);

	pTimingFunction = VisualElementAnimation::GetTimingFunctionByName(L"Discrete");
	pAnimation->AddKeyFrame(0.6f, FloatRectangle(__clientRect.x + __clientRect.width - __buttonSize, __clientRect.y + __buttonSize * 3, __buttonSize, __buttonSize), pTimingFunction);

	pTimingFunction = VisualElementAnimation::GetTimingFunctionByName(L"ExpOut");
	pAnimation->AddKeyFrame(0.8f, FloatRectangle(__clientRect.x, __clientRect.y + __buttonSize * 4, __buttonSize, __buttonSize), pTimingFunction);

	__pRect->AddAnimation(L"keyframe", *pAnimation);
	
	delete pAnimation;
}

void
KeyFrameForm::Stop(void)
{
	__pRect->RemoveAllAnimations();
}
