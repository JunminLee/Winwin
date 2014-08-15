
#include "AppResourceId.h"
#include "Idl_tutorial1.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::App;

Idl_tutorial1::Idl_tutorial1(void)
{
}

Idl_tutorial1::~Idl_tutorial1(void)
{
}

bool
Idl_tutorial1::Initialize()
{
	Form::Construct(IDL_TUTORIAL1);

	return true;
}

result
Idl_tutorial1::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	Label* pTlabel1 = static_cast<Label*>(GetControl(IDC_TLABEL1));  
	if(pTlabel1)
	{
		pTlabel1->AddTouchEventListener(*this);
	}
	return r;
}

result
Idl_tutorial1::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Idl_tutorial1::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	// TODO: Add your implementation codes here
	pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
}

void
Idl_tutorial1::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial1::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial1::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{


	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
}

void
Idl_tutorial1::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial1::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here
	e_start = currentPosition.x;
}

void
Idl_tutorial1::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here
	SceneManager* pSceneManager = SceneManager::GetInstance();

	e_end = currentPosition.x;
	if(e_start > e_end)
	{
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_TUTORIAL2, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
	}
	else
	{

	}

}
void
Idl_tutorial1::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial1::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}

void  Idl_tutorial1::OnFormBackRequested (Tizen::Ui::Controls::Form &source)
{
	AppLog("왜안꺼져");
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}
