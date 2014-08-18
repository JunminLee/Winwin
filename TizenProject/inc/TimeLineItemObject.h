/*
 * TimeLineItemObject.h
 *
 *  Created on: Aug 18, 2014
 *      Author: pji
 */

#ifndef TIMELINEITEMOBJECT_H_
#define TIMELINEITEMOBJECT_H_



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

class TimeLineItemObject
{
public:
	String				id;
	String				writer;
	String				national;
	String				writing_time;
	String				writing_text;
	String				extend_text;
	String				comment_cnt;
	String				mylike;
	String				writer_like_cnt;
	String				edit;


    //Overload the assignment operator.
	TimeLineItemObject& operator = (const TimeLineItemObject& rhs)
	{
		if(this == &rhs)
		{
			return *this;

		}
		id = rhs.id;
		writer = rhs.writer;
		national = rhs.national;
		writing_time = rhs.writing_time;
		writing_text = rhs.writing_text;
		extend_text = rhs.extend_text;
		comment_cnt = rhs.comment_cnt;
		mylike = rhs.mylike;
		writer_like_cnt = rhs.writer_like_cnt;
		edit = rhs.edit;

		return *this;
	}

    //Overload the equivalent operator.
    bool operator ==(const TimeLineItemObject& rhs) const
	{
		bool r = true;
		if(this == &rhs)
		{
			r = true;
		}
		else
		{
			r = false;
		}
		return r;
	}

    //Overload the not equivalent operator.
    bool operator !=(const TimeLineItemObject& rhs) const
	{
		bool r = true;
		if( this == &rhs)
		{
			r = false;
		}
		else
		{
			r = true;
		}
		return r;
	}
};



#endif /* TIMELINEITEMOBJECT_H_ */
