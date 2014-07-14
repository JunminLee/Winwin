#ifndef _TEST_FRAME_H_
#define _TEST_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class testFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	testFrame(void);
	virtual ~testFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_TEST_FRAME_H_
