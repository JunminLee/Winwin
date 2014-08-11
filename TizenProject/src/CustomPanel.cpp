/*
 * CustomPanel.cpp
 *
 *  Created on: Jul 31, 2014
 *      Author: pji
 */



#include "CustomPanel.h"
#include "AppResourceId.h"
#include "SceneRegister.h"

static TableView *table_view = null;

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

    pCanvas->FillRectangle(Color(246, 246, 0, 255), Rectangle(0,0,this->GetWidth(), this->GetHeight()));

    pCanvas->FillRectangle(Color(255, 255, 255, 255), content_area);

    //DrawEllipseImage(*pCanvas, Color(255,255,255,255), Rectangle(50,70,100,100), *profile_image);

    //pCanvas->DrawText(Point(180, 80), L"David Beckham");

    pCanvas->DrawBitmap(Rectangle(180, 130, 50,30), *national_flag_image);

    pCanvas->DrawText(Point(240, 130), L"미국 14일 오후 6:00");
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
		//pCanvas->DrawRectangle(*tmp_rect);
	}

	if(extend_content_flag == true)
	{
		for(i=0; i<arr_extend_text_element_rect.GetCount(); i++)
		{
			tmp_rect = static_cast< Rectangle* > (arr_extend_text_element_rect.GetAt(i));
			tmp_string = static_cast< String *> (arr_extend_text_element.GetAt(i));
			tmp_highlight = static_cast <Boolean *> (arr_extend_text_element_highlight.GetAt(i));
			if(tmp_highlight->ToBool() == true)
			{
				pCanvas->DrawText(Point(tmp_rect->x, tmp_rect->y), *tmp_string, Color(0,255,0,150));
			}
			else
			{
				pCanvas->DrawText(Point(tmp_rect->x, tmp_rect->y), *tmp_string);
			}
			//pCanvas->DrawRectangle(*tmp_rect);
		}
	}

	if(onHighlightStart == true)
	{
		pCanvas->FillRectangle(Color(100,100,255,255), cur_start_rect);
		pCanvas->FillRectangle(Color(100,100,255,255), cur_end_rect);
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
CustomPanel::Initialize(String name, String time, String content, String extend_content, TableView *pb, TableViewItem *pItem, int _index)
{
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
    Dimension		tmp_dim;
    String			tmp_str;
    wchar_t			tmp_char;

    int current_x = 50, current_y = 200;
    int i;


    Font font;
    font.Construct(FONT_STYLE_PLAIN, 30);

    pvi = pItem;
    index = _index;
    extend_content_flag = false;
	arr_text_element.Construct();
	arr_text_element_rect.Construct();
	arr_text_element_highlight.Construct();

	arr_extend_text_element.Construct();
	arr_extend_text_element_rect.Construct();
	arr_extend_text_element_highlight.Construct();

	content_area.SetBounds(30,30,this->GetWidth()-60, this->GetHeight()-60);

	str_name = name;

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

				if(current_x + tmp_dim.width > content_area.width)
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
		else if(i == content.GetLength()-1)
		{
			font.GetTextExtent(tmp_str, tmp_str.GetLength(), tmp_dim);
			arr_text_element.Add(new String(tmp_str));

			if(current_x + tmp_dim.width > content_area.width)
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




	panel_height = current_y + 250;

	draw_timer.Construct(*this);

	isLongTouchPressed = false;

    contextMenu = new ContextMenu();
    contextMenu->Construct(Point(50, 50), CONTEXT_MENU_STYLE_GRID, CONTEXT_MENU_ANCHOR_DIRECTION_UPWARD );
    contextMenu->SetFocusable(true);
    contextMenu->AddItem(L"복사", 1);
    contextMenu->AddItem(L"메모장", 2);
    onContextMenu = false;
    contextMenu->AddActionEventListener(*this);


	this->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height));
	content_area.SetBounds(30,30,this->GetWidth()-60, panel_height);

	AddControl(contextMenu);

	onHighlightStart = false;

	national_flag_image = pAppResource->GetBitmapN(L"nationalflag.png");
	profile_iamge = pAppResource->GetBitmapN(L"tizen.png");

	if(table_view == null)
		table_view = pb;




    int remain;

    remain = STRIATION_SPACING - current_y%STRIATION_SPACING;
    current_y = current_y + remain;

    extend_content_area_y = current_y + 100;

    button_content = new Button;
    button_like = new Button;
    button_comment = new Button;
    button_name = new Button;
    button_profile_image = new Button;

    //pCanvas->DrawText(Point(180, 80), L"David Beckham");

    //pCanvas->DrawBitmap(Rectangle(180, 130, 50,30), *national_flag_image);

    font.GetTextExtent(name, name.GetLength(), tmp_dim);
    name_width = tmp_dim.width;
    button_name->Construct(Rectangle( 180, 80, tmp_dim.width, tmp_dim.height), name);
    button_profile_image->Construct(Rectangle(50,70,100,100), " ");
    button_profile_image->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"tizen.png")));
    button_content->Construct(Rectangle( 50, current_y, this->GetWidth()-100, 50), " ");
    button_like->Construct(Rectangle(50, extend_content_area_y, this->GetWidth()/2-50, 50), " ");
    button_comment->Construct(Rectangle(this->GetWidth()/2, extend_content_area_y, this->GetWidth()/2-50, 50), " ");
    button_content->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"extend_button.png")));
    button_comment->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"comment_button.png")));
    button_like->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"feedback_button.png")));

    button_content->SetActionId(7);
    button_like->SetActionId(8);
    button_comment->SetActionId(9);
    button_name->SetActionId(10);
    button_profile_image->SetActionId(10);

    button_name->SetColor(BUTTON_STATUS_NORMAL, Color(255,255,255,255));

    button_content->AddActionEventListener(*this);
    button_like->AddActionEventListener(*this);
    button_comment->AddActionEventListener(*this);
    button_name->AddActionEventListener(*this);
    button_profile_image->AddActionEventListener(*this);

    AddControl(button_content);
    AddControl(button_like);
    AddControl(button_comment);
    AddControl(button_profile_image);
    AddControl(button_name);

    current_y = current_y + STRIATION_SPACING*2;

	current_x = 50;

	for(i=0; i<extend_content.GetLength(); i++)
	{

		extend_content.GetCharAt(i, tmp_char);
		tmp_str.Append(tmp_char);
		if(tmp_char == ' ' && (i+1) < extend_content.GetLength())
		{
			extend_content.GetCharAt(i+1,tmp_char);
			if(tmp_char != ' ' || i == extend_content.GetLength()-1)
			{
				font.GetTextExtent(tmp_str, tmp_str.GetLength(), tmp_dim);
				arr_extend_text_element.Add(new String(tmp_str));

				if(current_x + tmp_dim.width > content_area.width)
				{
					current_x = 50;
					current_y += (STRIATION_SPACING);
				}
				arr_extend_text_element_highlight.Add(new Boolean(false));
				arr_extend_text_element_rect.Add(new Rectangle(current_x, current_y, tmp_dim.width ,STRIATION_SPACING));
				current_x += tmp_dim.width;
				tmp_str.Clear();
			}

		}

		else if(i == extend_content.GetLength()-1)
		{
			font.GetTextExtent(tmp_str, tmp_str.GetLength(), tmp_dim);
			arr_extend_text_element.Add(new String(tmp_str));

			if(current_x + tmp_dim.width > content_area.width)
			{
				current_x = 50;
				current_y += (STRIATION_SPACING);
			}
			arr_extend_text_element_highlight.Add(new Boolean(false));
			arr_extend_text_element_highlight.Add(new Rectangle(current_x, current_y, tmp_dim.width ,STRIATION_SPACING));
			current_x += tmp_dim.width;
			tmp_str.Clear();
		}
	}

	comment_list_view_flag = false;
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

	/*
	isLongTouchPressed = true;

	touch_start_point.y = (currentPosition.y / STRIATION_SPACING) * STRIATION_SPACING;
	touch_start_point.x = currentPosition.x;

	draw_timer.Start(50);

	AppLog("LongTouch");

	*/
}

void
CustomPanel::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here


	int i = 0;
	String		*tmp_string;
	Rectangle   *tmp_rect, *tmp_rect2;
	Point		tmp_point;

	table_view->SetScrollEnabled(true);

	if(select_cur == 1)
	{
		tmp_rect = static_cast <Rectangle *> (arr_text_element_rect.GetAt(start_index));
		tmp_rect2 = static_cast <Rectangle *> (arr_text_element_rect.GetAt(0));

		cur_start_point.x = currentPosition.x;
		cur_start_point.y = currentPosition.y-25;

		cur_start_point.y = (cur_start_point.y/STRIATION_SPACING) * STRIATION_SPACING + 50;


		if(cur_start_point.y >= cur_end_point.y)
		{
			cur_start_point.y = cur_end_point.y;

			if((cur_start_point.x+cur_start_rect.width) <= (tmp_rect->x))
			{
				cur_start_point.x = tmp_rect->x - cur_start_rect.width;
			}
		}
		else if(cur_start_point.y <= tmp_rect2->y+50)
		{
			cur_start_point.y = tmp_rect2->y+50;

			if((cur_start_point.x+cur_start_rect.width) <= (tmp_rect2->x))
			{
				cur_start_point.x = tmp_rect2->x - cur_start_rect.width;
			}
		}


		for(i=0; i<arr_text_element_rect.GetCount(); i++)
		{
			tmp_rect = static_cast <Rectangle *> (arr_text_element_rect.GetAt(i));
			if((cur_start_point.x+cur_start_rect.width) >= (tmp_rect->x) && (cur_start_point.x + cur_start_rect.width)< (tmp_rect->x + tmp_rect->width)
					&& (tmp_rect->y + tmp_rect->height) == cur_start_point.y)
			{
				start_index = i;
				break;
			}
		}
		cur_start_rect.x = cur_start_point.x;
		cur_start_rect.y = cur_start_point.y;



	}
	else if(select_cur == 2)
	{
		cur_end_point.x = currentPosition.x;
		cur_end_point.y = currentPosition.y-25;

		cur_end_point.y = (cur_end_point.y/STRIATION_SPACING) * STRIATION_SPACING + 50;


		tmp_rect = static_cast <Rectangle *> (arr_text_element_rect.GetAt(start_index));
		tmp_rect2 = static_cast <Rectangle *> (arr_text_element_rect.GetAt(arr_text_element_rect.GetCount()-1));




		if(cur_end_point.y <= cur_start_point.y)
		{
			cur_end_point.y = cur_start_point.y;

			if(cur_end_point.x <= (tmp_rect->x + tmp_rect->width))
			{
				cur_end_point.x = tmp_rect->x + tmp_rect->width;
			}
		}
		else if(cur_end_point.y >= tmp_rect2->y+50)
		{
			cur_end_point.y = tmp_rect2->y+50;

			if(cur_end_point.x >= (tmp_rect2->x + tmp_rect2->width))
			{
				cur_end_point.x = tmp_rect2->x + tmp_rect2->width;
			}
		}

		cur_end_rect.x = cur_end_point.x;
		cur_end_rect.y = cur_end_point.y;

	}

	if(onHighlightStart == true)
	{
		table_view->SetScrollEnabled(false);
		if(select_cur == 1)
		{
			for(i=0; i<start_index; i++)
				arr_text_element_highlight.SetAt(new Boolean(false), i);
		}
		for(i=start_index; i<arr_text_element.GetCount(); i++)
		{
			tmp_rect = static_cast <Rectangle *> (arr_text_element_rect.GetAt(i));


			if(cur_start_rect.y == cur_end_rect.y)
			{
				if(cur_end_rect.x >= (tmp_rect->x + tmp_rect->width) && (tmp_rect->y + tmp_rect->height) == cur_end_rect.y)
				{
					arr_text_element_highlight.SetAt(new Boolean(true), i);
				}
				else
					arr_text_element_highlight.SetAt(new Boolean(false), i);

			}
			else if(cur_start_rect.y < cur_end_rect.y)
			{
				if((tmp_rect->y + tmp_rect->height) == cur_end_rect.y && cur_end_rect.x >= (tmp_rect->x + tmp_rect->width))
				{
					arr_text_element_highlight.SetAt(new Boolean(true), i);
				}
				else if((tmp_rect->y + tmp_rect->height) < cur_end_rect.y)
				{
					arr_text_element_highlight.SetAt(new Boolean(true), i);
				}
				else
					arr_text_element_highlight.SetAt(new Boolean(false), i);
			}

		}
	}




	/*
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

	*/


}

bool
CustomPanel::GetHighlightMode()
{
	return onHighlightStart;
}
void
CustomPanel::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

	touch_point = currentPosition;

	if(onHighlightStart == true)
	{
		if(currentPosition.x > cur_start_rect.x && currentPosition.x < (cur_start_rect.x + cur_start_rect.width) &&
				currentPosition.y > cur_start_rect.y && currentPosition.y < (cur_start_rect.y + cur_start_rect.height))
			select_cur = 1;
		else if(currentPosition.x > cur_end_rect.x && currentPosition.x < (cur_end_rect.x + cur_end_rect.width) &&
				currentPosition.y > cur_end_rect.y && currentPosition.y < (cur_end_rect.y + cur_end_rect.height))
			select_cur = 2;
	}



}

void
CustomPanel::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	Rectangle   *tmp_rect;
	Point		tmp_point;

	Point screenPosition;
	int i;
	int cnt = 0;



	if(touch_point == currentPosition)
	{
		for(i=0; i<arr_text_element.GetCount(); i++)
		{
			tmp_rect = static_cast <Rectangle *> (arr_text_element_rect.GetAt(i));
			if(currentPosition.x > tmp_rect->x && currentPosition.x < (tmp_rect->x + tmp_rect->width) &&
					currentPosition.y > tmp_rect->y && currentPosition.y < (tmp_rect->y + tmp_rect->height))
			{
				onHighlightStart = true;

				cur_start_rect.x = tmp_rect->x - 30;
				cur_start_rect.width = 30;
				cur_start_rect.y = tmp_rect->y + tmp_rect->height;
				cur_start_rect.height = 40;

				cur_end_rect.x = tmp_rect->x + tmp_rect->width;
				cur_end_rect.width = 30;
				cur_end_rect.y = tmp_rect->y + tmp_rect->height;
				cur_end_rect.height = 40;

				cur_start_point.x = cur_start_rect.x;
				cur_start_point.y = cur_start_rect.y-25;

				cur_end_point.x = cur_end_rect.x;
				cur_end_point.y = cur_end_rect.y-25;

				cur_start_point.y = (cur_start_point.y/STRIATION_SPACING) * STRIATION_SPACING + 50;
				cur_start_rect.y = cur_start_point.y;

				arr_text_element_highlight.SetAt(new Boolean(true), i);
				start_index = i;
			}
			else
			{
				arr_text_element_highlight.SetAt(new Boolean(false), i);
				cnt++;
			}
		}

		if(cnt >= arr_text_element.GetCount())
			onHighlightStart = false;
	}

	if(onHighlightStart == true)
	{
		screenPosition = this->ConvertToScreenPosition(currentPosition);
		contextMenu->SetAnchorPosition(screenPosition);
		bool abc = contextMenu->HasFocus();
		ShowContextMenu(true, screenPosition);

		abc = contextMenu->HasFocus();
	}


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

    		onHighlightStart = false;

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
    		popup->Destroy();
    	}
    	break;
    case 7:
		{
			if(extend_content_flag == false)
			{
				Rectangle *tmp_rect;
				tmp_rect = static_cast <Rectangle *> (arr_extend_text_element_rect.GetAt(arr_extend_text_element_rect.GetCount()-1));
				panel_height = tmp_rect->y + tmp_rect->height;

				int a = this->GetHeight();

				pvi->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height+150));
				this->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height+150));

				content_area.SetBounds(30,30,this->GetWidth()-60, panel_height+120);
			    button_like->SetBounds(Rectangle(50, this->GetHeight()-100, this->GetWidth()/2-50, 50));
			    button_comment->SetBounds(Rectangle(this->GetWidth()/2, this->GetHeight()-100, this->GetWidth()/2-50, 50));
				table_view->RefreshAllItems();
				extend_content_flag = true;
			}
			else
			{
				Rectangle *tmp_rect;
				tmp_rect = static_cast <Rectangle *> (arr_extend_text_element_rect.GetAt(0));
				panel_height = tmp_rect->y;
				pvi->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height + 100));
				this->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height + 100));
				content_area.SetBounds(30,30,this->GetWidth()-60, panel_height + 70);
			    button_like->SetBounds(Rectangle(50, extend_content_area_y, this->GetWidth()/2-50, 50));
			    button_comment->SetBounds(Rectangle(this->GetWidth()/2, extend_content_area_y, this->GetWidth()/2-50, 50));
				table_view->RefreshAllItems();
				extend_content_flag = false;
			}
		}
		break;
    case 8:
		{
			if(comment_list_view_flag == false)
			{
				pvi->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height + 200));
				this->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height + 200));
				content_area.SetBounds(30,30,this->GetWidth()-60, panel_height + 170);

				__pListView = new ListView();
				__pListView->Construct(Rectangle(30, button_comment->GetY() + 80, this->GetWidth()/2-50, 100));
				__pListView->SetItemProvider(*this);
				AddControl(__pListView);

				table_view->RefreshAllItems();

				comment_list_view_flag = true;
			}
			else if(comment_list_view_flag == true)
			{
				__pListView->Destroy();
				if(extend_content_flag == false)
				{
					pvi->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height + 100));
					this->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height + 100));
					content_area.SetBounds(30,30,this->GetWidth()-60, panel_height + 70);
				}
				else
				{
					pvi->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height + 150));
					this->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height + 150));
					content_area.SetBounds(30,30,this->GetWidth()-60, panel_height + 120);
				}
				table_view->RefreshAllItems();
				comment_list_view_flag = false;
			}
		}
		break;
    case 9:
    {
    	SceneManager* pSceneManager = SceneManager::GetInstance();
    	AppAssert(pSceneManager);
    	pSceneManager->GoForward(ForwardSceneTransition(SCENE_EDITING_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
    	break;
    }
    case 10:
        {
        	Dimension	tmp_dim;
        	popup = new Popup;
            popup->Construct(true, Dimension(600,900));
            popup->SetColor(Color(255,255,255,255));

            Button* pCloseButton = new Button();
            pCloseButton->Construct(Rectangle(10,700, 250, 80), L"Close Popup");
            pCloseButton->SetActionId(3);
            pCloseButton->AddActionEventListener(*this);


        	Label *tmp_profile_label = new Label();
        	Label *tmp_name = new Label();
        	Label *tmp_flag = new Label();
            EditArea* __pEditArea;
            __pEditArea = new EditArea();
            __pEditArea->Construct(Rectangle(50, 400, 500, 350),INPUT_STYLE_OVERLAY);
            __pEditArea->SetText("Tizen is a new open platform that enables richer user experience Tizen is a new open platform that enables richer user experience Tizen is a new open platform that enables richer user experience");
            __pEditArea->SetKeypadEnabled(false);
            __pEditArea->SetColor(EDIT_STATUS_NORMAL, Color(255,255,255,255));
            __pEditArea->SetColor(EDIT_STATUS_DISABLED, Color(255,255,255,255));
            __pEditArea->SetColor(EDIT_STATUS_PRESSED, Color(255,255,255,255));
            __pEditArea->SetColor(EDIT_STATUS_HIGHLIGHTED, Color(255,255,255,255));
            __pEditArea->SetViewModeEnabled(true);
            popup->AddControl(__pEditArea);

        	Font tmp_font;

        	tmp_font.Construct(FONT_STYLE_PLAIN, 30);

        	tmp_font.GetTextExtent(str_name,str_name.GetLength(), tmp_dim);

        	tmp_profile_label->Construct(Rectangle(50,70,100,100), " ");
        	tmp_name->Construct(Rectangle( 180, 80,  tmp_dim.width, 50), str_name);
        	tmp_name->SetTextConfig(25, LABEL_TEXT_STYLE_NORMAL);
        	tmp_flag->Construct(Rectangle(180, 130, 50,30), " ");

        	tmp_flag->SetBackgroundBitmap(*national_flag_image);
        	tmp_profile_label->SetBackgroundBitmap(*profile_iamge);

            // Adds the button to the popup
            popup->AddControl(pCloseButton);
            popup->AddControl(tmp_flag);
            popup->AddControl(tmp_profile_label);
            popup->AddControl(tmp_name);

            ShowPopup();
        }
        break;
    default:
        break;
    }
}


void
CustomPanel::OnTextValueChanged(const Tizen::Ui::Control& source)
{
    // ....
}


ListItemBase*
CustomPanel::CreateItem(int index, int itemWidth)
{
    // Creates an instance of CustomItem
    CustomItem* pItem = new CustomItem();
    ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;

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

    return pItem;
}

bool
CustomPanel::DeleteItem(int index, ListItemBase* pItem, int itemWidth)
{
    delete pItem;
    pItem = null;
    return true;
}

int
CustomPanel::GetItemCount(void)
{
    return 15;
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
	if(onHighlightStart == true)
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
