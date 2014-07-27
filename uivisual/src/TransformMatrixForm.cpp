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

#include "TransformMatrixForm.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

#define ALMOST_ZERO_FLOAT   0.00001f

TransformMatrixForm::TransformMatrixForm(void)
	: __pRed(null)
	, __pYellow(null)
	, __pGreen(null)
	, __pLabel(null)
	, __isPerspective(false)
	, __isAnimating(false)
{
}

TransformMatrixForm::~TransformMatrixForm(void)
{
}

result
TransformMatrixForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Transform matrix");

	Rectangle clientRect = GetClientAreaBounds();

	__pLabel = new (std::nothrow) Label();
	__pLabel->Construct(Rectangle(50, clientRect.height - 125, clientRect.width - 100, 105), L"Orthogonal Matrix");
	AddControl(__pLabel);

	__pBlack = new (std::nothrow) VisualElement();
	__pBlack->Construct();
	__pBlack->SetName(L"Black");
	__pBlack->SetBounds(FloatRectangle(clientRect.x, clientRect.y, clientRect.width, clientRect.width));
	__pBlack->SetShowState(true);
	_pFormElement->AttachChild(__pBlack);

	__pRed = new (std::nothrow) VisualElement();
	__pRed->Construct();
	__pRed->SetName(L"Red");
	__pRed->SetBounds(FloatRectangle(75.0f, 75.0f, 375.0f, 375.0f));
	__pRed->SetShowState(true);
	__pRed->SetZPosition(-2.3f);
	__pBlack->AttachChild(__pRed);

	Canvas* pCanvas = __pRed->GetCanvasN();
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_RED), FloatRectangle(0.0f, 0.0f, 375.0f, 375.0f));
	delete pCanvas;

	__pYellow = new (std::nothrow) VisualElement();
	__pYellow->Construct();
	__pYellow->SetName(L"Yellow");
	__pYellow->SetBounds(FloatRectangle(150.0f, 150.0f, 375.0f, 375.0f));
	__pYellow->SetShowState(true);
	__pYellow->SetZPosition(-2.0f);
	__pBlack->AttachChild(__pYellow);

	pCanvas = __pYellow->GetCanvasN();
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_YELLOW), FloatRectangle(0.0f, 0.0f, 375.0f, 375.0f));
	delete pCanvas;

	__pGreen = new (std::nothrow) VisualElement();
	__pGreen->Construct();
	__pGreen->SetName(L"Green");
	__pGreen->SetBounds(FloatRectangle(225.0f, 225.0f, 375.0f, 375.0f));
	__pGreen->SetShowState(true);
	__pGreen->SetZPosition(-1.7f);
	__pBlack->AttachChild(__pGreen);

	pCanvas = __pGreen->GetCanvasN();
	pCanvas->FillRectangle(Color::GetColor(COLOR_ID_GREEN), FloatRectangle(0.0f, 0.0f, 375.0f, 375.0f));
	delete pCanvas;

	__orthogonalMatrix = __pBlack->GetChildrenTransformMatrix();

	__perspectiveMatrix.SetAsIdentity();
	PerspectiveMatrix(__perspectiveMatrix, 60.0f, 1.0f, 0.01f, 100.0f);

	return r;
}

void
TransformMatrixForm::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_TRANSFORM:
		if (__isAnimating == false)
		{
			ChangeTransformMatrix();
		}
		break;

	default:
		break;
	}
}

void
TransformMatrixForm::InitializeFooter(void)
{
	FooterItem  item;
	item.Construct(ID_FOOTER_BUTTON_TRANSFORM);
	item.SetText(L"Change Matrix");

	Footer* pFooter = Form::GetFooter();
	pFooter->AddItem(item);
	pFooter->AddActionEventListener(*this);
}

void
TransformMatrixForm::OnAnimationTransactionFinished(int transactionId)
{
	__isAnimating = false;
}

void
TransformMatrixForm::ChangeTransformMatrix(void)
{
	String text;

	AnimationTransaction::Begin();
	AnimationTransaction::SetCurrentTransactionEventListener(this);

	if (__isPerspective)
	{
		__pBlack->SetChildrenTransformMatrix(__orthogonalMatrix);
		__isPerspective = false;

		text.Append(L"Orthogonal Matrix");
	}
	else
	{
		__pBlack->SetChildrenTransformMatrix(__perspectiveMatrix);
		__isPerspective = true;

		text.Append(L"Perspective Matrix");
	}

	AnimationTransaction::Commit();
	__isAnimating = true;

	__pLabel->SetText(text);
	__pLabel->Draw();
}

void
TransformMatrixForm::PerspectiveMatrix(FloatMatrix4& m, float fov, float aspect, float nearZ, float farZ)
{
	float frustumW, frustumH;

	frustumH = tan(fov / 360.0f * M_PI) * nearZ;
	frustumW = frustumH * aspect;

	FrustumMatrix(m, -frustumW, frustumW, -frustumH, frustumH, nearZ, farZ);
}

void
TransformMatrixForm::FrustumMatrix(FloatMatrix4& m, float left, float right, float bottom, float top, float nearZ, float farZ)
{
	float w, h, d;

	w = right - left;
	h = top - bottom;
	d = farZ - nearZ;

	if (w == 0.0f)
	{
		w = ALMOST_ZERO_FLOAT;
	}
	
	if (h == 0.0f)
	{
		h = ALMOST_ZERO_FLOAT;
	}
	
	if (d == 0.0f)
	{
		d = ALMOST_ZERO_FLOAT;
	}

	m.matrix[0][0] = 2.0f * nearZ / w;

	m.matrix[1][1] = 2.0f * nearZ / h;

	m.matrix[2][0] = (right + left) / w;
	m.matrix[2][1] = (top + bottom) / h;
	m.matrix[2][2] = -(farZ + nearZ) / d;
	m.matrix[2][3] = -1.0f;

	m.matrix[3][2] = -(2.0f * farZ * nearZ) / d;
	m.matrix[3][3] = 0.0f;
}
