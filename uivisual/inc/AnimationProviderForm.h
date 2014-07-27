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

#ifndef _ANIMATION_PROVIDER_FORM_H_
#define _ANIMATION_PROVIDER_FORM_H_

#include "AnimationBaseForm.h"

class AnimationProviderForm
	: public AnimationBaseForm
	, public Tizen::Ui::Animations::VisualElementAnimationProvider
{
public:
	AnimationProviderForm(void);
	virtual ~AnimationProviderForm(void);

	virtual result OnInitializing(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual Tizen::Ui::Animations::VisualElementAnimation* CreateAnimationForProperty(Tizen::Ui::Animations::VisualElement& target, const Tizen::Base::String& property);

private:
	void ChangeAnimationProvider(void);
	virtual void InitializeFooter(void);

private:
	Tizen::Ui::Animations::VisualElement* __pRect;
	Tizen::Ui::Controls::Label* __pLabel;

	Tizen::Graphics::FloatRectangle __startRect, __endRect;
	bool __isCustom;

	static const int ID_FOOTER_BUTTON_ANIMATION_PROVIDER = 301;
};

#endif // _ANIMATION_PROVIDER_FORM_H_
