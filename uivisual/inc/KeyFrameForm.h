//
// Open Service Platform
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

#ifndef _KEY_FRAME_FORM_H_
#define _KEY_FRAME_FORM_H_

#include "AnimationBaseForm.h"

class KeyFrameForm
	: public AnimationBaseForm
{
public:
	KeyFrameForm(void);
	virtual ~KeyFrameForm(void);

	virtual result OnInitializing(void);
	virtual void Play(void);
	virtual void Stop(void);

private:
	Tizen::Ui::Animations::VisualElement* __pRect;
	Tizen::Graphics::Rectangle __clientRect;

	static const int __buttonSize = 150;
};

#endif // _KEY_FRAME_FORM_H_
