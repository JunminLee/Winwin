#ifndef _TIZEN_PROJECT_FORM_FACTORY_H_
#define _TIZEN_PROJECT_FORM_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class TizenProjectFormFactory
	: public Tizen::Ui::Scenes::IFormFactory
{
public:
	TizenProjectFormFactory(void);
	virtual ~TizenProjectFormFactory(void);

	virtual Tizen::Ui::Controls::Form* CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _TIZEN_PROJECT_FORM_FACTORY_H_
