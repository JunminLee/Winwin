/*
 * Toast.h
 *
 *  Created on: Aug 16, 2014
 *      Author: pji
 */

#ifndef TOAST_H_
#define TOAST_H_

#include "tizenx.h"

using namespace Tizen::Base::Runtime;
using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;

class Toast
: public Tizen::Ui::Window
	, public Tizen::Base::Runtime::ITimerEventListener
  {
  private:
	Label	*ToastLabel;
	Timer	ToastTimer;
  public:
	result Construct(const Tizen::Graphics::Rectangle &rect, String text, int time = 0)
	{
		Window::Construct(rect, false, false);

		ToastLabel = new Label;
		ToastLabel->Construct(Rectangle(0,0,rect.width,rect.height), text);
		ToastLabel->SetTextColor(Color(255,255,255,255));
		ToastLabel->SetBackgroundColor(Color(93,93,93,255));
		ToastLabel->SetTextConfig(30, LABEL_TEXT_STYLE_NORMAL);

		this->AddControl(ToastLabel);
		ToastTimer.Construct(*this);
		ToastTimer.Start(time);
<<<<<<< HEAD

=======
>>>>>>> refs/heads/pji4
		this->Show();
	};

	void 	OnTimerExpired (Timer &timer)
	{

		if(&timer == &ToastTimer)
		{
			ToastLabel->Destroy();
			this->Destroy();
		}
	};

  };


#endif /* TOAST_H_ */
