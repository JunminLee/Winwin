/*
 * PartnerListForm.cpp
 *
 *  Created on: Jul 27, 2014
 *      Author: Gants
 */

#include "PartnerListForm.h"
#include "AppResourceId.h"
#include "SceneRegister.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;

const int GROUP_INDEX0 = 0;
const int GROUP_INDEX1 = 1;
const int GROUP_INDEX2 = 2;
const int GROUP_INDEX3 = 3;
const int GROUP_INDEX4 = 4;
const int GROUP_INDEX5 = 5;
const int GROUP_INDEX6 = 6;
const int GROUP_INDEX7 = 7;
const int GROUP_INDEX8 = 8;
const int GROUP_INDEX9 = 9;
const int GROUP_INDEX10 = 10;
const int GROUP_INDEX11 = 11;
const int GROUP_INDEX12 = 12;
const int GROUP_INDEX13 = 13;
const int GROUP_INDEX14 = 14;
const int GROUP_INDEX15 = 15;
const int GROUP_INDEX16 = 16;
const int GROUP_INDEX17 = 17;
const int GROUP_INDEX18 = 18;
const int GROUP_INDEX19 = 19;
const int GROUP_INDEX20 = 20;
const int GROUP_INDEX21 = 21;
const int GROUP_INDEX22 = 22;
const int GROUP_INDEX23 = 23;
const int GROUP_INDEX24 = 24;
const int GROUP_INDEX25 = 25;

int ITEM_COUNT[26];

PartnerListForm::PartnerListForm(void)
{
}

PartnerListForm::~PartnerListForm(void)
{
}

bool
PartnerListForm::Initialize(void)
{
	result r =  Construct(FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR | FORM_STYLE_FOOTER | FORM_STYLE_HEADER);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
PartnerListForm::OnInitializing(void)
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

	footerItem[2].SetBackgroundBitmap(FOOTER_ITEM_STATUS_PRESSED,
	inActivation_Image[2].DecodeN(inActivation_Path[2], BITMAP_PIXEL_FORMAT_ARGB8888));

	footerItem[2].SetBackgroundBitmap(FOOTER_ITEM_STATUS_NORMAL,
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

	Header* pHeader = GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetBackgroundBitmap(pAppResource->GetBitmapN(L"header.png"));

	Footer* pFooter = GetFooter();
	if (pFooter)
	{
		pFooter->AddActionEventListener(*this);
	}
	if (pHeader)
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
	CreateGroupedListView();

	PartnerItem p;
	String check_name;
	wchar_t temp;

	p.Initialize(L"Iron Man",L"s-face1.png");
	temp = p.GetPartnerFirstName();
	temp-='a';
	ITEM_COUNT[temp]++;

	ArrPartnerItem.Add(p);
	p.Initialize(L"Hawk Eye",L"s-face2.png");
	temp = p.GetPartnerFirstName();
	temp-='a';
	ITEM_COUNT[temp]++;
	ArrPartnerItem.Add(p);

	p.Initialize(L"Thor",L"s-face3.png");
	ArrPartnerItem.Add(p);
	temp = p.GetPartnerFirstName();
	temp-='a';
	ITEM_COUNT[temp]++;

	p.Initialize(L"Nick Fury",L"s-face4.png");
	ArrPartnerItem.Add(p);
	temp = p.GetPartnerFirstName();
	temp-='a';
	ITEM_COUNT[temp]++;

	p.Initialize(L"Hulk",L"s-face5.png");
	ArrPartnerItem.Add(p);
	temp = p.GetPartnerFirstName();
	temp-='a';
	ITEM_COUNT[temp]++;

	p.Initialize(L"Captain Amerian",L"s-face6.png");
	ArrPartnerItem.Add(p);
	temp = p.GetPartnerFirstName();
	temp-='a';
	ITEM_COUNT[temp]++;

	p.Initialize(L"Black Widow",L"s-face7.png");
	ArrPartnerItem.Add(p);
	temp = p.GetPartnerFirstName();
	temp-='a';
	ITEM_COUNT[temp]++;

	return r;
}

result
PartnerListForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
PartnerListForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
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
PartnerListForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
PartnerListForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
PartnerListForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}
/*
void
PartnerListForm::GetBitmap(void)
{
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

}
*/
void
PartnerListForm::CreateGroupedListView(void)
{
	__pList = static_cast <GroupedListView*> (GetControl(IDC_GROUPEDLISTVIEW1));
	__pList->SetItemProvider(*this);
	__pList->SetFastScrollIndex(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ", false);
	__pList->AddFastScrollListener(*this);
	__pList->AddGroupedListViewItemEventListener(*this);
	AddControl(__pList);
}

void
PartnerListForm::OnFastScrollIndexSelected(Control& source, Tizen::Base::String& index)
{

	if( !index.CompareTo(L"A" ))
	{
		__pList->ScrollToItem(GROUP_INDEX0, -1);
	}
	else if( !index.CompareTo(L"B"))
	{
		__pList->ScrollToItem(GROUP_INDEX1, -1);
	}
	else if( !index.CompareTo(L"C"))
	{
		__pList->ScrollToItem(GROUP_INDEX2, -1);
	}
	else if( !index.CompareTo(L"D"))
	{
		__pList->ScrollToItem(GROUP_INDEX3, -1);
	}
	else if( !index.CompareTo(L"E"))
	{
		__pList->ScrollToItem(GROUP_INDEX4, -1);
	}
	else if( !index.CompareTo(L"F"))
	{
		__pList->ScrollToItem(GROUP_INDEX5, -1);
	}
	else if( !index.CompareTo(L"G"))
	{
		__pList->ScrollToItem(GROUP_INDEX6, -1);
	}
	else if( !index.CompareTo(L"H"))
	{
		__pList->ScrollToItem(GROUP_INDEX7, -1);
	}
	else if( !index.CompareTo(L"I"))
	{
		__pList->ScrollToItem(GROUP_INDEX8, -1);
	}
	else if( !index.CompareTo(L"J"))
	{
		__pList->ScrollToItem(GROUP_INDEX9, -1);
	}
	else if( !index.CompareTo(L"K"))
	{
		__pList->ScrollToItem(GROUP_INDEX10, -1);
	}
	else if( !index.CompareTo(L"L"))
	{
		__pList->ScrollToItem(GROUP_INDEX11, -1);
	}
	else if( !index.CompareTo(L"M"))
	{
		__pList->ScrollToItem(GROUP_INDEX12, -1);
	}
	else if( !index.CompareTo(L"N"))
	{
		__pList->ScrollToItem(GROUP_INDEX13, -1);
	}
	else if( !index.CompareTo(L"O"))
	{
		__pList->ScrollToItem(GROUP_INDEX14, -1);
	}
	else if( !index.CompareTo(L"P"))
	{
		__pList->ScrollToItem(GROUP_INDEX15, -1);
	}
	else if( !index.CompareTo(L"Q"))
	{
		__pList->ScrollToItem(GROUP_INDEX16, -1);
	}
	else if( !index.CompareTo(L"R"))
	{
		__pList->ScrollToItem(GROUP_INDEX17, -1);
	}
	else if( !index.CompareTo(L"S"))
	{
		__pList->ScrollToItem(GROUP_INDEX18, -1);
	}
	else if( !index.CompareTo(L"T"))
	{
		__pList->ScrollToItem(GROUP_INDEX19, -1);
	}
	else if( !index.CompareTo(L"U"))
	{
		__pList->ScrollToItem(GROUP_INDEX20, -1);
	}
	else if( !index.CompareTo(L"V"))
	{
		__pList->ScrollToItem(GROUP_INDEX21, -1);
	}
	else if( !index.CompareTo(L"W"))
	{
		__pList->ScrollToItem(GROUP_INDEX22, -1);
	}
	else if( !index.CompareTo(L"X"))
	{
		__pList->ScrollToItem(GROUP_INDEX23, -1);
	}
	else if( !index.CompareTo(L"Y"))
	{
		__pList->ScrollToItem(GROUP_INDEX24, -1);
	}
	else if( !index.CompareTo(L"Z"))
	{
		__pList->ScrollToItem(GROUP_INDEX25, -1);
	}
	Invalidate(true);
}
void
OnGroupedListViewContextItemStateChanged(Tizen::Ui::Controls::GroupedListView &listView, int groupIndex, int itemIndex, int elementId, Tizen::Ui::Controls::ListContextItemStatus state)
{

}
void
PartnerListForm::OnGroupedListViewItemStateChanged(GroupedListView& listView, int groupIndex, int itemIndex, int elementId, ListItemStatus state)
{
}



void
PartnerListForm::OnGroupedListViewItemSwept(GroupedListView& listView, int groupIndex,  int itemIndex, SweepDirection direction)
{

}

void
PartnerListForm::OnGroupedListViewItemLongPressed(GroupedListView& listView, int groupIndex, int itemIndex, int elementId, bool &  invokeListViewItemCallback  )
{


}

int
PartnerListForm::GetGroupCount(void)
{
	int i, groupcount=0;
	for(i=0; i<26; i++)
	{
		if(ITEM_COUNT[i]!=0)
		{
			groupcount++;
		}
	}
	return groupcount;
}

int
PartnerListForm::GetItemCount(int groupIndex)
{
	int itemCount = 0;
	switch(groupIndex)
	{
	case GROUP_INDEX0:
		itemCount = ITEM_COUNT[0];
		break;
	case GROUP_INDEX1:
		itemCount = ITEM_COUNT[1];
		break;
	case GROUP_INDEX2:
		itemCount = ITEM_COUNT[2];
		break;
	case GROUP_INDEX3:
		itemCount = ITEM_COUNT[3];
		break;
	case GROUP_INDEX4:
		itemCount = ITEM_COUNT[4];
		break;
	case GROUP_INDEX5:
		itemCount = ITEM_COUNT[5];
		break;
	case GROUP_INDEX6:
		itemCount = ITEM_COUNT[6];
		break;
	case GROUP_INDEX7:
		itemCount = ITEM_COUNT[7];
		break;
	case GROUP_INDEX8:
		itemCount = ITEM_COUNT[8];
		break;
	case GROUP_INDEX9:
		itemCount = ITEM_COUNT[9];
		break;
	case GROUP_INDEX10:
		itemCount = ITEM_COUNT[10];
		break;
	case GROUP_INDEX11:
		itemCount = ITEM_COUNT[11];
		break;
	case GROUP_INDEX12:
		itemCount = ITEM_COUNT[12];
		break;
	case GROUP_INDEX13:
		itemCount = ITEM_COUNT[13];
		break;
	case GROUP_INDEX14:
		itemCount = ITEM_COUNT[14];
		break;
	case GROUP_INDEX15:
		itemCount = ITEM_COUNT[15];
		break;
	case GROUP_INDEX16:
		itemCount = ITEM_COUNT[16];
		break;
	case GROUP_INDEX17:
		itemCount = ITEM_COUNT[17];
		break;
	case GROUP_INDEX18:
		itemCount = ITEM_COUNT[18];
		break;
	case GROUP_INDEX19:
		itemCount = ITEM_COUNT[19];
		break;
	case GROUP_INDEX20:
		itemCount = ITEM_COUNT[20];
		break;
	case GROUP_INDEX21:
		itemCount = ITEM_COUNT[21];
		break;
	case GROUP_INDEX22:
		itemCount = ITEM_COUNT[22];
		break;
	case GROUP_INDEX23:
		itemCount = ITEM_COUNT[23];
		break;
	case GROUP_INDEX24:
		itemCount = ITEM_COUNT[24];
		break;
	case GROUP_INDEX25:
		itemCount = ITEM_COUNT[25];
		break;
	default:
		break;
	}
	return itemCount;
}

GroupItem*
PartnerListForm::CreateGroupItem(int groupIndex, float itemWidth)
{
	GroupItem* pItem = new (std::nothrow) GroupItem();
	pItem->Construct(FloatDimension(itemWidth, 76.0f));
	String text(L"");
	switch (groupIndex)
	{
	case GROUP_INDEX0:
		text = L"A";
		break;
	case GROUP_INDEX1:
		text = L"B";
		break;
	case GROUP_INDEX2:
		text = L"C";
		break;
	case GROUP_INDEX3:
		text = L"D";
		break;
	case GROUP_INDEX4:
		text = L"E";
		break;
	case GROUP_INDEX5:
		text = L"F";
		break;
	case GROUP_INDEX6:
		text = L"G";
		break;
	case GROUP_INDEX7:
		text = L"H";
		break;
	case GROUP_INDEX8:
		text = L"I";
		break;
	case GROUP_INDEX9:
		text = L"J";
		break;
	case GROUP_INDEX10:
		text = L"K";
		break;
	case GROUP_INDEX11:
		text = L"L";
		break;
	case GROUP_INDEX12:
		text = L"M";
		break;
	case GROUP_INDEX13:
		text = L"N";
		break;
	case GROUP_INDEX14:
		text = L"O";
		break;
	case GROUP_INDEX15:
		text = L"P";
		break;
	case GROUP_INDEX16:
		text = L"Q";
		break;
	case GROUP_INDEX17:
		text = L"R";
		break;
	case GROUP_INDEX18:
		text = L"S";
		break;
	case GROUP_INDEX19:
		text = L"T";
		break;
	case GROUP_INDEX20:
		text = L"U";
		break;
	case GROUP_INDEX21:
		text = L"V";
		break;
	case GROUP_INDEX22:
		text = L"W";
		break;
	case GROUP_INDEX23:
		text = L"X";
		break;
	case GROUP_INDEX24:
		text = L"Y";
		break;
	case GROUP_INDEX25:
		text = L"Z";
		break;
	default:
		break;
	}
	pItem->SetElement(text, null);
	return pItem;
}

ListItemBase*
PartnerListForm::CreateItem(int groupIndex, int itemIndex, float itemWidth)
{
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
	CustomItem* pItem = new (std::nothrow) CustomItem();
	pItem->Construct(Tizen::Graphics::FloatDimension(itemWidth, 200.0f), style);

	PartnerItem *h;
	//AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	h = new PartnerItem;
	ArrPartnerItem.GetAt(itemIndex, *h);


	return pItem;
}

bool
PartnerListForm::DeleteItem(int groupIndex, int itemIndex, Controls::ListItemBase* pItem, float itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}

bool
PartnerListForm::DeleteGroupItem(int groupIndex, Controls::GroupItem* pItem, float itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}


