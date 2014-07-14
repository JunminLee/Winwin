#ifndef _TEST_PANEL_FACTORY_H_
#define _TEST_PANEL_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class testPanelFactory
	: public Tizen::Ui::Scenes::IPanelFactory
{
public:
	testPanelFactory(void);
	virtual ~testPanelFactory(void);

	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _TEST_PANEL_FACTORY_H_
