/*
 * PartnerListCustom.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Gants
 */

#include "tizenx.h"

using namespace Tizen::Graphics;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;

class PartnerItem : public Tizen::Ui::Controls::ICustomElement
{
public:
	void	SetCustomItem(String pName, String pNation, String pEnjoy, String pName2, String pNation2, String pEnjoy2);
	void DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap &bitmap);
	virtual bool OnDraw	(	Tizen::Graphics::Canvas & 	canvas,
	const Tizen::Graphics::Rectangle & 	rect,
	Tizen::Ui::Controls::ListItemDrawingStatus 	status
	);
	void	PanelClick(const Tizen::Graphics::Point &point);

private:
	Bitmap 			*bitmap_Profile;
	Bitmap			*bitmap_Flag;
	ArrayList		*bitmap_content_array;
	String			name;
	String			enjoy;
	String 			nation;
	Dimension		Dim_Content;
	Rectangle		Contents;

	Bitmap 			*bitmap_Profile2;
	Bitmap			*bitmap_Flag2;
	ArrayList		*bitmap_content_array2;
	String			name2;
	String			enjoy2;
	String 			nation2;
	Dimension		Dim_Content2;
	Rectangle		Contents2;

public:
    //Overload the assignment operator.
	PartnerItem& operator = (const PartnerItem& rhs);

    //Overload the equivalent operator.
    bool operator ==(const PartnerItem& rhs) const;

    //Overload the not equivalent operator.
    bool operator !=(const PartnerItem& rhs) const;
};



