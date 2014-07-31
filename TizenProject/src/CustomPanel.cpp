/*
 * CustomPanel.cpp
 *
 *  Created on: Jul 31, 2014
 *      Author: pji
 */



#include "CustomPanel.h"



result
CustomPanel::OnDraw()
{
	int i;
	Rectangle *tmp_rect;
	String	  *tmp_string;
	Boolean	  *tmp_highlight;


    Font font;
    font.Construct(FONT_STYLE_PLAIN, 30);

	pCanvas = this->GetCanvasN();

    pCanvas->SetFont(font);

	//pCanvas->FillRectangle(Color(200,100,0,255), Rectangle(0,0,300,300));

	for(i=0; i<arr_text_element.GetCount(); i++)
	{
		tmp_rect = static_cast< Rectangle* > (arr_text_element_rect.GetAt(i));
		tmp_string = static_cast< String *> (arr_text_element.GetAt(i));
		tmp_highlight = static_cast <Boolean *> (arr_text_element_highlight.GetAt(i));
		if(tmp_highlight->ToBool() == true)
		{
			pCanvas->DrawText(Point(tmp_rect->x, tmp_rect->y), *tmp_string, Color(0,255,0,150));
		}
		else
		{
			pCanvas->DrawText(Point(tmp_rect->x, tmp_rect->y), *tmp_string);
		}
		pCanvas->DrawRectangle(*tmp_rect);
	}
}



bool
CustomPanel::Construct(const Rectangle& rect)
{
	result r = Container::Construct(rect, true, true);
	return true;
}

int
CustomPanel::GetPanelHeight()
{
	return panel_height;
}
void
CustomPanel::Initialize(String name, String time, String content)
{
    Dimension		tmp_dim;
    String			tmp_str;
    wchar_t			tmp_char;

    int current_x = 50, current_y = 50;
    int i;

    Font font;
    font.Construct(FONT_STYLE_PLAIN, 30);


	arr_text_element.Construct();
	arr_text_element_rect.Construct();
	arr_text_element_highlight.Construct();

	for(i=0; i<content.GetLength(); i++)
	{
		content.GetCharAt(i, tmp_char);
		tmp_str.Append(tmp_char);
		if(tmp_char == ' ' && (i+1) < content.GetLength())
		{
			content.GetCharAt(i+1,tmp_char);
			if(tmp_char != ' ')
			{
				font.GetTextExtent(tmp_str, tmp_str.GetLength(), tmp_dim);
				arr_text_element.Add(new String(tmp_str));

				if(current_x + tmp_dim.width > this->GetWidth())
				{
					current_x = 50;
					current_y += (STRIATION_SPACING);
				}
				arr_text_element_highlight.Add(new Boolean(false));
				arr_text_element_rect.Add(new Rectangle(current_x, current_y, tmp_dim.width ,STRIATION_SPACING));
				current_x += tmp_dim.width;
				tmp_str.Clear();
			}
		}
	}

	panel_height = current_y + 100;

	draw_timer.Construct(*this);

	isLongTouchPressed = false;

    contextMenu = new ContextMenu();
    contextMenu->Construct(Point(50, 50), CONTEXT_MENU_STYLE_GRID);
    contextMenu->SetFocusable(true);
    contextMenu->AddItem(L"복사", 1);
    contextMenu->AddItem(L"메모장", 2);
    onContextMenu = false;
    contextMenu->AddActionEventListener(*this);

	this->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height));

	AddControl(contextMenu);
}


void
CustomPanel::ShowContextMenu(bool show, Point currentPosition)
{
	//contextMenu->SetAnchorPosition(currentPosition);

    // Change to desired show state
	contextMenu->SetShowState(show);
	onContextMenu = true;
    //Calls Show() of the control
    if (show)
    {
    	contextMenu->Show();
    }
    else
    {
        Invalidate(true);
    }
}

void
CustomPanel::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here


}

void
CustomPanel::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
CustomPanel::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
CustomPanel::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

	isLongTouchPressed = true;

	touch_start_point.y = (currentPosition.y / STRIATION_SPACING) * STRIATION_SPACING;
	touch_start_point.x = currentPosition.x;

	draw_timer.Start(50);

	AppLog("LongTouch");
}

void
CustomPanel::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

	int i = 0;
	String		*tmp_string;
	Rectangle   *tmp_rect;
	Point		tmp_point;

	tmp_point.y = (currentPosition.y / STRIATION_SPACING) * STRIATION_SPACING;


	if(isLongTouchPressed == true)
	{
		for(i=0; i<arr_text_element.GetCount(); i++)
		{
			tmp_string = static_cast <String *> (arr_text_element.GetAt(i));
			tmp_rect = static_cast <Rectangle *> (arr_text_element_rect.GetAt(i));

			if(tmp_point.y > touch_start_point.y)
			{
				if((tmp_rect->y/STRIATION_SPACING)*STRIATION_SPACING < tmp_point.y &&
						(tmp_rect->y/STRIATION_SPACING)*STRIATION_SPACING >= touch_start_point.y)
				{
					arr_text_element_highlight.SetAt(new Boolean(true), i);

					AppLog("%S : true", tmp_string->GetPointer());
				}
			}
			else if(tmp_point.y < touch_start_point.y)
			{
				if((tmp_rect->y/STRIATION_SPACING)*STRIATION_SPACING > tmp_point.y &&
						(tmp_rect->y/STRIATION_SPACING)*STRIATION_SPACING <= touch_start_point.y)
				{
					arr_text_element_highlight.SetAt(new Boolean(true), i);

					AppLog("%S : true", tmp_string->GetPointer());
				}
			}

			else if(tmp_point.y == (tmp_rect->y/STRIATION_SPACING)*STRIATION_SPACING)
			{
				if(currentPosition.x > tmp_rect->x && currentPosition.x < (tmp_rect->x + tmp_rect->width))
				{
					arr_text_element_highlight.SetAt(new Boolean(true), i);
					AppLog("%S : true", tmp_string->GetPointer());
				}
			}

			else
			{
				arr_text_element_highlight.SetAt(new Boolean(false), i);
			}
		}
	}


}

void
CustomPanel::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}

void
CustomPanel::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

	Point screenPosition;



	isLongTouchPressed = false;

	screenPosition = this->ConvertToScreenPosition(currentPosition);
	contextMenu->SetAnchorPosition(screenPosition);
	bool abc = contextMenu->HasFocus();
	ShowContextMenu(true, screenPosition);

	abc = contextMenu->HasFocus();
}

void
CustomPanel::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	int i;

    switch (actionId)
    {
    case 1:
        {

    		String	  *tmp_string;
    		Boolean	  *tmp_highlight;

    		int i;
    		draw_timer.Cancel();



    		for(i=0; i<arr_text_element_highlight.GetCount(); i++)
    		{
    			tmp_highlight = static_cast <Boolean *> (arr_text_element_highlight.GetAt(i));
    			tmp_string = static_cast< String *> (arr_text_element.GetAt(i));
    			if(tmp_highlight->ToBool() == true)
    			{
    				popup_edit_string.Append(*tmp_string);
    				arr_text_element_highlight.SetAt(new Boolean(false), i);
    			}
    		}

        	this->RequestRedraw(true);
            popup = new Popup;
            popup->Construct(true, Dimension(600,800));
            popup->SetTitleText(L"Popup Sample");

            EditArea* __pEditArea;
            __pEditArea = new EditArea();
            __pEditArea->Construct(Rectangle(50, 100, 400, 150),INPUT_STYLE_OVERLAY);
            __pEditArea->SetText(popup_edit_string);

            __pEditArea->AddTextEventListener(*this);
            popup->AddControl(__pEditArea);

            Button* pCloseButton = new Button();
            pCloseButton->Construct(Rectangle(10, 10, 250, 80), L"Close Popup");
            pCloseButton->SetActionId(3);
            pCloseButton->AddActionEventListener(*this);

            // Adds the button to the popup
            popup->AddControl(pCloseButton);

            ShowPopup();
        }
        break;
    case 2:
        {
            // ....
        }
        break;
    case 3:
    	{
    		popup_edit_string.Clear();
    		HidePopup();
    	}
    default:
        break;
    }
}


void
CustomPanel::OnTextValueChanged(const Tizen::Ui::Control& source)
{
    // ....
}

void
CustomPanel::OnTextValueChangeCanceled(const Tizen::Ui::Control& source)
{
    // ....
}

void
CustomPanel::ShowPopup(void)
{
    popup->SetShowState(true);
    popup->Show();
}

void
CustomPanel::HidePopup(void)
{
	popup->SetShowState(false);
    Invalidate(true);
}

void
CustomPanel::OnTimerExpired (Timer &timer)
{
	if(isLongTouchPressed == true)
	{
		if(&timer == &draw_timer)
		{
			this->RequestRedraw(true);
			draw_timer.Start(100);
		}
	}

	AppLog("timer On");
}


void
CustomPanel::DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap &bitmap)
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
