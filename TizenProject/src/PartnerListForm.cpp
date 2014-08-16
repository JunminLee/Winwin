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
int ITEM_CREATE_CNT=0;
int Total_COUNT;
int Group_Item_Count[26];
char Group_name[26];
int Group_Scroll[26];
PartnerItem p;
PartnerListForm::PartnerListForm(void) : __pList(null)
{
}

PartnerListForm::~PartnerListForm(void)
{
}

bool
PartnerListForm::Initialize(void)
{
	result r =  Construct(FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR | FORM_STYLE_FOOTER);
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


	Footer* pFooter = GetFooter();
	if (pFooter)
	{
		pFooter->AddActionEventListener(*this);
	}


	head = new Panel();

	head->Construct(Rectangle(0,0, this->GetWidth(), 96));
	head->SetBackgroundColor(Color(0,181,238,255));


	head_center = new Button();
	head_center->Construct(Rectangle(257, 32, 206, 40));
	head_center->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"partnerList2.png")));

	head_left = new Button();
	head_left->Construct(Rectangle(37, 22, 62, 56));
	head_left->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"friend_plz.png")));
	head_left->SetActionId(ID_LIST_PARTNER_LEFT);
	head_left->AddActionEventListener(*this);


	head_right = new Button();
	head_right->Construct(Rectangle(646, 29, 38, 43));
	head_right->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"flag_partner.png")));
	head_right->SetActionId(ID_LIST_PARTNER_RIGHT);
	head_right->AddActionEventListener(*this);

	this->AddControl(head);
	this->AddControl(head_center);
	this->AddControl(head_left);
	this->AddControl(head_right);

	pFooter->AddItem(footerItem[0]);
	pFooter->AddItem(footerItem[1]);
	pFooter->AddItem(footerItem[2]);
	pFooter->AddItem(footerItem[3]);
	pFooter->AddItem(footerItem[4]);
	// Setup back event listener
	SetFormBackEventListener(this);
	CreateGroupedListView();


	String check_name;





	p.Initial(L"Black Widow",L"s-face7.png", L"nationalflag.png","한국" , "축구, 배구", L"hobby.png" );
	ArrPartnerItem.Add(p);
	CheckGorupComponent();

	p.Initial(L"Captain Amerian",L"s-face6.png",L"nationalflag.png","한국","축구, 배구", L"hobby.png");
	ArrPartnerItem.Add(p);
	CheckGorupComponent();

	p.Initial(L"Hawk Eye",L"s-face2.png",L"nationalflag.png","한국","독서", L"hobby.png");
	ArrPartnerItem.Add(p);
	CheckGorupComponent();

	p.Initial(L"Hulk",L"s-face5.png",L"nationalflag.png","한국","공부, 토론", L"hobby.png");
	ArrPartnerItem.Add(p);
	CheckGorupComponent();

	p.Initial(L"Iron Man",L"s-face1.png",L"nationalflag.png","한국","랩, 노래", L"hobby.png");
	ArrPartnerItem.Add(p);
	CheckGorupComponent();

	p.Initial(L"Nick Fury",L"s-face4.png",L"nationalflag.png","한국","족구, 테니스", L"hobby.png");
	ArrPartnerItem.Add(p);
	CheckGorupComponent();

	p.Initial(L"Thor",L"s-face3.png",L"nationalflag.png","한국","헬스", L"hobby.png");
	ArrPartnerItem.Add(p);
	CheckGorupComponent();



	return r;
}

result
PartnerListForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void PartnerListForm::CheckGorupComponent()
{
	wchar_t temp;
	temp = p.GetPartnerFirstName();
	temp-='A';
	ITEM_COUNT[temp]++;

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
	case ID_LIST_PARTNER_LEFT:
		toast = new Toast();
		toast->Construct(Rectangle(30,1100 ,660,70), L"들어온 파트너 요청페이지로 이동합니다", 2000);
		break;
	case ID_LIST_PARTNER_RIGHT:
		toast = new Toast();
		toast->Construct(Rectangle(30,1100 ,660,70), L"언어를 선택합니다", 2000);
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
	__pList = new GroupedListView();
	__pList->Construct(Rectangle(0, 96, GetClientAreaBounds().width, GetClientAreaBounds().height -100), GROUPED_LIST_VIEW_STYLE_INDEXED, true, true);
	__pList->SetBackgroundColor(Color(246,246,246));
	__pList->SetItemProvider(*this);
	__pList->SetFastScrollIndex(L"ABCDEFGHIJKLMNOPQRSTUVWXYZ", false);
	__pList->AddFastScrollListener(*this);
	__pList->AddGroupedListViewItemEventListener(*this);
	__pList->SetSectionColor(Color(0,0,0,255));

	AddControl(__pList);
}

void
PartnerListForm::OnFastScrollIndexSelected(Control& source, Tizen::Base::String& index)
{

	if( !index.CompareTo(L"A" ))
	{
		if(ITEM_COUNT[0]>0)
		{
			__pList->ScrollToItem(Group_Scroll[0], -1);
		}
	}
	else if( !index.CompareTo(L"B"))
	{
		if(ITEM_COUNT[1]>0)
		{
			__pList->ScrollToItem(Group_Scroll[1], -1);
		}
	}
	else if( !index.CompareTo(L"C"))
	{
		if(ITEM_COUNT[2]>0)
		{
			__pList->ScrollToItem(Group_Scroll[2], -1);
		}
	}
	else if( !index.CompareTo(L"D"))
	{
		if(ITEM_COUNT[3]>0)
		{
			__pList->ScrollToItem(Group_Scroll[3], -1);
		}
	}
	else if( !index.CompareTo(L"E"))
	{
		if(ITEM_COUNT[4]>0)
		{
			__pList->ScrollToItem(Group_Scroll[4], -1);
		}
	}
	else if( !index.CompareTo(L"F"))
	{
		if(ITEM_COUNT[5]>0)
		{
			__pList->ScrollToItem(Group_Scroll[5], -1);
		}
	}
	else if( !index.CompareTo(L"G"))
	{
		if(ITEM_COUNT[6]>0)
		{
			__pList->ScrollToItem(Group_Scroll[6], -1);
		}
	}
	else if( !index.CompareTo(L"H"))
	{
		if(ITEM_COUNT[7]>0)
		{
			__pList->ScrollToItem(Group_Scroll[7], -1);
		}
	}
	else if( !index.CompareTo(L"I"))
	{
		if(ITEM_COUNT[8]>0)
		{
			__pList->ScrollToItem(Group_Scroll[8], -1);
		}
	}
	else if( !index.CompareTo(L"J"))
	{
		if(ITEM_COUNT[9]>0)
		{
			__pList->ScrollToItem(Group_Scroll[9], -1);
		}
	}
	else if( !index.CompareTo(L"K"))
	{
		if(ITEM_COUNT[10]>0)
		{
			__pList->ScrollToItem(Group_Scroll[10], -1);
		}
	}
	else if( !index.CompareTo(L"L"))
	{
		if(ITEM_COUNT[11]>0)
		{
			__pList->ScrollToItem(Group_Scroll[11], -1);
		}
	}
	else if( !index.CompareTo(L"M"))
	{
		if(ITEM_COUNT[12]>0)
		{
			__pList->ScrollToItem(Group_Scroll[12], -1);
		}
	}
	else if( !index.CompareTo(L"N"))
	{
		if(ITEM_COUNT[13]>0)
		{
			__pList->ScrollToItem(Group_Scroll[13], -1);
		}
	}
	else if( !index.CompareTo(L"O"))
	{
		if(ITEM_COUNT[14]>0)
		{
			__pList->ScrollToItem(Group_Scroll[14], -1);
		}
	}
	else if( !index.CompareTo(L"P"))
	{
		if(ITEM_COUNT[15]>0)
		{
			__pList->ScrollToItem(Group_Scroll[15], -1);
		}
	}
	else if( !index.CompareTo(L"Q"))
	{
		if(ITEM_COUNT[16]>0)
		{
			__pList->ScrollToItem(Group_Scroll[16], -1);
		}
	}
	else if( !index.CompareTo(L"R"))
	{
		if(ITEM_COUNT[17]>0)
		{
			__pList->ScrollToItem(Group_Scroll[17], -1);
		}
	}
	else if( !index.CompareTo(L"S"))
	{
		if(ITEM_COUNT[18]>0)
		{
			__pList->ScrollToItem(Group_Scroll[18], -1);
		}
	}
	else if( !index.CompareTo(L"T"))
	{
		if(ITEM_COUNT[19]>0)
		{
			__pList->ScrollToItem(Group_Scroll[19], -1);
		}
	}
	else if( !index.CompareTo(L"U"))
	{
		if(ITEM_COUNT[20]>0)
		{
			__pList->ScrollToItem(Group_Scroll[20], -1);
		}
	}
	else if( !index.CompareTo(L"V"))
	{
		if(ITEM_COUNT[21]>0)
		{
			__pList->ScrollToItem(Group_Scroll[21], -1);
		}
	}
	else if( !index.CompareTo(L"W"))
	{
		if(ITEM_COUNT[22]>0)
		{
			__pList->ScrollToItem(Group_Scroll[22], -1);
		}
	}
	else if( !index.CompareTo(L"X"))
	{
		if(ITEM_COUNT[23]>0)
		{
			__pList->ScrollToItem(Group_Scroll[23], -1);
		}
	}
	else if( !index.CompareTo(L"Y"))
	{
		if(ITEM_COUNT[24]>0)
		{
			__pList->ScrollToItem(Group_Scroll[24], -1);
		}
	}
	else if( !index.CompareTo(L"Z"))
	{
		if(ITEM_COUNT[25]>0)
		{
			__pList->ScrollToItem(Group_Scroll[25], -1);
		}
	}

	Invalidate(true);
}


void
PartnerListForm::OnGroupedListViewContextItemStateChanged(Tizen::Ui::Controls::GroupedListView &listView, int groupIndex, int itemIndex, int elementId, Tizen::Ui::Controls::ListContextItemStatus state)
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
			Group_name[groupcount]='A'+i;
			Group_Scroll[i]=groupcount;
			Group_Item_Count[groupcount]=ITEM_COUNT[i];
			Total_COUNT+=ITEM_COUNT[i];
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
		itemCount = Group_Item_Count[0];
		break;
	case GROUP_INDEX1:
		itemCount = Group_Item_Count[1];
		break;
	case GROUP_INDEX2:
		itemCount = Group_Item_Count[2];
		break;
	case GROUP_INDEX3:
		itemCount = Group_Item_Count[3];
		break;
	case GROUP_INDEX4:
		itemCount = Group_Item_Count[4];
		break;
	case GROUP_INDEX5:
		itemCount = Group_Item_Count[5];
		break;
	case GROUP_INDEX6:
		itemCount = Group_Item_Count[6];
		break;
	case GROUP_INDEX7:
		itemCount = Group_Item_Count[7];
		break;
	case GROUP_INDEX8:
		itemCount = Group_Item_Count[8];
		break;
	case GROUP_INDEX9:
		itemCount = Group_Item_Count[9];
		break;
	case GROUP_INDEX10:
		itemCount = Group_Item_Count[10];
		break;
	case GROUP_INDEX11:
		itemCount = Group_Item_Count[11];
		break;
	case GROUP_INDEX12:
		itemCount = Group_Item_Count[12];
		break;
	case GROUP_INDEX13:
		itemCount = Group_Item_Count[13];
		break;
	case GROUP_INDEX14:
		itemCount = Group_Item_Count[14];
		break;
	case GROUP_INDEX15:
		itemCount = Group_Item_Count[15];
		break;
	case GROUP_INDEX16:
		itemCount = Group_Item_Count[16];
		break;
	case GROUP_INDEX17:
		itemCount = Group_Item_Count[17];
		break;
	case GROUP_INDEX18:
		itemCount = Group_Item_Count[18];
		break;
	case GROUP_INDEX19:
		itemCount = Group_Item_Count[19];
		break;
	case GROUP_INDEX20:
		itemCount = Group_Item_Count[20];
		break;
	case GROUP_INDEX21:
		itemCount = Group_Item_Count[21];
		break;
	case GROUP_INDEX22:
		itemCount = Group_Item_Count[22];
		break;
	case GROUP_INDEX23:
		itemCount = Group_Item_Count[23];
		break;
	case GROUP_INDEX24:
		itemCount = Group_Item_Count[24];
		break;
	case GROUP_INDEX25:
		itemCount = Group_Item_Count[25];
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
		text.Append(Group_name[0]);

		break;
	case GROUP_INDEX1:
		text.Append(Group_name[1]);
		break;
	case GROUP_INDEX2:
		text.Append(Group_name[2]);
		break;
	case GROUP_INDEX3:
		text.Append(Group_name[3]);
		break;
	case GROUP_INDEX4:
		text.Append(Group_name[4]);
		break;
	case GROUP_INDEX5:
		text.Append(Group_name[5]);
		break;
	case GROUP_INDEX6:
		text.Append(Group_name[6]);
		break;
	case GROUP_INDEX7:
		text.Append(Group_name[7]);
		break;
	case GROUP_INDEX8:
		text.Append(Group_name[8]);
		break;
	case GROUP_INDEX9:
		text.Append(Group_name[9]);
		break;
	case GROUP_INDEX10:
		text.Append(Group_name[10]);
		break;
	case GROUP_INDEX11:
		text.Append(Group_name[11]);
		break;
	case GROUP_INDEX12:
		text.Append(Group_name[12]);
		break;
	case GROUP_INDEX13:
		text.Append(Group_name[13]);
		break;
	case GROUP_INDEX14:
		text.Append(Group_name[14]);
		break;
	case GROUP_INDEX15:
		text.Append(Group_name[15]);
		break;
	case GROUP_INDEX16:
		text.Append(Group_name[16]);
		break;
	case GROUP_INDEX17:
		text.Append(Group_name[17]);
		break;
	case GROUP_INDEX18:
		text.Append(Group_name[18]);
		break;
	case GROUP_INDEX19:
		text.Append(Group_name[19]);
		break;
	case GROUP_INDEX20:
		text.Append(Group_name[20]);
		break;
	case GROUP_INDEX21:
		text.Append(Group_name[21]);
		break;
	case GROUP_INDEX22:
		text.Append(Group_name[22]);
		break;
	case GROUP_INDEX23:
		text.Append(Group_name[23]);
		break;
	case GROUP_INDEX24:
		text.Append(Group_name[24]);
		break;
	case GROUP_INDEX25:
		text.Append(Group_name[25]);
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
		pItem->Construct(Tizen::Graphics::FloatDimension(itemWidth, 210.0f), style);

		PartnerItem *p;
		p= new PartnerItem;
		ArrPartnerItem.GetAt(ITEM_CREATE_CNT++, *p);
		pItem->AddElement(Rectangle(0, 0, itemWidth, 210.0f), 0, *(static_cast<ICustomElement *>(p)));
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


