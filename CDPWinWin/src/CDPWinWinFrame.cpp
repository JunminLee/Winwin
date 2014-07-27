#include "CDPWinWinFrame.h"
#include "CDPWinWinFormFactory.h"
#include "CDPWinWinPanelFactory.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

CDPWinWinFrame::CDPWinWinFrame(void)
{
}

CDPWinWinFrame::~CDPWinWinFrame(void)
{
}

result
CDPWinWinFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static CDPWinWinFormFactory formFactory;
	static CDPWinWinPanelFactory panelFactory;
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterPanelFactory(panelFactory);
	pSceneManager->RegisterScene(L"workflow");

	// Go to the scene.
	result r = E_FAILURE;
	r = pSceneManager->GoForward(SceneTransitionId(IDSCNT_1));
	

	// TODO: Add your frame initialization code here.
	return r;
}

result
CDPWinWinFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}
