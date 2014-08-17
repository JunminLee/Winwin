/*
 * Editing.h
 *
 *  Created on: Aug 7, 2014
 *      Author: pji
 */

#ifndef EDITING_H_
#define EDITING_H_

#include "tizenx.h"
#include "EditPanel.h"
#include "Word.h"

using namespace Tizen::Base::Runtime;
using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;



class Editing
 	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
    , public Tizen::Ui::IActionEventListener
 	, public Tizen::Ui::ITouchEventListener
 	, Tizen::Ui::Controls::IScrollEventListener
 	, public Tizen::Base::Runtime::ITimerEventListener
 	{
 	private:
 		Panel			*head;
 		Panel			*profile_image_panel;
 		String			 str_content;
 		String			popup_edit_string;

 		String			Eng;

 		Timer			timer;

 		Button			*editing_button;
 		Button			*eng_button;
 		Button			*editing_completion_button;

 		ScrollPanel		*panel_me;
 		ScrollPanel		*panel_view;

 		int				scroll_position;
 	public:
 		Editing(void);
 		virtual ~Editing(void);
 		virtual result	OnDraw();
 		bool Initialize(void);

 		virtual void 	OnTimerExpired (Timer &timer);


 	private:
 		virtual result OnInitializing(void);
 		virtual result OnTerminating(void);
 		virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
 		virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
 		virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
 									   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
 		virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
 										const Tizen::Ui::Scenes::SceneId& nextSceneId);

 		virtual void 	OnScrollEndReached (Tizen::Ui::Control &source, Tizen::Ui::Controls::ScrollEndEvent type);
 		virtual void 	OnScrollPositionChanged (Tizen::Ui::Control &source, int scrollPosition);
 		virtual void 	OnScrollStopped (Tizen::Ui::Control &source);

 	protected:
 		virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
 		virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);


 	};

#endif /* EDITING_H_ */
