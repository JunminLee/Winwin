/*
 * BaseForm.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Gants
 */

#ifndef BASEFORM_H_
#define BASEFORM_H_

#include <FUi.h>
#include <FGraphics.h>
#include <FMedia.h>
#include <FBase.h>

class BaseForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
{
public:
	BaseForm(void);
	virtual ~BaseForm(void);

	virtual bool Initialize(void) = 0;
	virtual result OnInitializing(void);
	bool SetFooter(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source) ;

protected:

};


#endif /* BASEFORM_H_ */
