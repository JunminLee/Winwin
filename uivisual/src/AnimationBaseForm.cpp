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

#include "AnimationBaseForm.h"

using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

AnimationBaseForm::AnimationBaseForm(void)
	: _pFormElement(null)
{
}

AnimationBaseForm::~AnimationBaseForm(void)
{
}

bool
AnimationBaseForm::Initialize()
{
	Construct(FORM_STYLE_NORMAL | FORM_STYLE_HEADER | FORM_STYLE_FOOTER | FORM_STYLE_INDICATOR);
	SetFormBackEventListener(this);

	Footer* pFooter = Form::GetFooter();
	pFooter->SetStyle(FOOTER_STYLE_BUTTON_TEXT);
	pFooter->SetBackButton();

	InitializeFooter();

	_pFormElement = GetVisualElement();

	return true;
}

result
AnimationBaseForm::OnInitializing(void)
{
	return E_SUCCESS;
}

result
AnimationBaseForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	Stop();

	return r;
}

void
AnimationBaseForm::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_PLAY:
		Play();
		break;

	case ID_FOOTER_BUTTON_STOP:
		Stop();
		break;

	default:
		break;
	}
}

void
AnimationBaseForm::OnFormBackRequested(Form& source)
{
	SceneManager::GetInstance()->GoBackward(BackwardSceneTransition());
}

void
AnimationBaseForm::InitializeFooter(void)
{
	FooterItem item1;
	item1.Construct(ID_FOOTER_BUTTON_PLAY);
	item1.SetText(L"Play");

	FooterItem item2;
	item2.Construct(ID_FOOTER_BUTTON_STOP);
	item2.SetText(L"Stop");

	Footer* pFooter = Form::GetFooter();
	pFooter->AddItem(item1);
	pFooter->AddItem(item2);
	pFooter->AddActionEventListener(*this);
}

void
AnimationBaseForm::Play(void)
{
}

void
AnimationBaseForm::Stop(void)
{
}
