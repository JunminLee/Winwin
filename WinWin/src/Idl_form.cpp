
#include "AppResourceId.h"
#include "Idl_form.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;



Idl_form::Idl_form(void)
{
}

Idl_form::~Idl_form(void)
{
}

bool
Idl_form::Initialize()
{
	Form::Construct(IDL_FORM);

	return true;
}

result
Idl_form::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	AddTouchEventListener(*this);

	AddFocusEventListener(*this);

	SetFormBackEventListener(this);


	return r;
}

result
Idl_form::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Idl_form::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	// TODO: Add your implementation codes here

}

void
Idl_form::OnFocusGained(const Tizen::Ui::Control& source)
{
	//SceneManager* pSceneManager = SceneManager::GetInstance();
	
	// TODO: Add your implementation codes here

}

void
Idl_form::OnFocusLost(const Tizen::Ui::Control& source)
{
	// TODO: Add your implementation codes here

}

void
Idl_form::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Idl_form::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}

void
Idl_form::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_form::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_form::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_form::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_form::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_form::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Idl_form::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}
