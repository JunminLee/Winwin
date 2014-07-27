//
// Tizen C++ SDK
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <FApp.h>
#include "SceneRegister.h"
#include "MainForm.h"
#include "FormFactory.h"

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::App;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

const String MainForm::__groupItemName[MainForm::GROUPED_LIST_VIEW_GROUP_ITEM_COUNT] =
{
	L"Visual Element",
	L"Animation"
};

const String MainForm::__visualElementItemName[MainForm::VISUAL_ELEMENT_ITEM_COUNT] =
{
	L"Z-order & hit test",
	L"Clip",
	L"Transform matrix",
	L"Surface & content bounds",
	L"Event listener",
	L"Animation provider"
};

const String MainForm::__animationItemName[MainForm::ANIMATION_ITEM_COUNT] = {
	L"Property animation",
	L"Value animation",
	L"Interpolator",
	L"Key frame",
	L"Transaction",
	L"Group",
	L"Gallery"
};

MainForm::MainForm(void)
{
}

MainForm::~MainForm(void)
{
}

bool
MainForm::Initialize(void)
{
	Form::Construct(FORM_STYLE_NORMAL | FORM_STYLE_INDICATOR | FORM_STYLE_HEADER);
	SetFormBackEventListener(this);

	return true;
}

result
MainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"UI visual element");

	Rectangle bounds(0, 0, GetClientAreaBounds().width, GetClientAreaBounds().height);
	__pGroupedListView = new (std::nothrow) GroupedListView();
	__pGroupedListView->Construct(bounds, GROUPED_LIST_VIEW_STYLE_INDEXED, true, false);
	__pGroupedListView->SetItemProvider(*this);
	__pGroupedListView->AddGroupedListViewItemEventListener(*this);
	AddControl(__pGroupedListView);

	return r;
}

result
MainForm::OnTerminating(void)
{
	return E_SUCCESS;
}

void
MainForm::OnFormBackRequested(Form& source)
{
	UiApp* pApp = UiApp::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();
}

void
MainForm::OnGroupedListViewContextItemStateChanged(GroupedListView &listView, int groupIndex, int itemIndex, int elementId, ListContextItemStatus state)
{
}

void
MainForm::OnGroupedListViewItemStateChanged(GroupedListView &listView, int groupIndex, int itemIndex, int elementId, ListItemStatus state)
{
	const wchar_t* id = null;
	switch (groupIndex)
	{
	case 0:
		switch (itemIndex)
		{
		case 0:
			id = SCENE_ZORDER;
			break;

		case 1:
			id = SCENE_CLIP;
			break;

		case 2:
			id = SCENE_TRANSFORM_MATRIX;
			break;

		case 3:
			id = SCENE_SURFACE;
			break;

		case 4:
			id = SCENE_EVENT_LISTENER;
			break;

		case 5:
			id = SCENE_ANIMATION_PROVIDER;
			break;

		default:
			break;
		}
		break;

	case 1:
		switch (itemIndex)
		{
		case 0:
			id = SCENE_PROPERTY_ANIMATION;
			break;

		case 1:
			id = SCENE_VALUE_ANIMATION;
			break;

		case 2:
			id = SCENE_INTERPOLATOR;
			break;

		case 3:
			id = SCENE_KEY_FRAME_ANIMATION;
			break;

		case 4:
			id = SCENE_TRANSACTION;
			break;

		case 5:
			id = SCENE_GROUP_ANIMATION;
			break;

		case 6:
			id = SCENE_GALLERY;
			break;

		default:
			break;
		}
		break;

	default:
		break;
	}

	SceneManager::GetInstance()->GoForward(ForwardSceneTransition(String(id)), null);
}

void
MainForm::OnGroupedListViewItemSwept(GroupedListView &listView, int groupIndex,  int itemIndex, SweepDirection direction)
{
}

int
MainForm::GetGroupCount(void)
{
	return GROUPED_LIST_VIEW_GROUP_ITEM_COUNT;
}

int
MainForm::GetItemCount(int groupIndex)
{
	int itemCount = 0;

	switch (groupIndex)
	{
	case 0:
		itemCount = VISUAL_ELEMENT_ITEM_COUNT;
		break;

	case 1:
		itemCount = ANIMATION_ITEM_COUNT;
		break;

	default:
		break;
    }

    return itemCount;
}

ListItemBase*
MainForm::CreateItem(int groupIndex, int itemIndex, int itemWidth)
{
	String elementText;

	switch(groupIndex)
	{
	case 0:
		elementText = __visualElementItemName[itemIndex];
		break;

	case 1:
		elementText = __animationItemName[itemIndex];
		break;

	default:
		break;
	}

	CustomItem* pItem = new (std::nothrow) CustomItem();
	pItem->Construct(Dimension(itemWidth, GROUPED_LIST_VIEW_CUSTOM_ITEM_HEIGHT), LIST_ANNEX_STYLE_NORMAL);

	Rectangle textRect = Rectangle(GROUPED_LIST_VIEW_CUSTOM_ITEM_TEXT_POS_X, 0, itemWidth - GROUPED_LIST_VIEW_CUSTOM_ITEM_TEXT_POS_X, GROUPED_LIST_VIEW_CUSTOM_ITEM_HEIGHT);
	pItem->AddElement(textRect, 0, elementText, true);

	return pItem;
}

GroupItem*
MainForm::CreateGroupItem(int groupIndex, int itemWidth)
{
	GroupItem* pItem = new (std::nothrow) GroupItem();
	pItem->Construct(Dimension(itemWidth, GROUPED_LIST_VIEW_GROUP_ITEM_HEIGHT));
	pItem->SetElement(__groupItemName[groupIndex], null);

	return pItem;
}

bool
MainForm::DeleteItem(int groupIndex, int itemIndex, ListItemBase* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;

	return true;
}

bool
MainForm::DeleteGroupItem(int groupIndex, GroupItem* pItem, int itemWidth)
{
	delete pItem;
	pItem = null;

	return true;
}

void
MainForm::OnSceneActivatedN(const SceneId& previousSceneId, const SceneId& currentSceneId, IList* pArgs)
{
}

void
MainForm::OnSceneDeactivated(const SceneId& currentSceneId, const SceneId& nextSceneId)
{
}

