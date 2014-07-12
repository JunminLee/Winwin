#ifndef _TEST_2_TAB2_H_
#define _TEST_2_TAB2_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class Test2Tab2
	: public Tizen::Ui::Controls::Panel
	, public Tizen::Ui::Scenes::ISceneEventListener
{
public:
	Test2Tab2(void);
	virtual ~Test2Tab2(void);
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

};

#endif // _TEST_2_TAB2_H_
