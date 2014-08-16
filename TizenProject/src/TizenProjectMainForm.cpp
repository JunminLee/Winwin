#include "TizenProjectMainForm.h"

#include "AppResourceId.h"

#include "SceneRegister.h"

#include "CustomPanel.h"

#include "CommentItem.h"

#include "Toast.h"

using namespace Tizen::Base;

using namespace Tizen::App;

using namespace Tizen::Ui;

using namespace Tizen::Ui::Controls;

using namespace Tizen::Ui::Scenes;

using namespace Tizen::Graphics;

using namespace Tizen::Media;

TizenProjectMainForm::TizenProjectMainForm(void)

{

}

TizenProjectMainForm::~TizenProjectMainForm(void)

{

}

bool

TizenProjectMainForm::Initialize(void)

{

	result r = Construct(
			FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR
					| FORM_STYLE_FOOTER);

	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;

}

result

TizenProjectMainForm::OnInitializing(void)

{

	result r = E_SUCCESS;

	popup = new Popup;
	sp = new ScrollPanel;
	tb = new TextBox;

	Font font;
	font.Construct(FONT_STYLE_PLAIN, 35);

	tb->Construct(Rectangle(260, 0, 100, 50), TEXT_BOX_BORDER_NONE);
	tb->SetText(L"알람");
	tb->SetFont(font);
	tb->SetColor(TEXT_BOX_STATUS_NORMAL, Color(255, 255, 255, 255));
	tb->SetTextColor(TEXT_BOX_TEXT_COLOR_NORMAL, Color(0, 181, 237, 255));

	sp->Construct(Rectangle(0, 50, 600, 360));
	sp->SetBackgroundColor(Color(220, 220, 200, 150));

	popup->Construct(false, Dimension(600, 410));
	popup->AddControl(tb);
	popup->SetPosition(60, 170);
	popup->AddFocusEventListener(*this);
	popup->SetColor(Color(255, 255, 255, 255));


// TODO: Add your initialization code here

	FooterItem footerItem[5];

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();


	footerItem[0].Construct(ID_FOOTER_ITEM1);

	footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
			pAppResource->GetBitmapN(L"TimeLine_InAct.png"));

	footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
			pAppResource->GetBitmapN(L"TimeLine_Act.png"));

	footerItem[1].Construct(ID_FOOTER_ITEM2);

	footerItem[1].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
			pAppResource->GetBitmapN(L"Chatting_InAct.png"));

	footerItem[1].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
			pAppResource->GetBitmapN(L"Chatting_Act.png"));

	footerItem[2].Construct(ID_FOOTER_ITEM3);

	footerItem[2].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
			pAppResource->GetBitmapN(L"PartnerList_InAct.png"));

	footerItem[2].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
			pAppResource->GetBitmapN(L"PartnerList_Act.png"));

	footerItem[3].Construct(ID_FOOTER_ITEM4);

	footerItem[3].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
			pAppResource->GetBitmapN(L"PartnerResearch_InAct.png"));

	footerItem[3].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
			pAppResource->GetBitmapN(L"PartnerResearch_Act.png"));

	footerItem[4].Construct(ID_FOOTER_ITEM5);

	footerItem[4].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
			pAppResource->GetBitmapN(L"Setting_InAct.png"));

	footerItem[4].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
			pAppResource->GetBitmapN(L"Setting_Act.png"));

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

	head = new Panel();

	head->Construct(Rectangle(0, 0, this->GetWidth(), 96));

	head->SetBackgroundColor(Color(0, 181, 238, 255));

	button_winwin = new Button();

	button_winwin->Construct(Rectangle(257, 29, 215, 38));

	button_winwin->SetNormalBackgroundBitmap(
			*pAppResource->GetBitmapN(L"winwin_button.png"));

	button_winwin->AddActionEventListener(*this);

	button_winwin->SetActionId(700);

	AppLog("11");
	button_my = new Button();

	button_my->Construct(Rectangle(33, 34, 53, 29));

	button_my->SetNormalBackgroundBitmap(
			*pAppResource->GetBitmapN(L"my_button.png"));

	button_my->AddActionEventListener(*this);

	button_my->SetActionId(701);

	button_flag = new Button();

	button_flag->Construct(Rectangle(646, 29, 38, 43));

	button_flag->SetNormalBackgroundBitmap(
			*pAppResource->GetBitmapN(L"flag_button.png"));

	button_flag->AddActionEventListener(*this);

	button_flag->SetActionId(702);

	head->AddControl(button_winwin);

	head->AddControl(button_my);

	head->AddControl(button_flag);

// Setup back event listener

	SetFormBackEventListener(this);

// Get a button via resource ID

	TimelineTableView = new TableView();

	TimelineTableView->Construct(
			Rectangle(0, 96, GetClientAreaBounds().width,
					GetClientAreaBounds().height - 96), true,
			TABLE_VIEW_SCROLL_BAR_STYLE_FADE_OUT);

	TimelineTableView->SetItemProvider(this);

	TimelineTableView->AddScrollEventListener(*this);


	this->AddTouchEventListener(*this);

	TimelineTableView->AddTableViewItemEventListener(*this);

	// Adds the TableView to the form


	AddControl(TimelineTableView);

	AddControl(head);

	button_text_upload=null;

	return r;

}

result

TizenProjectMainForm::OnTerminating(void)

{

	result r = E_SUCCESS;

	AppLog("22");
	/*
	if(popup != null)
		popup->Destroy();
	if(sp != null)
		sp->Destroy();
	if(tb != null)
		tb->Destroy();*/


// TODO: Add your termination code here

	return r;

}

void

TizenProjectMainForm::OnActionPerformed(const Tizen::Ui::Control& source,
		int actionId)

		{

	SceneManager* pSceneManager = SceneManager::GetInstance();

	AppAssert(pSceneManager);

	switch (actionId)

	{

	case ID_FOOTER_ITEM1:

		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_MAIN_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_NONE));

		break;

	case ID_FOOTER_ITEM2:

		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_CHATTING_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_NONE));

		break;

	case ID_FOOTER_ITEM3:

		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_PARTNER_LIST_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_NONE));

		break;

	case ID_FOOTER_ITEM4:

		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_PARTNER_SEARCH_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_NONE));

		break;

	case ID_FOOTER_ITEM5:

		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_SETTING_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_NONE));

		break;

	case 700: {

		CommentItem *cii;

		for (int i = 0; i < 7; i++) {
			cii = new CommentItem();
			cii->Construct(Rectangle(0, i * 120, popup->GetWidth(), 120));
			cii->Initialize(L"Rosa", L"3분전", L"회원님의 게시물을 좋아합니당!", L"tizen.png");
			arr_comment_item.InsertAt(cii, i);
			sp->AddControl(cii);
		}

		popup->AddControl(sp);
		popup->AddTouchEventListener(*this);
		ShowPopup();
		break;

	}

	case 701: {
		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_MYHOME_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_NONE));
		break;
	}
	case 702: {

		break;
	}
	case 703: {

	}
	default: {
		break;
	}
	}

}

void TizenProjectMainForm::OnFocusGained(const Tizen::Ui::Control &source) {

}
void TizenProjectMainForm::OnFocusLost(const Tizen::Ui::Control &source) {
	AppLog("lost");
}

void TizenProjectMainForm::ShowPopup(void) {
	popup->SetShowState(true);
	popup->Show();
}

void TizenProjectMainForm::HidePopup(void) {

	popup->SetShowState(false);
	Invalidate(true);
}

void

TizenProjectMainForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)

{

	UiApp* pApp = UiApp::GetInstance();

	AppAssert(pApp);

	pApp->Terminate();

}

void

TizenProjectMainForm::OnSceneActivatedN(
		const Tizen::Ui::Scenes::SceneId& previousSceneId,

		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		Tizen::Base::Collection::IList* pArgs)

		{

// TODO: Activate your scene here.

}

void

TizenProjectMainForm::OnSceneDeactivated(
		const Tizen::Ui::Scenes::SceneId& currentSceneId,

		const Tizen::Ui::Scenes::SceneId& nextSceneId)

		{

// TODO: Deactivate your scene here.

}

void

TizenProjectMainForm::OnTouchDoublePressed(const Tizen::Ui::Control& source,
		const Tizen::Graphics::Point& currentPosition,
		const Tizen::Ui::TouchEventInfo& touchInfo)

		{

// TODO: Add your implementation codes here

}

void

TizenProjectMainForm::OnTouchFocusIn(const Tizen::Ui::Control& source,
		const Tizen::Graphics::Point& currentPosition,
		const Tizen::Ui::TouchEventInfo& touchInfo)

		{

// TODO: Add your implementation codes here

}

void

TizenProjectMainForm::OnTouchFocusOut(const Tizen::Ui::Control& source,
		const Tizen::Graphics::Point& currentPosition,
		const Tizen::Ui::TouchEventInfo& touchInfo)

		{

// TODO: Add your implementation codes here

}

void

TizenProjectMainForm::OnTouchLongPressed(const Tizen::Ui::Control& source,
		const Tizen::Graphics::Point& currentPosition,
		const Tizen::Ui::TouchEventInfo& touchInfo)

		{

// TODO: Add your implementation codes here

}

void

TizenProjectMainForm::OnTouchMoved(const Tizen::Ui::Control& source,
		const Tizen::Graphics::Point& currentPosition,
		const Tizen::Ui::TouchEventInfo& touchInfo)

		{
AppLog("fdfdf");
// TODO: Add your implementation codes here

}

void

TizenProjectMainForm::OnTouchPressed(const Tizen::Ui::Control& source,
		const Tizen::Graphics::Point& currentPosition,
		const Tizen::Ui::TouchEventInfo& touchInfo)

		{

	AppLog("pressed!!!!!!!");

	/*CustomPanel *cp;

	 for(int i=0; i<TimelineTableView->GetItemCount(); i++)

	 {

	 cp = static_cast <CustomPanel *>(ArrCustomPanel.GetAt(i));

	 if(cp->GetHighlightMode()==true)

	 {

	 TimelineTableView->GetControl(1)->SetBounds(TimelineTableView->GetControl(1)->GetBounds());

	 }

	 }*/

}

void

TizenProjectMainForm::OnTouchReleased(const Tizen::Ui::Control& source,
		const Tizen::Graphics::Point& currentPosition,
		const Tizen::Ui::TouchEventInfo& touchInfo)

		{
	AppLog("pressed");

	AppLog("state : %d", popup->GetShowState());

	if (popup->GetShowState() == true) {
		HidePopup();
		arr_comment_item.RemoveAll();

	}

}

// ITableViewItemProvider implementation

int

TizenProjectMainForm::GetItemCount(void)

{

	return 5;

}

int

TizenProjectMainForm::GetDefaultItemHeight(void)

{

	return 100;

}

TableViewItem*

TizenProjectMainForm::CreateItem(int itemIndex, int itemWidth)

{

	String name, time, content, ex_content;

	TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL;

	TableViewItem* pItem = new TableViewItem();

	CustomPanel *cp;

	int item_height;

	content =
			L"Tizen is a new open platform that enables richer user experience Tizen is a new open platform that enables richer user experience Tizen is a new open platform that enables richer user experience";

	ex_content =
			L"육군사관학교 34기인 권 총장은 육군본부 계획편제처장, 국방부 정책기획관 취임했다. 육군사관학교 34기인 권 총장은 육군본부 계획편제처장, 국방부 정책기획관 취임했다.";

	Font font;

	font.Construct(FONT_STYLE_PLAIN, 30);

	style = TABLE_VIEW_ANNEX_STYLE_NORMAL;

	cp = new CustomPanel();

	cp->Construct(Rectangle(0, 0, itemWidth, 500));

	cp->Initialize(L"David Beckham", L"123", content, ex_content,
			TimelineTableView, pItem, itemIndex);

	item_height = cp->GetPanelHeight();

	cp->AddTouchEventListener(*cp);

	pItem->Construct(Dimension(itemWidth, item_height), style);

	pItem->AddControl(cp);

	ArrCustomPanel.Add(cp);

	return pItem;

}

bool

TizenProjectMainForm::DeleteItem(int itemIndex,
		Tizen::Ui::Controls::TableViewItem* pItem)

		{

	pItem->Destroy();


	return true;

}

void

TizenProjectMainForm::UpdateItem(int itemIndex,
		Tizen::Ui::Controls::TableViewItem* pItem)

		{

	// ....

}

void

TizenProjectMainForm::OnScrollEndReached(Tizen::Ui::Control &source,
		Tizen::Ui::Controls::ScrollEndEvent type)

		{

}

void

TizenProjectMainForm::OnScrollPositionChanged(Tizen::Ui::Control &source,
		int scrollPosition)

{
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	static int old_scroll = scrollPosition;

	AppLog("ab222");
	if(button_text_upload == null)
	{
		AppLog("ab111");
		button_text_upload = new Button;

		button_text_upload->Construct(Rectangle(178, 115, 363, 90), " ");
		button_text_upload->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN("upload_button.png")));
		button_text_upload->AddActionEventListener(*this);
		AddControl(button_text_upload);
	}
	else
	{
		AppLog("ab333");
		if(scrollPosition > old_scroll)
		{
			button_text_upload->SetShowState(false);
		}
		else
			button_text_upload->SetShowState(true);
	}

	old_scroll = scrollPosition;

}

void

TizenProjectMainForm::OnScrollStopped(Tizen::Ui::Control &source)

{

}
void
TizenProjectMainForm::OnTableViewContextItemActivationStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewContextItem *pContextItem, bool activated)
{
	AppLog("11111");
}
void
TizenProjectMainForm::OnTableViewItemReordered (Tizen::Ui::Controls::TableView &tableView, int itemIndexFrom, int itemIndexTo)
{
	AppLog("222222");
}

void
TizenProjectMainForm::OnTableViewItemStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewItem *pItem, Tizen::Ui::Controls::TableViewItemStatus status)
{
	CustomPanel* cp = static_cast <CustomPanel *>(pItem->GetControl(0));
	AppLog("cp->remove_button_on : %d",cp->remove_button_on);
	if(cp->remove_button_on == true)
	{
		cp->index = itemIndex;
	}
}
