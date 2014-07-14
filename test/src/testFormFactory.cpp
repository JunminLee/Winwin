#include <new>
#include "testFormFactory.h"
#include "testMainForm.h"
#include "AppResourceId.h"

using namespace Tizen::Ui::Scenes;


testFormFactory::testFormFactory(void)
{
}

testFormFactory::~testFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
testFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == IDL_FORM)
	{
		testMainForm* pForm = new (std::nothrow) testMainForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	// TODO: Add your form creation code here

	return pNewForm;
}
