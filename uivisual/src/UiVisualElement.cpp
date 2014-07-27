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

#include "UiVisualElement.h"
#include "UiVisualElementFrame.h"
#include "FormFactory.h"
#include "SceneRegister.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::System;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

UiVisualElement::UiVisualElement(void)
{
}

UiVisualElement::~UiVisualElement(void)
{
}

UiApp*
UiVisualElement::CreateInstance(void)
{
	return new UiVisualElement();
}

bool
UiVisualElement::OnAppInitializing(AppRegistry& appRegistry)
{
	return true;
}

bool
UiVisualElement::OnAppInitialized(void)
{
	UiVisualElementFrame* pUiVisualElementFrame = new UiVisualElementFrame();
	pUiVisualElementFrame->Construct();
	pUiVisualElementFrame->SetName(L"UiVisualElement");
	AddFrame(*pUiVisualElementFrame);

	SceneRegister::RegisterAllScenes();
	SceneManager::GetInstance()->GoForward(ForwardSceneTransition(SCENE_MAIN_MENU));

	return true;
}

bool
UiVisualElement::OnAppWillTerminate(void)
{
	return true;
}

bool
UiVisualElement::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	return true;
}

void
UiVisualElement::OnForeground(void)
{
}

void
UiVisualElement::OnBackground(void)
{
}

void
UiVisualElement::OnLowMemory(void)
{
}

void
UiVisualElement::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
}

void
UiVisualElement::OnScreenOn(void)
{
}

void
UiVisualElement::OnScreenOff(void)
{
}

