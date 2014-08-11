
#include "AppResourceId.h"
#include "Idl_tutorial4.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


Idl_tutorial4::Idl_tutorial4(void)
{
}

Idl_tutorial4::~Idl_tutorial4(void)
{
}

bool
Idl_tutorial4::Initialize()
{
	Form::Construct(IDL_TUTORIAL4);

	return true;
}

result
Idl_tutorial4::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here

	Label* pTlabel4 = static_cast<Label*>(GetControl(IDC_TLABEL4));  
	if(pTlabel4)
	{
		pTlabel4->AddTouchEventListener(*this);
	}
	return r;
}

result
Idl_tutorial4::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Idl_tutorial4::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial4::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial4::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial4::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial4::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial4::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here
	e_start = currentPosition.x;
}

void
Idl_tutorial4::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	e_end = currentPosition.x;
	if(e_start > e_end)
	{
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
	} else if(e_start == e_end)
	{
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
	}
	else
	{
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_TUTORIAL3, SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));
	}
}
void
Idl_tutorial4::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Idl_tutorial4::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}
