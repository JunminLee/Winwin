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

#ifndef _EVENT_LISTENER_FORM_H_
#define _EVENT_LISTENER_FORM_H_

#include "AnimationBaseForm.h"

class EventListenerForm
	: public AnimationBaseForm
{
public:
	EventListenerForm(void);
	virtual ~EventListenerForm(void);

	virtual result OnInitializing(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);

private:
	virtual void InitializeFooter(void);

private:
	Tizen::Ui::Animations::VisualElement* __pRed;
	Tizen::Ui::Animations::VisualElement* __pYellow;

	Tizen::Ui::Animations::IVisualElementEventListener* __pListener;
	Tizen::Ui::Controls::Label* __pLabel;

	bool __bAttached;

	static const int ID_FOOTER_BUTTON_ATTACH_DETACH = 501;
};

class MyEventListener
	: public Tizen::Ui::Animations::IVisualElementEventListener
{
public:
	MyEventListener(Tizen::Ui::Controls::Label* pLabel, Tizen::Graphics::FloatRectangle bounds)
		: __pLabel(pLabel)
		, __bounds(bounds)
	{
	}
	virtual ~MyEventListener(void){}

	virtual void OnChildAttached(Tizen::Ui::Animations::VisualElement& parent, Tizen::Ui::Animations::VisualElement& child);
	virtual void OnChildDetached(Tizen::Ui::Animations::VisualElement& parent, Tizen::Ui::Animations::VisualElement& child);
	virtual void OnAttached(Tizen::Ui::Animations::VisualElement& child, Tizen::Ui::Animations::VisualElement& parent){}
	virtual void OnDetached(Tizen::Ui::Animations::VisualElement& child, Tizen::Ui::Animations::VisualElement& parent) {}
	virtual result OnTransformChanging(Tizen::Ui::Animations::VisualElement& source, Tizen::Graphics::FloatMatrix4& newTransform){ return E_SUCCESS; }
	virtual void OnTransformChanged(Tizen::Ui::Animations::VisualElement& source, const Tizen::Graphics::FloatMatrix4& previousTransform){}
	virtual result OnChildrenTransformChanging(Tizen::Ui::Animations::VisualElement& source, Tizen::Graphics::FloatMatrix4& newTransform){ return E_SUCCESS; }
	virtual void OnChildrenTransformChanged(Tizen::Ui::Animations::VisualElement& source, const Tizen::Graphics::FloatMatrix4& previousTransform){}
	virtual result OnBoundsChanging(Tizen::Ui::Animations::VisualElement& source, Tizen::Graphics::FloatRectangle& newBounds){ return E_SUCCESS; }
	virtual void OnBoundsChanged(Tizen::Ui::Animations::VisualElement& source, const Tizen::Graphics::FloatRectangle& previousBounds){}
	virtual void OnShowStateChanged(Tizen::Ui::Animations::VisualElement& source, bool previousShowState){}

	Tizen::Ui::Controls::Label* __pLabel;

	Tizen::Graphics::FloatRectangle __bounds;
 };

#endif // _EVENT_LISTENER_FORM_H_
