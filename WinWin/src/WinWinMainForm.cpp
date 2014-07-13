#include "WinWinMainForm.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


WinWinMainForm::WinWinMainForm(void)
{
}

WinWinMainForm::~WinWinMainForm(void)
{
}

bool
WinWinMainForm::Initialize(void)
{
	result r = Construct(IDL_FORM);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
WinWinMainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Footer* pFooter = GetFooter();
			if (pFooter)
			{
				pFooter->AddActionEventListener(*this);
			}

			// Setup back event listener
			SetFormBackEventListener(this);

	return r;
}

result
WinWinMainForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
WinWinMainForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
		SceneManager* pSceneManager = SceneManager::GetInstance();
		AppAssert(pSceneManager);

		switch(actionId)
		{
		case ID_FOOTER_ITEM1:
			pSceneManager->GoForward(SceneTransitionId(IDSCNT_3));
			break;
		case ID_FOOTER_ITEM2:
			pSceneManager->GoForward(SceneTransitionId(IDSCNT_4));
			break;
		case ID_FOOTER_ITEM3:
			pSceneManager->GoForward(SceneTransitionId(IDSCNT_5));
			break;
		case ID_FOOTER_ITEM4:
			pSceneManager->GoForward(SceneTransitionId(IDSCNT_6));
			break;
		case ID_FOOTER_ITEM5:
			pSceneManager->GoForward(SceneTransitionId(IDSCNT_7));
			break;
		default:
			break;
		}
}

void
WinWinMainForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
WinWinMainForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
WinWinMainForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

