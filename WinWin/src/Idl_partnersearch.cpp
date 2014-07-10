
#include "AppResourceId.h"
#include "Idl_partnersearch.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


Idl_partnersearch::Idl_partnersearch(void)
{
}

Idl_partnersearch::~Idl_partnersearch(void)
{
}

bool
Idl_partnersearch::Initialize()
{
	Form::Construct(IDL_PartnerSearch);

	return true;
}

result
Idl_partnersearch::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	SetFormBackEventListener(this);


	return r;
}

result
Idl_partnersearch::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Idl_partnersearch::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Idl_partnersearch::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}

void
Idl_partnersearch::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	// TODO: Add your implementation codes here

}
