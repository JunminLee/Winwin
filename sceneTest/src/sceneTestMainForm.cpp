#include "sceneTestMainForm.h"
#include "AppResourceId.h"
#include "DelayThread.h"
#include <FSystem.h>
using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Base::Runtime;



sceneTestMainForm::sceneTestMainForm(void)
{
}

sceneTestMainForm::~sceneTestMainForm(void)
{
}

bool
sceneTestMainForm::Initialize(void)
{
	result r = Construct(IDL_FORM);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");


	return true;
}

result
sceneTestMainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	// Setup back event listener
	SetFormBackEventListener(this);




	Label* pLabel1 = static_cast<Label*>(GetControl(IDC_LABEL1));  
	if(pLabel1)
	{
		pLabel1->AddTouchEventListener(*this);
	}
	Timer* pTimer=new Timer;
	pTimer->Construct(*this);
	pTimer->Start(2000);
	return r;
}

void sceneTestMainForm::OnTimerExpired(Tizen::Base::Runtime::Timer& timer)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
		pSceneManager->GoForward(SceneTransitionId(IDSNT_1));

}

result
sceneTestMainForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
sceneTestMainForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	



}

void
sceneTestMainForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
sceneTestMainForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
sceneTestMainForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

void
sceneTestMainForm::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
sceneTestMainForm::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
sceneTestMainForm::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
sceneTestMainForm::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
sceneTestMainForm::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
sceneTestMainForm::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	//SceneManager* pSceneManager = SceneManager::GetInstance();
	//pSceneManager->GoForward(SceneTransitionId(IDSCNT_1));
	// TODO: Add your implementation codes here

}

void
sceneTestMainForm::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}
