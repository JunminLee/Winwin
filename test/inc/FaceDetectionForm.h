//
// Tizen C++ SDK
// Copyright (c) 2012-2013 Samsung Electronics Co., Ltd.
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

#ifndef _FACE_DETECTION_FORM_H_
#define _FACE_DETECTION_FORM_H_

#include <FApp.h>
#include <FBase.h>
#include <FIo.h>
#include <FUi.h>
#include <FUix.h>
#include <FGraphics.h>
#include <FMedia.h>

#include "Info.h"

class FaceDetectionForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener

{
public:
	FaceDetectionForm(void);
	virtual ~FaceDetectionForm(void);

	virtual result OnInitializing(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual result OnDraw(void);

	Tizen::Base::ByteBuffer* LoadImageN(Tizen::Base::String FileName, int& nWidth, int& nHeight);
	result DrawImage(const Tizen::Graphics::Bitmap* pBitmap);
	result DrawFaceDetectArea(const Info* pInfo);
	Tizen::Base::Collection::IList* GetFaceDetectAreaN(const Info* pInfo);

	void DoRecognizing(void);
	bool FaceRecognize(Tizen::Base::Collection::IList* pFaceDetectList1, Tizen::Base::Collection::IList* pFaceDetectList2);
	void DoFaceSimilarity(void);
	int GetSimilarity(Tizen::Base::Collection::IList* pFaceDetectList1, Tizen::Base::Collection::IList* pFaceDetectList2);
	void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

protected:
	static const int ID_BUTTON = 101;
	static const int ID_BUTTON2 = 102;

private:
	double __percent;
	int __panelY;

	Tizen::Ui::Controls::Button* __pButton;
	Tizen::Ui::Controls::Button* __pButton2;
	Tizen::Ui::Controls::ScrollPanel* __pPanel;
	Tizen::Graphics::Canvas* __pCanvas;
	Info* __pPicture;

	Tizen::Base::Collection::ArrayListT< Info >* __pInfoList;
};

#endif // _FACE_DETECTION_FORM_H_
