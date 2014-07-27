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

#ifndef _CLIP_FORM_H_
#define _CLIP_FORM_H_

#include "AnimationBaseForm.h"

class ClipForm
	: public AnimationBaseForm
{
public:
	ClipForm(void);
	virtual ~ClipForm(void);

	virtual result OnInitializing(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	void ChangeClip(void);
	virtual void InitializeFooter(void);

private:
	Tizen::Ui::Animations::VisualElement* __pRed;
	Tizen::Ui::Animations::VisualElement* __pYellow;
	Tizen::Ui::Animations::VisualElement* __pGreen;

	Tizen::Ui::Controls::Label* __pLabel;

	static const int ID_FOOTER_BUTTON_CLIP = 401;
};

#endif // _CLIP_FORM_H_
