
#include "AppResourceId.h"
#include "Intro_form.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Base::Runtime;


Intro_form::Intro_form(void)
{
}

Intro_form::~Intro_form(void)
{
}

bool
Intro_form::Initialize()
{
	Form::Construct(INTRO_FORM);

	return true;
}

result
Intro_form::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	Timer* pTimer=new Timer;
	pTimer->Construct(*this);
	pTimer->Start(2000);

	return r;
}

result
Intro_form::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void Intro_form::OnTimerExpired(Tizen::Base::Runtime::Timer& timer)
{
		SceneManager* pSceneManager = SceneManager::GetInstance();
		pSceneManager->GoForward(SceneTransitionId(IDSCNT_2));
}

void
Intro_form::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Intro_form::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Intro_form::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Intro_form::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Intro_form::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Intro_form::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	pSceneManager->GoForward(SceneTransitionId(IDSCNT_2));
	// TODO: Add your implementation codes here

}

void
Intro_form::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Intro_form::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Intro_form::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}
