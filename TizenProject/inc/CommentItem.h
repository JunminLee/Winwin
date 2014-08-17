/*
 * CommentItem.h
 *
 *  Created on: Aug 15, 2014
 *      Author: pji
 */

#ifndef COMMENTITEM_H_
#define COMMENTITEM_H_


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


class CommentItem
: public Tizen::Ui::Container
{
private:
	EnrichedText		*enriched_text1;
	EnrichedText		*enriched_text2;
	EnrichedText		*enriched_text3;
	Bitmap				*profile_image;

	TextElement			*text_element_name;
	TextElement			*text_element_time;
	TextElement			*text_element_comment;

	Canvas				*pCanvas;
public:
	virtual 		result	OnDraw();
	bool			Construct(const Rectangle& rect);
	void			Initialize(String name, String time, String comment, String bitmap_path);
};



#endif /* COMMENTITEM_H_ */
