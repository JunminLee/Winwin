#include "WinWinPanelFactory.h"
#include "AppResourceId.h"


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
	/*
	// TODO: Add your panel creation code here
	if (panelId == MainScene_Panel)
	{
		Mainscene_panel* pPanel = new Mainscene_panel();
		pPanel->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pPanel);
		pNewPanel = pPanel;
	}
	else if (panelId == ChattingScenePanel)
	{
		Chattingscenepanel* pPanel = new Chattingscenepanel();
		pPanel->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pPanel);
		pNewPanel = pPanel;
	}

	else if (panelId == ResearchFriendsPanel)
	{
		Researchfriendspanel* pPanel = new Researchfriendspanel();
		pPanel->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pPanel);
		pNewPanel = pPanel;
	}
	else if (panelId == SettingPanel)
	{
		Settingpanel* pPanel = new Settingpanel();
		pPanel->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pPanel);
		pNewPanel = pPanel;
	}


*/


return pNewPanel;
}
