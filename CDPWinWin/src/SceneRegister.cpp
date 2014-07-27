/*
 * SceneRegister.cpp
 *
 *  Created on: Jul 27, 2014
 *      Author: Gants
 */



#include "AppResourceId.h"
#include "SceneRegister.h"
#include "CDPWinWinFormFactory.h"
#include "CDPWinWinPanelFactory.h"
#include <FUi.h>

using namespace Tizen::Ui::Scenes;

const wchar_t* SCENE_MAIN_FORM =L"SCENE_MAIN_FORM";
const wchar_t* SCENE_CHATTING_FORM =L"SCENE_CHATTING_FORM";
const wchar_t* SCENE_PARTNER_LIST_FORM =L"SCENE_PARTNER_LIST_FORM";
const wchar_t* SCENE_PARTNER_SEARCH_FORM =L"SCENE_PARTNER_SEARCH_FORM";
const wchar_t* SCENE_SETTING_FORM =L"SCENE_SETTING_FORM";


SceneRegister::SceneRegister(void)
{

}
SceneRegister::~SceneRegister(void)
{

}

void
SceneRegister::RegisterAllScenes(void)
{
	static const wchar_t* PANEL_BLANK =L"";
	static WinWinFormFactory formFactory;
	//static WinWinPanelFactory panelFactory;

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->RegisterFormFactory(formFactory);
	//pSceneManager->RegisterPanelFactory(panelFactory);


	pSceneManager->RegisterScene(SCENE_MAIN_FORM, IDL_FORM, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_CHATTING_FORM, IDL_FORM2, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_PARTNER_LIST_FORM, IDL_FORM3, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_PARTNER_SEARCH_FORM, IDL_FORM4, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_SETTING_FORM, IDL_FORM5, PANEL_BLANK);
}

