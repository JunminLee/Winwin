#ifndef _CDP_WIN_WIN_PANEL_FACTORY_H_
#define _CDP_WIN_WIN_PANEL_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class CDPWinWinPanelFactory
	: public Tizen::Ui::Scenes::IPanelFactory
{
public:
	CDPWinWinPanelFactory(void);
	virtual ~CDPWinWinPanelFactory(void);

	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _CDP_WIN_WIN_PANEL_FACTORY_H_
