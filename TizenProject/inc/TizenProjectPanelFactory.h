#ifndef _TIZEN_PROJECT_PANEL_FACTORY_H_
#define _TIZEN_PROJECT_PANEL_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class TizenProjectPanelFactory
	: public Tizen::Ui::Scenes::IPanelFactory
{
public:
	TizenProjectPanelFactory(void);
	virtual ~TizenProjectPanelFactory(void);

	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _TIZEN_PROJECT_PANEL_FACTORY_H_
