#include "MyHome.h"

#include "AppResourceId.h"

#include "SceneRegister.h"

#include "CustomPanel.h"



#include "Toast.h"

using namespace Tizen::Base;

using namespace Tizen::App;

using namespace Tizen::Ui;

using namespace Tizen::Ui::Controls;

using namespace Tizen::Ui::Scenes;

using namespace Tizen::Graphics;

using namespace Tizen::Media;

MyHome::MyHome(void)

{

}

MyHome::~MyHome(void)

{

}

bool

MyHome::Initialize(void)

{

	result r = Construct(
			FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR);

	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;

}

result

MyHome::OnInitializing(void)

{

	result r = E_SUCCESS;

// TODO: Add your initialization code here



	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	head = new Panel();

	head->Construct(Rectangle(0, 0, this->GetWidth(), 96));

	head->SetBackgroundColor(Color(0, 181, 238, 255));

	button_MyHome = new Button();

	button_MyHome->Construct(Rectangle(33, 34, 195, 28));

	button_MyHome->SetNormalBackgroundBitmap(
			*pAppResource->GetBitmapN(L"my_home_button.png"));

	button_MyHome->AddActionEventListener(*this);

	button_MyHome->SetActionId(700);

	AppLog("11");
	button_note = new Button();

	button_note->Construct(Rectangle(542, 25, 34, 42));

	button_note->SetNormalBackgroundBitmap(
			*pAppResource->GetBitmapN(L"note.png"));

	button_note->AddActionEventListener(*this);

	button_note->SetActionId(701);

	button_flag = new Button();

	button_flag->Construct(Rectangle(646, 29, 38, 43));

	button_flag->SetNormalBackgroundBitmap(
			*pAppResource->GetBitmapN(L"flag_button.png"));

	button_flag->AddActionEventListener(*this);

	button_flag->SetActionId(702);

	head->AddControl(button_MyHome);

	head->AddControl(button_note);

	head->AddControl(button_flag);

// Setup back event listener

	SetFormBackEventListener(this);

// Get a button via resource ID

	//image_panel->Construct(Rectangle(96,0,this->GetWidth(), 500));
	//image_panel->

	image_panel = new Label();
	image_panel->Construct(Rectangle(0,96,this->GetWidth(), 500), " ");
	image_panel->SetBackgroundBitmap(*(pAppResource->GetBitmapN(L"tizen.png")));

	TimelineTableView = new TableView();

	TimelineTableView->Construct(
			Rectangle(0, 610, GetClientAreaBounds().width,
					GetClientAreaBounds().height - 610), true,
			TABLE_VIEW_SCROLL_BAR_STYLE_FADE_OUT);

	TimelineTableView->SetItemProvider(this);

	TimelineTableView->AddTableViewItemEventListener(*this);

	// Adds the TableView to the form


	AddControl(TimelineTableView);

	AddControl(head);

	AddControl(image_panel);

	return r;

}

result

MyHome::OnTerminating(void)

{

	result r = E_SUCCESS;



// TODO: Add your termination code here

	return r;

}

void

MyHome::OnActionPerformed(const Tizen::Ui::Control& source,
		int actionId)

		{

	SceneManager* pSceneManager = SceneManager::GetInstance();

	AppAssert(pSceneManager);

	switch (actionId)

	{
	case 701:
		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_NOTE_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_NONE));
	break;
	}
}




void

MyHome::OnFormBackRequested(Tizen::Ui::Controls::Form& source)

{

	UiApp* pApp = UiApp::GetInstance();

	AppAssert(pApp);

	pApp->Terminate();

}

void

MyHome::OnSceneActivatedN(
		const Tizen::Ui::Scenes::SceneId& previousSceneId,

		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		Tizen::Base::Collection::IList* pArgs)

		{

// TODO: Activate your scene here.

}

void

MyHome::OnSceneDeactivated(
		const Tizen::Ui::Scenes::SceneId& currentSceneId,

		const Tizen::Ui::Scenes::SceneId& nextSceneId)

		{

// TODO: Deactivate your scene here.

}



// ITableViewItemProvider implementation

int

MyHome::GetItemCount(void)

{

	return 5;

}




TableViewItem*

MyHome::CreateItem(int itemIndex, int itemWidth)

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

MyHome::DeleteItem(int itemIndex,
		Tizen::Ui::Controls::TableViewItem* pItem)

		{

	pItem->Destroy();


	return true;

}

void

MyHome::UpdateItem(int itemIndex,
		Tizen::Ui::Controls::TableViewItem* pItem)

		{

	// ....

}


void
MyHome::OnTableViewContextItemActivationStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewContextItem *pContextItem, bool activated)
{
	AppLog("11111");
}
void
MyHome::OnTableViewItemReordered (Tizen::Ui::Controls::TableView &tableView, int itemIndexFrom, int itemIndexTo)
{
	AppLog("222222");
}

int
MyHome::GetDefaultItemHeight(void)

{

	return 100;

}
void
MyHome::OnTableViewItemStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewItem *pItem, Tizen::Ui::Controls::TableViewItemStatus status)
{
	CustomPanel* cp = static_cast <CustomPanel *>(pItem->GetControl(0));
	AppLog("cp->remove_button_on : %d",cp->remove_button_on);
	if(cp->remove_button_on == true)
	{
		cp->index = itemIndex;
	}
}
