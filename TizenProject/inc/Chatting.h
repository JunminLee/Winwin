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

class Chatting
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
	, public Tizen::Ui::ITextEventListener
	, public Tizen::Ui::IScrollPanelEventListener
	, public Tizen::Ui::ILanguageEventListener
	, public Tizen::Ui::IKeypadEventListener
{
public:
	Chatting(void);
	virtual ~Chatting(void);
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
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
		virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);
		void OnChattImageSelected(long nIndex);
		void OnButtonSend();
		void OnScreenOff (void);
		virtual void  OnLanguageChanged (const Tizen::Ui::Control &source, Tizen::Locales::LanguageCode oldLanguage, Tizen::Locales::LanguageCode newLanguage);



		virtual void  OnKeypadActionPerformed (Tizen::Ui::Control &source, Tizen::Ui::KeypadAction keypadAction);
		virtual void  OnKeypadBoundsChanged (Tizen::Ui::Control &source);
		virtual void  OnKeypadClosed (Tizen::Ui::Control &source);
		virtual void  OnKeypadOpened (Tizen::Ui::Control &source);
		virtual void  OnKeypadWillOpen (Tizen::Ui::Control &source);


protected:
		static const int IDC_BUTTON_SEND = 201;
		static const int ID_BUTTON_EDITFIELD_DONE = 501;
		static const int ID_BUTTON_EDITFIELD_CANCEL = 502;
		static const int IDC_BUTTON_PLUS = 202;

			Tizen::Ui::Controls::Button* __pButtonSend;
			Tizen::Ui::Controls::Button* __pButtonPlus;
			Tizen::Ui::Controls::EditField* __pEditField;
			Tizen::Ui::Controls::Panel* __pPanel;
			Tizen::Base::String*	__pEditFieldText;
			Point where;
			Point where2;
			bool ischeck_plus = false;
			bool ischeck_key = false;
			JMChattControl* __pChattControl;
};



#endif /* CHATTING_H_ */
