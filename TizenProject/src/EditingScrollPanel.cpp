/*
 * EditingScrollPanel.cpp
 *
 *  Created on: Aug 7, 2014
 *      Author: pji
 */


/*
 * Editing.cpp
 *
 *  Created on: Aug 7, 2014
 *      Author: pji
 */


#include "AppResourceId.h"
#include "SceneRegister.h"
#include "EditingScrollPanel.h"

#define STRIATION_SPACING 50


EditingScrollPanel::EditingScrollPanel(void)
{
}

EditingScrollPanel::~EditingScrollPanel(void)
{
}

result
EditingScrollPanel::OnDraw()
{
	int i;
	Rectangle *tmp_rect;
	String	  *tmp_string;
	Boolean	  *tmp_highlight;
	Font font;
    font.Construct(FONT_STYLE_PLAIN, 30);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	Rectangle tmp_client_rect = GetClientAreaBounds();

	Canvas *pCanvas = this->GetCanvasN(Rectangle(0,0,this->GetWidth(), tmp_client_rect.height));

	pCanvas->FillRectangle(Color(246,0,200,255), Rectangle(0,0,this->GetWidth(), tmp_client_rect.height));
	pCanvas->FillRectangle(Color(246,255,0,255), Rectangle(0,200,this->GetWidth(), tmp_client_rect.height));

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

}

bool
EditingScrollPanel::Initialize(String content)
{
	result r =  Construct(FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();



	int i;
	int current_y = 0;
	int current_x = 70;

    Dimension		tmp_dim;
    String			tmp_str;
    Rectangle		panel_rect;
    wchar_t			tmp_char;
	Font font;
    font.Construct(FONT_STYLE_PLAIN, 30);

    str_content = content;
	str_content = L"이용수 위원장은 협상팀과 함께 지난 4일 출국해 6일 귀국했고 곧바로 7일 브리핑을 하는 셈이다. 큰 틀에서 이미 판 마르바이크 감독과 합의가 이루어진 것으로 예상할 수 있는 대목이다. 판 마르바이크 감독과의 교감이 없었다면 굳이 브리핑을 할 이유가 없으며 다른 후보자들을 두고 조기 귀국할 이유 역시 없기 때문이다. 사실상 판 마르바이크 감독과의 세부적인 조율만을 남겨놓고 있다는 전망이 나오고 있는 이유다. 이미 네덜란드 언론에서도 판 마르바이크 감독이 한국와의 협상이 진행중이라는 보도가 나온 만큼 대한축구협회가 판 마르바이크 감독에게 관심을 보이고 있다는 사실은 더 이상 비밀이 아니다. 7일 열리는 브리핑을 통해 한국 축구대표팀 차기 감독의 윤곽이 드러날지 기대된다.";

	for(i=0; i<str_content.GetLength(); i++)
	{
		str_content.GetCharAt(i, tmp_char);
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
					current_x = 70;
					current_y += (STRIATION_SPACING);
				}
				arr_text_element_highlight.Add(new Boolean(false));
				arr_text_element_rect.Add(new Rectangle(current_x, current_y, tmp_dim.width ,STRIATION_SPACING));
				current_x += tmp_dim.width;
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
			//this->SetBounds(30, 377, this->GetWidth()-60, + current_y+STRIATION_SPACING);

			current_x += tmp_dim.width;
			tmp_str.Clear();
		}
	}

	this->AddTouchEventListener(*this);
	this->AddScrollEventListener(*this);

	this->Show();

	return true;
}

result
EditingScrollPanel::OnInitializing(void)
{
	result r = E_SUCCESS;

	// TODO: Add your initialization code here
	// Setup back event listener

	// Get a button via resource ID


    // Adds the TableView to the form
	return r;
}

result
EditingScrollPanel::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}




void
EditingScrollPanel::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here


}

void
EditingScrollPanel::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
EditingScrollPanel::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
EditingScrollPanel::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
EditingScrollPanel::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
EditingScrollPanel::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	AppLog("Touch");
}

void
EditingScrollPanel::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}

void
EditingScrollPanel::OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{

}
void
EditingScrollPanel::OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition)
{
}
void
EditingScrollPanel::OnScrollStopped (Tizen::Ui::Control &source)
{

}



