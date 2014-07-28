#include "TizenProjectMainForm.h"
#include "AppResourceId.h"
#include "SceneRegister.h"

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
	footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED, pAppResource->GetBitmapN(L"TimeLine_Act.png"));
	footerItem[0].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,pAppResource->GetBitmapN(L"TimeLine_InAct.png"));

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



    // Creates an instance of ListView
    TimeLineListView = new ListView();
    TimeLineListView->Construct(Rectangle(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height), true, false);
    TimeLineListView->SetItemProvider(*this);
    TimeLineListView->AddListViewItemEventListener(*this);

    // Adds the list view to the form
    AddControl(TimeLineListView);

    TimeLineListView->AddTouchEventListener(*this);
    TimeLineListView->AddScrollEventListener(*this);


    TimeLineItem h;

    h.Initialize(L"Army Conzo", L"한국 12일 오전 11:00시", L"Wow, Amazing Movie");
    h.SetExtendContentViewCheck(true);

    ArrTimeLineItem.Add(h);

    h.Initialize(L"Kermy Antos", L"한국 12일 오전 11:00시", L"Wow, Amazing Movie2");
    h.SetExtendContentViewCheck(true);

    ArrTimeLineItem.Add(h);

    h.Initialize(L"Komyca sar", L"한국 12일 오전 11:00시", L"Wow, Amazing Movie3");
    h.SetExtendContentViewCheck(true);

    ArrTimeLineItem.Add(h);

    h.Initialize(L"Barbieri kho", L"한국 12일 오전 11:00시", L"Wow, Amazing Movie4");
    h.SetExtendContentViewCheck(true);

    ArrTimeLineItem.Add(h);

    h.Initialize(L"Rooney Soccer King", L"한국 12일 오전 11:00시", L"Wow, Amazing Movie5");
    h.SetExtendContentViewCheck(true);

    ArrTimeLineItem.Add(h);

	PostingButtonCheck = true;

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



// IListViewItemEventListener implementation

void
TizenProjectMainForm::OnListViewItemStateChanged(ListView &listView, int index, int elementId, ListItemStatus status)
{
	/*
    switch (elementId)
    {
    case ID_FORMAT_BITMAP:
        {
            // ....
        }
        break;
    case ID_FORMAT_STRING:
        {
            // ....
        	check = true;
        	TimeLineListView->UpdateList();
        }
        break;
    default:
        break;
    }*/
}


void
TizenProjectMainForm::OnListViewContextItemStateChanged(ListView &listView, int index, int elementId, ListContextItemStatus state)
{
}

void
TizenProjectMainForm::OnListViewItemSwept(ListView &listView, int index, SweepDirection direction)
{
    // ....
}

// IListViewItemProvider implementation
ListItemBase*
TizenProjectMainForm::CreateItem(int index, int itemWidth)
{
    // Creates an instance of CustomItem
    pItem = new CustomItem();
    ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;

    TimeLineItem *h;

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

    h = new TimeLineItem;

    ArrTimeLineItem.GetAt(index, *h);


    style = LIST_ANNEX_STYLE_NORMAL;

    if(PostingButtonCheck == true && index == 0)
    {
		pItem->Construct(Dimension(itemWidth, 150), style);
		pItem->AddElement(Rectangle(itemWidth/2 - 200, 20, 400, 100), 102, *pAppResource->GetBitmapN(L"PostingButton.png"),null,null);
    }
	else if(index < itemWidth && index >= 1)
    {

			pItem->Construct(Dimension(itemWidth-120, 630), style);
			//  pItem->AddElement(Rectangle(10, 20, 60, 60), ID_FORMAT_BITMAP, *__pMsg, null, null);
			//pItem->AddElement(Rectangle(10, 20, itemWidth-20, 500), ID_FORMAT_BITMAP, *BackGroundImg, null, null);

			// pItem->AddElement(Rectangle(80, 25, 150, 50), ID_FORMAT_STRING, L"Msg", true);
			//pItem->AddElement(Rectangle(80, 25, 150, 50), ID_FORMAT_STRING, L"Home", true);
			pItem->AddElement(Rectangle(60, 30, itemWidth-120, 600), 0,
					*(static_cast<ICustomElement *>(h)));


		/*if (check == false) {
			pItem->Construct(Dimension(itemWidth, 600), style);
			pItem->AddElement(Rectangle(0, 0, itemWidth, 600), ID_FORMAT_STRING,
					*(static_cast<ICustomElement *>(h)));
			//__pListView->RefreshList(0, LIST_REFRESH_TYPE_ITEM_MODIFY);

		}
*/




		//pItem->
		//pItem->SetContextItem(TimeLineItemContext);
    }
    return pItem;
}

bool
TizenProjectMainForm::DeleteItem(int index, ListItemBase* pItem, int itemWidth)
{
    delete pItem;
    pItem = null;
    return true;
}

int
TizenProjectMainForm::GetItemCount(void)
{
    return 5;
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
	int index = 0, id = 0;
	TimeLineListView->GetItemIndexFromPosition(currentPosition, index, id);
	TimeLineItem h;
	ArrTimeLineItem.GetAt(index,h);

	h.ActiveButton(currentPosition, 0);

	// TODO: Add your implementation codes here

}

void
TizenProjectMainForm::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

	int index = 0, id = 0;
	TimeLineListView->GetItemIndexFromPosition(currentPosition, index, id);
	TimeLineItem h;
	ArrTimeLineItem.GetAt(index,h);

	h.ActiveButton(currentPosition, 1);
}



void
TizenProjectMainForm::OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{

}
void
TizenProjectMainForm::OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition)
{
	AppLog("gg : %d", scrollPosition);

	static int oldScrollPosition = 0;

	if(oldScrollPosition < scrollPosition)
	{
		PostingButtonCheck = false;
	}
	else
	{
		PostingButtonCheck = true;
	}

	oldScrollPosition = scrollPosition;

}
void
TizenProjectMainForm::OnScrollStopped (Tizen::Ui::Control &source)
{

}

