
#include "AppResourceId.h"
#include "Friendslistscenepanel.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


Friendslistscenepanel::Friendslistscenepanel(void)
{
}

Friendslistscenepanel::~Friendslistscenepanel(void)
{
}

bool
Friendslistscenepanel::Initialize()
{
	Panel::Construct(FriendsListScenePanel);

	return true;
}

result
Friendslistscenepanel::OnInitializing(void)
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
Friendslistscenepanel::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Friendslistscenepanel::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Friendslistscenepanel::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}
