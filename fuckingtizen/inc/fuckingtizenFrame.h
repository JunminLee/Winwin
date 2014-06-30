#ifndef _FUCKINGTIZEN_FRAME_H_
#define _FUCKINGTIZEN_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class fuckingtizenFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	fuckingtizenFrame(void);
	virtual ~fuckingtizenFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_FUCKINGTIZEN_FRAME_H_
