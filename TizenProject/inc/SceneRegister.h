/*
 * SceneRegister.h
 *
 *  Created on: Jul 27, 2014
 *      Author: Gants
 */

#ifndef SCENEREGISTER_H_
#define SCENEREGISTER_H_

extern const wchar_t* SCENE_MAIN_FORM;
extern const wchar_t* SCENE_CHATTING_FORM;
extern const wchar_t* SCENE_PARTNER_LIST_FORM;
extern const wchar_t* SCENE_PARTNER_SEARCH_FORM;
extern const wchar_t* SCENE_SETTING_FORM;


extern const wchar_t* SCENE_TUTORIAL1;
extern const wchar_t* SCENE_TUTORIAL2;
extern const wchar_t* SCENE_TUTORIAL3;
extern const wchar_t* SCENE_TUTORIAL4;


extern const wchar_t* SCENE_EDITING_FORM;
extern const wchar_t* SCENE_CHATTING;

class SceneRegister
{
public:
	static void RegisterAllScenes(void);
private:
	SceneRegister(void);
	~SceneRegister(void);
};



#endif /* SCENEREGISTER_H_ */
