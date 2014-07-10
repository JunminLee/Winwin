
#ifndef _IDL_PARTNERSEARCH_H_
#define _IDL_PARTNERSEARCH_H_

#include <FBase.h>
#include <FUi.h>



class Idl_partnersearch :
	public Tizen::Ui::Controls::Form,
 	public Tizen::Ui::Scenes::ISceneEventListener,
 	public Tizen::Ui::Controls::IFormBackEventListener
{

// Construction
public:
	Idl_partnersearch(void);
	virtual ~Idl_partnersearch(void);
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

	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
};

#endif
