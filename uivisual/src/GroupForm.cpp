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

#include "GroupForm.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

GroupForm::GroupForm(void)
	: __pRect(null)
	, __pLabel(null)
	, __addAnimation(false)
{
}

GroupForm::~GroupForm(void)
{	
}

result
GroupForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Group");

	Rectangle clientRect = GetClientAreaBounds();

	__pLabel = new (std::nothrow) Label();
	__pLabel->Construct(Rectangle(50, clientRect.height - 125, clientRect.width - 100, 100), L"Group status");
	AddControl(__pLabel);

	__pRect = new (std::nothrow) VisualElement();
	__pRect->Construct();
	__pRect->SetName(L"Group");
	__pRect->SetBounds(FloatRectangle(clientRect.x + 60, clientRect.y + 60, __buttonSize, __buttonSize));
	__pRect->SetShowState(true);
	__pRect->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect);

	Canvas* pCanvas = __pRect->GetCanvasN();
	pCanvas->FillRectangle(Color(255, 0, 0), FloatRectangle(0, 0, __buttonSize, __buttonSize));
	delete pCanvas;

	return r;
}

void
GroupForm::Play(void)
{
	if (__addAnimation == false)
	{
		if (__pRect->GetProperty(L"transform.scale.x") != 1.0f)
		{
			__pLabel->SetText(L"Group status");
			__pLabel->Draw();

			Rectangle clientRect = GetClientAreaBounds();

			__pRect->SetProperty(L"transform.scale.x", Variant(1.0f));
			__pRect->SetProperty(L"transform.scale.y", Variant(1.0f));
			__pRect->SetBounds(FloatRectangle(clientRect.x + 60, clientRect.y + 60, __buttonSize, __buttonSize));

			Canvas* pCanvas = __pRect->GetCanvasN();
			pCanvas->FillRectangle(Color(255,0,0), FloatRectangle(0, 0, __buttonSize, __buttonSize));
			delete pCanvas;
		}

		VisualElementAnimationGroup* pOuterGroup = new (std::nothrow) VisualElementAnimationGroup();
		pOuterGroup->SetDuration(6000);
		pOuterGroup->SetDelay(2000);
		pOuterGroup->SetVisualElementAnimationStatusEventListener(this);

		VisualElementPropertyAnimation* pPropertyAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pPropertyAnimation->SetPropertyName(L"transform.scale.x");
		pPropertyAnimation->SetStartValue(Variant(1.0f));
		pPropertyAnimation->SetEndValue(Variant(0.25f));
		pPropertyAnimation->SetDuration(1000);
		pOuterGroup->AddAnimation(*pPropertyAnimation);
		delete pPropertyAnimation;

		pPropertyAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pPropertyAnimation->SetPropertyName(L"transform.scale.y");
		pPropertyAnimation->SetStartValue(Variant(1.0f));
		pPropertyAnimation->SetEndValue(Variant(0.25f));
		pPropertyAnimation->SetDelay(1000);
		pPropertyAnimation->SetDuration(1000);
		pOuterGroup->AddAnimation(*pPropertyAnimation);
		delete pPropertyAnimation;

		VisualElementValueAnimation* pValueAnimation = new (std::nothrow) VisualElementValueAnimation();
		pValueAnimation->SetStartValue(Variant(0));
		pValueAnimation->SetEndValue(Variant(255));
		pValueAnimation->SetDelay(3000);
		pValueAnimation->SetDuration(5000);
		pValueAnimation->SetVisualElementAnimationTickEventListener(this);
		pOuterGroup->AddAnimation(*pValueAnimation);
		delete pValueAnimation;

		VisualElementAnimationGroup* pInnerGroup = new (std::nothrow) VisualElementAnimationGroup();
		pInnerGroup->SetDuration(2000);
		pInnerGroup->SetDelay(3000);
		pInnerGroup->SetOffset(1000);
		pInnerGroup->SetVisualElementAnimationStatusEventListener(this);
		pInnerGroup->SetUserData((void*)(new (std::nothrow) String(L"InnerGroup")));

		pPropertyAnimation = new (std::nothrow) VisualElementPropertyAnimation();
		pPropertyAnimation->SetPropertyName(L"bounds");
		FloatRectangle	rectf = __pRect->GetBounds();
		rectf.Translate(100.0f, 0.0f);
		pPropertyAnimation->SetEndValue(Variant(rectf));
		pPropertyAnimation->SetDuration(2000);
		pInnerGroup->AddAnimation(*pPropertyAnimation);
		delete pPropertyAnimation;

		pOuterGroup->AddAnimation(*pInnerGroup);
		delete pInnerGroup;

		__pRect->AddAnimation(L"OuterGroup", *pOuterGroup);
		delete pOuterGroup;

		__addAnimation = true;
	}
}

void
GroupForm::Stop(void)
{
	__pRect->RemoveAllAnimations();
}

void
GroupForm::OnTickOccurred(const VisualElementAnimation& animation, const String& keyName, VisualElement& target, const Variant& currentValue)
{
	Canvas* pCanvas = __pRect->GetCanvasN();
	pCanvas->FillRectangle(Color(255 - currentValue.ToInt(), currentValue.ToInt(), 0), FloatRectangle(0, 0, __buttonSize, __buttonSize));
	delete pCanvas;
}

void
GroupForm::OnVisualElementAnimationStarted(const VisualElementAnimation& animation, const String& keyName, VisualElement& target)
{
	if (keyName == L"OuterGroup")
	{
		__pLabel->SetText(L"[Outer] Group is started!");
		__pLabel->Draw();
	}
	else
	{
		String* pGroupName = reinterpret_cast<String*>(animation.GetUserData());
		if (pGroupName != null)
		{
			if (*pGroupName == L"InnerGroup")
			{
				__pLabel->SetText(L"{Inner} Group is started!");
				__pLabel->Draw();
			}
		}
	}
}

void
GroupForm::OnVisualElementAnimationFinished(const VisualElementAnimation& animation, const String& keyName, VisualElement& target, bool completedNormally)
{
	if (keyName == L"OuterGroup")
	{
		if (completedNormally == true)
		{
			__pLabel->SetText(L"[Outer] Group is Finished!");
			__pLabel->Draw();
		}
		else
		{
			__pLabel->SetText(L"Animation is stopped abruptly!");
			__pLabel->Draw();
		}

		__addAnimation = false;
	}
	else
	{
		String* pGroupName = reinterpret_cast<String*>(animation.GetUserData());
		if (pGroupName != null)
		{
			if (*pGroupName == L"InnerGroup")
			{
				if (completedNormally == true)
				{
					__pLabel->SetText(L"{Inner} Group is Finished!");
					__pLabel->Draw();
				}
				else
				{
					__pLabel->SetText(L"Animation is stopped abruptly!");
					__pLabel->Draw();
				}
			}

			delete pGroupName;
		}
	}
}

void
GroupForm::OnVisualElementAnimationRepeated(const VisualElementAnimation& animation, const String& keyName, VisualElement& target, long currentRepeatCount)
{
}
