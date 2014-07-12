#include <new>
#include "Test2PanelFactory.h"
#include "Test2Tab1.h"
#include "Test2Tab2.h"
#include "Test2Tab3.h"
#include "AppResourceId.h"

using namespace Tizen::Ui::Scenes;


Test2PanelFactory::Test2PanelFactory(void)
{
}

Test2PanelFactory::~Test2PanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
Test2PanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Panel* pNewPanel = null;

	if (panelId == IDL_PANEL1)
	{
		Test2Tab1* pPanel = new (std::nothrow) Test2Tab1();
		pPanel->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pPanel);
		pNewPanel = pPanel;
	}
	else
	if (panelId == IDL_PANEL2)
	{
		Test2Tab2* pPanel = new (std::nothrow) Test2Tab2();
		pPanel->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pPanel);
		pNewPanel = pPanel;
	}
	else
	if (panelId == IDL_PANEL3)
	{
		Test2Tab3* pPanel = new (std::nothrow) Test2Tab3();
		pPanel->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pPanel);
		pNewPanel = pPanel;
	}
	// TODO: Add your panel creation code here
	return pNewPanel;
}
