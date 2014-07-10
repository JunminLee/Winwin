
#include "AppResourceId.h"
#include "Idl_partnerlist.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


Idl_partnerlist::Idl_partnerlist(void)
{
}

Idl_partnerlist::~Idl_partnerlist(void)
{
}

bool
Idl_partnerlist::Initialize()
{
	Form::Construct(IDL_PartnerList);

	return true;
}

result
Idl_partnerlist::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	SetFormBackEventListener(this);


	return r;
}

result
Idl_partnerlist::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Idl_partnerlist::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	// TODO: Add your implementation codes here

}

void
Idl_partnerlist::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Idl_partnerlist::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}
