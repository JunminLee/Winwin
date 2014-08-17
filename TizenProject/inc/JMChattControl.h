/*
 * JMChattControl.h
 *
 *  Created on: Aug 13, 2014
 *      Author: Gants
 */

#ifndef JMCHATTCONTROL_H_
#define JMCHATTCONTROL_H_

#include <FBase.h>
#include <FUi.h>
#include <FGraphics.h>
#include <FMedia.h>
#include <FSystem.h>
#include <FLocales.h>
#include <FApp.h>
#include <FUiIme.h>
#include <gl.h>
#include <FMedia.h>

using namespace Tizen::Media;
using namespace Tizen::Base;
using namespace Tizen::Base::Runtime;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Utility;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::System;
using namespace Tizen::Locales;
using namespace Tizen::App;


struct stSCREEN_INFO {
	Rectangle rtScreen;
	Rectangle rtScreenNow;
	Color colorBackground;
	Bitmap* pBitmapBackground;
	String strMyName;
	String strYouName;
	Bitmap* pBitmapMyPhoto;
	Bitmap* pBitmapYouPhoto;
	int nElementGapY;
	int nTextBoxWidth;
	int nTextBoxInsideGap;
	int nTextBoxMarginI;
	int nTextBoxMarginYou;
	int nPhotoBoxMarginYou;

	int nYouPhotoBoxHeight;
	int nYouNameHeight;
	int nMyPhotoBoxHeight;
	int nMyNameHeight;



	int nTextBoxMarginDate;
	Font fontText;
	int nImageBoxMaxHeight;
	int nTimeAreaWidth;
	int nTimeAreaHeight;
	Font fontTime;
	Color colorTextI;
	Color colorTextBackI;
	Color colorTextOutlineI;
	Color colorTextYou;
	Color colorTextBackYou;
	Color colorTextOutlineYou;
	Color colorTextTime;
	Color colorTextBackTime;
	Color colorTextOutlineTime;
	long nTotalElementHeight;
	long nViewAreaTop;
	long nViewAreaBottom;
	long nViewAreaStartIndex;
	long nViewAreaEndIndex;
	Point pointTouchPrev;
	bool bNeedRedraw;
	int nSlideDistance;
	float fSlideSpeed;
	float fSlideSpeedDecrease;
	long long nTimeTickTouchMoved;
	long nSelectedImageIndex;

};


struct stCHATT_DATA {
	int nDataType;
	bool bISend;
	String strText;
	EnrichedText* pEnrichedText;
	String strImageFile;
	Bitmap* pBitmapImage;
	DateTime timeSend;
	Rectangle rtElementBox;
	Bitmap* pBitmapCapture;
	bool isImage;
};

class JMChattControl:
	public Tizen::Ui::Controls::Panel,
	public Tizen::Ui::ITouchEventListener,
	public Tizen::Base::Runtime::ITimerEventListener,
	public Tizen::Ui::IActionEventListener,
	public Tizen::Media::IAudioRecorderEventListener,
	public Tizen::Media::IPlayerEventListener
{
public:
	JMChattControl();
	virtual ~JMChattControl();
	void Initialize(const Rectangle& bounds, String strYouName, Bitmap* pBitmapYouPhoto, String strMyName, Bitmap* pBitmapMyPhoto);

	void DrawBackground(Canvas* pCanvas);
	void SetBackColor(Color colorBackground, bool bRedraw=false);
	Tizen::Graphics::Bitmap* GetBitmapN(const Tizen::Base::String& name);
	void SetBackImage(Bitmap* strImageFileName, bool bRedraw=false);
	void ReDrawFeedback();
	void InitVariable();

	void DrawChattData(Canvas* pCanvas);
	void DrawTextBox(Canvas* pCanvas, String strText, Rectangle rtArea, Color colorText, Color colorBack, Color colorOutline);
	void DrawFillRoundRectangle(Canvas* pCanvas, Rectangle rtArea, Color colorBack, Color colorOutline);
	void DrawMultiLineText(Canvas* pCanvas, String strText, Rectangle rtArea, Color colorText, Color colorBack);

	Rectangle GetTextAreaInTextBox(Rectangle rtArea);
	EnrichedText* StringToEnrichedText(String strText, Color colorText);
	Rectangle ChangeRightRectangleToNormal(Rectangle rtArea);

	void FilteringViewAreaValue();
	bool IsElementInViewArea(Rectangle rtElement);
	Rectangle GetTimeAreaFromTextBox(Rectangle rtTextBox, bool bIsI);
	Rectangle GetTextAreaInTimeArea(Rectangle rtArea);
	Rectangle GetImageBoxArea(Rectangle rtArea);


	void DrawTimeText(Canvas* pCanvas, Rectangle rtText, DateTime timeSend);


	void AddDataText(DateTime timeSend, String strText, bool bISend, bool bRedraw=false);
	void AddDataImage(DateTime timeSend, String strImageFile, bool bISend, bool bRedraw=false);
	void AddDataFeedback(DateTime timeSend, String contents, bool bIsend, bool bRedraw=false);


	void AddIndexToNeedLoadImageArray(int nIndex);
	void SetImageRectToSize(Rectangle &rtImage, Bitmap* pImage);
	bool LoadImageInArray();
	void DrawChattDataText(Canvas* pCanvas, stCHATT_DATA* pChattData);
	void DrawChattDataImage(Canvas* pCanvas, stCHATT_DATA* pChattData);
	void DrawElementBackAndTime(Canvas* pCanvas, stCHATT_DATA* pChattData, Rectangle rtTextBox);

	void DrawYouPhotoAndName(Canvas* pCanvas, stCHATT_DATA* pChattData, Rectangle rtTextBox);
	void DrawMyPhotoAndName(Canvas* pCanvas, stCHATT_DATA* pChattData, Rectangle rtTextBox);

	bool IsChangedDate(DateTime timeSend);
	void AddDataDate(DateTime timeSend);
	int GetDayOfWeek(DateTime timeDate);
	String GetDayOfWeekString(DateTime timeDate);
	void DrawChattDataDate(Canvas* pCanvas, stCHATT_DATA* pChattData);
	long GetImageIndexByPoint(Point point);
	String GetImageFileName(long nIndex);
	void CreateElementCaptureImage(long nIndex);

	void ReDraw(const Rectangle& bounds);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);







	virtual void OnAudioRecorderCanceled(result r) {
	}
	virtual void OnAudioRecorderClosed(result r) {
	}
	virtual void OnAudioRecorderEndReached(RecordingEndCondition endCondition) {
	}
	virtual void OnAudioRecorderErrorOccurred(RecorderErrorReason r) {
	}
	virtual void OnAudioRecorderPaused(result r) {
	}
	virtual void OnAudioRecorderStarted(result r) {
	}
	virtual void OnAudioRecorderStopped(result r) {
	}
	virtual void OnPlayerAudioFocusChanged(void) {
	}
	virtual void OnPlayerBuffering(int percent) {
	}
	virtual void OnPlayerEndOfClip(void) {
	}
	virtual void OnPlayerErrorOccurred(Tizen::Media::PlayerErrorReason r) {
	}
	virtual void OnPlayerInterrupted(void) {
	}
	virtual void OnPlayerOpened(result r) {
	}
	virtual void OnPlayerReleased(void) {
	}
	virtual void OnPlayerSeekCompleted(result r) {
	}

// Implementation
protected:
	stSCREEN_INFO __stScreenInfo;
	Tizen::Base::Collection::ArrayList* __pArrayChattData;
	Tizen::Base::Collection::ArrayList* __pArrayNeedLoadImage;

	//static const int DF_TIMER_INTERVAL_REDRAW = 30;
	static const int DF_TIMER_INTERVAL_REDRAW = 40;
	static const int IDC_BUTTON_FEEDBACKX1 = 446;
	static const int IDC_BUTTON_RECORDER1 = 447;
	Tizen::Base::Runtime::Timer* __pTimerRedraw;
	Tizen::Base::Runtime::Timer* __pTimerAutoSlide;
	bool isimage= false;
	bool isfeedback = false;
	bool isfeedback_complete = false;
	Canvas* __pCanvasMain;
	Canvas* __pCanvasBack;

	int feed_back_count[100];
	int feed_back_cnt=0;








public:

	enum { DATA_TYPE_DATE = 0, DATA_TYPE_TEXT, DATA_TYPE_IMAGE };

	static const RequestId REQUEST_JCHATT_SELECT_PHOTO = 1101;
	static const RequestId REQUEST_JCHATT_SELECT_IMAGE = 1102;

	virtual result OnDraw(void);
	virtual void OnTimerExpired(Tizen::Base::Runtime::Timer& timer);

	virtual void OnTouchDoublePressed (const Tizen::Ui::Control &source,	const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo) {}
	virtual void OnTouchFocusIn(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo) {}
	virtual void OnTouchFocusOut(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo) {}
	virtual void OnTouchLongPressed(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo) {}
	virtual void OnTouchMoved(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchPressed(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchReleased(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo);
	Button* feed_back;
	Rectangle rtCanvas;
	static const int IDC_FEEDBACK_BUTTON = 344;
};


#endif /* JMCHATTCONTROL_H_ */
