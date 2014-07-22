/*
 * PartnerSearchForm.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Gants
 */

#ifndef PARTNERSEARCHFORM_H_
#define PARTNERSEARCHFORM_H_


#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>
#include "BaseForm.h"

class PartnerSearchForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
 	, public Tizen::Ui::Controls::IListViewItemEventListener
 	, public Tizen::Ui::Controls::IListViewItemProviderF
{
public:
		PartnerSearchForm(void);
	virtual ~PartnerSearchForm(void);
	bool Initialize(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);
	bool CreateMainList(void);
	bool MoveToForm(int index);
	virtual void OnListViewItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status);
	virtual void OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction);
	virtual void OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus status);
	virtual int GetItemCount(void);
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index, float itemWidth);
	virtual bool DeleteItem(int intdex, Tizen::Ui::Controls::ListItemBase* pItem, float itemWidth);

private:
	Tizen::Ui::Controls::ListView* __pList;

protected:
	static const int ID_FOOTER_ITEM1 = 101;
	static const int ID_FOOTER_ITEM2 = 102;
	static const int ID_FOOTER_ITEM3 = 103;
	static const int ID_FOOTER_ITEM4 = 104;
	static const int ID_FOOTER_ITEM5 = 105;

	static const int ID_FORMAT_STRING = 500;
};


#endif /* PARTNERSEARCHFORM_H_ */
