#include "Test2Frame.h"
#include "Test2FormFactory.h"
#include "Test2PanelFactory.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

Test2Frame::Test2Frame(void)
{
}

Test2Frame::~Test2Frame(void)
{
}

result
Test2Frame::OnInitializing(void)
{
	
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static Test2FormFactory formFactory;
	static Test2PanelFactory panelFactory;
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterPanelFactory(panelFactory);
	pSceneManager->RegisterScene(L"workflow");

	// Go to the scene.
	 result r = E_FAILURE;
	r = pSceneManager->GoForward(SceneTransitionId(IDSCNT_START));
	
	
	
	

	// TODO: Add your frame initialization code here.
	return r;
}

result
Test2Frame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your frame termination code here.
	return r;
}
