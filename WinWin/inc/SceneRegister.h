/*
 * SceneRegister.h
 *
 *  Created on: Jul 22, 2014
 *      Author: Gants
 */

#ifndef SCENEREGISTER_H_
#define SCENEREGISTER_H_

extern const wchar_t* SCENE_MAIN_FORM;
extern const wchar_t* SCENE_CHATTING_FORM;
extern const wchar_t* SCENE_PARTNER_LIST_FORM;
extern const wchar_t* SCENE_PARTNER_SEARCH_FORM;
extern const wchar_t* SCENE_SETTING_FORM;


class SceneRegister
{
public:
	static void RegisterAllScenes(void);
private:
	SceneRegister(void);
	~SceneRegister(void);
};


#endif /* SCENEREGISTER_H_ */
