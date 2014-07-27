#ifndef _CDP_WIN_WIN_MAIN_FORM_H_
#define _CDP_WIN_WIN_MAIN_FORM_H_


#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>
#include <FApp.h>

class CDPWinWinMainForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
 	, public Tizen::Ui::Controls::IListViewItemEventListener
 	, public Tizen::Ui::Controls::IListViewItemProviderF
{
public:
	CDPWinWinMainForm(void);
	virtual ~CDPWinWinMainForm(void);
	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);


private:

protected:
	static const int ID_FOOTER_ITEM1 = 101;
	static const int ID_FOOTER_ITEM2 = 102;
	static const int ID_FOOTER_ITEM3 = 103;
	static const int ID_FOOTER_ITEM4 = 104;
	static const int ID_FOOTER_ITEM5 = 105;

	static const int ID_FORMAT_STRING = 500;
};

#endif	//_CDP_WIN_WIN_MAIN_FORM_H_
