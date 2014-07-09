#include "WinWinFrame.h"
#include "WinWinFormFactory.h"
#include "WinWinPanelFactory.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

WinWinFrame::WinWinFrame(void)
{
}

WinWinFrame::~WinWinFrame(void)
{
}

result
WinWinFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static WinWinFormFactory formFactory;
	static WinWinPanelFactory panelFactory;
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
WinWinFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}
