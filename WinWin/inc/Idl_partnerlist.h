
#ifndef _IDL_PARTNERLIST_H_
#define _IDL_PARTNERLIST_H_

#include <FBase.h>
#include <FUi.h>



class Idl_partnerlist :
	public Tizen::Ui::Controls::Form,
 	public Tizen::Ui::Controls::IFormBackEventListener,
 	public Tizen::Ui::Scenes::ISceneEventListener
{

// Construction
public:
	Idl_partnerlist(void);
	virtual ~Idl_partnerlist(void);
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
