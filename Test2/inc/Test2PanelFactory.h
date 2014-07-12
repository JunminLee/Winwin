#ifndef _TEST_2_PANEL_FACTORY_H_
#define _TEST_2_PANEL_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>


class Test2PanelFactory
	: public Tizen::Ui::Scenes::IPanelFactory
{
public:
	Test2PanelFactory(void);
	virtual ~Test2PanelFactory(void);

	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _TEST_2_PANEL_FACTORY_H_
