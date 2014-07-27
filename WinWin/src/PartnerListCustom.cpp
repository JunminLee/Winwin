#include "PartnerListCustom.h"

using namespace Tizen::Graphics;
using namespace Tizen::App;

#define RED32(color32) static_cast< byte >(0x00F8 & (color32 >> 16))
#define GREEN32(color32) static_cast< byte >(0x00FC & (color32 >> 8))
#define BLUE32(color32) static_cast< byte >(0x00F8 & color32)

#define RGB888ToCOLOR16(red, green, blue) \
                       (static_cast< unsigned short >((static_cast< byte >(blue>>3) \
                       |(static_cast< unsigned short >(static_cast< byte >(green>>2))<<5)) \
                       |((static_cast< unsigned short > (static_cast< byte >((red>>3))<<11)))))

#define COLOR32ToCOLOR16(color32) RGB888ToCOLOR16(RED32(color32), GREEN32(color32), BLUE32(color32))


void
PartnerItem::SetCustomItem(String pName, String pNation, String pEnjoy, String pName2, String pNation2, String pEnjoy2)
{
	name = pName;
	nation = pNation;
	enjoy = pEnjoy;

	name2 = pName2;
	nation2 = pNation2;
	enjoy2 = pEnjoy2;
}

bool
PartnerItem::OnDraw (Tizen::Graphics::Canvas & 	canvas,
const Tizen::Graphics::Rectangle & 	rect,
Tizen::Ui::Controls::ListItemDrawingStatus status
)
{
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
    Font *pFont = new Font;
    Font *pFont2 = new Font;
    Font *pFont3 = new Font;

    Dimension Dim_Location;
    EnrichedText *pEnrichedText = null;
    TextElement* pTextElement = null;

    pEnrichedText = new EnrichedText;
    pTextElement = new TextElement;

    pFont->Construct(FONT_STYLE_PLAIN, 35);
    pFont2->Construct(FONT_STYLE_PLAIN, 25);
    pFont3->Construct(FONT_STYLE_PLAIN, 20);

    canvas.SetFont(*pFont);

    pFont->GetTextExtent(name, name.GetLength(), Dim_Content);

    //Contents = Rectangle(rect.x+3, rect.y+3, rect.width-6, 300);

	DrawEllipseImage(canvas, Color(255,255,255,255),Rectangle(rect.x + 90, rect.y + 30, 180, 180), *pAppResource->GetBitmapN(L"s-face1.png"));
	canvas.DrawBitmap(Rectangle(rect.x+210, rect.y+170, 80,40), *pAppResource->GetBitmapN(L"nationalflag.png"));
	DrawEllipseImage(canvas, Color(255,255,255,255),Rectangle(rect.x + 90 +rect.width/2, rect.y + 30, 180, 180), *pAppResource->GetBitmapN(L"s-face2.png"));
	canvas.DrawBitmap(Rectangle(rect.x+210+rect.width/2, rect.y+170, 80,40), *pAppResource->GetBitmapN(L"nationalflag.png"));

	canvas.DrawText(Point(180-((name.GetLength()/2)*20), rect.y + 230), name);
	canvas.DrawText(Point(180-((name2.GetLength()/2)*20)+rect.width/2, rect.y + 230), name2);



    canvas.SetFont(*pFont3);
	//canvas.DrawText(Point(rect.x + 30, rect.y + 150), content);

    pTextElement = new TextElement();


    pFont->GetTextExtent(pTextElement->GetText(), pTextElement->GetText().GetLength(), Dim_Location);

    pEnrichedText->Construct(Dim_Location);
    pEnrichedText->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
    pEnrichedText->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
    pEnrichedText->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
    pEnrichedText->SetTextAbbreviationEnabled(true);
    pTextElement->SetTextColor(Color(160,160,160,255));
    pTextElement->SetFont(*pFont2);
    pEnrichedText->Add(*pTextElement);
    canvas.SetFont(*pFont2);
	canvas.DrawText(Point(rect.x+260, rect.y+90), *pEnrichedText);



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

String			name;
String			location_and_time;
String			content;

PartnerItem&
PartnerItem::operator = (const PartnerItem& rhs)
{
	if(this == &rhs)
	{
		return *this;

	}

	name = rhs.name;



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
void
PartnerItem::PanelClick(const Tizen::Graphics::Point &point)
{


}


