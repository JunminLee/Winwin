
#include "AppResourceId.h"
#include "Idl_tutorial3.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


Idl_tutorial3::Idl_tutorial3(void)
{
}

Idl_tutorial3::~Idl_tutorial3(void)
{
}

bool
Idl_tutorial3::Initialize()
{
	Form::Construct(IDL_TUTORIAL3);

	return true;
}

result
Idl_tutorial3::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	Label* pTlabel3 = static_cast<Label*>(GetControl(IDC_TLABEL3));  
	if(pTlabel3)
	{
		pTlabel3->AddTouchEventListener(*this);
	}
	return r;
}

result
Idl_tutorial3::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Idl_tutorial3::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial3::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial3::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial3::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial3::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial3::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here
	e_start = currentPosition.x;
}

void
Idl_tutorial3::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	e_end = currentPosition.x;
	if(e_start > e_end)
	{
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_TUTORIAL4, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));

	}
	else
	{
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_TUTORIAL2, SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
	}
}
void
Idl_tutorial3::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial3::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}

