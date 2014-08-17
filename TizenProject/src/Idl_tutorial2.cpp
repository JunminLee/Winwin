
#include "AppResourceId.h"
#include "Idl_tutorial2.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::App;


Idl_tutorial2::Idl_tutorial2(void)
{
}

Idl_tutorial2::~Idl_tutorial2(void)
{
}

bool
Idl_tutorial2::Initialize()
{
	Form::Construct(IDL_TUTORIAL2);

	return true;
}

result
Idl_tutorial2::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	Label* pTlabel2 = static_cast<Label*>(GetControl(IDC_TLABEL2));  
	if(pTlabel2)
	{
		pTlabel2->AddTouchEventListener(*this);
	}
	return r;
}

result
Idl_tutorial2::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Idl_tutorial2::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial2::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial2::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial2::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial2::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial2::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here
	e_start = currentPosition.x;
}

void
Idl_tutorial2::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	e_end = currentPosition.x;
	if(e_start > e_end && e_start - e_end > 10)
	{
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_TUTORIAL3, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));

	}
	else if (e_start <= e_end &&  e_end - e_start > 10 )
	{
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_TUTORIAL1, SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
	}
}
void
Idl_tutorial2::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial2::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}
void  Idl_tutorial2::OnFormBackRequested (Tizen::Ui::Controls::Form &source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}
