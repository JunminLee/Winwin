/*
 * ChattingForm.cpp
 *
 *  Created on: Jul 27, 2014
 *      Author: Gants
 */
//

#include "ChattingForm.h"
#include "AppResourceId.h"
#include "SceneRegister.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;

ChattingForm::ChattingForm(void)
{
}

ChattingForm::~ChattingForm(void)
{
}

bool
ChattingForm::Initialize(void)
{
	result r =  Construct(FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR | FORM_STYLE_FOOTER);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
ChattingForm::OnInitializing(void)
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

	footerItem[1].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
	inActivation_Image[1].DecodeN(inActivation_Path[1], BITMAP_PIXEL_FORMAT_ARGB8888));

	footerItem[1].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
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

	head = new Panel();

	head->Construct(Rectangle(0,0, this->GetWidth(), 96));
	head->SetBackgroundColor(Color(0,181,238,255));

	head_Center = new Button();
	head_Center->Construct(Rectangle(285, 15, 129, 63));
	head_Center->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"chatting_name.png")));


	this->AddControl(head);
	this->AddControl(head_Center);

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
	// Get a button via resource ID

	Chatting_List_View = new TableView();
	Chatting_List_View->Construct(Rectangle(0, 96, GetClientAreaBounds().width, GetClientAreaBounds().height), true, TABLE_VIEW_SCROLL_BAR_STYLE_FADE_OUT);
	Chatting_List_View->SetItemProvider(this);
	Chatting_List_View->AddScrollEventListener(*this);


	    // Adds the TableView to the form
	AddControl(Chatting_List_View);

	return r;
}

result
ChattingForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
ChattingForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
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


	default:
		break;
	}
}

void
ChattingForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
ChattingForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
ChattingForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}

// ITableViewItemProvider implementation
int
ChattingForm::GetItemCount(void)
{
    return 5;
}

int
ChattingForm::GetDefaultItemHeight(void)
{
    return 100;
}

TableViewItem*
ChattingForm::CreateItem(int itemIndex, int itemWidth)
{

	String name, time, content, profile, nation;

    TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL;
    TableViewItem* pItem = new TableViewItem();
    ChattingListItem* ci;
    int item_height=300;

    name = L"Iron Man";
    time = L"PM 1:30";
    content = L"Hello, You can call me 'Iron Man' :)";
    profile = L"s-face1.png";
    nation = L"nationalflag.png";

    Font font;
    font.Construct(FONT_STYLE_PLAIN, 30);

    style = TABLE_VIEW_ANNEX_STYLE_NORMAL;

    ci = new ChattingListItem();

    ci->Construct(Rectangle(0,0,itemWidth,300));
    ci->Initialize(name, time, content, Chatting_List_View, pItem, profile, nation, itemIndex);


    item_height = ci->GetPanelHeight();
    AppLog("!!! : %d", item_height);
    ci->AddTouchEventListener(*ci);

    pItem->Construct(Dimension(itemWidth, item_height), style);

    pItem->AddControl(ci);

    ArrCustomItem.Add(ci);

    return pItem;
}

bool
ChattingForm::DeleteItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem)
{
    pItem->Destroy();

    return true;
}

void
ChattingForm::UpdateItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem)
{
    // ....
}

void 	ChattingForm::OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{

}
void 	ChattingForm::OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition)
{

}

void 	ChattingForm::OnScrollStopped (Tizen::Ui::Control &source)
{

}

void
ChattingForm::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here


}

void
ChattingForm::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
ChattingForm::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
ChattingForm::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
ChattingForm::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
ChattingForm::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}

void
ChattingForm::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}

