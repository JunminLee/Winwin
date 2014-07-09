#include "sceneTestFrame.h"
#include "sceneTestFormFactory.h"
#include "sceneTestPanelFactory.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

sceneTestFrame::sceneTestFrame(void)
{
}

sceneTestFrame::~sceneTestFrame(void)
{
}

result
sceneTestFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static sceneTestFormFactory formFactory;
	static sceneTestPanelFactory panelFactory;
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterPanelFactory(panelFactory);
	pSceneManager->RegisterScene(L"workflow");

	// Go to the scene.
	result r = pSceneManager->GoForward(SceneTransitionId(IDSCNT_MAIN_SCENE));


	return r;
}

result
sceneTestFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}
