#ifndef _TEST_2_FRAME_H_
#define _TEST_2_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class Test2Frame
	: public Tizen::Ui::Controls::Frame
{
public:
	Test2Frame(void);
	virtual ~Test2Frame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_TEST_2_FRAME_H_
