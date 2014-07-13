
#ifndef _RESEARCHFRIENDSPANEL_H_
#define _RESEARCHFRIENDSPANEL_H_

#include <FBase.h>
#include <FUi.h>



class Researchfriendspanel :
	public Tizen::Ui::Controls::Panel,
 	public Tizen::Ui::Scenes::ISceneEventListener
{

// Construction
public:
	Researchfriendspanel(void);
	virtual ~Researchfriendspanel(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:


	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
};

#endif
