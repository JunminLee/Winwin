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

#ifndef _PROPERTY_ANIMATION_FORM_H_
#define _PROPERTY_ANIMATION_FORM_H_

#include "AnimationBaseForm.h"

class PropertyAnimationForm
	: public AnimationBaseForm
	, public Tizen::Ui::Animations::IVisualElementAnimationStatusEventListener
{
public:
	PropertyAnimationForm(void);
	virtual ~PropertyAnimationForm(void);

	virtual result OnInitializing(void);

	virtual void Play(void);
	virtual void Stop(void);

	virtual void OnVisualElementAnimationStarted(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target);
	virtual void OnVisualElementAnimationFinished(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, bool completedNormally);
	virtual void OnVisualElementAnimationRepeated(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, long currentRepeatCount);

private:
	void RotateMatrix(Tizen::Graphics::FloatMatrix4& m, float angle, float x, float y, float z);

private:
	Tizen::Ui::Animations::VisualElement* __pRect1;
	Tizen::Ui::Animations::VisualElement* __pRect2;
	Tizen::Ui::Animations::VisualElement* __pRect3;

	Tizen::Graphics::FloatMatrix4 __startMatrix, __endMatrix;
	Tizen::Graphics::FloatRectangle __startRect, __endRect;
	float	__startOpacity, __endOpacity;

	static const float __buttonSize = 225.0f;
};

#endif // _PROPERTY_ANIMATION_FORM_H_
