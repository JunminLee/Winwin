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

#ifndef _ANIMATION_BASE_FORM_H_
#define _ANIMATION_BASE_FORM_H_

#include <FApp.h>
#include <FUi.h>

class AnimationBaseForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::IActionEventListener
{
public:
	AnimationBaseForm(void);
	virtual ~AnimationBaseForm(void);
	virtual bool Initialize(void);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void Play(void);
	virtual void Stop(void);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

private:
	virtual void InitializeFooter(void);

protected:
	Tizen::Ui::Animations::VisualElement* _pFormElement;

private:
	static const int ID_FOOTER_BUTTON_PLAY = 101;
	static const int ID_FOOTER_BUTTON_STOP = 102;
};

#endif // _ANIMATION_BASE_FORM_H_
