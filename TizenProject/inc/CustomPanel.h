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


using namespace Tizen::Base::Runtime;
using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;

class CustomPanel
	: public Tizen::Ui::Container
	, public Tizen::Ui::ITouchEventListener
	, public Tizen::Base::Runtime::ITimerEventListener
    , public Tizen::Ui::IActionEventListener
    , public Tizen::Ui::ITextEventListener
    , public Tizen::Ui::Controls::IListViewItemProvider
{
private:

	String			 str_name;
	String			 str_time;
	String			 str_content;
	String			 str_extend_content;

	Canvas 			*pCanvas;

	Button			*button_profile_image;
	Bitmap			*profile_iamge;
	Bitmap			*national_flag_image;

	EnrichedText	*enriched_content;

	ArrayList		arr_text_element;
	ArrayList		arr_text_element_rect;
	ArrayList		arr_text_element_highlight;

	ArrayList		arr_extend_text_element;
	ArrayList		arr_extend_text_element_rect;
	ArrayList		arr_extend_text_element_highlight;

	bool			isLongTouchPressed;

	int 			panel_height;

	Point			touch_start_point;

	Timer			draw_timer;

	ContextMenu		*contextMenu;
	String			popup_edit_string;
	Popup*			popup;

	bool			onContextMenu;

	Point			touch_point;
	bool			onHighlightStart;

	Rectangle		cur_start_rect;
	Rectangle		cur_end_rect;

	Point			cur_start_point;
	Point			cur_end_point;

	int				select_cur;

	int				start_index;

	Panel			*context_menu;
	Rectangle		context_rect;

	Rectangle		content_area;

	TableViewItem	*pvi;

	int				index;
	bool			extend_content_flag;
	int				extend_content_area_y;

	int name_width;
    ListView* __pListView;

    bool			comment_list_view_flag;
    Button		*button_content;
    Button		*button_like;
    Button		*button_comment;
	Button		*button_name;
public:
	virtual result	OnDraw();
	bool			Construct(const Rectangle& rect);
	void			Initialize(String name, String time, String content, String extend_content, TableView *pb, TableViewItem *pItem, int _index);
	void			DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap &bitmap);
	int				GetPanelHeight();
    void 			ShowPopup(void);
    void 			HidePopup(void);
	void			ShowContextMenu(bool show, Point currentPosition);

	bool			GetHighlightMode();

	virtual void 	OnTimerExpired (Timer &timer);

    virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

    virtual void OnTextValueChanged(const Tizen::Ui::Control& source);
    virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source);


    virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
    virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
    virtual int GetItemCount(void);

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
