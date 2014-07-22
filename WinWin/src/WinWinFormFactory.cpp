#include <new>
#include "WinWinFormFactory.h"
#include "WinWinMainForm.h"
#include "Intro_form.h"
#include "Idl_form.h"
#include "ChattingForm.h"
#include "PartnerListForm.h"
#include "PartnerSearchForm.h"
#include "SettingForm.h"
#include <FUi.h>
#include "AppResourceId.h"
using namespace Tizen::Ui::Scenes;


const wchar_t* FORM_INTRO = L"FORM_INTRO";
const wchar_t* FORM_MAIN = L"FORM_MAIN";
const wchar_t* FORM_CHATTING = L"FORM_CHATTING";
const wchar_t* FORM_LIST = L"FORM_LIST";
const wchar_t* FORM_SEARCH = L"FORM_SEARCH";
const wchar_t* FORM_SETTING = L"FORM_SETTING";

WinWinFormFactory::WinWinFormFactory(void)
{
}

WinWinFormFactory::~WinWinFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
WinWinFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == IDL_FORM)
	{
		WinWinMainForm* pForm = new (std::nothrow) WinWinMainForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == INTRO_FORM)
	{
		Intro_form* pForm = new Intro_form();
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM2)
	{
		ChattingForm* pForm = new (std::nothrow) ChattingForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}

	else if (formId == IDL_FORM3)
	{
		PartnerListForm* pForm = new (std::nothrow) PartnerListForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM4)
	{
		PartnerSearchForm* pForm = new (std::nothrow) PartnerSearchForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM5)
	{
		SettingForm* pForm = new (std::nothrow) SettingForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}

	// TODO: Add your form creation code here

	return pNewForm;
}
