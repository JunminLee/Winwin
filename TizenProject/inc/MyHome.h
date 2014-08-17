/*
 * MyHome.h
 *
 *  Created on: Aug 16, 2014
 *      Author: pji
 */

#ifndef MyHome_H_
#define MyHome_H_


#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>
#include <FMedia.h>
#include "TimeLineItem.h"
#include "CustomPanel.h"


using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;

class MyHome
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
    , public Tizen::Ui::Controls::ITableViewItemProvider
    , public  Tizen::Ui::Controls::ITableViewItemEventListener

{
public:
		MyHome(void);
	virtual ~MyHome(void);
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);


public:
    // ITableViewItemProvider
    virtual int GetItemCount(void);
    virtual Tizen::Ui::Controls::TableViewItem* CreateItem(int itemIndex, int itemWidth);
    virtual bool DeleteItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
    virtual void UpdateItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
    virtual int GetDefaultItemHeight(void);

public:

	virtual void 	OnTableViewContextItemActivationStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewContextItem *pContextItem, bool activated);
	virtual void 	OnTableViewItemReordered (Tizen::Ui::Controls::TableView &tableView, int itemIndexFrom, int itemIndexTo);
	virtual void 	OnTableViewItemStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewItem *pItem, Tizen::Ui::Controls::TableViewItemStatus status);

private:
	TableView* 		TimelineTableView;
	ArrayList  		ArrCustomPanel;
	Panel			*head;
	Label			*image_panel;

	Button*			button_note;
	Button*			button_flag;
	Button*			button_MyHome;

};


#endif /* MyHome_H_ */
