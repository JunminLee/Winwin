#include "Test2Tab2.h"
#include "AppResourceId.h"

using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

Test2Tab2::Test2Tab2(void)
{

}

Test2Tab2::~Test2Tab2(void)
{

}

bool
Test2Tab2::Initialize(void)
{
	result r = Construct(IDL_PANEL2);
	if (IsFailed(r))
	{
		return false;
	}

	return true;
}

result
Test2Tab2::OnInitializing(void)
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

	return r;
}

result
Test2Tab2::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
Test2Tab2::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
Test2Tab2::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}
