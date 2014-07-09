#include "WinWinPanelFactory.h"

using namespace Tizen::Ui::Scenes;


WinWinPanelFactory::WinWinPanelFactory(void)
{
}

WinWinPanelFactory::~WinWinPanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
WinWinPanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Panel* pNewPanel = null;

	// TODO: Add your panel creation code here
	return pNewPanel;
}
