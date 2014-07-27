#include <new>
#include "CDPWinWinFormFactory.h"
#include "CDPWinWinMainForm.h"
#include "AppResourceId.h"

using namespace Tizen::Ui::Scenes;


CDPWinWinFormFactory::CDPWinWinFormFactory(void)
{
}

CDPWinWinFormFactory::~CDPWinWinFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
CDPWinWinFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == IDL_FORM)
	{
		CDPWinWinMainForm* pForm = new (std::nothrow) CDPWinWinMainForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	// TODO: Add your form creation code here

	return pNewForm;
}
