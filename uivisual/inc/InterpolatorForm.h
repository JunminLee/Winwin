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

#ifndef _INTERPOLATOR_FORM_H_
#define _INTERPOLATOR_FORM_H_

#include "AnimationBaseForm.h"

class InterpolatorForm
	: public AnimationBaseForm
	, public Tizen::Ui::Animations::IVisualElementAnimationValueInterpolator
{
public:
	InterpolatorForm(void);
	virtual ~InterpolatorForm(void);

	virtual result OnInitializing(void);
		
	virtual void Play(void);
	virtual void Stop(void);

	virtual result Interpolate(float progress, const Tizen::Ui::Variant& startValue, const Tizen::Ui::Variant& endValue, Tizen::Ui::Variant& value) const;

private:
	Tizen::Ui::Animations::VisualElement* __pRect;
};

#endif // _INTERPOLATOR_FORM_H_
