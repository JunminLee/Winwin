/*
 * ChattingListItem.cpp
 *
 *  Created on: Aug 13, 2014
 *      Author: Gants
 */

#include "ChattingListItem.h"
#include "AppResourceId.h"
#include "SceneRegister.h"

static TableView *table_view = null;

result
ChattingListItem::OnDraw()
{

	pCanvas = this->GetCanvasN();

	pCanvas->FillRectangle(Color(255,255,255,255), Rectangle(50,15,620,170));
	pCanvas->DrawBitmap(Rectangle(80,50,100,100), *profile_iamge);
	pCanvas->DrawBitmap(Rectangle(140,130,50,30), *national_flag_image);

	Dimension Dim_Location;
	Font* font_name;
	Font* font_contents;
	Font* font_time;

	font_name = new Font();
	font_contents= new Font();
	font_time= new Font();

	font_name->Construct(FONT_STYLE_PLAIN, 35);
	font_contents->Construct(FONT_STYLE_PLAIN, 32);
	font_time->Construct(FONT_STYLE_PLAIN, 25);
//////////////////////////////////////////////////////////////////////////////////////////////////////
	EnrichedText *pEnrichedText_Name = new EnrichedText();
	TextElement* pTextElement_Name = new TextElement();

	pTextElement_Name->Construct(str_name);

	font_name->GetTextExtent(pTextElement_Name->GetText(), pTextElement_Name->GetText().GetLength(), Dim_Location);
	pEnrichedText_Name->Construct(Dim_Location);
    pEnrichedText_Name->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
	pEnrichedText_Name->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
	pEnrichedText_Name->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
	pEnrichedText_Name->SetTextAbbreviationEnabled(true);

	pTextElement_Name->SetTextColor(Color(80,80,80,255));

	pTextElement_Name->SetFont(*font_name);
	pEnrichedText_Name->Add(*pTextElement_Name);
	pCanvas->DrawText(Point(200,55), *pEnrichedText_Name);
	///////////////////////////////////////////////////////////////////////////////////////////////////////

	EnrichedText *pEnrichedText_Content = new EnrichedText();
	TextElement* pTextElement_Content = new TextElement();

	pTextElement_Content->Construct(str_contents);

	font_contents->GetTextExtent(pTextElement_Content->GetText(), pTextElement_Content->GetText().GetLength(), Dim_Location);
	pEnrichedText_Content->Construct(Dim_Location);
    pEnrichedText_Content->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
	pEnrichedText_Content->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
	pEnrichedText_Content->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
	pEnrichedText_Content->SetTextAbbreviationEnabled(true);

	pTextElement_Content->SetTextColor(Color(123,123,123,255));

	pTextElement_Content->SetFont(*font_contents);
	pEnrichedText_Content->Add(*pTextElement_Content);
	pCanvas->DrawText(Point(200,100), *pEnrichedText_Content);
	//////////////////////////////////////////////////////////////////////////////////////////////////////



	EnrichedText *pEnrichedText_Time = new EnrichedText();
	TextElement* pTextElement_Time = new TextElement();

	pTextElement_Time->Construct(str_time);

	font_time->GetTextExtent(pTextElement_Time->GetText(), pTextElement_Time->GetText().GetLength(), Dim_Location);
	pEnrichedText_Time->Construct(Dim_Location);
	pEnrichedText_Time->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
	pEnrichedText_Time->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
	pEnrichedText_Time->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
	pEnrichedText_Time->SetTextAbbreviationEnabled(true);

	pTextElement_Time->SetTextColor(Color(180,180,180,255));

	pTextElement_Time->SetFont(*font_time);
	pEnrichedText_Time->Add(*pTextElement_Time);
	pCanvas->DrawText(Point(550,20), *pEnrichedText_Time);



/*
	delete pEnrichedText_Name;
	delete pTextElement_Name;

	delete pEnrichedText_Content;
	delete pTextElement_Time;

	delete pEnrichedText_Time;
	delete pTextElement_Time;


	delete font_name;
	delete font_contents;
	delete font_time;

*/


}



bool
ChattingListItem::Construct(const Rectangle& rect)
{
	result r = Container::Construct(rect, true, true);
	return true;
}

int
ChattingListItem::GetPanelHeight()
{
	return 200;
}
void
ChattingListItem::Initialize(String name, String time, String content , TableView *pb, TableViewItem *pItem, String profile, String nation, int __index)
{


	/*
	 *
	String			 str_name;
	String			 str_time;
	Canvas 			*pCanvas;
	Bitmap			*profile_iamge;
	Bitmap			*national_flag_image;
	int 			index;
	TableViewItem	*pvi;
	ListView* 		__pListView;
	 */

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Dimension tmp_dim;

	Font font;
	font.Construct(FONT_STYLE_PLAIN, 25);
	bool ischecked = false;

	str_name = name;
	str_time = time;
	str_contents= content;

	if(str_contents.GetLength()>30)
		ischecked= true;
	str_contents.SetLength(30);
	if(ischecked)
	{
		str_contents.Append(L"...");
		ischecked=false;
	}
	national_flag_image = pAppResource->GetBitmapN(nation);
	profile_iamge = pAppResource->GetBitmapN(profile);
	_index = __index;
	pvi = pItem;

	if(table_view==null)
		table_view = pb;

	content_area.SetBounds(30,30,this->GetWidth()-60, this->GetHeight()-60);

}




void
ChattingListItem::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here


}

void
ChattingListItem::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
ChattingListItem::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
ChattingListItem::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}

void
ChattingListItem::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{



}


void
ChattingListItem::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();

	if(_index == 0)
	{
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_CHATTING, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
	}

}

void
ChattingListItem::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}

void
ChattingListItem::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{


    switch (actionId)
    {


    default:
        break;
    }
}




ListItemBase*
ChattingListItem::CreateItem(int index, int itemWidth)
{
    // Creates an instance of CustomItem

    CustomItem* pItem = new CustomItem();
    ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
/*
    switch (index % 4)
    {
    case 0:
        {
            style = LIST_ANNEX_STYLE_NORMAL;
            pItem->Construct(Dimension(itemWidth,50), style);
            pItem->AddElement(Rectangle(0, 0, itemWidth, 50), 555, L"Home", true);
        }
        break;
    case 1:
        {
            style = LIST_ANNEX_STYLE_NORMAL;
            pItem->Construct(Dimension(itemWidth,50), style);
            pItem->AddElement(Rectangle(0, 0, 150, 50), 555, L"Home", true);
        }
        break;
    case 2:
        {
            style = LIST_ANNEX_STYLE_NORMAL;
            pItem->Construct(Dimension(itemWidth,50), style);
            pItem->AddElement(Rectangle(0, 0, 150, 50), 555, L"Home", true);
        }
        break;
    case 3:
        {
            style = LIST_ANNEX_STYLE_NORMAL;
            pItem->Construct(Dimension(itemWidth,50), style);
            pItem->AddElement(Rectangle(0, 0, 150, 50), 555, L"Home", true);
        }
        break;
    default:
        break;
    }
*/
    return pItem;
}


int
ChattingListItem::GetItemCount(void)
{
    return 15;
}

bool
ChattingListItem::DeleteItem(int index, ListItemBase* pItem, int itemWidth)
{
    delete pItem;
    pItem = null;
    return true;
}

void
ChattingListItem::DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap &bitmap)
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

