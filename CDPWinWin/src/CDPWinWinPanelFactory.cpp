#include "CDPWinWinPanelFactory.h"

using namespace Tizen::Ui::Scenes;


CDPWinWinPanelFactory::CDPWinWinPanelFactory(void)
{
}

CDPWinWinPanelFactory::~CDPWinWinPanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
CDPWinWinPanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Panel* pNewPanel = null;

	// TODO: Add your panel creation code here
	return pNewPanel;
}
