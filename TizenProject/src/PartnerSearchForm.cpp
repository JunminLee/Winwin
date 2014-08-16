/*
 * PartnerSearchForm.cpp
 *
 *  Created on: Jul 27, 2014
 *      Author: Gants
 */


#include "PartnerSearchForm.h"
#include "AppResourceId.h"
#include "SceneRegister.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;

PartnerSearchForm::PartnerSearchForm(void)
{
}

PartnerSearchForm::~PartnerSearchForm(void)
{
}

bool
PartnerSearchForm::Initialize(void)
{
	result r =  Construct(FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR | FORM_STYLE_FOOTER);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
PartnerSearchForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	FooterItem footerItem[5];
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

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

	footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
	inActivation_Image[0].DecodeN(inActivation_Path[0], BITMAP_PIXEL_FORMAT_ARGB8888));

	footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
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

	footerItem[3].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
	inActivation_Image[3].DecodeN(inActivation_Path[3], BITMAP_PIXEL_FORMAT_ARGB8888));

	footerItem[3].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
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
	SetFormBackEventListener(this);

	// Get a button via resource ID
	head = new Panel();

	head->Construct(Rectangle(0,0, this->GetWidth(), 96));
	head->SetBackgroundColor(Color(0,181,238,255));

	head_center = new Button();
	head_center->Construct(Rectangle(257, 32, 206, 40));
	head_center->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"partnersearch.png")));

	head_left = new Button();
	head_left->Construct(Rectangle(31, 24, 47, 47));
	head_left->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"searchicon.png")));
	head_left->SetActionId(ID_SEARCH_PARTNER_LEFT);
	head_left->AddActionEventListener(*this);

	head_right = new Button();
	head_right->Construct(Rectangle(646, 29, 38, 43));
	head_right->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"flag_partner.png")));
	head_right->SetActionId(ID_SEARCH_PARTNER_RIGHT);
	head_right->AddActionEventListener(*this);


	AddControl(head);
	AddControl(head_center);
	AddControl(head_left);
	AddControl(head_right);


	Search_List_View = new TableView();
	Search_List_View->Construct(Rectangle(0, 96, GetClientAreaBounds().width, GetClientAreaBounds().height - 97), true, TABLE_VIEW_SCROLL_BAR_STYLE_FADE_OUT);
	Search_List_View->SetItemProvider(this);
	Search_List_View->AddScrollEventListener(*this);


		    // Adds the TableView to the form
	AddControl(Search_List_View);

	return r;
}

result
PartnerSearchForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
PartnerSearchForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	switch(actionId)
	{
	case ID_FOOTER_ITEM1:
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
		break;
	case ID_FOOTER_ITEM2:
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_CHATTING_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
		break;
	case ID_FOOTER_ITEM3:
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_PARTNER_LIST_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
		break;
	case ID_FOOTER_ITEM4:
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_PARTNER_SEARCH_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
		break;
	case ID_FOOTER_ITEM5:
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_SETTING_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
		break;
	case ID_SEARCH_PARTNER_LEFT:
		toast = new Toast();
		toast->Construct(Rectangle(30,1100 ,660,70), L"파트너를 찾는 페이지로 넘어갑니다", 2000);
		break;
	case ID_SEARCH_PARTNER_RIGHT:
		toast = new Toast();
		toast->Construct(Rectangle(30,1100 ,660,70), L"언어를 선택합니다", 2000);
		break;



	default:
		break;
	}
}

void
PartnerSearchForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
PartnerSearchForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
PartnerSearchForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

int
PartnerSearchForm::GetItemCount(void)
{
	return 7;
}
Tizen::Ui::Controls::TableViewItem*
PartnerSearchForm::CreateItem(int itemIndex, int itemWidth)
{


	    TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL;
	    TableViewItem* pItem = new TableViewItem();

	    PartnerSearchItem* ci;
	    int item_height;


	    style = TABLE_VIEW_ANNEX_STYLE_NORMAL;

	    ci = new PartnerSearchItem();

	    ci->Construct(Rectangle(0,0,itemWidth,260));
	    ci->Initialize(L"IronMan",L"s-face1.png",L"nationalflag.png",L"Eng",L"hobby.png",L"Soccer",L"Hello my name is gogosing Hello my name is gogosingHello my name is gogosingHello my name is gogosingHello my name is gogosingHello my name is gogosingHello my name is gogosing",Search_List_View,pItem,itemIndex);


	    item_height = ci->GetPanelHeight();
	    AppLog("!!! : %d", item_height);
	    ci->AddTouchEventListener(*ci);

	    pItem->Construct(Dimension(itemWidth, item_height), style);
	    pItem->AddControl(ci);

	    ArrCustomItem.Add(ci);


	    return pItem;
}
bool
PartnerSearchForm::DeleteItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem)
{
	pItem->Destroy();

	return true;
}
void
PartnerSearchForm::UpdateItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem)
{

}

int
PartnerSearchForm::GetDefaultItemHeight(void)
{
	return 300;
}

void
PartnerSearchForm::OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{

}
void
PartnerSearchForm::OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition)
{

}
void
PartnerSearchForm::OnScrollStopped (Tizen::Ui::Control &source)
{

}
void PartnerSearchForm::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void PartnerSearchForm::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void PartnerSearchForm::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void PartnerSearchForm::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void PartnerSearchForm::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void PartnerSearchForm::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void PartnerSearchForm::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
