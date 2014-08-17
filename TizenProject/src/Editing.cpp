/*
 * Editing.cpp
 *
 *  Created on: Aug 7, 2014
 *      Author: pji
 */


#include "AppResourceId.h"
#include "SceneRegister.h"
#include "Editing.h"
#include "EditPanel.h"

#define STRIATION_SPACING 100

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


}
void
Editing::OnTimerExpired (Timer &timer)
{
	EditPanel *ep = static_cast <EditPanel *>(panel_view->GetControl(0));
	//if(onHighlightStart == true)
	{
		if(&timer == &timer)
		{
			if(ep->scroll_state == 2)
			{
				scroll_position+=25;
				if(scroll_position >= panel_view->GetHeight())
					scroll_position = panel_view->GetHeight();

				panel_view->SetScrollPosition(scroll_position);
			}
			else if(ep->scroll_state == 3)
			{

				scroll_position-=25;
				if(scroll_position <= 0)
					scroll_position = 0;
				panel_view->SetScrollPosition(scroll_position);
			}
			timer.Start(75);
		}
	}

}



bool
Editing::Initialize(void)
{
	result r =  Construct(FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();


	str_content = L"이용수 위원장은 협상팀과 함께 지난 4일 출국해 6일 귀국했고 곧바로 7일 브리핑을 하는 셈이다. 큰 틀에서 이미 판 마르바이크 감독과 합의가 이루어진 것으로 예상할 수 있는 대목이다. 판 마르바이크 감독과의 교감이 없었다면 굳이 브리핑을 할 이유가 없으며 다른 후보자들을 두고 조기 귀국할 이유 역시 없기 때문이다. 사실상 판 마르바이크 감독과의 세부적인 조율만을 남겨놓고 있다는 전망이 나오고 있는 이유다. 이미 네덜란드 언론에서도 판 마르바이크 감독이 한국와의 협상이 진행중이라는 보도가 나온 만큼 대한축구협회가 판 마르바이크 감독에게 관심을 보이고 있다는 사실은 더 이상 비밀이 아니다. 7일 열리는 브리핑을 통해 한국 축구대표팀 차기 감독의 윤곽이 드러날지 기대된다.";
	Eng = L"Chairman of the past four days to leave the water six days he returned with the negotiating team and that the briefing is Shem 7 days straight. It is to be expected that the agreement made ​​board director and Marquez already big frame bike passage. Without sympathetic because of the dry plate bike coach no reason to doubt why the briefing dare not leave the other candidates to return home early. The only reason that comes the prospect that detailed coordination and supervision left on the bike virtually dry plate. It is not a secret that there already seems to plate dry bike in Dutch media director for the Football Association as from the reports of the negotiations with South Korea coach underway dry plate is no longer interested in bikes. Briefing paper is expected to be revealed over the seven days of the South Korea national football team will open the outline next coach.";

	head = new Panel();
	profile_image_panel = new Panel();


	Button *profile_button[5];


	profile_button[0] = new Button();
	profile_button[1] = new Button();
	profile_button[2] = new Button();
	profile_button[3] = new Button();
	profile_button[4] = new Button();


	profile_button[0]->Construct(Rectangle(30,30,130,130), L" ");
	profile_button[0]->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"tizen.png"));
	profile_button[0]->SetActionId(300);


	for(int i=1; i<5; i++)
	{
		profile_button[i]->Construct(Rectangle(250 + (i*90),50,80,80), L" ");
		profile_button[i]->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"tizen.png"));
		profile_button[i]->SetActionId(301+i);
	}

	editing_button = new Button();
	eng_button = new Button();
	editing_completion_button = new Button();

	head->Construct(Rectangle(0,0,this->GetWidth(), 96));
	head->SetBackgroundColor(Color(0,181,238,255));

	profile_image_panel->Construct(Rectangle(0,96,this->GetWidth(), 377-96));
	//profile_image_panel->SetBackgroundColor(Color(246,246,0,255));

	Label *tmp_label2 = new Label;



	//profile_image_panel->AddControl(tmp_label2);
	//profile_image_panel->AddControl(cur_label);

	for(int i=0; i<5; i++)
		profile_image_panel->AddControl(profile_button[i]);



	editing_button->Construct(Rectangle(0,0,287,96));
	editing_button->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"head_editing_button.png")));

	eng_button->Construct(Rectangle(this->GetWidth()-130,15,120, 66));
	eng_button->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"Eng.png")));
	eng_button->AddActionEventListener(*this);
	eng_button->SetActionId(90);

	editing_completion_button->Construct(Rectangle(204, 1120, 315, 73));
	editing_completion_button->SetNormalBackgroundBitmap(*(pAppResource->GetBitmapN(L"editing_completion_inact.png")));


	EditPanel *ep;

	ep = new EditPanel;

	ep->Construct(" ", true);
	panel_view = new ScrollPanel;

	panel_view->Construct(Rectangle(0, 390, this->GetWidth(), 710));
	panel_view->AddControl(ep);

	panel_view->AddTouchEventListener(*this);
	panel_view->AddScrollEventListener(*this);





	this->AddControl(head);
	this->AddControl(editing_button);
	this->AddControl(eng_button);
	this->AddControl(profile_image_panel);
	this->AddControl(editing_completion_button);
	this->AddControl(panel_view);


	timer.Construct(*this);
	timer.Start(75);
	return true;
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
	case 301:
	{

	}
	break;
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
	AppLog("long");
}
void
Editing::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void
Editing::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void
Editing::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void
Editing::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void
Editing::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}
void
Editing::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}


void
Editing::OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type)
{

}
void
Editing::OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition)
{
	EditPanel *ep = static_cast <EditPanel *>(panel_view->GetControl(0));

	AppLog("current lightmode : %d",ep->GetHighligtmode());
	AppLog("scrollPosition : %d",scrollPosition);
	AppLog("scroll___Position : %d",scroll_position);
	if(ep->GetHighligtmode() == true)
	{
		panel_view->SetScrollPosition(scroll_position);
	}
	else
		scroll_position = scrollPosition;


}
void
Editing::OnScrollStopped (Tizen::Ui::Control &source)
{

}
