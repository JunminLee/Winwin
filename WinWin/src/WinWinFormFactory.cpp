#include <new>
#include "WinWinFormFactory.h"
#include "WinWinMainForm.h"
#include "AppResourceId.h"
#include "Idl_intro.h"
#include "Idl_setting.h"
#include "Idl_partnersearch.h"
#include "Idl_partnerlist.h"
#include "Idl_chatting.h"

using namespace Tizen::Ui::Scenes;


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
	else if (formId == IDL_INTRO)
	{
		Idl_intro* pForm = new Idl_intro();
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_SETTING)
	{
		Idl_setting* pForm = new Idl_setting();
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_PartnerSearch)
	{
		Idl_partnersearch* pForm = new Idl_partnersearch();
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_PartnerList)
	{
		Idl_partnerlist* pForm = new Idl_partnerlist();
		pForm->Initialize();
		pNewForm = pForm;
	}
	else if (formId == IDL_Chatting)
	{
		Idl_chatting* pForm = new Idl_chatting();
		pForm->Initialize();
		pNewForm = pForm;
	}





	// TODO: Add your form creation code here

	return pNewForm;
}
