#ifndef _WIN_WIN_FORM_FACTORY_H_
#define _WIN_WIN_FORM_FACTORY_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>


extern const wchar_t* FORM_INTRO;
extern const wchar_t* FORM_MAIN;
extern const wchar_t* FORM_CHATTING;
extern const wchar_t* FORM_LIST;
extern const wchar_t* FORM_SEARCH;
extern const wchar_t* FORM_SETTING;


class WinWinFormFactory
	: public Tizen::Ui::Scenes::IFormFactory
{
public:
	WinWinFormFactory(void);
	virtual ~WinWinFormFactory(void);

	virtual Tizen::Ui::Controls::Form* CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _WIN_WIN_FORM_FACTORY_H_
