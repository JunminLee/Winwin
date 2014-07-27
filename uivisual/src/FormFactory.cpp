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

#include "FormFactory.h"
#include "MainForm.h"

#include "ZorderForm.h"
#include "ClipForm.h"
#include "TransformMatrixForm.h"
#include "SurfaceForm.h"
#include "EventListenerForm.h"
#include "AnimationProviderForm.h"
#include "PropertyAnimationForm.h"
#include "ValueAnimationForm.h"
#include "InterpolatorForm.h"
#include "KeyFrameForm.h"
#include "TransactionForm.h"
#include "GroupForm.h"
#include "GalleryForm.h"

using namespace Tizen::Base;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

const wchar_t* FORM_MAIN_MENU = L"FormMainMenu";

const wchar_t* FORM_ZORDER = L"FormZorder";
const wchar_t* FORM_CLIP = L"FormClip";
const wchar_t* FORM_TRANSFORM_MATRIX = L"FormTransformMatrix";
const wchar_t* FORM_SURFACE = L"FormSurface";
const wchar_t* FORM_EVENT_LISTENER = L"FormEventListener";
const wchar_t* FORM_ANIMATION_PROVIDER = L"FormAnimationProvider";

const wchar_t* FORM_PROPERTY_ANIMATION = L"FormPropertyAnimation";
const wchar_t* FORM_VALUE_ANIMATION = L"FormValueAnimation";
const wchar_t* FORM_KEY_FRAME_ANIMATION = L"FormKeyFrameAnimation";
const wchar_t* FORM_GROUP_ANIMATION = L"FormGroupAnimation";
const wchar_t* FORM_INTERPOLATOR = L"FormInterpolator";
const wchar_t* FORM_TRANSACTION = L"FormTransaction";
const wchar_t* FORM_GALLERY = L"FormGallery";

FormFactory::FormFactory(void)
{
}

FormFactory::~FormFactory(void)
{
}

Form*
FormFactory::CreateFormN(const String& formId, const SceneId& sceneId)
{
	Form* pNewForm = null;

	if (formId == FORM_MAIN_MENU)
	{
		MainForm* pMainForm = new (std::nothrow) MainForm();
		pMainForm->Initialize();
		pNewForm = pMainForm;
	}
	else
	{
		AnimationBaseForm* pAnimationForm = null;

		if (formId == FORM_ZORDER)
		{
			pAnimationForm = new (std::nothrow) ZorderForm();
		}
		else if (formId == FORM_CLIP)
		{
			pAnimationForm= new (std::nothrow) ClipForm();
		}
		else if (formId == FORM_TRANSFORM_MATRIX)
		{
			pAnimationForm = new (std::nothrow) TransformMatrixForm();
		}
		else if (formId == FORM_SURFACE)
		{
			pAnimationForm = new (std::nothrow) SurfaceForm();
		}
		else if (formId == FORM_EVENT_LISTENER)
		{
			pAnimationForm = new (std::nothrow) EventListenerForm();
		}
		else if (formId == FORM_ANIMATION_PROVIDER)
		{
			pAnimationForm = new (std::nothrow) AnimationProviderForm();
		}
		else if (formId == FORM_PROPERTY_ANIMATION)
		{
			pAnimationForm = new (std::nothrow) PropertyAnimationForm();
		}
		else if (formId == FORM_VALUE_ANIMATION)
		{
			pAnimationForm = new (std::nothrow) ValueAnimationForm();
		}
		else if (formId == FORM_KEY_FRAME_ANIMATION)
		{
			pAnimationForm = new (std::nothrow) KeyFrameForm();
		}
		else if (formId == FORM_GROUP_ANIMATION)
		{
			pAnimationForm = new (std::nothrow) GroupForm();
		}
		else if (formId == FORM_INTERPOLATOR)
		{
			pAnimationForm = new (std::nothrow) InterpolatorForm();
		}
		else if (formId == FORM_TRANSACTION)
		{
			pAnimationForm = new (std::nothrow) TransactionForm();
		}
		else if (formId == FORM_GALLERY)
		{
			pAnimationForm = new (std::nothrow) GalleryForm();
		}

		pAnimationForm->Initialize();
		pNewForm = pAnimationForm;
	}

	return pNewForm;
}
