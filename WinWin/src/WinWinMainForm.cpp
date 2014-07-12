#include "WinWinMainForm.h"
#include "AppResourceId.h"
#include <FMedia.h>

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;

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


	String Activation_Path[5];
	Image Activation_Image[5];

	String InActivation_Path[5];
	Image InActivation_Image[5];

	FooterItem footerItem[5];

	for(int i=0; i<5; i++)
	{
		InActivation_Image[i].Construct();
		InActivation_Path[i] = App::GetInstance()->GetAppResourcePath();

		Activation_Image[i].Construct();
		Activation_Path[i] = App::GetInstance()->GetAppResourcePath();
	}

	InActivation_Path[0] += L"screen-density-xhigh/TimeLine_InAct.png";
	Activation_Path[0] += L"screen-density-xhigh/TimeLine_Act.png";

	footerItem[0].Construct(ID_FOOTER_ITEM1);
	footerItem[1].Construct(ID_FOOTER_ITEM2);
	footerItem[2].Construct(ID_FOOTER_ITEM3);
	footerItem[3].Construct(ID_FOOTER_ITEM4);
	footerItem[4].Construct(ID_FOOTER_ITEM5);

	//inActivation_Bitmap[0] = inActivation_Image[0].DecodeN(inActivation_Path[0], BITMAP_PIXEL_FORMAT_ARGB8888);

	footerItem[0].SetText(L"1");
	footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
	InActivation_Image[0].DecodeN(InActivation_Path[0], BITMAP_PIXEL_FORMAT_ARGB8888));
	//inActivation_Bitmap[0].SetMaskingColor(Color(125,125,125,125));
	//footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_SELECTED, inActivation_Bitmap[0]);
	footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
	Activation_Image[0].DecodeN(Activation_Path[0], BITMAP_PIXEL_FORMAT_ARGB8888));

	// TODO: Add your initialization code here

	// Setup back event listener
	Footer* pFooter = GetFooter();
	if (pFooter)
	{
		pFooter->AddActionEventListener(*this);
	}

	pFooter->AddItem(footerItem[0]);
	pFooter->AddItem(footerItem[1]);
	pFooter->AddItem(footerItem[2]);
	pFooter->AddItem(footerItem[3]);
	pFooter->AddItem(footerItem[4]);

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
	/*
	pSceneManager->GoForward(SceneTransitionId(IDSCNT_3));
	pSceneManager->GoForward(SceneTransitionId(IDSCNT_4));
	pSceneManager->GoForward(SceneTransitionId(IDSCNT_5));
	pSceneManager->GoForward(SceneTransitionId(IDSCNT_6));
	pSceneManager->GoForward(SceneTransitionId(IDSCNT_7));
	*/
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

