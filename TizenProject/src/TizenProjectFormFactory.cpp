#include <new>
#include "TizenProjectFormFactory.h"
#include "TizenProjectMainForm.h"
#include "AppResourceId.h"
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

	// TODO: Add your form creation code here

	return pNewForm;
}
