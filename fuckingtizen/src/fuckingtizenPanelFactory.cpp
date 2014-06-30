#include "fuckingtizenPanelFactory.h"

using namespace Tizen::Ui::Scenes;


fuckingtizenPanelFactory::fuckingtizenPanelFactory(void)
{
}

fuckingtizenPanelFactory::~fuckingtizenPanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
fuckingtizenPanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Panel* pNewPanel = null;

	// TODO: Add your panel creation code here
	return pNewPanel;
}
