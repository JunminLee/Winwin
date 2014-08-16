/*
 * ChattingForm.h
 *
 *  Created on: Jul 27, 2014
 *      Author: Gants
 */
////
#ifndef CHATTINGFORM_H_
#define CHATTINGFORM_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>
#include <FMedia.h>
#include "tizenx.h"
#include "ChattingListItem.h"
#include "Toast.h"

using namespace Tizen::Base::Runtime;
using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;

class ChattingForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
 	, public Tizen::Ui::Controls::ITableViewItemProvider
 	, public Tizen::Ui::Controls::IScrollEventListener
 	, public Tizen::Ui::ITouchEventListener
{
public:
	ChattingForm(void);
	virtual ~ChattingForm(void);
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

	  // ITableViewItemProvider
	    virtual int GetItemCount(void);
	    virtual Tizen::Ui::Controls::TableViewItem* CreateItem(int itemIndex, int itemWidth);
	    virtual bool DeleteItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
	    virtual void UpdateItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
	    virtual int GetDefaultItemHeight(void);

	    virtual void 	OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type);
	    virtual void 	OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition);
	    virtual void 	OnScrollStopped (Tizen::Ui::Control &source);

	    ///////////
		virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
		virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
		virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
		virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
		virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
		virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
		virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);

protected:
	static const int ID_FOOTER_ITEM1 = 101;
	static const int ID_FOOTER_ITEM2 = 102;
	static const int ID_FOOTER_ITEM3 = 103;
	static const int ID_FOOTER_ITEM4 = 104;
	static const int ID_FOOTER_ITEM5 = 105;
	static const int ID_CHAT_PARTNER_RIGHT = 371;
	static const int ID_CHAT_PARTNER_LEFT  = 372;

	Button* head_left;
	Button* head_right;
	Toast* toast;
	Panel* head;
	Button* head_Center;
	Button* chatting_header_plus;
	Button* chatting_header_edit;
	TableView* Chatting_List_View;
	ArrayList ArrCustomItem;

};


#endif /* CHATTINGFORM_H_ */
