/*
 * EditingScrollPanel.h
 *
 *  Created on: Aug 7, 2014
 *      Author: pji
 */

#ifndef EDITINGSCROLLPANEL_H_
#define EDITINGSCROLLPANEL_H_

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


class EditingScrollPanel
	: public Tizen::Ui::Controls::ScrollPanel
	, public Tizen::Ui::ITouchEventListener
 	, public Tizen::Ui::Controls::IScrollEventListener
 	{

 	private:
 		ArrayList		arr_text_element;
 		ArrayList		arr_text_element_rect;
 		ArrayList		arr_text_element_highlight;

 		String			 str_content;

 		Timer			draw_timer;

 		Point			touch_point;
 		bool			onHighlightStart;

 		Rectangle		cur_start_rect;
 		Rectangle		cur_end_rect;

 		Point			cur_start_point;
 		Point			cur_end_point;

 		int				select_cur;

 		int				start_index;
 	public:
 		EditingScrollPanel(void);
 		virtual ~EditingScrollPanel(void);
 		virtual result	OnDraw();
 		bool Initialize(String content);

 		virtual void 	OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type);
 		virtual void 	OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition);
 		virtual void 	OnScrollStopped (Tizen::Ui::Control &source);

 		virtual result OnInitializing(void);
 		virtual result OnTerminating(void);

 	protected:
 		virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 	};


#endif /* EDITINGSCROLLPANEL_H_ */
