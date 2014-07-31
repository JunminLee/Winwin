/*
 * CustomPanel.h
 *
 *  Created on: Jul 31, 2014
 *      Author: pji
 */

#ifndef CUSTOMPANEL_H_
#define CUSTOMPANEL_H_

#include "tizenx.h"


#define RED32(color32) static_cast< byte >(0x00F8 & (color32 >> 16))
#define GREEN32(color32) static_cast< byte >(0x00FC & (color32 >> 8))
#define BLUE32(color32) static_cast< byte >(0x00F8 & color32)

#define RGB888ToCOLOR16(red, green, blue) \
                       (static_cast< unsigned short >((static_cast< byte >(blue>>3) \
                       |(static_cast< unsigned short >(static_cast< byte >(green>>2))<<5)) \
                       |((static_cast< unsigned short > (static_cast< byte >((red>>3))<<11)))))

#define COLOR32ToCOLOR16(color32) RGB888ToCOLOR16(RED32(color32), GREEN32(color32), BLUE32(color32))


#define STRIATION_SPACING			50

using namespace Tizen::Graphics;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Runtime;
using namespace Tizen::Ui::Controls;

class CustomPanel
	: public Tizen::Ui::Container
	, public Tizen::Ui::ITouchEventListener
	, public Tizen::Base::Runtime::ITimerEventListener
    , public Tizen::Ui::IActionEventListener
    , public Tizen::Ui::ITextEventListener
{
private:
	String			str_name;
	String			str_time;
	String			str_content;

	Canvas 			*pCanvas;

	EnrichedText	*enriched_content;

	ArrayList		arr_text_element;
	ArrayList		arr_text_element_rect;
	ArrayList		arr_text_element_highlight;

	bool			isLongTouchPressed;

	int 			panel_height;

	Point			touch_start_point;

	Timer			draw_timer;

	ContextMenu		*contextMenu;
	String			popup_edit_string;
	Popup*			popup;

	bool			onContextMenu;

public:
	virtual result	OnDraw();
	bool			Construct(const Rectangle& rect);
	void			Initialize(String name, String time, String content);
	void			DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap &bitmap);
	int				GetPanelHeight();
    void 			ShowPopup(void);
    void 			HidePopup(void);
	void			ShowContextMenu(bool show, Point currentPosition);

	virtual void 	OnTimerExpired (Timer &timer);

    virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

    virtual void OnTextValueChanged(const Tizen::Ui::Control& source);
    virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source);


protected:
	virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);

};


#endif /* CUSTOMPANEL_H_ */
