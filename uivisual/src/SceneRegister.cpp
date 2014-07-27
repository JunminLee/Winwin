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

#include "SceneRegister.h"
#include "FormFactory.h"

#include <FUi.h>

using namespace Tizen::Ui::Scenes;

const wchar_t* SCENE_MAIN_MENU = L"SceneMainMenu";

const wchar_t* SCENE_ZORDER = L"SceneZorder";
const wchar_t* SCENE_CLIP = L"SceneClip";
const wchar_t* SCENE_TRANSFORM_MATRIX = L"SceneTransformMatrix";
const wchar_t* SCENE_SURFACE = L"SceneSurface";
const wchar_t* SCENE_EVENT_LISTENER = L"SceneEventListener";
const wchar_t* SCENE_ANIMATION_PROVIDER = L"SceneAnimationProvider";

const wchar_t* SCENE_PROPERTY_ANIMATION = L"ScenePropertyAnimation";
const wchar_t* SCENE_VALUE_ANIMATION = L"SceneValueAnimation";
const wchar_t* SCENE_KEY_FRAME_ANIMATION = L"SceneKeyFrameAnimation";
const wchar_t* SCENE_GROUP_ANIMATION = L"SceneGroupAnimation";
const wchar_t* SCENE_INTERPOLATOR = L"SceneInterpolator";
const wchar_t* SCENE_TRANSACTION = L"SceneTransaction";
const wchar_t* SCENE_GALLERY = L"SceneGallery";

SceneRegister::SceneRegister(void)
{
}

SceneRegister::~SceneRegister(void)
{
}

void
SceneRegister::RegisterAllScenes(void)
{
	static const wchar_t* PANEL_BLANK = L"";
	static FormFactory formFactory;

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	pSceneManager->RegisterFormFactory(formFactory);

	pSceneManager->RegisterScene(SCENE_MAIN_MENU, FORM_MAIN_MENU, PANEL_BLANK);

	pSceneManager->RegisterScene(SCENE_ZORDER, FORM_ZORDER, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_CLIP, FORM_CLIP, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_TRANSFORM_MATRIX, FORM_TRANSFORM_MATRIX, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_SURFACE, FORM_SURFACE, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_EVENT_LISTENER, FORM_EVENT_LISTENER, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_ANIMATION_PROVIDER, FORM_ANIMATION_PROVIDER, PANEL_BLANK);

	pSceneManager->RegisterScene(SCENE_PROPERTY_ANIMATION, FORM_PROPERTY_ANIMATION, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_VALUE_ANIMATION, FORM_VALUE_ANIMATION, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_KEY_FRAME_ANIMATION, FORM_KEY_FRAME_ANIMATION, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_GROUP_ANIMATION, FORM_GROUP_ANIMATION, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_INTERPOLATOR, FORM_INTERPOLATOR, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_TRANSACTION, FORM_TRANSACTION, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_GALLERY, FORM_GALLERY, PANEL_BLANK);
}



