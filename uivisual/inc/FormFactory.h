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

#ifndef _FORM_FACTORY_H_
#define _FORM_FACTORY_H_

#include <FUi.h>

extern const wchar_t* FORM_MAIN_MENU;

extern const wchar_t* FORM_ZORDER;
extern const wchar_t* FORM_CLIP;
extern const wchar_t* FORM_TRANSFORM_MATRIX;
extern const wchar_t* FORM_SURFACE;
extern const wchar_t* FORM_EVENT_LISTENER;
extern const wchar_t* FORM_ANIMATION_PROVIDER;

extern const wchar_t* FORM_PROPERTY_ANIMATION;
extern const wchar_t* FORM_VALUE_ANIMATION;
extern const wchar_t* FORM_KEY_FRAME_ANIMATION;
extern const wchar_t* FORM_GROUP_ANIMATION;
extern const wchar_t* FORM_INTERPOLATOR;
extern const wchar_t* FORM_TRANSACTION;
extern const wchar_t* FORM_GALLERY;

class FormFactory
	: public Tizen::Ui::Scenes::IFormFactory
{
public:
	FormFactory(void);
	virtual ~FormFactory(void);

	virtual Tizen::Ui::Controls::Form* CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _FORM_FACTORY_H_
