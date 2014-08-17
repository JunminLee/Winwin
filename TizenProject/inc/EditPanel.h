/*
 * EditPanel.h
 *
 *  Created on: Aug 17, 2014
 *      Author: pji
 */

#ifndef EDITPANEL_H_
#define EDITPANEL_H_


#include "tizenx.h"
#include "Editing.h"
#include "Word.h"

#define	NONE 0
#define DELETED 1
#define REPLACED 2
#define ATTACHED 3;
#define ATTACHED_AND_REPLACED 4;
#define INSERTED 5

using namespace Tizen::Base::Runtime;
using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;


class EditPanel
 	: public Tizen::Ui::Controls::Panel
 	, public Tizen::Ui::ITouchEventListener
 	, public Tizen::Base::Runtime::ITimerEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
 	, public Tizen::Ui::Controls::IScrollEventListener
    , public Tizen::Ui::IActionEventListener
    , public Tizen::Ui::IKeyEventListener
 	{
 	private:
 		String			 str_content;
 		String			popup_edit_string;

 		String			Eng;

 		Canvas 			*pCanvas;

 		ArrayList		arr_text_element;
 		ArrayList		arr_text_element_rect;
 		ArrayList		arr_text_element_highlight;
 		ArrayList		arr_text_element_editing_mark;
 		ArrayList		arr_insert_check;
 		ArrayList		arr_text_insert;
    	ArrayList		arr_binding_start_and_end;
    	ArrayList		arr_memo;
    	ArrayList		arr_memo_rect;
 		ArrayList		arr_edit_text_element;

 		Point select_index_edit;
 		int scroll_end_point;

 		Point touch_point;
 		bool	onHighlightStart;

 		Timer			draw_timer;

 		ContextMenu		*contextMenu;
 		ContextMenu 	*contextMenu2;
 		bool			onContextMenu;

 		Rectangle		cur_start_rect;
 		Rectangle		cur_end_rect;

 		Point			cur_start_point;
 		Point			cur_end_point;

 		int				select_cur;
 		int				like_cnt;
 		int				start_index;
 		int				end_index;

 		Popup*			popup;

        EditArea* popup_ori_area;
        int		  ori_word_cnt;

        EditArea* popup_edit_area;
        int		  edit_area_length;
        int		  edt_word_cnt;

        EditArea* popup_explain;

        int		  minus[200];
        int		  plus[200];

        int		  plus_cnt;
        int		  minus_cnt;

        ArrayListT<EditWord>		arr_edit_word;
        ArrayListT<EditWord>		arr_ori_word;

    	Label *cur_label;

    	bool	 onEditClick;

 	public:

        int  scroll_state;
        int  real_position;
        int  real_position_end;

    	bool		GetHighligtmode()
    	{
    		return onHighlightStart;
    	}
    	EditPanel(void);
 		virtual ~EditPanel(void);
 		virtual result	OnDraw();
 		bool Construct(String content, bool me);
 		virtual void 	OnTimerExpired (Timer &timer);

 		void ShowContextMenu(bool show, Point currentPosition, int menu1_or_menu2);

 		virtual void 	OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type);
 		virtual void 	OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition);
 		virtual void 	OnScrollStopped (Tizen::Ui::Control &source);

 		virtual void 	OnKeyLongPressed (const Tizen::Ui::Control &source, Tizen::Ui::KeyCode keyCode);
 		virtual void 	OnKeyPressed (const Tizen::Ui::Control &source, Tizen::Ui::KeyCode keyCode);
 		virtual void 	OnKeyReleased (const Tizen::Ui::Control &source, Tizen::Ui::KeyCode keyCode);

 	    void 			ShowPopup(void);
 	    void 			HidePopup(void);

 	    void			Attached_decision(void);
 	    void			SyncText(void);
 	    void			TextCorrecting(void);

 	private:
 		virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
 		virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
 		virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
 									   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
 		virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
 										const Tizen::Ui::Scenes::SceneId& nextSceneId);

 	protected:
 		virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 	};




#endif /* EDITPANEL_H_ */
