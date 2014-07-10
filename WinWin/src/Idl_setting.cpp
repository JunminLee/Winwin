
#include "AppResourceId.h"
#include "Idl_setting.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


Idl_setting::Idl_setting(void)
{
}

Idl_setting::~Idl_setting(void)
{
}

bool
Idl_setting::Initialize()
{
	Form::Construct(IDL_SETTING);

	return true;
}

result
Idl_setting::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	SetFormBackEventListener(this);


	return r;
}

result
Idl_setting::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Idl_setting::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	// TODO: Add your implementation codes here

}

void
Idl_setting::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Idl_setting::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}
