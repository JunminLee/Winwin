/*
 * Chatting.h
 *
 *  Created on: Aug 13, 2014
 *      Author: Gants
 */

#ifndef CHATTING_H_
#define CHATTING_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>
#include <FLclLocale.h>
#include "JMChattControl.h"
#include "SceneRegister.h"
#include <FMedia.h>
#include <FContent.h>
#include <FMessaging.h>
#include <FIo.h>
#include <FWebJson.h>
#include <FNet.h>
#include "Toast.h"

using namespace Tizen::Ui::Controls;
using namespace Tizen::Media;

class Chatting: public Tizen::Ui::Controls::Form,
		public Tizen::Ui::IActionEventListener,
		public Tizen::Ui::Controls::IFormBackEventListener,
		public Tizen::Ui::Scenes::ISceneEventListener,
		public Tizen::Ui::ITextEventListener,
		public Tizen::Ui::IScrollPanelEventListener,
		public Tizen::Ui::ILanguageEventListener,
		public Tizen::Ui::IKeypadEventListener,
		public Tizen::Media::IAudioRecorderEventListener,
		public Tizen::Media::IPlayerEventListener,
		public Tizen::Messaging::IPushManagerListener,
		public Tizen::Messaging::IPushEventListener,
		public Tizen::Net::Http::IHttpTransactionEventListener {
public:
	Chatting(void);
	virtual ~Chatting(void);
	bool Initialize(void);
	void OnPushServiceRegistered(RequestId reqId,
			const Tizen::Base::String& registrationId, result r,
			const Tizen::Base::String& errorCode,
			const Tizen::Base::String& errorMsg);
	void OnPushServiceUnregistered(RequestId reqId, result r,
			const Tizen::Base::String& errorCode,
			const Tizen::Base::String& errorMsg);
	void OnPushMessageReceived(const Tizen::Messaging::PushMessage& message);
	void EnablePush(void);
	virtual void OnTransactionReadyToRead(
			Tizen::Net::Http::HttpSession& httpSession,
			Tizen::Net::Http::HttpTransaction& httpTransaction,
			int availableBodyLen);
	virtual void OnTransactionAborted(
			Tizen::Net::Http::HttpSession& httpSession,
			Tizen::Net::Http::HttpTransaction& httpTransaction, result r) {
	}
	virtual void OnTransactionReadyToWrite(
			Tizen::Net::Http::HttpSession& httpSession,
			Tizen::Net::Http::HttpTransaction& httpTransaction,
			int recommendedChunkSize) {
	}
	virtual void OnTransactionHeaderCompleted(
			Tizen::Net::Http::HttpSession& httpSession,
			Tizen::Net::Http::HttpTransaction& httpTransaction, int headerLen,
			bool authRequired) {
	}
	virtual void OnTransactionCompleted(
			Tizen::Net::Http::HttpSession& httpSession,
			Tizen::Net::Http::HttpTransaction& httpTransaction) {
	}
	virtual void OnTransactionCertVerificationRequiredN(
			Tizen::Net::Http::HttpSession& httpSession,
			Tizen::Net::Http::HttpTransaction& httpTransaction,
			Tizen::Base::String* pCert) {
	}
private:
	result RequestHttpPost(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source,
			int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(
			const Tizen::Ui::Scenes::SceneId& previousSceneId,
			const Tizen::Ui::Scenes::SceneId& currentSceneId,
			Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(
			const Tizen::Ui::Scenes::SceneId& currentSceneId,
			const Tizen::Ui::Scenes::SceneId& nextSceneId);
	// Called when the application's frame moves to the top of the screen.
	virtual void OnTextValueChanged(const Tizen::Ui::Control& source);
	virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source);
	void AddDataToChattControl();
	void CreateChattControl();
	virtual void OnOverlayControlCreated(const Tizen::Ui::Control& source);
	virtual void OnOverlayControlOpened(const Tizen::Ui::Control& source);
	virtual void OnOverlayControlClosed(const Tizen::Ui::Control& source);
	virtual void OnOtherControlSelected(const Tizen::Ui::Control& source);
	virtual void OnUserEventReceivedN(RequestId requestId,
			Tizen::Base::Collection::IList* pArgs);
	void OnChattImageSelected(long nIndex);
	void OnButtonSend();
	void OnScreenOff(void);
	virtual void OnLanguageChanged(const Tizen::Ui::Control &source,
			Tizen::Locales::LanguageCode oldLanguage,
			Tizen::Locales::LanguageCode newLanguage);

	virtual void OnKeypadActionPerformed(Tizen::Ui::Control &source,
			Tizen::Ui::KeypadAction keypadAction);
	virtual void OnKeypadBoundsChanged(Tizen::Ui::Control &source);
	virtual void OnKeypadClosed(Tizen::Ui::Control &source);
	virtual void OnKeypadOpened(Tizen::Ui::Control &source);
	virtual void OnKeypadWillOpen(Tizen::Ui::Control &source);

	virtual void OnAudioRecorderCanceled(result r) {
	}
	virtual void OnAudioRecorderClosed(result r) {
	}
	virtual void OnAudioRecorderEndReached(RecordingEndCondition endCondition) {
	}
	virtual void OnAudioRecorderErrorOccurred(RecorderErrorReason r) {
	}
	virtual void OnAudioRecorderPaused(result r) {
	}
	virtual void OnAudioRecorderStarted(result r) {
	}
	virtual void OnAudioRecorderStopped(result r) {
	}
	virtual void OnPlayerAudioFocusChanged(void) {
	}
	virtual void OnPlayerBuffering(int percent) {
	}
	virtual void OnPlayerEndOfClip(void) {
	}
	virtual void OnPlayerErrorOccurred(Tizen::Media::PlayerErrorReason r) {
	}
	virtual void OnPlayerInterrupted(void) {
	}
	virtual void OnPlayerOpened(result r) {
	}
	virtual void OnPlayerReleased(void) {
	}
	virtual void OnPlayerSeekCompleted(result r) {
	}

protected:
	static const int IDC_BUTTON_SEND = 201;
	static const int ID_BUTTON_EDITFIELD_DONE = 501;
	static const int ID_BUTTON_EDITFIELD_CANCEL = 502;
	static const int IDC_BUTTON_PLUS = 202;
	static const int IDC_BUTTON_RECORDGO = 203;
	static const int IDC_BUTTON_RECORDER = 250;
	static const int IDC_BUTTON_FEEDBACKB = 205;
	static const int IDC_BUTTON_FEEDBACKX = 204;
	static const int IDC_BUTTON_TRANSPORT = 207;
	static const int IDC_BUTTON_VOICE = 206;

	Tizen::Ui::Controls::Button* __pButtonSend;
	Tizen::Ui::Controls::Button* __pButtonPlus;
	Tizen::Ui::Controls::EditField* __pEditField;
	Tizen::Ui::Controls::Panel* __pPanel;
	Tizen::Base::String* __pEditFieldText;
	Point where;
	Point where2;
	bool ischeck_plus = false;
	bool ischeck_key = false;
	bool istransport = false;
	JMChattControl* __pChattControl;
	Button* __RecordGo;
	Popup* popup;
	Button* __Record;

	Button* pic;
	Button* camera;
	Button* voice;
	Button* feedback_x;
	Button* trans_voice;
	int Record_Status = 0;

	AudioRecorder __audioRecorder;
	Player __player;
	String __audioDestPath, __filepath, __filename;
	Tizen::Messaging::PushManager* __pPushManager;
};

#endif /* CHATTING_H_ */
