#include "TizenProjectPanelFactory.h"

using namespace Tizen::Ui::Scenes;


TizenProjectPanelFactory::TizenProjectPanelFactory(void)
{
}

TizenProjectPanelFactory::~TizenProjectPanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
TizenProjectPanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Panel* pNewPanel = null;

	// TODO: Add your panel creation code here
	return pNewPanel;
}
