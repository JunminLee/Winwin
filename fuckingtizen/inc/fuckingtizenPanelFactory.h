#ifndef _FUCKINGTIZEN_PANEL_FACTORY_H_
#define _FUCKINGTIZEN_PANEL_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class fuckingtizenPanelFactory
	: public Tizen::Ui::Scenes::IPanelFactory
{
public:
	fuckingtizenPanelFactory(void);
	virtual ~fuckingtizenPanelFactory(void);

	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _FUCKINGTIZEN_PANEL_FACTORY_H_
