#ifndef _CDP_WIN_WIN_FORM_FACTORY_H_
#define _CDP_WIN_WIN_FORM_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class CDPWinWinFormFactory
	: public Tizen::Ui::Scenes::IFormFactory
{
public:
	CDPWinWinFormFactory(void);
	virtual ~CDPWinWinFormFactory(void);

	virtual Tizen::Ui::Controls::Form* CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _CDP_WIN_WIN_FORM_FACTORY_H_
