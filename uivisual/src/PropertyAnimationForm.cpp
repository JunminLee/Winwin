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

#include "PropertyAnimationForm.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

PropertyAnimationForm::PropertyAnimationForm(void)
	: __pRect1(null)
	, __pRect2(null)
	, __pRect3(null)
{
}

PropertyAnimationForm::~PropertyAnimationForm(void)
{
}

result
PropertyAnimationForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Property animation");

	float buttonHeight = __buttonSize / 2.0f, offset = 75.0f;
	Canvas * pCanvas = null;

	Font* pFont = new (std::nothrow) Font();
	pFont->Construct(FONT_STYLE_PLAIN, 33);

	__pRect1 = new (std::nothrow) VisualElement();
	__pRect1->Construct();
	__pRect1->SetName(L"Transform");
	__pRect1->SetBounds(FloatRectangle(offset, 4.0f * offset, __buttonSize, buttonHeight));
	__pRect1->SetShowState(true);
	__pRect1->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect1);

	pCanvas = __pRect1->GetCanvasN();
	pCanvas->SetFont(*pFont);
	pCanvas->SetForegroundColor(Color::GetColor(COLOR_ID_BLACK));
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_GREY), FloatRectangle(0, 0, __buttonSize, buttonHeight));
	pCanvas->DrawText(Point(15, 30), String(L"Transform"));

	delete pCanvas;

	__pRect2 = new (std::nothrow) VisualElement();
	__pRect2->Construct();
	__pRect2->SetName(L"Bounds");
	__pRect2->SetBounds(FloatRectangle(offset, 7.0f * offset, __buttonSize, buttonHeight));
	__pRect2->SetShowState(true);
	__pRect2->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect2);

	pCanvas = __pRect2->GetCanvasN();
	pCanvas->SetFont(*pFont);
	pCanvas->SetForegroundColor(Color::GetColor(COLOR_ID_BLACK));
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_GREY), FloatRectangle(0, 0, __buttonSize, buttonHeight));
	pCanvas->DrawText(Point(15, 30), String(L"Bounds"));

	delete pCanvas;

	__pRect3 = new (std::nothrow) VisualElement();
	__pRect3->Construct();
	__pRect3->SetName(L"Opacity");
	__pRect3->SetBounds(FloatRectangle(offset, 10.0f * offset, __buttonSize, buttonHeight));
	__pRect3->SetShowState(true);
	__pRect3->SetImplicitAnimationEnabled(false);
	_pFormElement->AttachChild(__pRect3);

	pCanvas = __pRect3->GetCanvasN();
	pCanvas->SetFont(*pFont);
	pCanvas->SetForegroundColor(Color::GetColor(COLOR_ID_BLACK));
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_GREY), FloatRectangle(0, 0, __buttonSize, buttonHeight));
	pCanvas->DrawText(Point(15, 30), String(L"Opacity"));

	delete pCanvas;
	delete pFont;

	__startMatrix = __pRect1->GetTransformMatrix();
	__endMatrix = __startMatrix;
	RotateMatrix(__endMatrix, 180.0f, 0.0f, 0.0f, 1.0f);

	__startRect = __pRect2->GetBounds();
	__endRect = FloatRectangle(__startRect.width + __buttonSize, __startRect.y, __buttonSize, __buttonSize);

	__startOpacity = 1.0f;
	__endOpacity = 0.0f;

	return r;
}

void
PropertyAnimationForm::Play(void)
{
	VisualElementPropertyAnimation* pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"transform");
	pAnimation->SetStartValue(Variant(__startMatrix));
	pAnimation->SetEndValue(Variant(__endMatrix));
	pAnimation->SetDuration(2000);
	pAnimation->SetVisualElementAnimationStatusEventListener(this);
	__pRect1->AddAnimation(L"transform", *pAnimation);

	delete pAnimation;
	pAnimation = null;

	pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"bounds");
	pAnimation->SetStartValue(Variant(__startRect));
	pAnimation->SetEndValue(Variant(__endRect));
	pAnimation->SetDuration(2000);
	pAnimation->SetVisualElementAnimationStatusEventListener(this);
	__pRect2->AddAnimation(L"bounds", *pAnimation);

	delete pAnimation;
	pAnimation = null;

	pAnimation = new (std::nothrow) VisualElementPropertyAnimation();
	pAnimation->SetPropertyName(L"opacity");
	pAnimation->SetStartValue(Variant(__startOpacity));
	pAnimation->SetEndValue(Variant(__endOpacity));
	pAnimation->SetDuration(2000);
	pAnimation->SetVisualElementAnimationStatusEventListener(this);
	__pRect3->AddAnimation(L"opacity", *pAnimation);

	delete pAnimation;
	pAnimation = null;
}

void
PropertyAnimationForm::Stop(void)
{
	__pRect1->RemoveAllAnimations();
	__pRect2->RemoveAllAnimations();
	__pRect3->RemoveAllAnimations();
}

void
PropertyAnimationForm::OnVisualElementAnimationStarted(const VisualElementAnimation& animation, const String& keyName, VisualElement& target)
{
}

void
PropertyAnimationForm::OnVisualElementAnimationFinished(const VisualElementAnimation& animation, const String& keyName, VisualElement& target, bool completedNormally)
{
	if(completedNormally)
	{
		if(keyName == L"transform")
		{
			FloatMatrix4	swapMatrix = __startMatrix;
			__startMatrix = __endMatrix;
			__endMatrix = swapMatrix;
		}
		else if(keyName == L"bounds")
		{
			FloatRectangle swapRect = __startRect;
			__startRect = __endRect;
			__endRect = swapRect;
		}
		else if(keyName == L"opacity")
		{
			float swapOpacity = __startOpacity;
			__startOpacity = __endOpacity;
			__endOpacity = swapOpacity;
		}
	}
}
void
PropertyAnimationForm::OnVisualElementAnimationRepeated(const VisualElementAnimation& animation, const String& keyName, VisualElement& target, long currentRepeatCount)
{
}

void
PropertyAnimationForm::RotateMatrix(FloatMatrix4& m, float angle, float x, float y, float z)
{
	if (angle == 0.0f)
	{
		return;
	}

	angle = angle * M_PI / 180.0f;

	angle /= 2.0f;
	double sinA = sin((double)angle);
	double cosA = cos((double)angle);
	float sinA2 = float(sinA * sinA);

	float length = sqrtf(x * x + y * y + z * z);
	if (length == 0.0f)
	{
		return;
	}
	else if (length != 1.0f)
	{
		x /= length;
		y /= length;
		z /= length;
	}

	float mat[4][4] = { {0.0f, }, };

	if (x == 1.0f && y == 0.0f && z == 0.0f)
	{
		mat[0][0] = 1.0f;
		mat[0][1] = 0.0f;
		mat[0][2] = 0.0f;
		mat[1][0] = 0.0f;
		mat[1][1] = 1.0f - 2.0f * sinA2;
		mat[1][2] = 2.0f * sinA * cosA;
		mat[2][0] = 0.0f;
		mat[2][1] = -2.0f * sinA * cosA;
		mat[2][2] = 1.0f - 2.0f * sinA2;
		mat[0][3] = mat[1][3] = mat[2][3] = 0.0f;
		mat[3][0] = mat[3][1] = mat[3][2] = 0.0f;
		mat[3][3] = 1.0f;
	}
	else if (x == 0.0f && y == 1.0f && z == 0.0f)
	{
		mat[0][0] = 1.0f - 2.0f * sinA2;
		mat[0][1] = 0.0f;
		mat[0][2] = -2.0f * sinA * cosA;
		mat[1][0] = 0.0f;
		mat[1][1] = 1.0f;
		mat[1][2] = 0.0f;
		mat[2][0] = 2.0f * sinA * cosA;
		mat[2][1] = 0.0f;
		mat[2][2] = 1.0f - 2.0f * sinA2;
		mat[0][3] = mat[1][3] = mat[2][3] = 0.0f;
		mat[3][0] = mat[3][1] = mat[3][2] = 0.0f;
		mat[3][3] = 1.0f;
	}
	else if (x == 0.0f && y == 0.0f && z == 1.0f)
	{
		mat[0][0] = 1.0f - 2.0f * sinA2;
		mat[0][1] = 2.0f * sinA * cosA;
		mat[0][2] = 0.0f;
		mat[1][0] = -2.0f * sinA * cosA;
		mat[1][1] = 1.0f - 2.0f * sinA2;
		mat[1][2] = 0.0f;
		mat[2][0] = 0.0f;
		mat[2][1] = 0.0f;
		mat[2][2] = 1.0f;
		mat[0][3] = mat[1][3] = mat[2][3] = 0.0f;
		mat[3][0] = mat[3][1] = mat[3][2] = 0.0f;
		mat[3][3] = 1.0f;
	}
	else
	{
		float x2 = x * x;
		float y2 = y * y;
		float z2 = z * z;

		mat[0][0] = 1.0f - 2.0f * (y2 + z2) * sinA2;
		mat[0][1] = 2.0f * (x * y * sinA2 + z * sinA * cosA);
		mat[0][2] = 2.0f * (x * z * sinA2 - y * sinA * cosA);
		mat[1][0] = 2.0f * (y * x * sinA2 - z * sinA * cosA);
		mat[1][1] = 1.0f - 2.0f * (z2 + x2) * sinA2;
		mat[1][2] = 2.0f * (y * z * sinA2 + x * sinA * cosA);
		mat[2][0] = 2.0f * (z * x * sinA2 + y * sinA * cosA);
		mat[2][1] = 2.0f * (z * y * sinA2 - x * sinA * cosA);
		mat[2][2] = 1.0f - 2.0f * (x2 + y2) * sinA2;
		mat[0][3] = mat[1][3] = mat[2][3] = 0.0f;
		mat[3][0] = mat[3][1] = mat[3][2] = 0.0f;
		mat[3][3] = 1.0f;
	}

	m *= FloatMatrix4(mat);
}
