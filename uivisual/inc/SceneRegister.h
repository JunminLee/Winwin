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

#ifndef _SCENE_REGISTER_H_
#define _SCENE_REGISTER_H_

extern const wchar_t* SCENE_MAIN_MENU;

extern const wchar_t* SCENE_ZORDER;
extern const wchar_t* SCENE_CLIP;
extern const wchar_t* SCENE_TRANSFORM_MATRIX;
extern const wchar_t* SCENE_SURFACE;
extern const wchar_t* SCENE_EVENT_LISTENER;
extern const wchar_t* SCENE_ANIMATION_PROVIDER;

extern const wchar_t* SCENE_PROPERTY_ANIMATION;
extern const wchar_t* SCENE_VALUE_ANIMATION;
extern const wchar_t* SCENE_KEY_FRAME_ANIMATION;
extern const wchar_t* SCENE_GROUP_ANIMATION;
extern const wchar_t* SCENE_INTERPOLATOR;
extern const wchar_t* SCENE_TRANSACTION;
extern const wchar_t* SCENE_GALLERY;

class SceneRegister
{
public:
	static void RegisterAllScenes(void);

private:
	SceneRegister(void);
	~SceneRegister(void);
};

#endif // _SCENE_REGISTER_H_
