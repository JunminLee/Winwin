#ifndef _CDP_WIN_WIN_FRAME_H_
#define _CDP_WIN_WIN_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class CDPWinWinFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	CDPWinWinFrame(void);
	virtual ~CDPWinWinFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_CDP_WIN_WIN_FRAME_H_
