
#ifndef _IDL_AFORM_H_
#define _IDL_AFORM_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>



class Idl_aform :
	public Tizen::Ui::Controls::Form,
 	public Tizen::Ui::Scenes::ISceneEventListener,
 	public Tizen::Ui::Controls::IFormBackEventListener
{

// Construction
public:
	Idl_aform(void);
	virtual ~Idl_aform(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:

	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
};

#endif
