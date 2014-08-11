#include "TizenProjectMainForm.h"
#include "AppResourceId.h"
#include "SceneRegister.h"
#include "CustomPanel.h"

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
	result r =  Construct(FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR | FORM_STYLE_FOOTER | FORM_STYLE_HEADER);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
TizenProjectMainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	FooterItem	 footerItem[5];

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	footerItem[0].Construct(ID_FOOTER_ITEM1);
	footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED, pAppResource->GetBitmapN(L"TimeLine_InAct.png"));
	footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,pAppResource->GetBitmapN(L"TimeLine_Act.png"));

	footerItem[1].Construct(ID_FOOTER_ITEM2);
	footerItem[1].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,pAppResource->GetBitmapN(L"Chatting_InAct.png"));
	footerItem[1].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,pAppResource->GetBitmapN(L"Chatting_Act.png"));

	footerItem[2].Construct(ID_FOOTER_ITEM3);
	footerItem[2].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,pAppResource->GetBitmapN(L"PartnerList_InAct.png"));
	footerItem[2].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,pAppResource->GetBitmapN(L"PartnerList_Act.png"));

	footerItem[3].Construct(ID_FOOTER_ITEM4);
	footerItem[3].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,pAppResource->GetBitmapN(L"PartnerResearch_InAct.png"));
	footerItem[3].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,pAppResource->GetBitmapN(L"PartnerResearch_Act.png"));

	footerItem[4].Construct(ID_FOOTER_ITEM5);
	footerItem[4].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,pAppResource->GetBitmapN(L"Setting_InAct.png"));
	footerItem[4].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,pAppResource->GetBitmapN(L"Setting_Act.png"));



	Header* pHeader = GetHeader();
	 pHeader->SetStyle(HEADER_STYLE_TITLE);
	 pHeader->SetBackgroundBitmap(pAppResource->GetBitmapN(L"header.png"));
	Footer* pFooter = GetFooter();

	if (pFooter)
	{
		pFooter->AddActionEventListener(*this);
	}

	if(pHeader)
	{
		pHeader->AddActionEventListener(*this);
	}

	pFooter->AddItem(footerItem[0]);
	pFooter->AddItem(footerItem[1]);
	pFooter->AddItem(footerItem[2]);
	pFooter->AddItem(footerItem[3]);
	pFooter->AddItem(footerItem[4]);

	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID

    TimelineTableView = new TableView();
    TimelineTableView->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height), true, TABLE_VIEW_SCROLL_BAR_STYLE_FADE_OUT);
    TimelineTableView->SetItemProvider(this);
    TimelineTableView->AddScrollEventListener(*this);


    // Adds the TableView to the form
    AddControl(TimelineTableView);
	return r;
}

result
TizenProjectMainForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
TizenProjectMainForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
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
TizenProjectMainForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
TizenProjectMainForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
TizenProjectMainForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}




void
TizenProjectMainForm::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here


}

void
TizenProjectMainForm::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
TizenProjectMainForm::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
TizenProjectMainForm::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
TizenProjectMainForm::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
TizenProjectMainForm::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
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
TizenProjectMainForm::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

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
    CustomPanel		*cp;
    int item_height;

    content = L"Tizen is a new open platform that enables richer user experience Tizen is a new open platform that enables richer user experience Tizen is a new open platform that enables richer user experience";
    ex_content = L"육군사관학교 34기인 권 총장은 육군본부 계획편제처장, 국방부 정책기획관 취임했다. 육군사관학교 34기인 권 총장은 육군본부 계획편제처장, 국방부 정책기획관 취임했다.";
    Font font;
    font.Construct(FONT_STYLE_PLAIN, 30);





    style = TABLE_VIEW_ANNEX_STYLE_NORMAL;

    cp = new CustomPanel();

    cp->Construct(Rectangle(0,0,itemWidth,500));
    cp->Initialize(L"David Beckham", L"123", content, ex_content, TimelineTableView, pItem, itemIndex);
    item_height = cp->GetPanelHeight();
    cp->AddTouchEventListener(*cp);

    pItem->Construct(Dimension(itemWidth, item_height), style);

    pItem->AddControl(cp);

    ArrCustomPanel.Add(cp);

    return pItem;
}

bool
TizenProjectMainForm::DeleteItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem)
{
    pItem->Destroy();

    return true;
}

void
TizenProjectMainForm::UpdateItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem)
{
    // ....
}

void
TizenProjectMainForm::OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{

}
void
TizenProjectMainForm::OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition)
{

}
void
TizenProjectMainForm::OnScrollStopped (Tizen::Ui::Control &source)
{

}


