/*
 * Chatting.cpp
 *
 *  Created on: Aug 13, 2014
 *      Author: Gants
 */


#include "Chatting.h"
#include "AppResourceId.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;


Chatting::Chatting(void)
{

}

Chatting::~Chatting(void)
{
}

bool
Chatting::Initialize(void)
{
	result r = Construct(IDL_FORM_CHAT);
	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;
}

result
Chatting::OnInitializing(void)
{
	result r = E_SUCCESS;
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

		__audioRecorder.Construct(*this);
	     __player.Construct(*this, null);


		__pPanel = static_cast<Panel *>(GetControl(L"IDC_PANEL_CHAT", false));

		__pEditField = static_cast<EditField *>(GetControl(L"IDC_EDIT_SEND", true));

		__pEditField->AddTextEventListener(*this);
		__pEditField->AddScrollPanelEventListener(*this);
		__pEditField->AddActionEventListener(*this);
		__pEditField->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_LEFT, L"Done", ID_BUTTON_EDITFIELD_DONE);
		__pEditField->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_RIGHT, L"Cancel", ID_BUTTON_EDITFIELD_CANCEL);
		__pEditField->AddKeypadEventListener(*this);


		__pEditFieldText = new String();

		__pButtonSend = static_cast<Button *>(GetControl(L"IDC_BUTTON_SEND", true));
		if (__pButtonSend != null) {
			__pButtonSend->SetActionId(IDC_BUTTON_SEND);
			__pButtonSend->AddActionEventListener(*this);
		}
		__pButtonPlus = static_cast<Button *>(GetControl(L"IDC_BUTTON_PLUS", true));
						if (__pButtonPlus != null) {
							__pButtonPlus->SetActionId(IDC_BUTTON_PLUS);
							__pButtonPlus->AddActionEventListener(*this);
						}
		__pButtonPlus->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"chatting_plus.png"));
		__pButtonPlus->Draw();
		__RecordGo = static_cast<Button *>(GetControl(L"IDC_BUTTON_RECORDGO", true));
				if (__RecordGo != null) {
					__RecordGo->SetActionId(IDC_BUTTON_RECORDGO);
					__RecordGo->AddActionEventListener(*this);
				}
		__RecordGo->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"voice_chat.png"));
		__RecordGo->SetHighlightedBackgroundBitmap(*pAppResource->GetBitmapN(L"voice_chat.png"));
		__RecordGo->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"voice_chat.png"));

		where= __pPanel->GetPosition();

		AppLog("%d%d 처음",where.x,where.y);
		CreateChattControl();


		AddDataToChattControl();
		where2 = __pChattControl->GetPosition();
		SetFormBackEventListener(this);

		popup = new Popup;
		popup->Construct(true, Dimension(720,440));
		popup->SetPosition(0,840);

		feedback_x = new Button();
		feedback_x->Construct(Rectangle(630,-90,100,100));
		feedback_x->SetActionId(IDC_BUTTON_FEEDBACKX);
		feedback_x->AddActionEventListener(*this);
		feedback_x->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"feedback_x.png"));
		feedback_x->SetHighlightedBackgroundBitmap(*pAppResource->GetBitmapN(L"feedback_x.png"));
		feedback_x->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"feedback_x.png"));
		feedback_x->Draw();
		popup->AddControl(feedback_x);

		__Record = new Button();
		__Record->Construct(Rectangle(30,0,300,300));
		__Record->SetActionId(IDC_BUTTON_RECORDER);
		__Record->AddActionEventListener(*this);
		__Record->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"Record_Stop.png"));
		__Record->SetHighlightedBackgroundBitmap(*pAppResource->GetBitmapN(L"Record_Stop.png"));
		__Record->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"Record_Stop.png"));
		__Record->Draw();
		popup->AddControl(__Record);
		/*

		 * popup->SetShowState(false);
    	Invalidate(true);
    	delete popup;
		 */


	return r;
}

result
Chatting::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here
	return r;
}

void
Chatting::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();


	switch(actionId)
	{
	case IDC_BUTTON_SEND:
			AppLog("Send Button is clicked! \n");

			OnButtonSend();
			break;

		case ID_BUTTON_EDITFIELD_DONE:
			//__pPanel->
			__pEditField->Draw();
			__pEditField->Show();
			break;
		case ID_BUTTON_EDITFIELD_CANCEL:
			__pEditField->SetText(*__pEditFieldText);
			//__pPanel->CloseOverlayWindow();
			__pEditField->Draw();
			__pEditField->Show();
			break;

		case IDC_BUTTON_PLUS:
			if(ischeck_plus==false)
			{

			__pChattControl->SetPosition(0, -444);
			//__pChattControl->SetPosition(0, -813);
			__pChattControl->Draw();
			__pPanel->SetPosition(where.x,where.y-444);
			__pButtonPlus->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"chatting_x.png"));
			__pButtonPlus->Draw();
			__pPanel->Draw();
			ischeck_plus = true;

			} else {
				__pChattControl->SetPosition(where2.x, where2.y);
				__pChattControl->Draw();
				__pPanel->SetPosition(where.x, where.y);
				__pButtonPlus->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"chatting_plus.png"));
				__pButtonPlus->Draw();
				__pPanel->Draw();

				ischeck_plus= false;
			}

			break;
		case IDC_BUTTON_RECORDGO:
			popup->SetShowState(true);
			popup->Show();
			break;
		case IDC_BUTTON_FEEDBACKX:
			popup->SetShowState(false);

			break;
		case IDC_BUTTON_RECORDER:
			if(Record_Status == 0)
				{
				AppLog("녹음중");

				__Record->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"Record_Start.png"));
				__Record->SetHighlightedBackgroundBitmap(*pAppResource->GetBitmapN(L"Record_Start.png"));
				__Record->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"Record_Start.png"));
				__Record->Draw();
				popup->RequestRedraw(true);
				Record_Status = 1;

				    DateTime currentTime;
				    SystemTime::GetCurrentTime(TIME_MODE_WALL, currentTime);


				    __filename.Format(32, L"%04d%02d%02d_%02d%02d%02d.mp3", currentTime.GetYear(), currentTime.GetMonth(), currentTime.GetDay(), currentTime.GetHour(), currentTime.GetMinute(), currentTime.GetSecond());
				    __filepath =App::GetInstance()->GetAppDataPath() + __filename;

					__audioRecorder.CreateAudioFile(__filepath,true);
			        __audioRecorder.SetMaxRecordingTime(60000);    //60 sec
			        __audioRecorder.SetQuality(RECORDING_QUALITY_HIGH);
			        __audioRecorder.SetFormat(CODEC_MP3,MEDIA_CONTAINER_MP3);

			        __audioRecorder.Record();
			        __audioDestPath = Tizen::System::Environment::GetMediaPath()+__filepath;
				}
				else if(Record_Status == 1)
				{
					AppLog("녹음완료");
					__Record->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"Record_Complete.png"));
					__Record->SetHighlightedBackgroundBitmap(*pAppResource->GetBitmapN(L"Record_Complete.png"));
					__Record->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"Record_Complete.png"));
					__Record->Draw();
					Record_Status = 2;

					__audioRecorder.Stop();
			        __audioRecorder.Close();
				}
				else if (Record_Status == 2)
				{
					AppLog("재생");
					__filepath =App::GetInstance()->GetAppDataPath() + __filename;
			        __player.OpenFile(__filepath);
			        __player.SetVolume(100);
			        __player.Play();

				}


		break;
	default:
		break;
	}
}

void
Chatting::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();

	if(ischeck_key == false, ischeck_plus==false)
	{
		pSceneManager->GoForward(ForwardSceneTransition(SCENE_CHATTING_FORM, SCENE_TRANSITION_ANIMATION_TYPE_NONE));

	} else if (ischeck_plus==true && ischeck_key == false){
		__pChattControl->SetPosition(where2.x, where2.y);
		__pChattControl->Draw();
		__pPanel->SetPosition(where.x, where.y);
		__pPanel->Draw();

		ischeck_plus= false;

	}

}

void
Chatting::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
										  const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Activate your scene here.

}

void
Chatting::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
										   const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Deactivate your scene here.

}
void
Chatting::OnTextValueChanged(const Tizen::Ui::Control& source)
{

}

void
Chatting::OnTextValueChangeCanceled(const Tizen::Ui::Control& source)
{

}

void
Chatting::OnOverlayControlCreated(const Tizen::Ui::Control& source)
{
	AppLog("OverlayControl Created\n");

}

void
Chatting::OnOverlayControlOpened(const Tizen::Ui::Control& source)
{
	AppLog("OverlayControl Opend\n");
	ischeck_key = true;
	__pChattControl->SetPosition(0, -444);
	__pChattControl->Draw();
	__pPanel->SetPosition(where.x,where.y-444);
	__pPanel->Draw();
	__pEditFieldText->Clear();
	__pEditFieldText->Append(__pEditField->GetText());
}

void
Chatting::OnOverlayControlClosed(const Tizen::Ui::Control& source)
{
	AppLog("OverlayControl Closed\n");

	ischeck_key = false;
	__pChattControl->SetPosition(0, 0);
	__pChattControl->Draw();
	__pPanel->SetPosition(where.x, where.y);
	__pPanel->Draw();

	SetFocus();
}

void
Chatting::OnOtherControlSelected(const Tizen::Ui::Control& source)
{
	AppLog("Other Control Selected\n");
}


void Chatting::CreateChattControl()
{
	Rectangle rtCtrl = Rectangle(0,0,720,1124);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* iconImage = pAppResource->GetBitmapN(L"s-face1.png");

	__pChattControl = new JMChattControl();
	__pChattControl->Initialize(rtCtrl, L"IronMan", iconImage, L"TESTMAN", iconImage);
	AddControl(*__pChattControl);
	//__pChattControl->SetBackgroundColor(Color::COLOR_GREY);
	Bitmap* strBackImageFile = pAppResource->GetBitmapN(L"Wallpaper_05.jpg");
	__pChattControl->SetBackImage(strBackImageFile);
}


void Chatting::AddDataToChattControl()
{
	DateTime timeSend;
	String strText;
	Bitmap* strBitmap;

	timeSend.SetValue(2014, 7, 30, 9, 12, 4);
	int nTimeGap = 4;
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	for(int i=0 ; i < 10 ; i++) {

		strText.Format(200, L"%d번이나 시도를 하지. ", i+1);
		__pChattControl->AddDataText(timeSend, strText, true);
		//timeSend.AddMinutes(nTimeGap);
		timeSend.AddHours(nTimeGap);

		strText = L"지금은 몇시고 난 누구고 여기는 어딘가 ㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎㅎ";
		__pChattControl->AddDataText(timeSend, strText, false);
		//timeSend.AddMinutes(nTimeGap);
		timeSend.AddHours(nTimeGap);

		strText = L"타이젠은 제대로 구축되어 있는게 하나도 없다. 그래서 화가 난다. 내가 하나부터 열까지 다해야 한다 ㅠㅠ";
		__pChattControl->AddDataText(timeSend, strText, true);
		//timeSend.AddMinutes(nTimeGap);
		timeSend.AddHours(nTimeGap);

		strText = L"동해물과 백두산이 마르고 닳도록 하느님이 보우하사 우리나라만세";
		__pChattControl->AddDataText(timeSend, strText, true);
		//timeSend.AddMinutes(nTimeGap);
		timeSend.AddHours(nTimeGap);

		strBitmap = pAppResource->GetBitmapN(L"feedback_voice.png");
		__pChattControl->AddDataImage(timeSend, strBitmap, false);
		//timeSend.AddMinutes(nTimeGap);
		timeSend.AddHours(nTimeGap);

		strText = L"후아 ㅎㅎ";
		__pChattControl->AddDataText(timeSend, strText, true);
		//timeSend.AddMinutes(nTimeGap);
		timeSend.AddHours(nTimeGap);

		strText = L"음성 피드백이나 해라";
		__pChattControl->AddDataText(timeSend, strText, false);
		//timeSend.AddMinutes(nTimeGap);
		timeSend.AddHours(nTimeGap);
	}


	__pChattControl->RequestRedraw();
}

void Chatting::OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs)
{
	switch(requestId)
	{

	case JMChattControl::REQUEST_JCHATT_SELECT_IMAGE :
	{
		long nIndex=-1;
		if( pArgs ) {
			int nElementCount = pArgs->GetCount();
			if( nElementCount > 0 ) {
				Long* pIndex = static_cast<Long*>(pArgs->GetAt(0));
				nIndex = pIndex->ToLong();
			}

			pArgs->RemoveAll(false);
			delete pArgs;
			pArgs = null;
		}

		if( nIndex >= 0 ) {

			OnChattImageSelected(nIndex);
		}
	}
		break;
	default:
		break;
	}
}


void Chatting::OnButtonSend()
{
	DateTime timeSend;
	String strText;
	strText = __pEditField->GetText();
	if( strText.GetLength() < 1 )
		return;
	__pEditField->SetText(L"");
	__pEditField->RequestRedraw();

	SystemTime::GetCurrentTime(TIME_MODE_WALL, timeSend);
	__pChattControl->AddDataText(timeSend, strText, true, true);
}


void Chatting::OnChattImageSelected(long nIndex)
{
	String strText, strFileName;

	strFileName = __pChattControl->GetImageFileName(nIndex);
	strText.Format(50, L"%d번째꺼 %ls", nIndex, strFileName.GetPointer());
	__pEditField->SetText(strText);
	__pEditField->RequestRedraw();
}

void  Chatting::OnLanguageChanged (const Tizen::Ui::Control &source, Tizen::Locales::LanguageCode oldLanguage, Tizen::Locales::LanguageCode newLanguage)
{

}

void  Chatting::OnKeypadActionPerformed (Tizen::Ui::Control &source, Tizen::Ui::KeypadAction keypadAction)
{

}
void  Chatting::OnKeypadBoundsChanged (Tizen::Ui::Control &source)
{

}
void  Chatting::OnKeypadClosed (Tizen::Ui::Control &source)
{

}

void  Chatting::OnKeypadOpened (Tizen::Ui::Control &source)
{

}
void  Chatting::OnKeypadWillOpen (Tizen::Ui::Control &source)
{

}



