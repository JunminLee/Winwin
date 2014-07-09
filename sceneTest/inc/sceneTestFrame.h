#ifndef _SCENE_TEST_FRAME_H_
#define _SCENE_TEST_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class sceneTestFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	sceneTestFrame(void);
	virtual ~sceneTestFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_SCENE_TEST_FRAME_H_
