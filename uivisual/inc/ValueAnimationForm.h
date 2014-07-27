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

#ifndef _VALUE_ANIMATION_FORM_H_
#define _VALUE_ANIMATION_FORM_H_

#include "AnimationBaseForm.h"

class ValueAnimationForm
	: public AnimationBaseForm
	, public Tizen::Ui::Animations::IVisualElementAnimationTickEventListener
	, public Tizen::Ui::Animations::IVisualElementAnimationStatusEventListener
{
public:
	ValueAnimationForm(void);
	virtual ~ValueAnimationForm(void);

	virtual result OnInitializing(void);

	virtual void Play(void);
	virtual void Stop(void);

	virtual void OnTickOccurred(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, const Tizen::Ui::Variant& currentValue);

	virtual void OnVisualElementAnimationStarted(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target){}
	virtual void OnVisualElementAnimationRepeated(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, long currentRepeatCount){}
	virtual void OnVisualElementAnimationFinished(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, bool completedNormally);

private:
	Tizen::Ui::Animations::VisualElement* __pCircle;
	Tizen::Ui::Controls::Label* __pLabel;
};

#endif // _VALUE_ANIMATION_FORM_H_
