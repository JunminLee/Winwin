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

#ifndef _GALLERY_FORM_H_
#define _GALLERY_FORM_H_

#include "AnimationBaseForm.h"
#include "GalleryImageManager.h"

class GalleryForm
	: public AnimationBaseForm
	, public Tizen::Ui::ITouchEventListener
	, public Tizen::Ui::Animations::IVisualElementAnimationStatusEventListener
{
public:
	GalleryForm(void);
	virtual ~GalleryForm(void);

	virtual bool Initialize(void);

	virtual result OnInitializing(void);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);

	virtual void  OnTouchDoublePressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchFocusIn (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchFocusOut (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchLongPressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchMoved (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchPressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchReleased (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);

	virtual void OnVisualElementAnimationStarted(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target);
	virtual void OnVisualElementAnimationRepeated(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, long currentRepeatCount){}
	virtual void OnVisualElementAnimationFinished(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, bool completedNormally);

private:
	void CreateGallery(void);
	void CreateImageView(int index, bool slideShow);
	void CreateAnimationForImageView(int index);
	void CreateAnimationForReenter(int index);

	void ChangeView(void);
	void TileView(void);
	void StackView(void);
	void DrawImage(int index, bool border);

	virtual void InitializeFooter(void);

private:
	Tizen::Ui::Animations::VisualElement* __pElement[GALLERY_IMAGE_COUNT];
	GalleryImageManager* __pImgManager;
	Tizen::Ui::Animations::ExpOutTimingFunction* __pTimingFunction;

	int __viewNumber;
	int __touchedIndex;

	bool __isAnimatingImageView;

	static const int ID_FOOTER_BUTTON_VIEW = 601;
	static const int ID_FOOTER_BUTTON_SLIDESHOW = 602;
};

#endif // _GALLERY_FORM_H_
