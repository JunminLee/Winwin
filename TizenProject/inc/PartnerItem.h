/*
 * PartnerItem.h
 *
 *  Created on: Jul 29, 2014
 *      Author: Gants
 */

#ifndef PARTNERITEM_H_
#define PARTNERITEM_H_

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

class PartnerItem : public Tizen::Ui::Controls::ICustomElement,
public Tizen::Ui::IActionEventListener
{
public:
	void			Initial(String pName, String pProfile, String pnation, String pnation_name, String phobby, String phobby_pic);
	String			GetPartnerName();
	String			GetPartnerNation();
	String			GetPartnerNationflag();
	String			GetPartnerHobby();
	wchar_t			GetPartnerFirstName();
	String			GetProfilePath();
	void			DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap& bitmap);
    virtual bool OnDraw	(Tizen::Graphics::Canvas & 	canvas, const Tizen::Graphics::Rectangle& 	rect, Tizen::Ui::Controls::ListItemDrawingStatus status);
//	void			ActiveButton(const Tizen::Graphics::Point &point, int state);
	Dimension		Dim_Content;
	String Bitmap_Pofile;
	String Partner_Name;

	String partner_nation;
	String partner_hobby;
	String partner_hobby_pic;
	String partner_nation_what;

	Canvas 			*pCanvas;
	Label* nation_flag;
	Label* Person_Hobby;

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
public:
    //Overload the assignment operator.
	PartnerItem& operator = (const PartnerItem& rhs);

    //Overload the equivalent operator.
    bool operator ==(const PartnerItem& rhs) const;

    //Overload the not equivalent operator.
    bool operator !=(const PartnerItem& rhs) const;

    static const int IDC_PARTNERITEM_PROFILE = 431;
};


#endif /* PARTNERITEM_H_ */
