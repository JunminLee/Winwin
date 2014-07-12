#include <new>
#include "Test2FormFactory.h"
#include "Test2MainForm.h"
#include "AppResourceId.h"

using namespace Tizen::Ui::Scenes;


Test2FormFactory::Test2FormFactory(void)
{
}

Test2FormFactory::~Test2FormFactory(void)
{
}

Tizen::Ui::Controls::Form*
Test2FormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == IDL_FORM)
	{
		Test2MainForm* pForm = new (std::nothrow) Test2MainForm();
		TryReturn(pForm != null, null, "The memory is insufficient.");
		pForm->Initialize();
		pNewForm = pForm;
	}

	// TODO: Add your form creation code here

	return pNewForm;
}
