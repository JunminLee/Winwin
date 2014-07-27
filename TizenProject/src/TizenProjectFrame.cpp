#include "TizenProjectFrame.h"
#include "TizenProjectFormFactory.h"
#include "TizenProjectPanelFactory.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

TizenProjectFrame::TizenProjectFrame(void)
{
}

TizenProjectFrame::~TizenProjectFrame(void)
{
}

result
TizenProjectFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static TizenProjectFormFactory formFactory;
	static TizenProjectPanelFactory panelFactory;
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
TizenProjectFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}
