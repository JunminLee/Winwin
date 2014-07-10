
#include "AppResourceId.h"
#include "Idl_chatting.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;


Idl_chatting::Idl_chatting(void)
{
}

Idl_chatting::~Idl_chatting(void)
{
}

bool
Idl_chatting::Initialize()
{
	Form::Construct(IDL_Chatting);

	return true;
}

result
Idl_chatting::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	SetFormBackEventListener(this);


	return r;
}

result
Idl_chatting::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}



void
Idl_chatting::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	// TODO: Add your implementation codes here

}

void
Idl_chatting::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here

}

void
Idl_chatting::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here

}
