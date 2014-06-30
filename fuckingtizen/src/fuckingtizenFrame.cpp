#include "fuckingtizenFrame.h"
#include "fuckingtizenFormFactory.h"
#include "fuckingtizenPanelFactory.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

fuckingtizenFrame::fuckingtizenFrame(void)
{
}

fuckingtizenFrame::~fuckingtizenFrame(void)
{
}

result
fuckingtizenFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static fuckingtizenFormFactory formFactory;
	static fuckingtizenPanelFactory panelFactory;
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterPanelFactory(panelFactory);
	pSceneManager->RegisterScene(L"workflow");

	// Go to the scene.
	result r = pSceneManager->GoForward(SceneTransitionId(IDSCNT_MAIN_SCENE));

	// TODO: Add your frame initialization code here.
	return r;
}

result
fuckingtizenFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}
