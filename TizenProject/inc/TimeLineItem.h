/*
 * TimeLineItem.h
 *
 *  Created on: Jul 27, 2014
 *      Author: pji
 */

#ifndef TIMELINEITEM_H_
#define TIMELINEITEM_H_


#include "tizenx.h"

#define					EXTEND_CONTENT_BUTTON		200
#define					FEEDBACK_BUTTON				201
#define					COMMENT_BUTTON				202
#define					NONE						203

using namespace Tizen::Graphics;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;


class TimeLineItem
{
public:
	void			Initialize(String pName, String pLocation_and_time, String pContent);
	void			SetExtendContentViewCheck(bool t);
	void			DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap& bitmap);
	void			ActiveButton(const Tizen::Graphics::Point &point, int state);

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

public:
    //Overload the assignment operator.
	TimeLineItem& operator = (const TimeLineItem& rhs);

    //Overload the equivalent operator.
    bool operator ==(const TimeLineItem& rhs) const;

    //Overload the not equivalent operator.
    bool operator !=(const TimeLineItem& rhs) const;
};


#endif /* TIMELINEITEM_H_ */
