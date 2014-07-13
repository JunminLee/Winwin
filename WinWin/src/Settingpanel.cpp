
#include "AppResourceId.h"
#include "Settingpanel.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


Settingpanel::Settingpanel(void)
{
}

Settingpanel::~Settingpanel(void)
{
}

bool
Settingpanel::Initialize()
{
	Panel::Construct(SettingPanel);

	return true;
}

result
Settingpanel::OnInitializing(void)
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
Settingpanel::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Settingpanel::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Settingpanel::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}
