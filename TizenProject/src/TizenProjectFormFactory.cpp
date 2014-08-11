#include <new>
#include "TizenProjectFormFactory.h"
#include "TizenProjectMainForm.h"
#include "AppResourceId.h"
#include "ChattingForm.h"
#include "PartnerListForm.h"
#include "PartnerSearchForm.h"
#include "SettingForm.h"
#include "Editing.h"
#include "Idl_intro.h"

using namespace Tizen::Ui::Scenes;


TizenProjectFormFactory::TizenProjectFormFactory(void)
{
}

TizenProjectFormFactory::~TizenProjectFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
TizenProjectFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == IDL_FORM)
	{
		TizenProjectMainForm* pForm = new (std::nothrow) TizenProjectMainForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == IDL_INTRO)
	{
		Idl_intro* pForm = new Idl_intro();
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM2)
	{
		ChattingForm* pForm = new ChattingForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM3)
	{
		PartnerListForm* pForm = new PartnerListForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM4)
	{
		PartnerSearchForm* pForm = new PartnerSearchForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM5)
	{
		SettingForm* pForm = new SettingForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == IDL_FORM6)
	{
		Editing* pForm = new Editing();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	return pNewForm;
}
