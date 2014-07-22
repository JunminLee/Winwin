/*
 * BaseForm.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: Gants
 */

#ifndef BASEFORM_CPP_
#define BASEFORM_CPP_

#include "BaseForm.h"

using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

BaseForm::BaseForm(void)
{
}

BaseForm::~BaseForm(void)
{
}

void
BaseForm::OnActionPerformed(const Control& source, int actionId)
{
}

result
BaseForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	SetFormBackEventListener(this);

	return r;
}

void
BaseForm::OnFormBackRequested(Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->GoBackward(BackwardSceneTransition());
}


#endif /* BASEFORM_CPP_ */
