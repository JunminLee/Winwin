#ifndef _WIN_WIN_PANEL_FACTORY_H_
#define _WIN_WIN_PANEL_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class WinWinPanelFactory
	: public Tizen::Ui::Scenes::IPanelFactory
{
public:
	WinWinPanelFactory(void);
	virtual ~WinWinPanelFactory(void);

	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _WIN_WIN_PANEL_FACTORY_H_
