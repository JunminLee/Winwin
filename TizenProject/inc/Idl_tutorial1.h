
#ifndef _IDL_TUTORIAL1_H_
#define _IDL_TUTORIAL1_H_

#include <FBase.h>
#include <FUi.h>
#include "SceneRegister.h"
#include <FApp.h>
using namespace Tizen::Ui::Scenes;

class Idl_tutorial1 :
	public Tizen::Ui::Controls::Form,
 	public Tizen::Ui::ITouchEventListener,
 	public Tizen::Ui::Scenes::ISceneEventListener,
 	public Tizen::Ui::Controls::IFormBackEventListener
{

// Construction
public:
	Idl_tutorial1(void);
	virtual ~Idl_tutorial1(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
	int e_start;
	int e_end;
// Implementation
protected:

// Generated call-back functions
public:
	virtual void  OnFormBackRequested (Tizen::Ui::Controls::Form &source);

	virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
	virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);
};

#endif
