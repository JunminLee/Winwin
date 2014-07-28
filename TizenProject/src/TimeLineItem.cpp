/*
 * TimeLineItem.cpp
 *
 *  Created on: Jul 27, 2014
 *      Author: pji
 */


#include "TimeLineItem.h"


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
TimeLineItem::SetExtendContentViewCheck(bool t)
{
	extend_content_actived_check = t;
}
void
TimeLineItem::Initialize(String pName, String pLocation_and_time, String pContent)
{
	//bitmap_Profile = new Bitmap;
	//bitmap_Flag = new Bitmap;

	//bitmap_Profile = Profile;
	//bitmap_Flag = Flag;
	name = pName;
	location_and_time = pLocation_and_time;
	content = pContent;
	extend_content_actived_check = false;
	pressed_button_state = NONE;
	released_button_state = NONE;

    //RC_extendButton = Rectangle(30, 150, 60, 70);
}

bool
TimeLineItem::OnDraw	(	Tizen::Graphics::Canvas & 	canvas,
const Tizen::Graphics::Rectangle & 	rect,
Tizen::Ui::Controls::ListItemDrawingStatus 	status
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


    RC_itemArea = rect;





    pFont->Construct(FONT_STYLE_PLAIN, 35);
    pFont2->Construct(FONT_STYLE_PLAIN, 25);
    pFont3->Construct(FONT_STYLE_PLAIN, 30);




    canvas.SetFont(*pFont);


    pFont->GetTextExtent(content, content.GetLength(), Dim_Content);

    RC_extendButton = Rectangle(rect.x+30, rect.y+150+Dim_Content.height+30, rect.width-60, 70);
    RC_commentButton = Rectangle(rect.x+30, RC_extendButton.y + 110, RC_extendButton.width/2-10, 70);
    RC_feedbackButton = Rectangle(RC_commentButton.x+RC_commentButton.width+20, RC_extendButton.y + 110, RC_extendButton.width/2-10, 70);

	//canvas.DrawLine(Point(rect.x, rect.y), Point(rect.width, rect.height));
    canvas.FillRectangle(Color(245,245,245,255), Rectangle(rect.x, rect.y, rect.width, rect.height));
    canvas.FillRectangle(Color(255,255,255,255), Rectangle(rect.x, rect.y, rect.width-5, rect.height-5));

	DrawEllipseImage(canvas, Color(255,255,255,255),Rectangle(rect.x + 30, rect.y + 30, 100, 100), *pAppResource->GetBitmapN(L"tizen.png"));
	canvas.DrawBitmap(Rectangle(rect.x+195, rect.y+90, 60,30), *pAppResource->GetBitmapN(L"nationalflag.png"));
	//canvas.FillRectangle(Color(255,255,255,255),Rectangle(rect.x + 30, rect.y + 30, 100, 100));

	canvas.DrawBitmap(RC_extendButton, *pAppResource->GetBitmapN(L"extend_button.png"));
	canvas.DrawBitmap(RC_commentButton, *pAppResource->GetBitmapN(L"comment_button.png"));
	canvas.DrawBitmap(RC_feedbackButton, *pAppResource->GetBitmapN(L"feedback_button.png"));

	canvas.DrawText(Point(rect.x + 200, rect.y + 50), name);
    canvas.SetFont(*pFont3);
	canvas.DrawText(Point(rect.x + 30, rect.y + 150), content);

    pTextElement = new TextElement();
    pTextElement->Construct(location_and_time);

    pFont->GetTextExtent(pTextElement->GetText(), pTextElement->GetText().GetLength(), Dim_Location);

    pEnrichedText->Construct(Dim_Location);


    pEnrichedText->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
    pEnrichedText->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
    pEnrichedText->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
    pEnrichedText->SetTextAbbreviationEnabled(true);

    pTextElement->SetTextColor(Color(160,160,160,255));

    pTextElement->SetFont(*pFont2);
    pEnrichedText->Add(*pTextElement);

	//FillRectangle(canvas, Color(0,0,0,255), Rectangle(rect.x + 30, rect.y + 30, 100, 100));

    canvas.SetFont(*pFont2);
	canvas.DrawText(Point(rect.x+260, rect.y+90), *pEnrichedText);



	if(released_button_state == EXTEND_CONTENT_BUTTON && pressed_button_state == EXTEND_CONTENT_BUTTON)
	{
		AppLog("EXTEND_CONTENT_BUTTON");
	}
	else if(released_button_state == FEEDBACK_BUTTON && pressed_button_state == FEEDBACK_BUTTON)
	{
		AppLog("FEEDBACK_BUTTON");
	}
	else if(released_button_state == COMMENT_BUTTON && pressed_button_state == COMMENT_BUTTON)
	{
		AppLog("COMMENT_BUTTON");
	}
	released_button_state = NONE;
	pressed_button_state = NONE;
}


void
TimeLineItem::DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap &bitmap)
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

TimeLineItem&
TimeLineItem::operator = (const TimeLineItem& rhs)
{
	if(this == &rhs)
	{
		return *this;

	}

	name = rhs.name;
	location_and_time = rhs.location_and_time;
	content = rhs.content;

	return *this;
}

bool
TimeLineItem::operator == (const TimeLineItem& rhs) const
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
TimeLineItem::operator != (const TimeLineItem& rhs) const
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
TimeLineItem::ActiveButton(const Tizen::Graphics::Point &point, int state) // 0 preesed 1 released
{

	if(state == 0)
	{
		if(RC_extendButton.x < point.x && RC_extendButton.y < point.y && (RC_extendButton.x + RC_extendButton.width) > point.x &&
				(RC_extendButton.y + RC_extendButton.height) > point.y)
			pressed_button_state = EXTEND_CONTENT_BUTTON;
		else if(RC_feedbackButton.x < point.x && RC_feedbackButton.y < point.y && (RC_feedbackButton.x + RC_feedbackButton.width) > point.x &&
				(RC_feedbackButton.y + RC_feedbackButton.height) > point.y)
			pressed_button_state = FEEDBACK_BUTTON;
		else if(RC_commentButton.x < point.x && RC_commentButton.y < point.y && (RC_commentButton.x + RC_commentButton.width) > point.x &&
				(RC_commentButton.y + RC_commentButton.height) > point.y)
			pressed_button_state = COMMENT_BUTTON;
	}

	else if(state == 1)
	{
		if(RC_extendButton.x < point.x && RC_extendButton.y < point.y && (RC_extendButton.x + RC_extendButton.width) > point.x &&
				(RC_extendButton.y + RC_extendButton.height) > point.y)
			released_button_state = EXTEND_CONTENT_BUTTON;
		else if(RC_feedbackButton.x < point.x && RC_feedbackButton.y < point.y && (RC_feedbackButton.x + RC_feedbackButton.width) > point.x &&
				(RC_feedbackButton.y + RC_feedbackButton.height) > point.y)
			released_button_state = FEEDBACK_BUTTON;
		else if(RC_commentButton.x < point.x && RC_commentButton.y < point.y && (RC_commentButton.x + RC_commentButton.width) > point.x &&
				(RC_commentButton.y + RC_commentButton.height) > point.y)
			released_button_state = COMMENT_BUTTON;
		else
		{
			pressed_button_state = NONE;
			released_button_state = NONE;
		}
	}
}


