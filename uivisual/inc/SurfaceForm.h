//
// Tizen C++ SDK
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license/
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef _SURFACE_FORM_H_
#define _SURFACE_FORM_H_

#include "AnimationBaseForm.h"

class SurfaceForm
	: public AnimationBaseForm
	, public Tizen::Ui::ITouchEventListener
{
public:
	SurfaceForm(void);
	virtual ~SurfaceForm(void);

	virtual result OnInitializing(void);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

	virtual void  OnTouchDoublePressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
	virtual void  OnTouchFocusIn (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
	virtual void  OnTouchFocusOut (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
	virtual void  OnTouchLongPressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
	virtual void  OnTouchMoved (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
	virtual void  OnTouchPressed (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}
	virtual void  OnTouchReleased (const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo){}

private:
	void ShareSurface(int style);
	virtual void InitializeFooter(void);

private:

	Tizen::Ui::Animations::VisualElement* __pOriginal;
	Tizen::Ui::Animations::VisualElement* __pShared[9];

	static const int ID_FOOTER_BUTTON_CONTENT_BOUNDS = 901;

	static const int SHARE_STYLE_CLONE = 1;
	static const int SHARE_STYLE_SPLIT = 2;

	static const float PADDING = 10.0f;
	static const float ELEMENT_WIDTH = 225.0f;
	static const float ELEMENT_HEIGHT = 225.0f;
	static const int IMAGE_WIDTH = 720;
	static const int IMAGE_HEIGHT = 720;
	static const int ROW = 3;
	static const int COL = 3;
};

#endif // _SURFACE_FORM_H_
