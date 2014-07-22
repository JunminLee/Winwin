#include "WinWinMainForm.h"
#include "AppResourceId.h"
#include <FMedia.h>
#include "SceneRegister.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;

static const int ITEM_COUNT = 100;
WinWinMainForm::WinWinMainForm(void)
	: __pList(null)
{
}

WinWinMainForm::~WinWinMainForm(void)
{
}

bool
WinWinMainForm::Initialize(void)
{
	result r =  Construct(FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR | FORM_STYLE_FOOTER);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");


	return true;
}

result
WinWinMainForm::OnInitializing(void)
{



	 FooterItem footerItem[5];

	 Image inActivation_Image[5];
	 String inActivation_Path[5];

	 Image Activation_Image[5];
	 String Activation_Path[5];

	 for(int i=0; i<5; i++)
	 {
	 	inActivation_Image[i].Construct();
	 	inActivation_Path[i] = App::GetInstance()->GetAppResourcePath();

	 	Activation_Image[i].Construct();
	 	Activation_Path[i] = App::GetInstance()->GetAppResourcePath();
	 }

	 inActivation_Path[0] += L"screen-density-xhigh/TimeLine_InAct.png";
	 Activation_Path[0] += L"screen-density-xhigh/TimeLine_Act.png";

	 footerItem[0].Construct(ID_FOOTER_ITEM1);

	 footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
	 inActivation_Image[0].DecodeN(inActivation_Path[0], BITMAP_PIXEL_FORMAT_ARGB8888));

	 footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
	 Activation_Image[0].DecodeN(Activation_Path[0], BITMAP_PIXEL_FORMAT_ARGB8888));

	 inActivation_Path[1] += L"screen-density-xhigh/Chatting_InAct.png";
	 Activation_Path[1] += L"screen-density-xhigh/Chatting_Act.png";

	 footerItem[1].Construct(ID_FOOTER_ITEM2);

	 footerItem[1].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
	 inActivation_Image[1].DecodeN(inActivation_Path[1], BITMAP_PIXEL_FORMAT_ARGB8888));

	 footerItem[1].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
	 Activation_Image[1].DecodeN(Activation_Path[1], BITMAP_PIXEL_FORMAT_ARGB8888));

	 inActivation_Path[2] += L"screen-density-xhigh/PartnerList_InAct.png";
	 Activation_Path[2] += L"screen-density-xhigh/PartnerList_Act.png";

	 footerItem[2].Construct(ID_FOOTER_ITEM3);

	 footerItem[2].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
	 inActivation_Image[2].DecodeN(inActivation_Path[2], BITMAP_PIXEL_FORMAT_ARGB8888));

	 footerItem[2].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
	 Activation_Image[2].DecodeN(Activation_Path[2], BITMAP_PIXEL_FORMAT_ARGB8888));

	 inActivation_Path[3] += L"screen-density-xhigh/PartnerResearch_InAct.png";
	 Activation_Path[3] += L"screen-density-xhigh/PartnerResearch_Act.png";

	 footerItem[3].Construct(ID_FOOTER_ITEM4);

	 footerItem[3].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
	 inActivation_Image[3].DecodeN(inActivation_Path[3], BITMAP_PIXEL_FORMAT_ARGB8888));

	 footerItem[3].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
	 Activation_Image[3].DecodeN(Activation_Path[3], BITMAP_PIXEL_FORMAT_ARGB8888));

	 inActivation_Path[4] += L"screen-density-xhigh/Setting_InAct.png";
	 Activation_Path[4] += L"screen-density-xhigh/Setting_Act.png";

	 footerItem[4].Construct(ID_FOOTER_ITEM5);

	 footerItem[4].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
	 inActivation_Image[4].DecodeN(inActivation_Path[4], BITMAP_PIXEL_FORMAT_ARGB8888));

	 footerItem[4].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
	 Activation_Image[4].DecodeN(Activation_Path[4], BITMAP_PIXEL_FORMAT_ARGB8888));

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
	// Setup back event listener

	if(!CreateMainList())
	{

		return false;
	}

	SetFormBackEventListener(this);

	return E_SUCCESS;
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
			pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
			AppLog("1");
			break;
		case ID_FOOTER_ITEM2:
			pSceneManager->GoForward(ForwardSceneTransition(SCENE_CHATTING_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
			AppLog("2");
			break;
		case ID_FOOTER_ITEM3:
			pSceneManager->GoForward(ForwardSceneTransition(SCENE_PARTNER_LIST_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
			AppLog("3");
			break;
		case ID_FOOTER_ITEM4:
			pSceneManager->GoForward(ForwardSceneTransition(SCENE_PARTNER_SEARCH_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
			AppLog("4");
			break;
		case ID_FOOTER_ITEM5:
			pSceneManager->GoForward(ForwardSceneTransition(SCENE_SETTING_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
			AppLog("5");
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

bool
WinWinMainForm::CreateMainList(void)
{
	__pList = new (std::nothrow) ListView();
	__pList->Construct(FloatRectangle(0.0f, 0.0f, GetClientAreaBoundsF().width, GetClientAreaBoundsF().height), true, SCROLL_STYLE_FADE_OUT);
	__pList->SetItemProvider(*this);
	__pList->AddListViewItemEventListener(*this);
	AddControl(__pList);
	return true;
}

void
WinWinMainForm::OnListViewItemStateChanged(ListView& view, int index, int elementId, ListItemStatus status)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	if(status == LIST_CONTEXT_ITEM_STATUS_SELECTED)
	{
		switch(index)
		{
		case 0:
			//pSceneManager->GoForward(ForwardSceneTransition(SCENE_LISTVIEW1, SCENE_TRANSITION_ANIMATION_TYPE_LEFT));
			break;

		default:
			break;
		}
	}
}

void
WinWinMainForm::OnListViewItemSwept(ListView& listView, int index, SweepDirection direction)
{

}

void
WinWinMainForm::OnListViewContextItemStateChanged(ListView& listView, int index, int elementId, ListContextItemStatus status)
{

}

int
WinWinMainForm::GetItemCount(void)
{
	return ITEM_COUNT;
}

bool
WinWinMainForm::DeleteItem(int index, ListItemBase* pItem, float itemWidth)
{
	delete pItem;
	pItem = null;
	return false;
}

ListItemBase*
WinWinMainForm::CreateItem(int index, float itemWidth)
{
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
	CustomItem* pItem = new (std::nothrow) CustomItem;
	pItem->Construct(CoordinateSystem::AlignToDevice(Tizen::Graphics::FloatDimension(itemWidth, 112.0f)), style);
	FloatRectangle mainListItemRect(26.0f, 32.0f, GetClientAreaBoundsF().width, 60.0f);

	switch(index)
	{
	case 0:
		pItem->AddElement(mainListItemRect, ID_FORMAT_STRING, L"Main1", true);
		break;
	case 1:
		pItem->AddElement(mainListItemRect, ID_FORMAT_STRING, L"Main2", true);
		break;
	case 2:
		pItem->AddElement(mainListItemRect, ID_FORMAT_STRING, L"Main3", true);
		break;
	default:
		break;
	}
	return pItem;
}


