#include <new>
#include "fuckingtizenFormFactory.h"
#include "fuckingtizenMainForm.h"
#include "AppResourceId.h"

using namespace Tizen::Ui::Scenes;


fuckingtizenFormFactory::fuckingtizenFormFactory(void)
{
}

fuckingtizenFormFactory::~fuckingtizenFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
fuckingtizenFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == IDL_FORM)
	{
		fuckingtizenMainForm* pForm = new (std::nothrow) fuckingtizenMainForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	// TODO: Add your form creation code here

	return pNewForm;
}
