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

#ifndef _MAIN_FORM_H_
#define _MAIN_FORM_H_

#include <FBase.h>
#include <FGraphics.h>
#include <FUi.h>

class MainForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IGroupedListViewItemEventListener
	, public Tizen::Ui::Controls::IGroupedListViewItemProvider
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
{
public:
	MainForm(void);
	virtual ~MainForm(void);
	bool Initialize(void);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnGroupedListViewContextItemStateChanged(Tizen::Ui::Controls::GroupedListView &listView, int groupIndex, int itemIndex, int elementId, Tizen::Ui::Controls::ListContextItemStatus state);
	virtual void OnGroupedListViewItemStateChanged(Tizen::Ui::Controls::GroupedListView &listView, int groupIndex, int itemIndex, int elementId, Tizen::Ui::Controls::ListItemStatus state);
	virtual void OnGroupedListViewItemSwept(Tizen::Ui::Controls::GroupedListView &listView, int groupIndex,  int itemIndex, Tizen::Ui::Controls::SweepDirection direction);

	virtual int GetGroupCount(void);
	virtual int GetItemCount(int groupIndex);
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int groupIndex, int itemIndex, int itemWidth);
	virtual Tizen::Ui::Controls::GroupItem* CreateGroupItem(int groupIndex, int itemWidth);
	virtual bool DeleteItem(int groupIndex, int itemIndex, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
	virtual bool DeleteGroupItem(int groupIndex, Tizen::Ui::Controls::GroupItem* pItem, int itemWidth);

	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId, const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId, const Tizen::Ui::Scenes::SceneId& nextSceneId);

private:
	Tizen::Ui::Controls::GroupedListView* __pGroupedListView;

	static const int GROUPED_LIST_VIEW_CUSTOM_ITEM_TEXT_POS_X = 46;
	static const int GROUPED_LIST_VIEW_CUSTOM_ITEM_HEIGHT = 112;
	static const int GROUPED_LIST_VIEW_GROUP_ITEM_HEIGHT = 80;
	static const int GROUPED_LIST_VIEW_GROUP_ITEM_COUNT = 2;

	static const int VISUAL_ELEMENT_ITEM_COUNT = 6;
	static const int ANIMATION_ITEM_COUNT = 7;

	static const Tizen::Base::String __groupItemName[GROUPED_LIST_VIEW_GROUP_ITEM_COUNT];
	static const Tizen::Base::String __visualElementItemName[VISUAL_ELEMENT_ITEM_COUNT];
	static const Tizen::Base::String __animationItemName[ANIMATION_ITEM_COUNT];
};

#endif //_MAIN_FORM_H_
