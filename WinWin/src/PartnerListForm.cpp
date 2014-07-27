/*
 * PartnerListForm.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Gants
 */


//////

#include "PartnerListForm.h"
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
PartnerListForm::PartnerListForm(void)
	: __pList(null)
{
}

PartnerListForm::~PartnerListForm(void)
{
}

bool
PartnerListForm::Initialize(void)
{
	AppLog("welcomePartnerListForm");
	result r =  Construct(FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR | FORM_STYLE_FOOTER);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");


	return true;
}

result
PartnerListForm::OnInitializing(void)
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

	pFooter->AddItem(footerItem[0]);
	pFooter->AddItem(footerItem[1]);
	pFooter->AddItem(footerItem[2]);
	pFooter->AddItem(footerItem[3]);
	pFooter->AddItem(footerItem[4]);
	// Setup back event listener



	SetFormBackEventListener(this);
	GridLayout gridPanelLayout;
	gridPanelLayout.Construct(3, 2);

	Panel* pPanel = new Panel();
	pPanel->Construct(gridPanelLayout, Rectangle(5, 5, 710, 1112));
	    {
	        // Creates instances of Label and an instance of Button
			Panel* pPanel1 = new Panel();
			pPanel1->Construct(Rectangle(0, 0, 200, 200), GROUP_STYLE_NONE);
			pPanel1->SetBackgroundColor(Color(0xea, 0xea, 0xea, 0xea));
			pPanel->AddControl(pPanel1);
			//pPanel1->AddTouchEventListener();

			Panel* pPanel2 = new Panel();
			pPanel2->Construct(Rectangle(0, 0, 200, 200), GROUP_STYLE_NONE);
			pPanel2->SetBackgroundColor(Color(0xea, 0xea, 0xea, 0xea));
			pPanel->AddControl(pPanel2);

			Panel* pPanel3 = new Panel();
			pPanel3->Construct(Rectangle(0, 0, 200, 200), GROUP_STYLE_NONE);
			pPanel3->SetBackgroundColor(Color(0xea, 0xea, 0xea, 0xea));
	        pPanel->AddControl(pPanel3);

	        Panel* pPanel4 = new Panel();
	        pPanel4->Construct(Rectangle(0, 0, 200, 200), GROUP_STYLE_NONE);
	        pPanel4->SetBackgroundColor(Color(0xea, 0xea, 0xea, 0xea));
	        pPanel->AddControl(pPanel4);

	        Panel* pPanel5 = new Panel();
	        pPanel5->Construct(Rectangle(0, 0, 200, 200), GROUP_STYLE_NONE);
	        pPanel5->SetBackgroundColor(Color(0xea, 0xea, 0xea, 0xea));
	        pPanel->AddControl(pPanel5);

	        Panel* pPanel6 = new Panel();
	        pPanel6->Construct(Rectangle(0, 0, 200, 200), GROUP_STYLE_NONE);
	        pPanel6->SetBackgroundColor(Color(0xea, 0xea, 0xea, 0xea));
	        pPanel->AddControl(pPanel6);

	        // Sets position to each label and button in grid layout

	        gridPanelLayout.SetPosition(*pPanel1, 0, 0, 1, 1);
	        gridPanelLayout.SetPosition(*pPanel2, 0, 1, 1, 1);
	        gridPanelLayout.SetPosition(*pPanel3, 1, 0, 1, 1);
	        gridPanelLayout.SetPosition(*pPanel4, 1, 1, 1, 1);
	        gridPanelLayout.SetPosition(*pPanel5, 2, 0, 1, 1);
	        gridPanelLayout.SetPosition(*pPanel6, 2, 1, 1, 1);

	        // Sets stretchability each label and button in grid layout
	        gridPanelLayout.SetColumnStretchable(0, true);
	        gridPanelLayout.SetColumnStretchable(1, true);
	        gridPanelLayout.SetRowStretchable(0, true);
	        gridPanelLayout.SetRowStretchable(1, true);
	        gridPanelLayout.SetRowStretchable(2, true);

	        // Sets spacing
	        gridPanelLayout.SetColumnSpacing(1, 3);
	        gridPanelLayout.SetRowSpacing(2, 3);
	        gridPanelLayout.SetRowSpacing(1, 3);

	    }
		pPanel->SetBackgroundColor(Color(0xc9, 0xc9, 0xc9, 0xc9));
	    // Adds the top panel to the form
	    AddControl(pPanel);
	return E_SUCCESS;
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

bool
PartnerListForm::CreateMainList(void)
{
	__pList = new (std::nothrow) ListView();
	__pList->Construct(FloatRectangle(0.0f, 0.0f, GetClientAreaBoundsF().width, GetClientAreaBoundsF().height), true, SCROLL_STYLE_FADE_OUT);
	__pList->SetItemProvider(*this);
	__pList->AddListViewItemEventListener(*this);
	AddControl(__pList);
	return true;
}

void
PartnerListForm::OnListViewItemStateChanged(ListView& view, int index, int elementId, ListItemStatus status)
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
PartnerListForm::OnListViewItemSwept(ListView& listView, int index, SweepDirection direction)
{

}

void
PartnerListForm::OnListViewContextItemStateChanged(ListView& listView, int index, int elementId, ListContextItemStatus status)
{

}

int
PartnerListForm::GetItemCount(void)
{
	return ITEM_COUNT;
}

bool
PartnerListForm::DeleteItem(int index, ListItemBase* pItem, float itemWidth)
{
	delete pItem;
	pItem = null;
	return false;
}

ListItemBase*
PartnerListForm::CreateItem(int index, float itemWidth)
{
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
	CustomItem* pItem = new (std::nothrow) CustomItem;
	pItem->Construct(CoordinateSystem::AlignToDevice(Tizen::Graphics::FloatDimension(itemWidth, 112.0f)), style);
	FloatRectangle mainListItemRect(26.0f, 32.0f, GetClientAreaBoundsF().width, 60.0f);

	switch(index)
	{
	case 0:
		pItem->AddElement(mainListItemRect, ID_FORMAT_STRING, L"Chatting1", true);
		break;
	case 1:
		pItem->AddElement(mainListItemRect, ID_FORMAT_STRING, L"Chatting2", true);
		break;
	case 2:
		pItem->AddElement(mainListItemRect, ID_FORMAT_STRING, L"Chatting3", true);
		break;
	default:
		break;
	}
	return pItem;
}

