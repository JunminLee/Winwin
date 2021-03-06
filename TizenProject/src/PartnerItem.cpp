/*
 * PartnerItem.cpp
 *
 *  Created on: Jul 30, 2014
 *      Author: Gants
 */

#include "PartnerItem.h"

using namespace Tizen::Graphics;
using namespace Tizen::App;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Base;

#define RED32(color32) static_cast< byte >(0x00F8 & (color32 >> 16))
#define GREEN32(color32) static_cast< byte >(0x00FC & (color32 >> 8))
#define BLUE32(color32) static_cast< byte >(0x00F8 & color32)

#define RGB888ToCOLOR16(red, green, blue) \
                       (static_cast< unsigned short >((static_cast< byte >(blue>>3) \
                       |(static_cast< unsigned short >(static_cast< byte >(green>>2))<<5)) \
                       |((static_cast< unsigned short > (static_cast< byte >((red>>3))<<11)))))

#define COLOR32ToCOLOR16(color32) RGB888ToCOLOR16(RED32(color32), GREEN32(color32), BLUE32(color32))

void
PartnerItem::Initial(String pName, String pProfile, String pnation, String pnation_name, String phobby, String phobby_pic , String want_language, int __level)
{


	Partner_Name = pName;
	Bitmap_Pofile=pProfile;
	partner_nation = pnation;
	partner_nation_what = pnation_name.GetPointer();
	partner_hobby = phobby.GetPointer();
	partner_hobby_pic = phobby_pic;
	str_want_language = want_language;
	_level = __level;





}

bool
PartnerItem::OnDraw	(	Tizen::Graphics::Canvas & 	canvas,
const Tizen::Graphics::Rectangle & 	rect,
Tizen::Ui::Controls::ListItemDrawingStatus 	status
)
{

	canvas.FillRectangle(Color(246,246,246), Rectangle(0,0,720,210));
	canvas.FillRectangle(Color(255,255,255,255), Rectangle(40,15,620,210));

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

    Font *pFont = new Font;
    Font *pFont2 = new Font;
    Font *pFont3 = new Font;
    pFont->Construct(FONT_STYLE_PLAIN, 40);
    pFont2->Construct(FONT_STYLE_PLAIN, 30);
    pFont3->Construct(FONT_STYLE_PLAIN, 25);

    Dimension Dim_Location;



    EnrichedText *pEnrichedText = new EnrichedText();
    TextElement* pTextElement = new TextElement();


	EnrichedText *pEnrichedText1 = new EnrichedText();
	TextElement* pTextElement1 = new TextElement();


    EnrichedText *pEnrichedText2 = new EnrichedText();
    TextElement* pTextElement2 = new TextElement();

     EnrichedText *pEnrichedText3 = new EnrichedText();
     TextElement* pTextElement3 = new TextElement();

     String lang_pic;
     lang_pic.Append(L"blue_point");
     lang_pic.Append(_level);
     lang_pic.Append(L".png");

/*
    nation_flag->Construct(Rectangle(rect.x + 200, rect.y + 70, 50, 30),L"");
    nation_flag->SetBackgroundBitmap(*pAppResource->GetBitmapN(Partner_nation));*/


    canvas.DrawBitmap(Rectangle(rect.x + 220, rect.y + 95, 50, 30),*pAppResource->GetBitmapN(partner_nation));
    canvas.DrawBitmap(Rectangle(rect.x + 225, rect.y + 145, 39, 39),*pAppResource->GetBitmapN(partner_hobby_pic));
    canvas.DrawBitmap(Rectangle(rect.x + 455, rect.y + 107, 43, 13),*pAppResource->GetBitmapN(lang_pic));

    DrawEllipseImage(canvas, Color(249,246,239,255),Rectangle(rect.x + 90, rect.y + 40, 100, 100), *pAppResource->GetBitmapN(Bitmap_Pofile));



	pTextElement->Construct(Partner_Name);

	pFont->GetTextExtent(pTextElement->GetText(), pTextElement->GetText().GetLength(), Dim_Location);
	pEnrichedText->Construct(Dim_Location);
    pEnrichedText->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
	pEnrichedText->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
	pEnrichedText->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
	pEnrichedText->SetTextAbbreviationEnabled(true);

	pTextElement->SetTextColor(Color(40,40,40,255));

	pTextElement->SetFont(*pFont);
	pEnrichedText->Add(*pTextElement);
	canvas.DrawText(Point(rect.x + 220, rect.y + 40), *pEnrichedText);

//////////////////////////////////////////////////////////

	pTextElement1->Construct(str_want_language);

		pFont2->GetTextExtent(pTextElement1->GetText(), pTextElement1->GetText().GetLength(), Dim_Location);
		pEnrichedText1->Construct(Dim_Location);
		pEnrichedText1->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
		pEnrichedText1->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
		pEnrichedText1->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
		pEnrichedText1->SetTextAbbreviationEnabled(true);

		pTextElement1->SetTextColor(Color(140,140,140,255));

		pTextElement1->SetFont(*pFont2);
		pEnrichedText1->Add(*pTextElement1);
		canvas.DrawText(Point(rect.x + 400, rect.y + 94), *pEnrichedText1);










	///////////////////////////////////////////////////

	pTextElement2->Construct(partner_nation_what.GetPointer());

	pFont2->GetTextExtent(pTextElement2->GetText(), pTextElement2->GetText().GetLength(), Dim_Location);
	pEnrichedText2->Construct(Dim_Location);
	pEnrichedText2->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
	pEnrichedText2->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
	pEnrichedText2->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
	pEnrichedText2->SetTextAbbreviationEnabled(true);

	pTextElement2->SetTextColor(Color(140,140,140,255));

	pTextElement2->SetFont(*pFont2);
	pEnrichedText2->Add(*pTextElement2);
	canvas.DrawText(Point(rect.x + 280, rect.y + 94), *pEnrichedText2);




	pTextElement3->Construct(partner_hobby.GetPointer());

	pFont3->GetTextExtent(pTextElement3->GetText(), pTextElement3->GetText().GetLength(), Dim_Location);
	pEnrichedText3->Construct(Dim_Location);
	pEnrichedText3->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
	pEnrichedText3->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
	pEnrichedText3->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
	pEnrichedText3->SetTextAbbreviationEnabled(true);

	pTextElement3->SetTextColor(Color(140,140,140,255));

	pTextElement3->SetFont(*pFont3);
	pEnrichedText3->Add(*pTextElement3);
	canvas.DrawText(Point(rect.x + 280, rect.y + 149), *pEnrichedText3);

	return 0;
}


void
PartnerItem::DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap &bitmap)
{
   BufferInfo bufferInfo;
   int x;
   int y;
   int offset;
   byte srcR;
   byte srcG;
   byte srcB;
   byte destR;
   byte destG;
   byte destB;
   int alphaLevel;
   int srcLevel;
   int destLevel;
   int r;
   int g;
   int b;
   unsigned short color16;
   unsigned short* pBuffer16;
   unsigned long* pBuffer32;
   int bufferWidth;
   int bufferX1;
   int bufferY1;
   int bufferX2;
   int bufferY2;
   int x1;
   int y1;
   int x2;
   int y2;
   int width;
   int height;

   canvas.DrawBitmap(rect, bitmap);
   canvas.Lock(bufferInfo);

   x1 = rect.x;
   y1 = rect.y;
   width  = rect.width;
   height = rect.height;

   x2 = x1 + width - 1;
   y2 = y1 + height - 1;

   bufferX1 = 0;
   bufferY1 = 0;
   bufferX2 = bufferX1 + bufferInfo.width - 1;
   bufferY2 = bufferY1 + bufferInfo.height - 1;

   if (x1 > bufferX2 || x2 < bufferX1)
   {
      return;
   }
   if (y1 > bufferY2 || y2 < bufferY1)
   {
      return;
   }
   if (x1 < bufferX1)
   {
      x1 = bufferX1;
   }
   if (x2 > bufferX2)
   {
      x2 = bufferX2;
   }
   if (y1 < bufferY1)
   {
      y1 = bufferY1;
   }
   if (y2 > bufferY2)
   {
      y2 = bufferY2;
   }
   width  = x2 - x1 + 1;
   height = y2 - y1 + 1;

   bufferWidth = bufferInfo.width;
   int k = 0;
   if (bufferInfo.bitsPerPixel == 16)
   {
      color16 = static_cast< unsigned short >(COLOR32ToCOLOR16 (color.GetRGB32()));
      pBuffer16 = static_cast< unsigned short* >(bufferInfo.pPixels);
      alphaLevel = 100 - static_cast< int >(static_cast< float >(color.GetAlpha() / 2.56));
      srcLevel = alphaLevel;
      destLevel = 100 - alphaLevel;

      srcR = static_cast< byte >(color16 >> 11);
      srcG = static_cast< byte >((color16 >> 6) & 0x001F);
      srcB = static_cast< byte >(color16 & 0x001F);

      for (y = y1; y < y1 + height; y++)
      {
         for (x = x1; x < x1 + width; x++)
         {
        	k = ((y-y1)-height/2)*((y-y1)-height/2) + ((x-x1)-height/2) * ((x-x1)-height/2);
        	k = sqrt(k);
        	if(k>(height/2))
        	{
				offset = bufferWidth * y + x;
				destR = static_cast< byte >(pBuffer16[offset] >> 11);
				destG = static_cast< byte >((pBuffer16[offset] >> 6) & 0x001F);
				destB = static_cast< byte >(pBuffer16[offset] & 0x001F);
				r = (destR * destLevel + srcR * srcLevel) / 100;
				g = (destG * destLevel + srcG * srcLevel) / 100;
				b = (destB * destLevel + srcB * srcLevel) / 100;
				destR = static_cast< byte >(r);
				destG = static_cast< byte >(g);
				destB = static_cast< byte >(b);
				pBuffer16[offset] = static_cast< unsigned short >((destR << 11) | (destG << 6) | (destB));
        	}
         }
      }
   }
   else if (bufferInfo.bitsPerPixel == 32)
   {
      pBuffer32 = static_cast< unsigned long* >(bufferInfo.pPixels);

      for (y = y1; y < y1 + height; y++)
      {
         for (x = x1; x < x1 + width; x++)
         {
         	k = ((y-y1)-height/2)*((y-y1)-height/2) + ((x-x1)-height/2) * ((x-x1)-height/2);
         	k = sqrt(k);
         	if(k>(height/2))
         	{
 				offset = bufferWidth * y + x;
 				pBuffer32[offset] = color.GetRGB32();
         	}
         }
      }
   }

   canvas.Unlock();
}



PartnerItem&
PartnerItem::operator = (const PartnerItem& rhs)
{
	if(this == &rhs)
	{
		return *this;

	}

	Partner_Name = rhs.Partner_Name;
	Bitmap_Pofile=rhs.Bitmap_Pofile;
	partner_hobby = rhs.partner_hobby;
	partner_hobby_pic = rhs.partner_hobby_pic;
	partner_nation = rhs.partner_nation;
	partner_nation_what = rhs.partner_nation_what;
	str_want_language = rhs.str_want_language;
	_level = rhs._level;

	return *this;
}

bool
PartnerItem::operator == (const PartnerItem& rhs) const
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

bool
PartnerItem::operator != (const PartnerItem& rhs) const
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


String	PartnerItem::GetPartnerName()
{
	return Partner_Name;
}
wchar_t	PartnerItem::GetPartnerFirstName()
{
	wchar_t t;
	String lower;
	Partner_Name.ToUpperCase(lower);
	lower.GetCharAt(0,t);
	return t;
}
String PartnerItem::GetProfilePath()
{
	return Bitmap_Pofile;
}
String			PartnerItem::GetPartnerNation()
{
	return partner_nation_what;

}
String			PartnerItem::GetPartnerNationflag()
{
	return partner_nation;
}
String			PartnerItem::GetPartnerHobby()
{
	return partner_hobby;
}


void PartnerItem::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	switch(actionId)
		{


		}

}
