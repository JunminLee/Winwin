/*
 * Word.h
 *
 *  Created on: Aug 17, 2014
 *      Author: pji
 */

#ifndef WORD_H_
#define WORD_H_

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
	EditWord& operator = (const EditWord& rhs)
	{
		if(this == &rhs)
		{
			return *this;

		}
		word = rhs.word;
		start_index = rhs.start_index;
		end_index = rhs.end_index;
		state = rhs.state;
		blank_cnt = rhs.blank_cnt;
		arr_insert = rhs.arr_insert;

		return *this;
	}

    //Overload the equivalent operator.
    bool operator ==(const EditWord& rhs) const
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
    bool operator !=(const EditWord& rhs) const
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


#endif /* WORD_H_ */
