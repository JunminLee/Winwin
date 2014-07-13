
#include "AppResourceId.h"
#include "Mainscene_panel.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


Mainscene_panel::Mainscene_panel(void)
{
}

Mainscene_panel::~Mainscene_panel(void)
{
}

bool
Mainscene_panel::Initialize()
{
	Panel::Construct(MainScene_Panel);

	return true;
}

result
Mainscene_panel::OnInitializing(void)
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
Mainscene_panel::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Mainscene_panel::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Mainscene_panel::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}
