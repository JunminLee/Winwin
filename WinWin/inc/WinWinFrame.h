#ifndef _WIN_WIN_FRAME_H_
#define _WIN_WIN_FRAME_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>

class WinWinFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	WinWinFrame(void);
	virtual ~WinWinFrame(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_WIN_WIN_FRAME_H_
