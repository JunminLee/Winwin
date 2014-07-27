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

#ifndef _TRANSFORM_MATRIX_FORM_H_
#define _TRANSFORM_MATRIX_FORM_H_

#include "AnimationBaseForm.h"

class TransformMatrixForm
	: public AnimationBaseForm
	, public Tizen::Ui::Animations::IAnimationTransactionEventListener
{
public:
	TransformMatrixForm(void);
	virtual ~TransformMatrixForm(void);

	virtual result OnInitializing(void);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	virtual void OnAnimationTransactionStarted(int transactionId){}
	virtual void OnAnimationTransactionStopped(int transactionId){}
	virtual void OnAnimationTransactionFinished(int transactionId);

private:
	void PerspectiveMatrix(Tizen::Graphics::FloatMatrix4& m, float fov, float aspect, float nearZ, float farZ);
	void FrustumMatrix(Tizen::Graphics::FloatMatrix4& m, float left, float right, float bottom, float top, float nearZ, float farZ);
	void ChangeTransformMatrix(void);
	virtual void InitializeFooter(void);

private:
	Tizen::Ui::Animations::VisualElement* __pBlack;
	Tizen::Ui::Animations::VisualElement* __pRed;
	Tizen::Ui::Animations::VisualElement* __pYellow;
	Tizen::Ui::Animations::VisualElement* __pGreen;

	Tizen::Ui::Controls::Label* __pLabel;

	Tizen::Graphics::FloatMatrix4 __orthogonalMatrix, __perspectiveMatrix;
	bool __isPerspective;
	bool	__isAnimating;

	static const int ID_FOOTER_BUTTON_TRANSFORM = 999;
};

#endif // _TRANSFORM_MATRIX_FORM_H_
