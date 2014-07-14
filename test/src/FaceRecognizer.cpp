//
// Tizen C++ SDK
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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

#include <new>
#include "FaceRecognizer.h"
#include "FaceDetectionForm.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Io;
using namespace Tizen::System;
using namespace Tizen::Text;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;

FaceRecognizer::FaceRecognizer(void)
{
}

FaceRecognizer::~FaceRecognizer(void)
{
}

Application*
FaceRecognizer::CreateInstance(void)
{
	return new FaceRecognizer();
}

bool
FaceRecognizer::OnAppInitializing(AppRegistry& appRegistry)
{
	Frame* pAppFrame = new (std::nothrow) Frame();
	pAppFrame->Construct();
	AddFrame(*pAppFrame); 
	
	FaceDetectionForm* pForm = new (std::nothrow) FaceDetectionForm();
	TryReturn(pForm != null, false, "Failed to create form");
	result r = pForm->Construct(FORM_STYLE_NORMAL | FORM_STYLE_HEADER | FORM_STYLE_FOOTER | FORM_STYLE_INDICATOR);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	// Set Header
	Header* pHeader = pForm->GetHeader();
	pHeader->SetTitleText(L"Face recognizer");

	r = GetAppFrame()->GetFrame()->AddControl(pForm);
	TryReturn(r == E_SUCCESS, false, "Failed to attach FormMgr to the frame");

	pForm->Draw();

	return true;
}

bool
FaceRecognizer::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	return true;
}

void
FaceRecognizer::OnForeground(void)
{
}

void
FaceRecognizer::OnBackground(void)
{
}

void
FaceRecognizer::OnLowMemory(void)
{
}

void
FaceRecognizer::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
}

void
FaceRecognizer::OnScreenOn(void)
{
}

void
FaceRecognizer::OnScreenOff(void)
{
}
