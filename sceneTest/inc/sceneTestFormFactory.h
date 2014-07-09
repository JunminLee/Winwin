#ifndef _SCENE_TEST_FORM_FACTORY_H_
#define _SCENE_TEST_FORM_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class sceneTestFormFactory
	: public Tizen::Ui::Scenes::IFormFactory
{
public:
	sceneTestFormFactory(void);
	virtual ~sceneTestFormFactory(void);

	virtual Tizen::Ui::Controls::Form* CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _SCENE_TEST_FORM_FACTORY_H_
