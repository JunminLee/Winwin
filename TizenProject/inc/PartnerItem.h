/*
 * PartnerItem.h
 *
 *  Created on: Jul 29, 2014
 *      Author: Gants
 */

#ifndef PARTNERITEM_H_
#define PARTNERITEM_H_

#include "tizenx.h"


using namespace Tizen::Graphics;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;


class PartnerItem : public Tizen::Ui::Controls::ICustomElement
{
public:
	void			Initialize(String pName, String pProfile);
	String			GetPartnerName();
	wchar_t			GetPartnerFirstName();
	String			GetProfilePath();
	void			DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap& bitmap);
    virtual bool OnDraw	(Tizen::Graphics::Canvas & 	canvas, const Tizen::Graphics::Rectangle& 	rect, Tizen::Ui::Controls::ListItemDrawingStatus status);
//	void			ActiveButton(const Tizen::Graphics::Point &point, int state);
	Dimension		Dim_Content;
	String Bitmap_Pofile;
	String name;
public:
    //Overload the assignment operator.
	PartnerItem& operator = (const PartnerItem& rhs);

    //Overload the equivalent operator.
    bool operator ==(const PartnerItem& rhs) const;

    //Overload the not equivalent operator.
    bool operator !=(const PartnerItem& rhs) const;
};


#endif /* PARTNERITEM_H_ */
