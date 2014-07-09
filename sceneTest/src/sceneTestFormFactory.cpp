#include <new>
#include "sceneTestFormFactory.h"
#include "sceneTestMainForm.h"
#include "AppResourceId.h"
#include "Idl_aform.h"


using namespace Tizen::Ui::Scenes;


sceneTestFormFactory::sceneTestFormFactory(void)
{
}

sceneTestFormFactory::~sceneTestFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
sceneTestFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == IDL_FORM)
	{

		sceneTestMainForm* pForm = new (std::nothrow) sceneTestMainForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == IDL_AFORM)
	{
		Idl_aform* pForm = new Idl_aform();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}



	// TODO: Add your form creation code here

	return pNewForm;
}
