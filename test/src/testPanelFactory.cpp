#include "testPanelFactory.h"

using namespace Tizen::Ui::Scenes;


testPanelFactory::testPanelFactory(void)
{
}

testPanelFactory::~testPanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
testPanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Panel* pNewPanel = null;

	// TODO: Add your panel creation code here
	return pNewPanel;
}
