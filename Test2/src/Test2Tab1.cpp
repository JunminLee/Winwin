#include "Test2Tab1.h"
#include "AppResourceId.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

Test2Tab1::Test2Tab1(void)
{

}

Test2Tab1::~Test2Tab1(void)
{

}

bool
Test2Tab1::Initialize(void)
{
	result r = Construct(IDL_PANEL1);
	if (IsFailed(r))
	{
		return false;
	}

	return true;
}

result
Test2Tab1::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Layout setting
	const Form* pForm = dynamic_cast< Form* >(GetParent());
	if (pForm)
	{
		RelativeLayout* pRelativeLayout = dynamic_cast< RelativeLayout* >(pForm->GetLandscapeLayoutN());
		if (pRelativeLayout)
		{
			pRelativeLayout->SetHorizontalFitPolicy(*this, FIT_POLICY_PARENT);
			pRelativeLayout->SetVerticalFitPolicy(*this, FIT_POLICY_PARENT);
			delete pRelativeLayout;
		}
		pRelativeLayout = dynamic_cast< RelativeLayout* >(pForm->GetPortraitLayoutN());
		if (pRelativeLayout)
		{		
			pRelativeLayout->SetHorizontalFitPolicy(*this, FIT_POLICY_PARENT);
			pRelativeLayout->SetVerticalFitPolicy(*this, FIT_POLICY_PARENT);
			delete pRelativeLayout;
		}
	}

	AddTouchEventListener(*this);

	return r;
}

result
Test2Tab1::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
Test2Tab1::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
Test2Tab1::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

void
Test2Tab1::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Test2Tab1::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Test2Tab1::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Test2Tab1::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Test2Tab1::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	
	// TODO: Add your implementation codes here

}

void
Test2Tab1::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Test2Tab1::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}
