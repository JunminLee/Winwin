/*
 * ChattingListItem.cpp
 *
 *  Created on: Aug 13, 2014
 *      Author: Gants
 */

#include "tizenx.h"
#include "SceneRegister.h"

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

class ChattingListItem
	: public Tizen::Ui::Container
	, public Tizen::Ui::ITouchEventListener
    , public Tizen::Ui::IActionEventListener
    , public Tizen::Ui::Controls::IListViewItemProvider
{
private:

	String			 str_name;
	String			 str_time;
	String 			str_contents;
	Canvas 			*pCanvas;
	Bitmap			*profile_iamge;
	Bitmap			*national_flag_image;
	int 			_index;
	TableViewItem	*pvi;
	ListView* 		__pListView;
	Rectangle		content_area;
public:
	virtual result	OnDraw();
	bool			Construct(const Rectangle& rect);
	void			Initialize(String name, String time, String content, TableView *pb, TableViewItem *pItem, String profile, String nation, int _index);
	void			DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap &bitmap);
	int				GetPanelHeight();
    virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
    virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
    virtual int GetItemCount(void);
    virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);

protected:
	virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);

};
