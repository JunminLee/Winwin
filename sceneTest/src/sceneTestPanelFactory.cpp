#include "sceneTestPanelFactory.h"

using namespace Tizen::Ui::Scenes;


sceneTestPanelFactory::sceneTestPanelFactory(void)
{
}

sceneTestPanelFactory::~sceneTestPanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
sceneTestPanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Panel* pNewPanel = null;

	// TODO: Add your panel creation code here
	return pNewPanel;
}
