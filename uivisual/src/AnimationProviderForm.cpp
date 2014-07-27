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

#include "AnimationProviderForm.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

AnimationProviderForm::AnimationProviderForm(void)
	: __pRect(null)
	, __pLabel(null)
	, __isCustom(false)
{
}

AnimationProviderForm::~AnimationProviderForm(void)
{
}

result
AnimationProviderForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Animation provider");

	Rectangle clientRect = GetClientAreaBounds();

	__pLabel = new (std::nothrow) Label();
	__pLabel->Construct(Rectangle(50, clientRect.height - 125, clientRect.width - 100, 100), L"Default Provider");
	AddControl(__pLabel);

	float startSize = 300.f;
	float endSize = 525.f;

	__pRect = new (std::nothrow) VisualElement();
	__pRect->Construct();
	__pRect->SetName(L"Red");
	__pRect->SetBounds(FloatRectangle(clientRect.x + (clientRect.width - startSize) / 2.0f, clientRect.y + (clientRect.height / 2.0f - startSize / 1.5f), startSize, startSize));
	__pRect->SetShowState(true);
	__pRect->SetAnchor(FloatPoint(0.5f, 0.5f));
	_pFormElement->AttachChild(__pRect);

	Canvas* pCanvas = __pRect->GetCanvasN();
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_GREY), FloatRectangle(0.0f, 0.0f, 375.0f, 375.0f));
	delete pCanvas;

	__startRect = __pRect->GetBounds();
	__endRect = FloatRectangle(clientRect.x + (clientRect.width - endSize) / 2.0f, clientRect.y + (clientRect.height / 2.0f - endSize / 1.5f), endSize, endSize);

	return r;
}

void
AnimationProviderForm::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_ANIMATION_PROVIDER:
		ChangeAnimationProvider();
		break;

	default:
		break;
	}
}

void
AnimationProviderForm::InitializeFooter(void)
{
	FooterItem item;
	item.Construct(ID_FOOTER_BUTTON_ANIMATION_PROVIDER);
	item.SetText(L"Change Provider");

	Footer* pFooter = Form::GetFooter();
	pFooter->AddItem(item);
	pFooter->AddActionEventListener(*this);
}

VisualElementAnimation*
AnimationProviderForm::CreateAnimationForProperty(VisualElement& target, const String& property)
{
	VisualElementAnimation* pAnimation = null;

	if (property == L"bounds")
	{
		VisualElementAnimationGroup* pGroup = new (std::nothrow) VisualElementAnimationGroup();
		pGroup->SetDuration(1000);

		VisualElementPropertyAnimation* pRotateAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pRotateAnimation->SetPropertyName(L"transform.rotation.z");
		pRotateAnimation->SetStartValue(Variant(720.0f));
		pRotateAnimation->SetEndValue(Variant(0.0f));
		pRotateAnimation->SetDuration(1000);

		pGroup->AddAnimation(*pRotateAnimation);
		delete pRotateAnimation;

		VisualElementPropertyAnimation* pBoundsAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pBoundsAnimation->SetPropertyName(L"bounds");
		pBoundsAnimation->SetEndValue(Variant(target.GetBounds()));
		pBoundsAnimation->SetDuration(1000);

		pGroup->AddAnimation(*pBoundsAnimation);
		delete pBoundsAnimation;

		pAnimation = pGroup;
	}
	else
	{
		pAnimation = VisualElementAnimationProvider::CreateAnimationForProperty(target, property);
	}

	return pAnimation;
}

void
AnimationProviderForm::ChangeAnimationProvider(void)
{
	String text;
	FloatRectangle rect;
	const VisualElement* pPresentation = __pRect->AcquirePresentationInstance();

	if (__isCustom && pPresentation->GetProperty(L"transform.rotation.z").ToFloat() == 0.0f)
	{
		__pRect->SetAnimationProvider(null);
		__isCustom = false;

		rect = __startRect;
		text.Append(L"Default Provider");

		__pRect->SetBounds(rect);

		__pLabel->SetText(text);
		__pLabel->Draw();
	}
	else if (!__isCustom)
	{
		__pRect->SetAnimationProvider(this);
		__isCustom = true;

		rect = __endRect;
		text.Append(L"Custom Provider");

		__pRect->SetBounds(rect);

		__pLabel->SetText(text);
		__pLabel->Draw();
	}

	__pRect->ReleasePresentationInstance();
}
