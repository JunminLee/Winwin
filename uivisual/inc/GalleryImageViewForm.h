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

#ifndef _GALLERY_IMAGE_VIEW_FORM_H_
#define _GALLERY_IMAGE_VIEW_FORM_H_

#include <FApp.h>
#include <FBase.h>
#include <FGraphics.h>
#include <FUi.h>
#include <FUiAnimations.h>
#include <FUiControls.h>

#include "GalleryImageManager.h"

#define PIECE_ROW 4
#define PIECE_COL 4
#define PIECE_COUNT (PIECE_ROW * PIECE_COL)

class GalleryImageViewForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
	, public Tizen::Ui::ITouchEventListener
	, public Tizen::Base::Runtime::ITimerEventListener
	, public Tizen::Ui::Animations::IVisualElementAnimationStatusEventListener
	, public Tizen::Ui::Animations::IAnimationTransactionEventListener
{
public:
	GalleryImageViewForm(GalleryImageManager* pImgManager, int index);
	virtual ~GalleryImageViewForm(void);
	virtual bool Initialize(void);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnUserEventReceivedN(RequestId requestId, Tizen::Base::Collection::IList* pArgs);

	virtual void InitializeFooter(void);

	virtual void  OnTouchDoublePressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchFocusIn (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchFocusOut (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchLongPressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchMoved (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchPressed (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo){}
	virtual void  OnTouchReleased (const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo);

	void OnTimerExpired(Tizen::Base::Runtime::Timer& timer);

	virtual void OnVisualElementAnimationStarted(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target){}
	virtual void OnVisualElementAnimationRepeated(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, long currentRepeatCount){}
	virtual void OnVisualElementAnimationFinished(const Tizen::Ui::Animations::VisualElementAnimation& animation, const Tizen::Base::String& keyName, Tizen::Ui::Animations::VisualElement& target, bool completedNormally);

	virtual void OnAnimationTransactionStarted(int transactionId){}
	virtual void OnAnimationTransactionStopped(int transactionId);
	virtual void OnAnimationTransactionFinished(int transactionId);

	void	StartTimerForSlideShow(void);

private:
	Tizen::Ui::Animations::VisualElement* CreateImageView(int index, Tizen::Graphics::Rectangle rect);
	void CreateAnimationForDestroy(void);
	void PlaySlideShow(void);

private:
	Tizen::Ui::Animations::VisualElement* __pElement[GALLERY_IMAGE_COUNT];
	Tizen::Ui::Animations::VisualElement* __pVisualElement;

	Tizen::Ui::Animations::VisualElement* __pOldPiece[PIECE_COUNT];
	Tizen::Ui::Animations::VisualElement* __pNewPiece[PIECE_COUNT];

	Tizen::Ui::Controls::Form* __pPreviousForm;
	Tizen::Base::Runtime::Timer* __pTimer;

	GalleryImageManager* __pImgManager;

	int __currentIndex;
	int __transactionId;
	bool __isSlideShowPlaying;
	bool __isSlideShowPaused;

	Tizen::Graphics::Rectangle __clientRect;
	
	static const int ID_FOOTER_BUTTON_SLIDESHOW = 801;
};

#endif // _GALLERY_IMAGE_VIEW_FORM_H_