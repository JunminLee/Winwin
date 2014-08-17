#ifndef _TIZEN_PROJECT_MAIN_FORM_H_
#define _TIZEN_PROJECT_MAIN_FORM_H_

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
#include <FNet.h>
#include <FWebJson.h>
using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;

class TizenProjectMainForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
 	, public Tizen::Ui::ITouchEventListener
    , public Tizen::Ui::Controls::ITableViewItemProvider
    , public Tizen::Ui::Controls::IScrollEventListener
    , public Tizen::Ui::IFocusEventListener
    , public  Tizen::Ui::Controls::ITableViewItemEventListener
    , public Tizen::Net::Http::IHttpTransactionEventListener
    , public Tizen::Base::Runtime::ITimerEventListener
{
public:
	TizenProjectMainForm(void);
	virtual ~TizenProjectMainForm(void);
	bool Initialize(void);
	virtual void OnTransactionReadyToRead(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int availableBodyLen);
	   virtual void OnTransactionAborted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, result r);
	   virtual void OnTransactionReadyToWrite(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int recommendedChunkSize);
	   virtual void OnTransactionHeaderCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, int headerLen, bool authRequired);
	   virtual void OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction);
	   virtual void OnTransactionCertVerificationRequiredN(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, Tizen::Base::String* pCert);

		virtual void 	OnTimerExpired (Timer &timer);

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

    virtual void 	OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type);
    virtual void 	OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition);
    virtual void 	OnScrollStopped (Tizen::Ui::Control &source);

    virtual void 	OnFocusGained (const Tizen::Ui::Control &source);
    virtual void 	OnFocusLost (const Tizen::Ui::Control &source);
protected:
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
	static const int ID_HEADER_ITEM	 = 106;

public:
	void ShowPopup(void);
	void HidePopup(void);


	virtual void 	OnTableViewContextItemActivationStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewContextItem *pContextItem, bool activated);
	virtual void 	OnTableViewItemReordered (Tizen::Ui::Controls::TableView &tableView, int itemIndexFrom, int itemIndexTo);
	virtual void 	OnTableViewItemStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewItem *pItem, Tizen::Ui::Controls::TableViewItemStatus status);
private:
	result RequestHttpPost(void);
	TableView* 		TimelineTableView;
	ArrayList  		ArrCustomPanel;
	Panel			*head;
	Popup 			*popup;
	ScrollPanel 	*sp;
	TextBox 		*tb;
	Timer			timer;

	Button*			button_my;
	Button*			button_flag;
	Button*			button_winwin;

	Button*			button_text_upload;

	ArrayList		arr_comment_item;
	Tizen::Net::Http::HttpSession* __pHttpSession;

};

#endif	//_TIZEN_PROJECT_MAIN_FORM_H_
