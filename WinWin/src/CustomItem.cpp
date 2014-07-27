/*
 * CustomItem.h
 *
 *  Created on: Jul 21, 2014
 *      Author: pji
 */

#ifndef CUSTOMITEM_H_
#define CUSTOMITEM_H_

#include "tizenx.h"

#define			EXTEND_CONTENT_BUTTON 	200
#define			FEEDBACK_BUTTON			201
#define			COMMENT_BUTTON			202
#define			NONE					203

using namespace Tizen::Graphics;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;

class customitem : public Tizen::Ui::Controls::ICustomElement
{
public:
	void	SetCustomItem(String pName, String pLocation_and_time, String pContent);
	//void OutOfEllipse(Canvas& canvas, const Color& color, const Point& point, const int radius);
	void	SetContentViewCheck(bool t);
	void DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap &bitmap);
	virtual bool OnDraw	(	Tizen::Graphics::Canvas & 	canvas,
	const Tizen::Graphics::Rectangle & 	rect,
	Tizen::Ui::Controls::ListItemDrawingStatus 	status
	);

	void	ActiveButton(const Tizen::Graphics::Point &point, int state);


private:
	Bitmap 			*bitmap_Profile;
	Bitmap			*bitmap_Flag;
	ArrayList		*bitmap_content_array;
	String			name;
	String			location_and_time;
	String			content;
	String			extend_content;



	Dimension		Dim_Content;
	Rectangle		RC_extendButton;
	Rectangle		RC_commentButton;
	Rectangle		RC_feedbackButton;
	Rectangle		RC_itemArea;
	bool			extend_content_actived_check;

	int			pressed_button_state;
	int			released_button_state;

public:
    //Overload the assignment operator.
	customitem& operator = (const customitem& rhs);

    //Overload the equivalent operator.
    bool operator ==(const customitem& rhs) const;

    //Overload the not equivalent operator.
    bool operator !=(const customitem& rhs) const;
};


#endif /* CUSTOMITEM_H_ */
