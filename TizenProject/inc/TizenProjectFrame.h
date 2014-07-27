#ifndef _TIZEN_PROJECT_FRAME_H_
#define _TIZEN_PROJECT_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class TizenProjectFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	TizenProjectFrame(void);
	virtual ~TizenProjectFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_TIZEN_PROJECT_FRAME_H_
