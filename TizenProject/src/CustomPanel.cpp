/*
 * CustomPanel.cpp
 *
 *  Created on: Jul 31, 2014
 *      Author: pji
 */



#include "CustomPanel.h"
#include "AppResourceId.h"
#include "SceneRegister.h"
#include "Toast.h"

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

	//pCanvas = this->GetCanvasN();


	pCanvas = this->GetCanvasN();

    pCanvas->SetFont(font);

    pCanvas->FillRectangle(Color(246, 246, 246, 255), Rectangle(0,0,this->GetWidth(), this->GetHeight()));

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

	pCanvas->DrawBitmap(Rectangle(594, 70, 44, 40), *button_item_remove);

/*	if(text_singo == true)
	{
		EnrichedText et;
		TextElement te;

		et.Construct(Dimension(150, 900));

		te.Construct(L"      글 숨기기를 완료하였습니다.     ");
		et.Add(te);

		draw_timer.Start(1500);
		pCanvas->DrawText(Point(150, 900), et);
	}
	else if(text_remove == true)
	{
		EnrichedText et;
		TextElement te;

		et.Construct(Dimension(150, 900));

		te.Construct(L"      글 신고를 완료하였습니다.      ");
		te.SetBackgroundColor(Color(130,130,130,150));

		et.Add(te);
		draw_timer.Start(1500);
		pCanvas->DrawText(Point(150, 900), et);

	}*/

	pCanvas->~Canvas();
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

	button_item_remove = pAppResource->GetBitmapN(L"item_remove_button.png");
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
    contextMenu->AddItem(L"복사하기", 20);
    contextMenu->AddItem(L"단어장 추가", 1);
    contextMenu->AddItem(L"음성 피드백 요청", 22);
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

	text_singo = false;
	text_remove = false;



    int remain;

    remain = STRIATION_SPACING - current_y%STRIATION_SPACING;
    current_y = current_y + remain;

    extend_content_area_y = current_y + 100;

    button_content = new Button;
    button_like = new Button;
    button_comment = new Button;
    button_name = new Button;
    button_profile_image = new Button;
    button_edit = new Button;

    //pCanvas->DrawText(Point(180, 80), L"David Beckham");

    //pCanvas->DrawBitmap(Rectangle(180, 130, 50,30), *national_flag_image);

    font.GetTextExtent(name, name.GetLength(), tmp_dim);
    name_width = tmp_dim.width;
    button_name->Construct(Rectangle( 180, 80, tmp_dim.width, tmp_dim.height), name);
    button_profile_image->Construct(Rectangle(50,70,100,100), " ");

    button_profile_image->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"tizen.png")));

    button_content->Construct(Rectangle( 70, current_y, 580, 60), " ");
    button_like->Construct(Rectangle(50, extend_content_area_y, 133, 60), " ");
    button_comment->Construct(Rectangle(253, extend_content_area_y,112 , 60), " ");
    button_edit->Construct(Rectangle(450, extend_content_area_y, 213, 68));
    button_content->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"extend_button.png")));
    button_comment->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"comment_button.png")));
    button_like->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"like_button.png")));
    button_edit->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"edit_button.png")));

    button_content->SetActionId(7);
    button_like->SetActionId(2);
    button_edit->SetActionId(9);
    button_comment->SetActionId(8);
    button_name->SetActionId(10);
    button_profile_image->SetActionId(10);

    button_name->SetColor(BUTTON_STATUS_NORMAL, Color(255,255,255,255));

    button_content->AddActionEventListener(*this);
    button_like->AddActionEventListener(*this);
    button_comment->AddActionEventListener(*this);
    button_name->AddActionEventListener(*this);
    button_profile_image->AddActionEventListener(*this);
    button_edit->AddActionEventListener(*this);

    AddControl(button_content);
    AddControl(button_like);
    AddControl(button_comment);
    AddControl(button_profile_image);
    AddControl(button_name);
    AddControl(button_edit);

    current_y = current_y + STRIATION_SPACING*2;

	current_x = 50;

	like_cnt = 0;

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
	remove_button_on = false;
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
					if(contextPosition.y >= tmp_rect->y)
					{
						contextPosition.y = tmp_rect->y;
					}
					if(contextPosition.x >= tmp_rect->x)
					{
						contextPosition.x = tmp_rect->x;
					}
					else if((contextPosition.width) <= (tmp_rect->x + tmp_rect->width))
					{
						contextPosition.width =  (tmp_rect->x + tmp_rect->width);
					}
				}
				else
					arr_text_element_highlight.SetAt(new Boolean(false), i);

			}
			else if(cur_start_rect.y < cur_end_rect.y)
			{
				if((tmp_rect->y + tmp_rect->height) == cur_end_rect.y && cur_end_rect.x >= (tmp_rect->x + tmp_rect->width))
				{
					arr_text_element_highlight.SetAt(new Boolean(true), i);
					if(contextPosition.y >= tmp_rect->y)
					{
						contextPosition.y = tmp_rect->y;
					}
					if(contextPosition.x >= tmp_rect->x)
					{
						contextPosition.x = tmp_rect->x;
					}
					else if((contextPosition.width) <= (tmp_rect->x + tmp_rect->width))
					{
						contextPosition.width =  (tmp_rect->x + tmp_rect->width);
					}
				}
				else if((tmp_rect->y + tmp_rect->height) < cur_end_rect.y)
				{
					arr_text_element_highlight.SetAt(new Boolean(true), i);
					if(contextPosition.y >= tmp_rect->y)
					{
						contextPosition.y = tmp_rect->y;
					}
					if(contextPosition.x >= tmp_rect->x)
					{
						contextPosition.x = tmp_rect->x;
					}
					else if((contextPosition.width) <= (tmp_rect->x + tmp_rect->width))
					{
						contextPosition.width =  (tmp_rect->x + tmp_rect->width);
					}
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
	contextPosition.x = 0;
	contextPosition.width = 0;
	contextPosition.y = 15000;
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
				if(contextPosition.y >= tmp_rect->y)
				{
					contextPosition.y = tmp_rect->y;
				}
				if(contextPosition.x >= tmp_rect->x)
				{
					contextPosition.x = tmp_rect->x;
				}
				else if((contextPosition.width) <= (tmp_rect->x + tmp_rect->width))
				{
					contextPosition.width =  (tmp_rect->x + tmp_rect->width);
				}

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

				contextPosition.width = tmp_rect->x + tmp_rect->width;
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
		AppLog("x : %d, y : %d", (contextPosition.x + contextPosition.width)/2,contextPosition.y );
		screenPosition = this->ConvertToScreenPosition(Point((contextPosition.x + contextPosition.width)/2, contextPosition.y));
		contextMenu->SetAnchorPosition(screenPosition);
		bool abc = contextMenu->HasFocus();
		ShowContextMenu(true, screenPosition);

		abc = contextMenu->HasFocus();
	}


	Rectangle temp_button = Rectangle(594, 70, 44, 40);

	if(currentPosition.x > temp_button.x && currentPosition.x < (temp_button.x + temp_button.width) &&
			currentPosition.y > temp_button.y && currentPosition.y < (temp_button.y + temp_button.height))
	{
		AppLog("currentPositoin : %d, %d", currentPosition.x, currentPosition.y);
		AppLog("temp_button : %d, %d", temp_button.x, temp_button.y);
		remove_button_on = true;

    	Button *remove = new Button;
    	Button *singo = new Button;

    	popup = new Popup;
        popup->Construct(false, Dimension(500,400));
        popup->SetPosition(Point(110, 400));
        popup->SetColor(Color(255,255,255,255));

        remove->Construct(Rectangle(0,0,500,200), "글숨기기");
        singo->Construct(Rectangle(0,200,500,200), "글 신고하기");

        remove->SetActionId(12);
        singo->SetActionId(13);
        remove->AddActionEventListener(*this);
        singo->AddActionEventListener(*this);

        popup->AddControl(remove);
        popup->AddControl(singo);


        ShowPopup();
	}

}

void
CustomPanel::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	int i;

    switch (actionId)
    {
    case 1:								//정보
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

        	title = new Label;

        	title->Construct(Rectangle(0,0,500,100), " ");
            title->SetText(L"단어장으로 보내기");
            title->SetTextColor(Color(0,181,237,255));

            popup = new Popup;
            popup->Construct(false, Dimension(500,600));
            popup->SetPosition(Point(110, 130));
            EditArea* __pEditArea;
            __pEditArea = new EditArea();
            __pEditArea->Construct(Rectangle(30, 100, 440, 180),INPUT_STYLE_OVERLAY);
            __pEditArea->SetText(popup_edit_string);

            __pEditArea->AddTextEventListener(*this);
            popup->AddControl(__pEditArea);

            EditArea* __pEditArea2;
            __pEditArea2 = new EditArea();
            __pEditArea2->Construct(Rectangle(30, 310, 440, 180),INPUT_STYLE_OVERLAY);
            __pEditArea2->SetGuideText("한글 뜻을 적어 주세요");
            __pEditArea2->SetGuideTextColor(Color(200,200,200,255));

            __pEditArea->AddTextEventListener(*this);
            popup->AddControl(__pEditArea2);

            popup->AddControl(title);

        	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

            Button* pCloseButton = new Button();
            pCloseButton->Construct(Rectangle(450, 12, 38, 38), L"");
            pCloseButton->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"close_button.png")));
            pCloseButton->SetActionId(3);
            pCloseButton->AddActionEventListener(*this);

            Button* ok_button = new Button;
            ok_button->Construct(Rectangle(30, 520, 440, 65), L"");
            ok_button->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"ok_button.png")));
            ok_button->SetActionId(3);
            ok_button->AddActionEventListener(*this);


            // Adds the button to the popup
            popup->AddControl(pCloseButton);
            popup->AddControl(ok_button);

            ShowPopup();
        }
        break;
    case 2:
        {
            like_cnt++;
        }
        break;
    case 3:
    	{
	   		title->Destroy();
    		popup_edit_string.Clear();
    		HidePopup();
    		popup->Destroy();

    		Toast *tt = new Toast;
    		tt->Construct(Rectangle(150, 900, 420, 100), L"단어장에 추가되었습니다", 3000);

    	}
    	break;
    case 7:
		{
			if(extend_content_flag == false)
			{
				Rectangle *tmp_rect;
				tmp_rect = static_cast <Rectangle *> (arr_extend_text_element_rect.GetAt(arr_extend_text_element_rect.GetCount()-1));
				panel_height = tmp_rect->y + tmp_rect->height;

				pvi->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height+150));
				this->SetBounds(Rectangle(0,0,this->GetWidth(), panel_height+150));

				content_area.SetBounds(30,30,this->GetWidth()-60, panel_height+120);
			    button_like->SetBounds(Rectangle(50, this->GetHeight()-100, 133, 60));
			    button_comment->SetBounds(Rectangle(253, this->GetHeight()-100,112 , 60));
			    button_edit->SetBounds(Rectangle(450, this->GetHeight()-100, 213, 68));

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

			    button_like->SetBounds(Rectangle(50, extend_content_area_y, 133, 60));
			    button_comment->SetBounds(Rectangle(253, extend_content_area_y,112 , 60));
			    button_edit->SetBounds(Rectangle(450, extend_content_area_y, 213, 68));

				table_view->RefreshAllItems();
				extend_content_flag = false;
			}
			this->RequestRedraw(true);
		}
		break;
    case 8:
		{
	    	SceneManager* pSceneManager = SceneManager::GetInstance();
	    	AppAssert(pSceneManager);
	    	pSceneManager->GoForward(ForwardSceneTransition(SCENE_COMMENT_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
	    	break;
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
    case 11:
    {

    }
    break;
    case 12:
    {
    	AppLog("index : %d",index);




    	if(index != 0)
    	{
    		table_view->RefreshItem(index, TABLE_VIEW_REFRESH_TYPE_ITEM_REMOVE);

    		Toast *tt = new Toast;
    		tt->Construct(Rectangle(150, 900, 420, 100), L"글 숨기기를 완료하였습니다.",3000);

    	}
    	else
    	{

        	Toast *tt = new Toast;
        	tt->Construct(Rectangle(150, 900, 420, 100), L"글 숨기기를 실패하였습니다.",3000);

    	}

    	remove_button_on = false;
		HidePopup();
		popup->Destroy();
    }
    break;
    case 13:
    {

		Toast *tt = new Toast;
		tt->Construct(Rectangle(150, 900, 420, 100), L"글 신고하기를 완료하였습니다.",3000);


		HidePopup();
    	remove_button_on = false;
		popup->Destroy();
    }
    break;

    case20:
    {
    	/*
    	Popup *memo;

    	momo = new Popup();

    	memo->Construct(true, Dimension(500,600));
    	memo->SetTitleText(L"단어장으로 보내기");
    	memo->SetTitleTextColor(Color(0,181,237,255));

    	EditArea *memo_area, *memo_area2;

    	memo_area = new EditArea;
    	memo_area2 = new EditArea;

    	memo_area->Construct(Rectangle(30,100,440,180));
    	memo_area2->Construct(Rectangle(30,330,440,180));

    	Button	*ok;
    	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

    	ok = new Button;

    	ok->Construct(Rectangle(30,500,440,65), " ");
    	ok->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN("ok_button.png")));

    	memo->AddControl(ok);
    	memo->AddControl(memo_area);
    	memo->AddControl(memo_area2);*/
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
