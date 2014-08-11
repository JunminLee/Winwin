/*
 * Editing.cpp
 *
 *  Created on: Aug 7, 2014
 *      Author: pji
 */


#include "AppResourceId.h"
#include "SceneRegister.h"
#include "Editing.h"

#define STRIATION_SPACING 50

#define	NONE 0
#define DELETED 1
#define REPLACED 2
#define ATTACHED 3;
#define ATTACHED_AND_REPLACED 4;
#define INSERTED 5


Editing::Editing(void)
{
}

Editing::~Editing(void)
{
}

result
Editing::OnDraw()
{
	int i;
	Rectangle *tmp_rect;
	String	  *tmp_string;
	Boolean	  *tmp_highlight;
	Font font;
    font.Construct(FONT_STYLE_PLAIN, 30);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	Rectangle tmp_client_rect = GetClientAreaBounds();

	Canvas *pCanvas = this->GetCanvasN(Rectangle(30,tmp_client_rect.y+377,this->GetWidth()-60, tmp_client_rect.height-497));
	pCanvas->SetFont(font);

	//pCanvas->DrawBitmap(Rectangle(0,0,this->GetWidth(), 855), *(pAppResource->GetBitmapN(L"editing_background.png")));
	pCanvas->FillRectangle(Color(246,246,246,255), Rectangle(0,0,this->GetWidth(), tmp_client_rect.height-497));

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

	if(onHighlightStart == true)
	{
		pCanvas->FillRectangle(Color(100,100,255,255), cur_start_rect);
		pCanvas->FillRectangle(Color(100,100,255,255), cur_end_rect);
	}

}

void
Editing::OnTimerExpired (Timer &timer)
{
	if(onHighlightStart == true)
	{
		if(&timer == &draw_timer)
		{
			editing_background->RequestRedraw(true);
			draw_timer.Start(100);
		}
	}
	AppLog("Timer On");
}

bool
Editing::Initialize(void)
{
	result r =  Construct(FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();



	int i;
	int current_y = 0;
	int current_x = 40;
	Rectangle *tmp_rect;
    Dimension		tmp_dim;
    String			tmp_str;
    wchar_t			tmp_char;
	Font font;
    font.Construct(FONT_STYLE_PLAIN, 30);
    ori_word_cnt = 0;
    edt_word_cnt = 0;

	str_content = L"      이용수 위원장은 협상팀과 함께 지난 4일 출국해 6일   귀국했고 곧바로 7일      브리핑을 하는 셈이다. 큰 틀에서 이미 판 마르바이크 감독과 합의가 이루어진 것으로 예상할 수 있는 대목이다. 판 마르바이크 감독과의 교감이 없었다면 굳이 브리핑을 할 이유가 없으며 다른 후보자들을 두고 조기 귀국할 이유 역시 없기 때문이다. 사실상 판 마르바이크 감독과의 세부적인 조율만을 남겨놓고 있다는 전망이 나오고 있는 이유다. 이미 네덜란드 언론에서도 판 마르바이크 감독이 한국와의 협상이 진행중이라는 보도가 나온 만큼 대한축구협회가 판 마르바이크 감독에게 관심을 보이고 있다는 사실은 더 이상 비밀이 아니다. 7일 열리는 브리핑을 통해 한국 축구대표팀 차기 감독의 윤곽이 드러날지 기대된다.";

	bool		start_blank_check = false;

	for(i=0; i<str_content.GetLength(); i++)
	{
		str_content.GetCharAt(i, tmp_char);
		if(tmp_char == ' ' && start_blank_check == false)
		{

		}
		else
		{
			start_blank_check = true;
			tmp_str.Append(tmp_char);
			if(tmp_char == ' ' && (i+1) < str_content.GetLength())
			{
				str_content.GetCharAt(i+1,tmp_char);
				if(tmp_char != ' ')
				{
					font.GetTextExtent(tmp_str, tmp_str.GetLength(), tmp_dim);
					arr_text_element.Add(new String(tmp_str));

					if(current_x + tmp_dim.width > 650)
					{
						current_x = 40;
						current_y += (STRIATION_SPACING);
					}
					arr_text_element_highlight.Add(new Boolean(false));
					arr_text_element_rect.Add(new Rectangle(current_x, current_y, tmp_dim.width ,STRIATION_SPACING));
					arr_text_element_editing_mark.Add(new Integer(NONE));
					current_x += tmp_dim.width;
					ori_word_cnt++;
					tmp_str.Clear();
				}
			}
			else if(i == str_content.GetLength()-1)
			{
				font.GetTextExtent(tmp_str, tmp_str.GetLength(), tmp_dim);
				arr_text_element.Add(new String(tmp_str));

				if(current_x + tmp_dim.width > 650)
				{
					current_x = 70;
					current_y += (STRIATION_SPACING);
				}
				arr_text_element_highlight.Add(new Boolean(false));
				arr_text_element_rect.Add(new Rectangle(current_x, current_y, tmp_dim.width ,STRIATION_SPACING));
				arr_text_element_editing_mark.Add(new Integer(NONE));
				current_x += tmp_dim.width;
				ori_word_cnt++;
				tmp_str.Clear();
			}

		}
	}

	tmp_rect = static_cast< Rectangle* > (arr_text_element_rect.GetAt(arr_text_element_rect.GetCount()-1));



	head = new Panel();
	profile_image_panel = new Panel();
	editing_background = new ScrollPanel();
	Label *tmp_label = new Label();

	tmp_label->Construct(Rectangle(current_y+STRIATION_SPACING, 0, 720, current_y+STRIATION_SPACING+1), " ");
	scroll_end_point = (current_y+STRIATION_SPACING)-(GetClientAreaBounds().height-497);

	editing_button = new Button();
	eng_button = new Button();
	editing_completion_button = new Button();

	head->Construct(Rectangle(0,0,this->GetWidth(), 96));
	head->SetBackgroundColor(Color(0,181,238,255));

	profile_image_panel->Construct(Rectangle(0,96,this->GetWidth(), 131));
	profile_image_panel->SetBackgroundColor(Color(246,246,0,255));

	editing_background->Construct(Rectangle(30,377,this->GetWidth()-60, GetClientAreaBounds().height-497), SCROLL_PANEL_SCROLL_DIRECTION_VERTICAL, true);
	editing_background->SetScrollBarVisible(true);
	editing_background->AddControl(tmp_label);


	editing_button->Construct(Rectangle(0,0,287,96));
	editing_button->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"head_editing_button.png")));

	eng_button->Construct(Rectangle(this->GetWidth()-130,15,120, 66));
	eng_button->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"Eng.png")));

	editing_completion_button->Construct(Rectangle(204, 1120, 315, 73));
	editing_completion_button->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"editing_completion_inact.png")));

	editing_background->AddTouchEventListener(*this);
	editing_background->AddScrollEventListener(*this);

	this->AddControl(head);
	this->AddControl(editing_button);
	this->AddControl(eng_button);
	this->AddControl(profile_image_panel);
	this->AddControl(editing_background);
	this->AddControl(editing_completion_button);

	draw_timer.Construct(*this);


	onHighlightStart = false;


    contextMenu = new ContextMenu();
    contextMenu->Construct(Point(50, 50), CONTEXT_MENU_STYLE_GRID, CONTEXT_MENU_ANCHOR_DIRECTION_UPWARD );
    contextMenu->SetFocusable(true);
    contextMenu->AddItem(L"첨삭하기", 1);
    contextMenu->AddActionEventListener(*this);

    onContextMenu = false;


	AddControl(contextMenu);

	return true;
}

void
Editing::ShowPopup(void)
{
    popup->SetShowState(true);
    popup->Show();
}

void
Editing::HidePopup(void)
{
	popup->SetShowState(false);
    Invalidate(true);
}

result
Editing::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	// Setup back event listener
	SetFormBackEventListener(this);

	// Get a button via resource ID


    // Adds the TableView to the form
	return r;
}

result
Editing::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
Editing::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	switch(actionId)
	{
	case 1:
	{
		String	  *tmp_string;
		Boolean	  *tmp_highlight;
		int i;

		for(i=0; i<arr_text_element_highlight.GetCount(); i++)
		{
			tmp_highlight = static_cast <Boolean *> (arr_text_element_highlight.GetAt(i));
			tmp_string = static_cast< String *> (arr_text_element.GetAt(i));
			if(tmp_highlight->ToBool() == true)
			{
				popup_edit_string.Append(*tmp_string);
				arr_text_element_highlight.SetAt(new Boolean(false), i);
				end_index = i;
			}
		}

		onHighlightStart = false;

    	this->RequestRedraw(true);

        popup = new Popup;
        popup->Construct(true, Dimension(600,800));

        popup->SetPosition(0,0);

        popup_ori_area = new EditArea();
        popup_ori_area->Construct(Rectangle(50, 50, 400, 200),INPUT_STYLE_OVERLAY);

        popup_ori_area->SetText(popup_edit_string);

        popup->AddControl(popup_ori_area);

        popup_edit_area = new EditArea();
        popup_edit_area->Construct(Rectangle(50, 250, 400, 200),INPUT_STYLE_OVERLAY);
        popup_edit_area->SetText(popup_edit_string);

        popup_edit_area->AddKeyEventListener(*this);

        popup->AddControl(popup_edit_area);

        popup_explain = new EditArea();
        popup_explain->Construct(Rectangle(50, 450, 400, 200),INPUT_STYLE_OVERLAY);
        popup_explain->SetText(L"123");

        popup->AddControl(popup_explain);

        Button* pCloseButton = new Button();
        pCloseButton->Construct(Rectangle(10, 10, 250, 80), L"Close Popup");
        pCloseButton->SetActionId(2);
        pCloseButton->AddActionEventListener(*this);

        // Adds the button to the popup
        popup->AddControl(pCloseButton);

        Button* CompletionButton = new Button();
        CompletionButton->Construct(Rectangle(10, 250, 250, 80), L"Completion");
        CompletionButton->SetActionId(3);
        CompletionButton->AddActionEventListener(*this);

        // Adds the button to the popup
       // popup->AddControl(CompletionButton);





        // 원문의 단어와 첨삭본의 단어의 개수를 구한다.

        for(i=start_index; i<=end_index; i++)
        {
			tmp_string = static_cast< String *> (arr_text_element.GetAt(i));
			arr_edit_text_element.Add(new String(*tmp_string));
			//arr_text_element_editing_mark.Add(new Integer(NONE));
        }

        edit_area_length = popup_edit_string.GetLength();



        ShowPopup();

        break;
	}
	case 2:
	{
		popup_edit_string.Clear();
		HidePopup();
		popup->Destroy();
		break;
	}
	case 3:
	{

		break;
	}
	}
}


void
Editing::OnKeyLongPressed (const Tizen::Ui::Control &source, Tizen::Ui::KeyCode keyCode)
{

}
void
Editing::OnKeyPressed (const Tizen::Ui::Control &source, Tizen::Ui::KeyCode keyCode)
{

}
void
Editing::OnKeyReleased (const Tizen::Ui::Control &source, Tizen::Ui::KeyCode keyCode)
{
	String tmp_str;

	String tmp_string;

	String *pTmp_edt_string;
	String *pTmp_ori_string;

	ArrayList static cur_stack;
	ArrayList static insert_str;
	ArrayList static insert_index_stack;
	ArrayList static insert_start_index;

	int word_cnt_gap = 0;
	int i;
	static int delete_index = 0;
	static int delete_cnt = 0;
	static int insert_cnt = 0;

	int current_length = 0;
    wchar_t			tmp_char, tmp_char2;
    Integer *tmp_int;
	Integer tmp;

    static String restoration_edit_str = " ";

    restoration_edit_str = popup_edit_area->GetText();

    for(i=0; i<cur_stack.GetCount(); i++)
    {
		tmp_int = static_cast< Integer *> (cur_stack.GetAt(i));
		if(popup_edit_area->GetCursorPosition() == tmp_int->value-1)
			tmp_int->value--;
		restoration_edit_str.Insert(' ', tmp_int->value);
    }


    for(i = insert_str.GetCount()-1; i>=0; i--)
   	{
		pTmp_edt_string = static_cast< String *> (insert_str.GetAt(i));
		tmp_int = static_cast< Integer *> (insert_start_index.GetAt(i));

		restoration_edit_str.Remove(tmp_int->value, pTmp_edt_string->GetLength());
		AppLog("remove restoration : %S", pTmp_edt_string->GetPointer());
   	}



	AppLog("edit_text22 : %S", restoration_edit_str.GetPointer());

	// edit_area 의 텍스트길이에 변화가 생긴다

	if(edit_area_length != restoration_edit_str.GetLength())
	{
		tmp_string = restoration_edit_str;

		//AppLog("edit_text : %S", tmp_string.GetPointer());
		arr_edit_text_element.RemoveAll();

		// 다시 edit_area 의 단어들을 구한다.
		for(i=0; i<tmp_string.GetLength(); i++)
		{
			tmp_string.GetCharAt(i, tmp_char);
			tmp_str.Append(tmp_char);
			if(tmp_char == ' ' && (i+1) < tmp_string.GetLength())
			{
				tmp_string.GetCharAt(i+1,tmp_char);
				if(tmp_char != ' ')
				{
					arr_edit_text_element.Add(new String(tmp_str));
					tmp_str.Clear();
				}
			}
			else if(i == tmp_string.GetLength()-1)
			{
				arr_edit_text_element.Add(new String(tmp_str));
				tmp_str.Clear();
			}
		}

		word_cnt_gap = (end_index - start_index + 1) - (arr_edit_text_element.GetCount() + delete_cnt);

		AppLog("cnt_gap : %d", word_cnt_gap);

		if(word_cnt_gap > 0)								//단어수가 1개 차이날 경우 <예 : 단어가 서로 결합하는 경우>
		{
			tmp_string.Clear();

			//AppLog("에디트 원본 : %S", popup_edit_area->GetText().GetPointer());

		    restoration_edit_str.GetCharAt(popup_edit_area->GetCursorPosition(), tmp_char);
		    restoration_edit_str.GetCharAt(popup_edit_area->GetCursorPosition()-1, tmp_char2);

		    if(tmp_char == ' ' && tmp_char2 == ' ')
		    {
		        for(i=0; i<cur_stack.GetCount(); i++)
		        {
		    		tmp_int = static_cast< Integer *> (cur_stack.GetAt(i));
		    		if(tmp_int->value == popup_edit_area->GetCursorPosition())
		    		{
		    			cur_stack.RemoveAt(i);
		    			break;
		    		}
		        }

				arr_text_element_editing_mark.SetAt(new Integer(1), delete_index);
				AppLog("deleteIndex : %d", delete_index);
		    	restoration_edit_str.Remove(popup_edit_area->GetCursorPosition()-1, 1);
		    	delete_cnt++;
		    }

		    else
		    {
		    	int cnt = 1;

				for(i=0; i<arr_edit_text_element.GetCount(); i++)
				{
					pTmp_edt_string = static_cast< String *> (arr_edit_text_element.GetAt(i));

					pTmp_ori_string = static_cast< String *> (arr_text_element.GetAt(i+start_index));

					tmp_int = static_cast< Integer *> (arr_text_element_editing_mark.GetAt(i+start_index + 1));

					if(tmp_int->value == 1)
					{
						cnt = 2;
						while(1)
						{
							tmp_int = static_cast< Integer *> (arr_text_element_editing_mark.GetAt(i+start_index + cnt));
							if(tmp_int->value != 1)
								break;
							cnt++;
						}
					}

					if(pTmp_edt_string->Equals(*pTmp_ori_string) == false)
					{
						tmp_string.Append(*pTmp_ori_string);
						tmp_string.Remove(tmp_string.GetLength()-1,1);

						pTmp_ori_string = static_cast< String *> (arr_text_element.GetAt(i+start_index+cnt));
						tmp_string.Append(*pTmp_ori_string);

						arr_text_element_editing_mark.SetAt(new Integer(3), i+start_index);
						//arr_text_element_editing_mark.SetAt(new Integer(3), i+start_index+1);

						cur_stack.Add(new Integer(popup_edit_area->GetCursorPosition()));

						break;
					}

				}
		    }
		}

		else if(word_cnt_gap == 0)
		{

		    for(i=0; i<cur_stack.GetCount(); i++)
		    {
				tmp_int = static_cast< Integer *> (cur_stack.GetAt(i));
				if(tmp_int->value >= popup_edit_area->GetCursorPosition())
				{
					tmp_int->value--;
					//restoration_edit_str.Insert(' ', tmp_int->value);
				}
		    }

			tmp_string = restoration_edit_str;
			arr_edit_text_element.RemoveAll();
			for(i=0; i<tmp_string.GetLength(); i++)
			{
				tmp_string.GetCharAt(i, tmp_char);
				tmp_str.Append(tmp_char);
				if(tmp_char == ' ' && (i+1) < tmp_string.GetLength())
				{
					tmp_string.GetCharAt(i+1,tmp_char);
					if(tmp_char != ' ')
					{
						arr_edit_text_element.Add(new String(tmp_str));
						tmp_str.Clear();
					}
				}
				else if(i == tmp_string.GetLength()-1)
				{
					arr_edit_text_element.Add(new String(tmp_str));
					tmp_str.Clear();
				}
			}
			int tmp_edit_index = 0;
		    for(i=0; i<arr_edit_text_element.GetCount() + delete_cnt; i++)
		    {

			    tmp_int = static_cast< Integer *> (arr_text_element_editing_mark.GetAt(i+start_index));

			    if(tmp_int->value == 1)
			    {

			    	AppLog("들어옴 ");
			    }
			    else
			    {

					pTmp_edt_string = static_cast< String *> (arr_edit_text_element.GetAt(tmp_edit_index));

					pTmp_ori_string = static_cast< String *> (arr_text_element.GetAt(i+start_index));

					if(pTmp_edt_string->Equals(*pTmp_ori_string) == false)
					{
						if(tmp_int->value == 3 || tmp_int->value == 4)
							arr_text_element_editing_mark.SetAt(new Integer(4), i+start_index );
						else
							arr_text_element_editing_mark.SetAt(new Integer(2), i+start_index );

						delete_index = i+start_index ;
					}
					tmp_edit_index++;
			    }
		    }

		   // for(i=0; i<arr_edit_text_element.getc)
		}

		else if(word_cnt_gap < 0)
		{
		    insert_cnt++;
			AppLog("들어왔다!!");
		    for(i=0; i<1000; i++)
		    {
		    	pTmp_edt_string = static_cast< String *> (arr_edit_text_element.GetAt(i));
		    	if(popup_edit_area->GetCursorPosition() <= current_length)
		    		break;
		    	current_length += pTmp_edt_string->GetLength();
		    }
		    int cur_idx = i;

		    pTmp_edt_string = static_cast< String *> (arr_edit_text_element.GetAt(cur_idx-1));
		    insert_str.Add(new String(*pTmp_edt_string));
		    insert_index_stack.Add(new Integer(cur_idx+start_index-insert_cnt-1));
		    current_length -= pTmp_edt_string->GetLength();

		    insert_start_index.Add(new Integer(current_length));
		    AppLog("cur_idx : %d", current_length);
		    AppLog("cur_idx_text : %S", pTmp_edt_string->GetPointer());



		    pTmp_edt_string = static_cast< String *> (arr_edit_text_element.GetAt(cur_idx));
		    pTmp_ori_string = static_cast< String *> (arr_edit_text_element.GetAt(cur_idx+start_index-insert_cnt));
		    if(pTmp_ori_string->Equals(*pTmp_ori_string) == true)
		    {
		    	arr_text_element_editing_mark.SetAt(new Integer(0), cur_idx+start_index-insert_cnt );
		    }

			/*
		    for(i=0; i<cur_stack.GetCount(); i++)
		    {
				tmp_int = static_cast< Integer *> (cur_stack.GetAt(i));
				if(tmp_int->value <= popup_edit_area->GetCursorPosition())
				{
					tmp_int->value++;
					//restoration_edit_str.Insert(' ', tmp_int->value);
				}
		    }



		    for(i=0; i<cur_idx; i++)
		    {

			    tmp_int = static_cast< Integer *> (arr_text_element_editing_mark.GetAt(i+start_index));

			    if(tmp_int->value == 1)
			    {
			    	arr_text_element_editing_mark.SetAt(new Integer(2), i+start_index );
			    	insert_check = true;
			    	break;
			    }


		    }
		    if(insert_check == false)
		    {
		    	pTmp_edt_string = static_cast< String *> (arr_edit_text_element.GetAt(i));
		    	insert_index_stack.Add(new Integer(cur_idx));
			    insert_str.Add(new String(*pTmp_edt_string));
				AppLog("insert_str : %S", pTmp_edt_string->GetPointer());
			}*/
		}

		AppLog("edit_text33 : %S", restoration_edit_str.GetPointer());
		AppLog("지워진 단어 개수 : %d", delete_cnt);

		for(i=start_index; i<=end_index; i++)
		{
			pTmp_ori_string = static_cast< String *> (arr_text_element.GetAt(i));
			tmp_int = static_cast< Integer *> (arr_text_element_editing_mark.GetAt(i));

			if(tmp_int->value == 3)
			{
				AppLog("붙임 %S ", pTmp_ori_string->GetPointer());
			}
			else if(tmp_int->value == 2)
			{
				AppLog("수정 %S ", pTmp_ori_string->GetPointer());
			}
			else if(tmp_int->value == 1)
			{
				AppLog("지움 %S ", pTmp_ori_string->GetPointer());
			}
			else if(tmp_int->value == 4)
			{
				AppLog("붙임&수정 %S ", pTmp_ori_string->GetPointer());
			}
		}
	}



}

void
Editing::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoForward(ForwardSceneTransition(SCENE_MAIN_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));
}

void
Editing::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
Editing::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}




void
Editing::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here


}

void
Editing::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Editing::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Editing::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
Editing::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

	int i = 0;
	Rectangle   *tmp_rect, *tmp_rect2;
	Point		tmp_point;

	draw_timer.Start(100);

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

	this->RequestRedraw(true);


}

void
Editing::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	touch_point = currentPosition;

	AppLog("touch");

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
Editing::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
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

		this->RequestRedraw(true);
	}

	if(onHighlightStart == true)
	{
		screenPosition = this->ConvertToScreenPosition(currentPosition);
		contextMenu->SetAnchorPosition(screenPosition);
		bool abc = contextMenu->HasFocus();
		ShowContextMenu(true, screenPosition);

		abc = contextMenu->HasFocus();
	}

	int x,y;

	Integer a;
	String s;

	a.Parse(s, x);
	AppLog("x : %S", s.GetPointer());

	a.Parse(s, y);
	AppLog("y : %S", s.GetPointer());
}

void
Editing::ShowContextMenu(bool show, Point currentPosition)
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
Editing::OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{

}
void
Editing::OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition)
{
	int i;
	Rectangle *tmp_rect, *tmp_rect2;
	static int old_scrollPosition = 0;
	static int start_point = 0;
	int scrollgap = 0;
	int current_y = start_point;

	Integer a;
	String s;


	if(old_scrollPosition < scrollPosition)
	{
		scrollgap = scrollPosition - old_scrollPosition;
		if(scrollPosition == scroll_end_point)
		{
			start_point = 0 - scroll_end_point;
		}
		else
		{
			start_point -= scrollgap;
		}
		current_y = start_point;
	}

	else if(old_scrollPosition > scrollPosition)
	{
		scrollgap = old_scrollPosition - scrollPosition;
		if(scrollPosition == 0)
		{
			start_point = 0;
		}
		else
		{
			start_point += scrollgap;
		}
		current_y = start_point;
	}
	s = a.ToString(current_y);

	AppLog("current_y : %S", s.GetPointer());


	s =  a.ToString(scrollPosition);

	AppLog("scrollPositoin : %S", s.GetPointer());

	for(i=0; i<arr_text_element.GetCount(); i++)
	{
		tmp_rect = static_cast< Rectangle* > (arr_text_element_rect.GetAt(i));

		arr_text_element_rect.SetAt(new Rectangle(tmp_rect->x, current_y, tmp_rect->width, tmp_rect->height), i);

		if(i+1 < arr_text_element.GetCount())
		{
			tmp_rect2 = static_cast< Rectangle* > (arr_text_element_rect.GetAt(i+1));

			if(tmp_rect->y < tmp_rect2->y)
				current_y += STRIATION_SPACING;
		}
	}

	old_scrollPosition = scrollPosition;



	this->RequestRedraw(true);
}
void
Editing::OnScrollStopped (Tizen::Ui::Control &source)
{

}

