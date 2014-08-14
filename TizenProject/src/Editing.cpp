/*
 * Editing.cpp
 *
 *  Created on: Aug 7, 2014
 *      Author: pji
 */


#include "AppResourceId.h"
#include "SceneRegister.h"
#include "Editing.h"

#define STRIATION_SPACING 100

#define	NONE 0
#define DELETED 1
#define REPLACED 2
#define ATTACHED 3;
#define ATTACHED_AND_REPLACED 4;
#define INSERTED 5



EditWord&
EditWord::operator = (const EditWord& rhs)
{
	if(this == &rhs)
	{
		return *this;

	}
	word = rhs.word;
	start_index = rhs.start_index;
	end_index = rhs.end_index;
	state = rhs.state;
	blank_cnt = rhs.blank_cnt;
	arr_insert = rhs.arr_insert;

	return *this;
}

bool
EditWord::operator == (const EditWord& rhs) const
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
EditWord::operator != (const EditWord& rhs) const
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
	Integer	  *tmp_int;
	String	  *tmp_insert_str;
	Integer   *tmp_check;
	Font font;
    font.Construct(FONT_STYLE_PLAIN, 30);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	Rectangle tmp_client_rect = GetClientAreaBounds();

	Canvas *pCanvas = this->GetCanvasN(Rectangle(30,tmp_client_rect.y+377,this->GetWidth()-60, tmp_client_rect.height-497));
	pCanvas->SetFont(font);


	//pCanvas->DrawBitmap(Rectangle(0,0,this->GetWidth(), 855), *(pAppResource->GetBitmapN(L"editing_background.png")));
	//pCanvas->FillRectangle(Color(246,246,246,255), Rectangle(0,0,this->GetWidth(), tmp_client_rect.height-497));
	pCanvas->FillRectangle(Color(255,255,255,255), Rectangle(0,0,this->GetWidth()-60, tmp_client_rect.height-497));

	for(i=0; i<arr_text_element.GetCount(); i++)
	{
		tmp_rect = static_cast< Rectangle* > (arr_text_element_rect.GetAt(i));
		tmp_string = static_cast< String *> (arr_text_element.GetAt(i));
		tmp_highlight = static_cast <Boolean *> (arr_text_element_highlight.GetAt(i));
		tmp_int = static_cast< Integer *> (arr_text_element_editing_mark.GetAt(i));
		tmp_check = static_cast< Integer *> (arr_insert_check.GetAt(i));
		tmp_insert_str = static_cast< String *> (arr_text_insert.GetAt(i));

		if(tmp_rect->height < 0 || tmp_rect->y > tmp_client_rect.height-497)
		{

		}
		else
		{
			if(tmp_highlight->ToBool() == true)
			{
				pCanvas->DrawText(Point(tmp_rect->x, tmp_rect->y), *tmp_string, Color(0,255,0,150));
			}
			else
			{
				pCanvas->DrawText(Point(tmp_rect->x, tmp_rect->y), *tmp_string);
			}
			if(tmp_int->value == 2)
			{

				pCanvas->FillRectangle(Color(0,187,237,255), Rectangle(tmp_rect->x, tmp_rect->y+15, tmp_rect->width, 5));
				pCanvas->DrawText(Point(tmp_rect->x, tmp_rect->y + tmp_rect->height), *tmp_insert_str, Color(0,187,237,255));

			}
			else if(tmp_int->value == 1)
			{
				pCanvas->FillRectangle(Color(0,187,237,255), Rectangle(tmp_rect->x, tmp_rect->y+15, tmp_rect->width, 5));
			}
			else if(tmp_check->value == 1)
			{
				pCanvas->DrawBitmap(Rectangle(tmp_rect->x-15, tmp_rect->y+15, 30 , 15), *pAppResource->GetBitmapN(L"attach_mark.png"));
				pCanvas->DrawText(Point(tmp_rect->x-(tmp_insert_str->GetLength()/2), tmp_rect->y + tmp_rect->height), *tmp_insert_str, Color(0,255,0,255));
			}
			else if(tmp_check->value == 2)
			{
				pCanvas->DrawBitmap(Rectangle(tmp_rect->x-15, tmp_rect->y+15, 30 , 15), *pAppResource->GetBitmapN(L"attach_mark.png"));
				pCanvas->DrawText(Point(tmp_rect->x-(tmp_insert_str->GetLength()/2), tmp_rect->y + tmp_rect->height), *tmp_insert_str, Color(0,255,0,255));
				tmp_insert_str = static_cast< String *> (arr_text_insert.GetAt(i+1));
				pCanvas->DrawBitmap(Rectangle(tmp_rect->x-15, tmp_rect->y+15, 30 , 15), *pAppResource->GetBitmapN(L"attach_mark.png"));
				pCanvas->DrawText(Point(tmp_rect->x-(tmp_insert_str->GetLength()/2), tmp_rect->y + tmp_rect->height), *tmp_insert_str, Color(0,255,0,255));
			}
			else if(tmp_check->value == 3)
			{
				tmp_insert_str = static_cast< String *> (arr_text_insert.GetAt(i+1));
				pCanvas->DrawBitmap(Rectangle(tmp_rect->x-15, tmp_rect->y+15, 30 , 15), *pAppResource->GetBitmapN(L"attach_mark.png"));
				pCanvas->DrawText(Point(tmp_rect->x-(tmp_insert_str->GetLength()/2), tmp_rect->y + tmp_rect->height), *tmp_insert_str, Color(0,255,0,255));
			}
			pCanvas->DrawRectangle(*tmp_rect);
		}
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
	//if(onHighlightStart == true)
	{
		if(&timer == &draw_timer)
		{
			this->RequestRedraw(true);
			draw_timer.Start(70);
			AppLog("Timer On!!");
		}
	}

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

	str_content = L"이용수 위원장은 협상팀과 함께 지난 4일 출국해 6일 귀국했고 곧바로 7일 브리핑을 하는 셈이다. 큰 틀에서 이미 판 마르바이크 감독과 합의가 이루어진 것으로 예상할 수 있는 대목이다. 판 마르바이크 감독과의 교감이 없었다면 굳이 브리핑을 할 이유가 없으며 다른 후보자들을 두고 조기 귀국할 이유 역시 없기 때문이다. 사실상 판 마르바이크 감독과의 세부적인 조율만을 남겨놓고 있다는 전망이 나오고 있는 이유다. 이미 네덜란드 언론에서도 판 마르바이크 감독이 한국와의 협상이 진행중이라는 보도가 나온 만큼 대한축구협회가 판 마르바이크 감독에게 관심을 보이고 있다는 사실은 더 이상 비밀이 아니다. 7일 열리는 브리핑을 통해 한국 축구대표팀 차기 감독의 윤곽이 드러날지 기대된다.";
	Eng = L"Chairman of the past four days to leave the water six days he returned with the negotiating team and that the briefing is Shem 7 days straight. It is to be expected that the agreement made ​​board director and Marquez already big frame bike passage. Without sympathetic because of the dry plate bike coach no reason to doubt why the briefing dare not leave the other candidates to return home early. The only reason that comes the prospect that detailed coordination and supervision left on the bike virtually dry plate. It is not a secret that there already seems to plate dry bike in Dutch media director for the Football Association as from the reports of the negotiations with South Korea coach underway dry plate is no longer interested in bikes. Briefing paper is expected to be revealed over the seven days of the South Korea national football team will open the outline next coach.";
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
					arr_text_element_rect.Add(new Rectangle(current_x, current_y, tmp_dim.width ,STRIATION_SPACING/2));
					arr_text_element_editing_mark.Add(new Integer(NONE));
					arr_insert_check.Add(new Integer(0));
					arr_text_insert.Add(new String(""));
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
				arr_text_element_rect.Add(new Rectangle(current_x, current_y, tmp_dim.width ,STRIATION_SPACING/2));
				arr_text_element_editing_mark.Add(new Integer(NONE));
				arr_insert_check.Add(new Integer(0));
				arr_text_insert.Add(new String(""));
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

	Button *profile_button[5];


	profile_button[0] = new Button();
	profile_button[1] = new Button();
	profile_button[2] = new Button();
	profile_button[3] = new Button();
	profile_button[4] = new Button();


	profile_button[0]->Construct(Rectangle(30,30,130,130), L" ");
	profile_button[0]->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"tizen.png"));
	profile_button[0]->SetActionId(300);
	profile_button[0]->AddTouchEventListener(*this);


	for(int i=1; i<5; i++)
	{
		profile_button[i]->Construct(Rectangle(250 + (i*90),50,80,80), L" ");
		profile_button[i]->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"tizen.png"));
		profile_button[i]->SetActionId(301+i);
		profile_button[i]->AddTouchEventListener(*this);
	}

	tmp_label->Construct(Rectangle(current_y+STRIATION_SPACING, 0, 720, current_y+STRIATION_SPACING+1), " ");
	scroll_end_point = (current_y+STRIATION_SPACING)-(GetClientAreaBounds().height-497);

	editing_button = new Button();
	eng_button = new Button();
	editing_completion_button = new Button();

	head->Construct(Rectangle(0,0,this->GetWidth(), 96));
	head->SetBackgroundColor(Color(0,181,238,255));

	profile_image_panel->Construct(Rectangle(0,96,this->GetWidth(), 377-96));
	//profile_image_panel->SetBackgroundColor(Color(246,246,0,255));

	Label *tmp_label2 = new Label;

	cur_label = new Label;

	cur_label->Construct(Rectangle(65,176,31,19), " ");
	cur_label->SetBackgroundBitmap(*pAppResource->GetBitmapN(L"edit_background_cursor.png"));
	tmp_label2->Construct(Rectangle(30,195,this->GetWidth()-60,86)," ");
	tmp_label2->SetBackgroundBitmap(*pAppResource->GetBitmapN(L"editing_background_text.png"));

	profile_image_panel->AddControl(tmp_label2);
	profile_image_panel->AddControl(cur_label);

	for(int i=0; i<5; i++)
		profile_image_panel->AddControl(profile_button[i]);

	editing_background->Construct(Rectangle(30,377,this->GetWidth()-60, GetClientAreaBounds().height-497), SCROLL_PANEL_SCROLL_DIRECTION_VERTICAL, true);
	//editing_background->SetBackgroundColor(Color(255,255,255,0));
	editing_background->SetScrollBarVisible(true);
	editing_background->AddControl(tmp_label);


	editing_button->Construct(Rectangle(0,0,287,96));
	editing_button->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"head_editing_button.png")));

	eng_button->Construct(Rectangle(this->GetWidth()-130,15,120, 66));
	eng_button->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"Eng.png")));
	eng_button->AddActionEventListener(*this);
	eng_button->SetActionId(90);

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


    for(i=0; i<200; i++)
    {
    	plus[i] = 0;
    	minus[i] = 0;
    }

    plus_cnt = 0;
    minus_cnt = 0;

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
	draw_timer.Start(300);

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



	    popup = new Popup;

	        popup->Construct(false, Dimension(600,800));

	        popup->SetPosition(60,30);

	        popup->SetColor(Color(246,246,246,255));



	        Label *label_ori, *label_edit, *label_explain;



	        label_ori = new Label;

	        label_ori->Construct(Rectangle(30,20,100,40), L"원문");

	        popup_ori_area = new EditArea();

	        popup_ori_area->Construct(Rectangle(50, 60, 500, 150),INPUT_STYLE_OVERLAY);

	        popup_ori_area->SetKeypadEnabled(false);

	        popup_ori_area->SetColor(EDIT_STATUS_NORMAL, Color(216,216,216,255));
	        popup_ori_area->SetColor(EDIT_STATUS_PRESSED, Color(216,216,216,255));
	        popup_ori_area->SetColor(EDIT_STATUS_HIGHLIGHTED, Color(216,216,216,255));

	        popup_ori_area->SetText(popup_edit_string);

	        popup->AddControl(popup_ori_area);

	        popup->AddControl(label_ori);



	        label_edit = new Label;

	        label_edit->Construct(Rectangle(30,220,280,40), L"글을 수정해주세요");

	        popup_edit_area = new EditArea();

	        popup_edit_area->Construct(Rectangle(50, 270, 500, 150),INPUT_STYLE_OVERLAY);
	        popup_edit_area->SetFocus();

	        popup_edit_area->SetText(popup_edit_string);
	        popup_edit_area->SetColor(EDIT_STATUS_NORMAL, Color(255,255,255,255));
	        popup_edit_area->SetColor(EDIT_STATUS_PRESSED , Color(255,255,255,255));
	        popup_edit_area->SetColor(EDIT_STATUS_HIGHLIGHTED, Color(255,255,255,255));
	        popup_edit_area->AddKeyEventListener(*this);

	        popup->AddControl(popup_edit_area);

	        popup->AddControl(label_edit);



	        label_explain = new Label;

	        label_explain->Construct(Rectangle(30,430,200,40), L"피드백 설명");

	        popup_explain = new EditArea();

	        popup_explain->Construct(Rectangle(50, 480, 500, 150),INPUT_STYLE_OVERLAY);
	        popup_explain->SetColor(EDIT_STATUS_HIGHLIGHTED, Color(255,255,255,255));
	        popup_explain->SetColor(EDIT_STATUS_PRESSED, Color(255,255,255,255));
	        popup_explain->SetColor(EDIT_STATUS_NORMAL, Color(255,255,255,255));



	        popup->AddControl(popup_explain);

	        popup->AddControl(label_explain);



	        Button* pCloseButton = new Button();

	        pCloseButton->Construct(Rectangle(20, 630, 250, 80), L"Close Popup");

	        pCloseButton->SetActionId(2);

	        pCloseButton->AddActionEventListener(*this);



	        // Adds the button to the popup

	        popup->AddControl(pCloseButton);



	        Button* CompletionButton = new Button();

	        CompletionButton->Construct(Rectangle(20, 630, 250, 80), L"Completion");

	        CompletionButton->SetActionId(3);

	        CompletionButton->AddActionEventListener(*this);

        // Adds the button to the popup
       // popup->AddControl(CompletionButton);





        // 원문의 단어와 첨삭본의 단어의 개수를 구한다.

        EditWord *tmp_word;
        int tmp_length = 0;
        for(i=start_index; i<=end_index; i++)
        {
			tmp_string = static_cast< String *> (arr_text_element.GetAt(i));
			tmp_word = new EditWord;
			tmp_word->word = *tmp_string;
			tmp_word->start_index = tmp_length;
			tmp_length += tmp_word->word.GetLength();
			tmp_word->end_index = tmp_length;
			arr_ori_word.Add(*tmp_word);
			//arr_text_element_editing_mark.Add(new Integer(NONE));
        }

        edit_area_length = popup_edit_string.GetLength();


        draw_timer.Cancel();
        ShowPopup();


        break;
	}
	case 2:
	{
		int i;
		Integer *tmp_int;
		String *tmp_str;
		Integer *tmp_check;

		Attached_decision();
		SyncText();
		TextCorrecting();

		/*EditWord tmp_word;
		for(i = 0; i < arr_ori_word.GetCount(); i++)
		{
			tmp_int = arr_text_element_editing_mark.GetAt(i);
			if(tmp_int == 3)
				AppLog("attach : %S, index : %d", tmp_word.word.GetPointer(), tmp_word.start_index);
		}
		for(i = 0; i < arr_edit_word.GetCount(); i++)
		{
			tmp_int = arr_text_element_editing_mark.GetAt(i);
			if(tmp_int == 3)
				AppLog("attach : %S, index : %d", tmp_word.word.GetPointer(), tmp_word.start_index);
		}*/

		for(i = 0; i < arr_text_element.GetCount(); i++)
		{
			tmp_int = static_cast< Integer *> (arr_text_element_editing_mark.GetAt(i));
			tmp_str = static_cast< String *> (arr_text_element.GetAt(i));
			tmp_check = static_cast< Integer *> (arr_insert_check.GetAt(i));

			AppLog("abra int : %d", tmp_int->value);

			if(tmp_int->value == 3)
				AppLog("attach : %S", tmp_str->GetPointer());
			else if(tmp_int->value == 2)
				AppLog("modify : %S", tmp_str->GetPointer());
			else if(tmp_int->value == 1)
				AppLog("delete : %S", tmp_str->GetPointer());
			/*else if(tmp_bool->GetTrue() == true)
			{
				tmp_str = static_cast< String *> (arr_text_insert.GetAt(i));
				AppLog("insert : %S", tmp_str->GetPointer());
			}*/
		}

		HidePopup();
		popup_edit_string.Clear();
		popup->Destroy();
		break;
	}
	case 90:
	{
		Button *button = new Button;
	    popup = new Popup;
	    AppLog("goood!!!");
	    popup->Construct(true, Dimension(600,800));
	    draw_timer.Cancel();
	    popup->SetPosition(60,60);

	    popup->SetTitleText(L"Ellen Page님의 글");

	    button->Construct(Rectangle(550,200,50,50),"닫");
	    button->SetActionId(91);
	    button->AddActionEventListener(*this);

	    EditArea *eng = new EditArea;

	    eng->Construct(Rectangle(0, 0, 550, 800),INPUT_STYLE_OVERLAY);
	    eng->SetKeypadEnabled(false);
	    eng->SetText(Eng);
	    eng->SetColor(EDIT_STATUS_HIGHLIGHTED, Color(255,255,255,255));
	    eng->SetColor(EDIT_STATUS_PRESSED, Color(255,255,255,255));
	    eng->SetColor(EDIT_STATUS_NORMAL, Color(255,255,255,255));

	    popup->SetColor(Color(255,255,255,255));

	    popup->AddControl(button);
	    popup->AddControl(eng);

	    ShowPopup();
	    break;

	}
	case 91:
	{
		HidePopup();
		popup->Destroy();
		break;
	}
	}
}

void
Editing::TextCorrecting()
{
	int i,j;
	//ArrayListT<EditWord> result_word;
	EditWord tmp_word, tmp_word2;
	String	tmp_str;
	Integer *tmp_int;


	if(arr_ori_word.GetCount() > arr_edit_word.GetCount())
	{
		int revise = 0;
		for(i=start_index; i<=end_index; i++)
		{

			arr_ori_word.GetAt(i, tmp_word);
			tmp_int = static_cast< Integer *> (arr_text_element_editing_mark.GetAt(i));


			if(tmp_int->value != 3)
			{
				for(j=i-start_index+revise; j<=i-start_index+revise; j++)
				{
					arr_edit_word.GetAt(j, tmp_word2);
					//AppLog("ori_index : %S , %d", tmp_word.word.GetPointer(), tmp_word.start_index);
					AppLog("edit_index : %S , %d", tmp_word2.word.GetPointer(), tmp_word2.start_index);
					if(tmp_word.start_index == tmp_word2.start_index)
					{
						if(tmp_word.word.Equals(tmp_word2.word) == true)
						{
							AppLog("tmp_word : %S", tmp_word.word.GetPointer());
							AppLog("tmp_word2 : %S", tmp_word2.word.GetPointer());
							arr_text_element_editing_mark.SetAt(new Integer(0), i);
							break;
						}
						else
						{
							tmp_str.Clear();
							arr_text_element_editing_mark.SetAt(new Integer(2), i);
							AppLog("tmp_word11 : %S", tmp_word.word.GetPointer());
							AppLog("tmp_word22 : %S", tmp_word2.word.GetPointer());
							tmp_str.Append(tmp_word2.word);
							arr_text_insert.SetAt(new String(tmp_str), i);
							break;
						}
					}
					else if(tmp_word2.start_index < tmp_word.start_index)
					{
						arr_text_element_editing_mark.SetAt(new Integer(1), i);
						revise++;
					}

				}
			}
		}
	}
	else if(arr_ori_word.GetCount() <= arr_edit_word.GetCount())
	{
		int revise = 0;
		for(i=start_index; i<=end_index; i++)
		{
			arr_ori_word.GetAt(i, tmp_word);
			tmp_str.Clear();
			tmp_int = static_cast< Integer *> (arr_text_element_editing_mark.GetAt(i));
			AppLog("tmp_int!!! : %d", tmp_int->value);
			if(tmp_int->value != 3)
			{
				for(j=i-start_index+revise; j<=i-start_index+revise; j++)
				{
					arr_edit_word.GetAt(j, tmp_word2);
					if(tmp_word.start_index == tmp_word2.start_index)
					{
						if(tmp_word.word.Equals(tmp_word2.word) == true)
						{
							arr_text_element_editing_mark.SetAt(new Integer(0), i);
							break;
						}
						else
						{
							arr_text_element_editing_mark.SetAt(new Integer(2), i);
							AppLog("tmp_word11 : %S", tmp_word.word.GetPointer());
							AppLog("tmp_word22 : %S", tmp_word2.word.GetPointer());
							tmp_str.Append(tmp_word2.word);
							arr_text_insert.SetAt(new String(tmp_str), i);
							break;
						}
					}
					else if(tmp_word2.start_index < tmp_word.start_index)
					{
						AppLog("!! ori_index : %S , %d", tmp_word.word.GetPointer(), tmp_word.start_index);
						AppLog("!! arr_edit_word %S , %d ", tmp_word2.word.GetPointer(),tmp_word2.start_index);

						arr_insert_check.SetAt(new Integer(1), i);
						tmp_str.Append(tmp_word2.word);
						arr_text_insert.SetAt(new String(tmp_str), i);

						revise++;

					}
				//	AppLog("afsdf %d", i);

				//	AppLog("edit_index : %S , %d", tmp_word2.word.GetPointer(), tmp_word2.start_index);
				}


			}
		}
		tmp_str.Clear();
		AppLog("tmp_str_good11 : %S", tmp_str.GetPointer());
		for(i=end_index-start_index+revise+1; i<arr_edit_word.GetCount(); i++)
		{
			tmp_int = static_cast< Integer *> (arr_insert_check.GetAt(end_index-start_index+revise));
			if(tmp_int->value == 1)
			{
				arr_edit_word.GetAt(i, tmp_word2);
				arr_insert_check.SetAt(new Integer(2), end_index-start_index+revise);
				tmp_str.Append(tmp_word2.word);
				arr_text_insert.SetAt(new String(tmp_str), end_index-start_index+revise+1);

				AppLog("tmp_str_good22 : %S", tmp_str.GetPointer());

			}
			else
			{
				arr_edit_word.GetAt(i, tmp_word2);
				arr_insert_check.SetAt(new Integer(3), end_index-start_index+revise);
				tmp_str.Append(tmp_word2.word);
				arr_text_insert.SetAt(new String(tmp_str), end_index-start_index+revise+1);
			}
		}
	}
}

void
Editing::SyncText()
{
	int i, j;
	EditWord *tmp_word;

	for(i = 0; i < arr_ori_word.GetCount(); i++)
	{
		tmp_word = new EditWord;
		arr_ori_word.GetAt(i, *tmp_word);
		for(j = 0; j < plus_cnt; j++)
		{
			if(plus[j] <= tmp_word->start_index)
			{
				tmp_word->start_index++;
				tmp_word->end_index++;

				arr_ori_word.SetAt(*tmp_word ,i);
			}
		}
		for(j = 0; j < minus_cnt; j++)
		{
			if(minus[j] < tmp_word->start_index)
			{
				tmp_word->start_index--;
				tmp_word->end_index--;

				arr_ori_word.SetAt(*tmp_word, i);
			}
		}
	}
}

void
Editing::Attached_decision()
{
	int i, j;
	EditWord tmp_word;
	EditWord *ptmp_word;
	String *tmp_string[3];
	String tmp_string_copy[3];
	String compare_word;
	String tmp_edit_text;
	String tmp_str;
	wchar_t tmp_char;
	int tmp_length = 0;
	tmp_edit_text = popup_edit_area->GetText();
	ptmp_word = new EditWord;
	tmp_length = 0;
	for(i=0; i<tmp_edit_text.GetLength(); i++)
	{
		tmp_edit_text.GetCharAt(i, tmp_char);
		tmp_str.Append(tmp_char);
		if(tmp_char == ' ' && (i+1) < tmp_edit_text.GetLength())
		{
			tmp_edit_text.GetCharAt(i+1,tmp_char);
			if(tmp_char != ' ')
			{
				ptmp_word = new EditWord;
				ptmp_word->word = tmp_str;
				ptmp_word->start_index = tmp_length;
				tmp_length += ptmp_word->word.GetLength();
				ptmp_word->end_index = tmp_length;
				arr_edit_word.Add(*ptmp_word);
				tmp_str.Clear();
			}
		}
		else if(i == tmp_edit_text.GetLength()-1)
		{
			ptmp_word = new EditWord;
			ptmp_word->word = tmp_str;
			ptmp_word->start_index = tmp_length;
			tmp_length += ptmp_word->word.GetLength();
			ptmp_word->end_index = tmp_length;
			arr_edit_word.Add(*ptmp_word);
			tmp_str.Clear();
		}
	}
	int revise = 0;

	for(i = 0; i < arr_edit_word.GetCount(); i++)
	{
		arr_edit_word.GetAt(i, tmp_word);

		for(j = start_index + revise; j <= end_index + revise; j++)
		{
			if(arr_text_element.GetAt(j+1) != null)
			{
				compare_word.Clear();
				tmp_string[0] = static_cast< String *> (arr_text_element.GetAt(j));
				tmp_string_copy[0] = *tmp_string[0];
				tmp_string_copy[0].Remove(tmp_string_copy[0].GetLength()-1, 1);
				compare_word.Append(tmp_string_copy[0]);

				tmp_string[1] = static_cast< String *> (arr_text_element.GetAt(j+1));
				tmp_string_copy[1] = *tmp_string[1];
				compare_word.Append(tmp_string_copy[1]);


				if(compare_word.Equals(tmp_word.word) == true)
				{
					arr_text_element_editing_mark.SetAt(new Integer(3), j);
					arr_text_element_editing_mark.SetAt(new Integer(3), j+1);
					revise = revise+2;
					break;
				}
			}
			if(arr_text_element.GetAt(j+2) != null)
			{
				compare_word.Clear();

				tmp_string[0] = static_cast< String *> (arr_text_element.GetAt(j));
				tmp_string_copy[0] = *tmp_string[0];
				tmp_string_copy[0].Remove(tmp_string_copy[0].GetLength()-1, 1);
				compare_word.Append(tmp_string_copy[0]);

				tmp_string[1] = static_cast< String *> (arr_text_element.GetAt(j+1));
				tmp_string_copy[1] = *tmp_string[1];
				tmp_string_copy[1].Remove(tmp_string_copy[1].GetLength()-1, 1);
				compare_word.Append(tmp_string_copy[1]);

				tmp_string[2] = static_cast< String *> (arr_text_element.GetAt(j+2));
				tmp_string_copy[2] = *tmp_string[2];
				compare_word.Append(tmp_string_copy[2]);

				if(compare_word.Equals(tmp_word.word) == true)
				{
					arr_text_element_editing_mark.SetAt(new Integer(3), j);
					arr_text_element_editing_mark.SetAt(new Integer(3), j+1);
					arr_text_element_editing_mark.SetAt(new Integer(3), j+2);
					revise = revise+3;
					break;
				}
			}

		}
	}

	Integer *tmp_int;
	String *tmp_str2;
	for(j = start_index; j <= end_index; j++)
	{
		tmp_int = static_cast <Integer *> (arr_text_element_editing_mark.GetAt(j));
		tmp_str2 = static_cast <String *> (arr_text_element.GetAt(j));
		if(tmp_int->value == 3)
			AppLog("붙임 : %S", tmp_str2->GetPointer());
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
	static int old_length = edit_area_length;
	int new_length = popup_edit_area->GetTextLength();
	if(old_length < new_length)
	{
		plus[plus_cnt] = popup_edit_area->GetCursorPosition()-1;
		plus_cnt++;
		AppLog("plus : %d",popup_edit_area->GetCursorPosition()-1);
	}
	else if(old_length > new_length)
	{
		minus[minus_cnt] = popup_edit_area->GetCursorPosition();
		minus_cnt++;
		AppLog("minus : %d", popup_edit_area->GetCursorPosition());
	}

	old_length = new_length;
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


	AppLog("touch_point x: %d, y : %d", touch_point.x, touch_point.y);
	AppLog("currentPosition x: %d, y : %d", currentPosition.x, currentPosition.y);
	int x_gap, y_gap;
	x_gap = abs(touch_point.y - currentPosition.y);
	y_gap = abs(touch_point.y - currentPosition.y);
	if(x_gap < 5 && y_gap < 5)
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


	AppLog("x : %d", cur_end_point.x);


	AppLog("y : %d", cur_end_point.y);
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
}
void
Editing::OnScrollStopped (Tizen::Ui::Control &source)
{

}

