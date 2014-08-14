/*
 * Editing.h
 *
 *  Created on: Aug 7, 2014
 *      Author: pji
 */

#ifndef EDITING_H_
#define EDITING_H_

#include "tizenx.h"

using namespace Tizen::Base::Runtime;
using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;


class EditWord
{


public:
	String 		word;
	int			start_index;
	int			end_index;
	int			state;
	int			blank_cnt;
	ArrayListT <String> *arr_insert;

    //Overload the assignment operator.
	EditWord& operator = (const EditWord& rhs);

    //Overload the equivalent operator.
    bool operator ==(const EditWord& rhs) const;

    //Overload the not equivalent operator.
    bool operator !=(const EditWord& rhs) const;
};

class Editing
 	: public Tizen::Ui::Controls::Form
 	, public Tizen::Ui::ITouchEventListener
 	, public Tizen::Base::Runtime::ITimerEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
 	, public Tizen::Ui::Controls::IScrollEventListener
    , public Tizen::Ui::IActionEventListener
    , public Tizen::Ui::IKeyEventListener
 	{
 	private:
 		Panel			*head;
 		Panel			*profile_image_panel;
 		ScrollPanel		*editing_background;

 		String			 str_content;
 		String			popup_edit_string;

 		String			Eng;

 		Canvas 			*pCanvas;

 		Button			*editing_button;
 		Button			*eng_button;
 		Button			*editing_completion_button;

 		ArrayList		arr_text_element;
 		ArrayList		arr_text_element_rect;
 		ArrayList		arr_text_element_highlight;
 		ArrayList		arr_text_element_editing_mark;
 		ArrayList		arr_insert_check;
 		ArrayList		arr_text_insert;


 		ArrayList		arr_edit_text_element;

 		int scroll_end_point;

 		Point touch_point;
 		bool	onHighlightStart;

 		Timer			draw_timer;

 		ContextMenu		*contextMenu;
 		bool			onContextMenu;

 		Rectangle		cur_start_rect;
 		Rectangle		cur_end_rect;

 		Point			cur_start_point;
 		Point			cur_end_point;

 		int				select_cur;

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
 	public:
 		Editing(void);
 		virtual ~Editing(void);
 		virtual result	OnDraw();
 		bool Initialize(void);
 		virtual void 	OnTimerExpired (Timer &timer);

 		void ShowContextMenu(bool show, Point currentPosition);

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
 		virtual result OnInitializing(void);
 		virtual result OnTerminating(void);
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

#endif /* EDITING_H_ */
