#include "AppResourceId.h"
#include "Idl_aform.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

Idl_aform::Idl_aform(void) {
}

Idl_aform::~Idl_aform(void) {
}

bool Idl_aform::Initialize() {
	Form::Construct(IDL_AFORM);

	return true;
}

result Idl_aform::OnInitializing(void) {
	result r = E_SUCCESS;
	SetFormBackEventListener(this);
	// TODO: Add your initialization code here

	return r;
}

result Idl_aform::OnTerminating(void) {
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}
void Idl_aform::OnFormBackRequested(Tizen::Ui::Controls::Form& source) {
	//SceneManager* pSceneManager = SceneManager::GetInstance();
		//pSceneManager->GoBackward(BackwardSceneTransition());
	UiApp* pApp = UiApp::GetInstance();
		AppAssert(pApp);
		pApp->Terminate();
}

void Idl_aform::OnSceneActivatedN(
		const Tizen::Ui::Scenes::SceneId& previousSceneId,
		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		Tizen::Base::Collection::IList* pArgs) {
	// TODO: Add your implementation codes here

}

void Idl_aform::OnSceneDeactivated(
		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		const Tizen::Ui::Scenes::SceneId& nextSceneId) {
	// TODO: Add your implementation codes here

}
