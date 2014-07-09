#include <new>
#include "WinWinFormFactory.h"
#include "WinWinMainForm.h"
#include "AppResourceId.h"
#include "Idl_intro.h"

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

	// TODO: Add your form creation code here

	return pNewForm;
}
