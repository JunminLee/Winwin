#ifndef _SCENE_TEST_PANEL_FACTORY_H_
#define _SCENE_TEST_PANEL_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class sceneTestPanelFactory
	: public Tizen::Ui::Scenes::IPanelFactory
{
public:
	sceneTestPanelFactory(void);
	virtual ~sceneTestPanelFactory(void);

	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _SCENE_TEST_PANEL_FACTORY_H_
