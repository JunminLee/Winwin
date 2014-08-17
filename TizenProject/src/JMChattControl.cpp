/*
 * JMChattControl.cpp
 *
 *  Created on: Aug 13, 2014
 *      Author: Gants
 */



#include "JMChattControl.h"

JMChattControl::JMChattControl() :
	__pArrayChattData(null), __pArrayNeedLoadImage(null), __pTimerRedraw(null), __pTimerAutoSlide(null),
	__pCanvasMain(null), __pCanvasBack(null)
{
	__stScreenInfo.colorTextI = Color(255,255,255);
	__stScreenInfo.colorTextBackI= Color(0,181,238);
	__stScreenInfo.colorTextOutlineI= Color(0,148,195);
	__stScreenInfo.colorTextYou =  Color(0,0,0);
	__stScreenInfo.colorTextBackYou =  Color(255,255,255);
	__stScreenInfo.colorTextOutlineYou= Color(240,240,240);
	__stScreenInfo.colorTextTime  = Color(255,255,255);
	__stScreenInfo.colorTextBackTime= Color(160,160,160,128);
	__stScreenInfo.colorTextOutlineTime= Color(160,160,160,128);

	__stScreenInfo.pBitmapYouPhoto = null;
	__stScreenInfo.colorBackground = Color(0,0,0,0);
	__stScreenInfo.pBitmapBackground = null;
	__stScreenInfo.nElementGapY = 10;

	__stScreenInfo.nTextBoxWidth = 240;
	__stScreenInfo.nTextBoxInsideGap = 15;
	__stScreenInfo.nTextBoxMarginI = 25;
	__stScreenInfo.nTextBoxMarginYou = __stScreenInfo.nPhotoBoxMarginYou * 2 + __stScreenInfo.nYouPhotoBoxHeight;

	__stScreenInfo.nTextBoxMarginDate = 10;

	__stScreenInfo.nPhotoBoxMarginYou = 15;
	__stScreenInfo.nYouPhotoBoxHeight = 40;
	__stScreenInfo.nImageBoxMaxHeight = 200;

	__stScreenInfo.nYouNameHeight = 30;


	__stScreenInfo.nTimeAreaWidth = 60;
	__stScreenInfo.nTimeAreaHeight = 40;

	__stScreenInfo.nTotalElementHeight = 0;

	__stScreenInfo.nViewAreaTop = 0;
	__stScreenInfo.nViewAreaBottom = 0;
	__stScreenInfo.nViewAreaStartIndex = -1;
	__stScreenInfo.nViewAreaEndIndex = -1;

	__stScreenInfo.pointTouchPrev = Point(-1,-1);

	__stScreenInfo.bNeedRedraw = false;

	__stScreenInfo.nSlideDistance = 0;
	__stScreenInfo.fSlideSpeed = 0.f;
	__stScreenInfo.fSlideSpeedDecrease = 0.f;
	__stScreenInfo.nTimeTickTouchMoved = 0;

	__stScreenInfo.nSelectedImageIndex = -1;
}

JMChattControl::~JMChattControl() {

	if( __pArrayChattData ) {
		__pArrayChattData->RemoveAll(false);
		delete __pArrayChattData;
		__pArrayChattData = null;
	}

	if( __pArrayNeedLoadImage ) {
		__pArrayNeedLoadImage->RemoveAll(false);
		delete __pArrayNeedLoadImage;
		__pArrayNeedLoadImage = null;
	}


	if( __pTimerRedraw ) {
		__pTimerRedraw->Cancel();
		delete __pTimerRedraw;
		__pTimerRedraw = null;
	}

	if( __pTimerAutoSlide ) {
		__pTimerAutoSlide->Cancel();
		delete __pTimerAutoSlide;
		__pTimerAutoSlide = null;
	}

	if( __pCanvasMain ) {
		delete __pCanvasMain;
		__pCanvasMain = null;
	}

	if( __pCanvasBack ) {
		delete __pCanvasBack;
		__pCanvasBack = null;
	}
}
void JMChattControl::ReDraw(const Rectangle& bounds)
{

}


void JMChattControl::Initialize(const Rectangle& bounds, String strYouName, Bitmap* pBitmapYouPhoto, String strMyName, Bitmap* pBitmapMyPhoto)
{
	this->Construct(bounds);


	AddTouchEventListener(*this);


	__stScreenInfo.rtScreen = this->GetBounds();


	if( __pCanvasBack == null ) {
		__pCanvasBack = new Canvas();
		__pCanvasBack->Construct(__stScreenInfo.rtScreen);
	}


	__stScreenInfo.strYouName = strYouName;
	__stScreenInfo.pBitmapYouPhoto = pBitmapYouPhoto;

	__stScreenInfo.strMyName = strMyName;
	__stScreenInfo.pBitmapMyPhoto = pBitmapMyPhoto;

	__pArrayChattData = new ArrayList();
	__pArrayChattData->Construct();


	__pArrayNeedLoadImage = new ArrayList();
	__pArrayNeedLoadImage->Construct();


	InitVariable();


	__pTimerRedraw = new Timer();
	__pTimerRedraw->Construct(*this);
	__pTimerRedraw->Start(DF_TIMER_INTERVAL_REDRAW);


	__pTimerAutoSlide = new Timer();
	__pTimerAutoSlide->Construct(*this);
}


Tizen::Graphics::Bitmap*
JMChattControl::GetBitmapN(const Tizen::Base::String& name)
{
	Bitmap* pBitmap = null;
	Image* pImage = new Image();
	pImage->Construct();

	String fullname(L"");
	fullname.Append(name);

	if(fullname.EndsWith(L"png")) {
		pBitmap = pImage->DecodeN(fullname, BITMAP_PIXEL_FORMAT_ARGB8888);
	}
	else {
		pBitmap = pImage->DecodeN(fullname, BITMAP_PIXEL_FORMAT_RGB565);
	}
	delete pImage;

	return pBitmap;
}


void JMChattControl::InitVariable()
{

	__stScreenInfo.nElementGapY = (int)(__stScreenInfo.rtScreen.width * 6. / 100.);

	__stScreenInfo.nTextBoxWidth = (int)(__stScreenInfo.rtScreen.width * 50. / 100.);

	__stScreenInfo.nTextBoxInsideGap = (int)(__stScreenInfo.rtScreen.width * 1.5 / 100.)+10;

	__stScreenInfo.nTextBoxMarginI = (int)(__stScreenInfo.rtScreen.width * 5. / 100.)+10;


	__stScreenInfo.nPhotoBoxMarginYou = (int)(__stScreenInfo.rtScreen.width * 2.5 / 100.);

	__stScreenInfo.nYouPhotoBoxHeight = (int)(__stScreenInfo.rtScreen.width * 14. / 100.);

	__stScreenInfo.nYouNameHeight = (int)(__stScreenInfo.rtScreen.width * 8. / 100.);

	__stScreenInfo.nTextBoxMarginYou = __stScreenInfo.nPhotoBoxMarginYou * 2 + __stScreenInfo.nYouPhotoBoxHeight;


	__stScreenInfo.nTextBoxMarginDate = (int)(__stScreenInfo.rtScreen.width * 2. / 100.);


	__stScreenInfo.fontText.Construct(FONT_STYLE_PLAIN, (int)(__stScreenInfo.rtScreen.width/17.));

	__stScreenInfo.nImageBoxMaxHeight = (int)(__stScreenInfo.rtScreen.width * 26. / 100.);

	__stScreenInfo.nTimeAreaWidth = (int)(__stScreenInfo.rtScreen.width * 20. / 110.);

	__stScreenInfo.nTimeAreaHeight = (int)(__stScreenInfo.rtScreen.width * 8. / 110.);

	__stScreenInfo.fontTime.Construct(FONT_STYLE_PLAIN, (int)(__stScreenInfo.rtScreen.width/25.));

	__stScreenInfo.fSlideSpeedDecrease = __stScreenInfo.rtScreen.width / 80.f;
}


void JMChattControl::DrawFillRoundRectangle(Canvas* pCanvas, Rectangle rtArea, Color colorBack, Color colorOutline)
{

	AppLog("33333DrawFillRoundRectangle");

	int nLineWidth = 4, nGapWidth=0;
	Dimension sizeCorner;
	Rectangle rtBack;


	nGapWidth = nLineWidth / 2;
	rtBack = rtArea;
	rtBack.x += nGapWidth;
	rtBack.y += nGapWidth;
	rtBack.width -= (nGapWidth * 2 );
	rtBack.height -= (nGapWidth * 2);


	pCanvas->SetBackgroundColor(colorBack);
	pCanvas->FillRectangle(colorBack, rtBack);


	pCanvas->SetLineWidth(4);
	pCanvas->SetForegroundColor(colorOutline);
	nGapWidth = (int)(nLineWidth * 1.5) + 1;
	sizeCorner.SetSize(nGapWidth, nGapWidth);
	pCanvas->DrawRoundRectangle(rtArea, sizeCorner);
}


Rectangle JMChattControl::GetTextAreaInTextBox(Rectangle rtArea)
{
	Rectangle rtText;
	rtText.x = rtArea.x + __stScreenInfo.nTextBoxInsideGap;
	rtText.y = rtArea.y + __stScreenInfo.nTextBoxInsideGap;
	rtText.width = rtArea.width - __stScreenInfo.nTextBoxInsideGap * 2;
	rtText.height = rtArea.height - __stScreenInfo.nTextBoxInsideGap * 2;
	return rtText;
}
Rectangle JMChattControl::GetImageBoxArea(Rectangle rtArea)
{
	Rectangle rtText;
	rtText.x = rtArea.x + __stScreenInfo.nTextBoxInsideGap - ((int)(__stScreenInfo.rtScreen.width * 1.5 / 100.)+10)-52;
	rtText.y = rtArea.y + __stScreenInfo.nTextBoxInsideGap - ((int)(__stScreenInfo.rtScreen.width * 1.5 / 100.)+10)-2 ;
	rtText.width = __stScreenInfo.nImageBoxMaxHeight + 262;
	rtText.height = __stScreenInfo.nImageBoxMaxHeight + 70;
	return rtText;
}


Rectangle JMChattControl::GetTextAreaInTimeArea(Rectangle rtArea)
{
	Rectangle rtText;
	rtText.x = rtArea.x + __stScreenInfo.nTextBoxInsideGap;
	rtText.y = rtArea.y + __stScreenInfo.nTextBoxInsideGap;
	rtText.width = rtArea.width - __stScreenInfo.nTextBoxInsideGap * 2;
	rtText.height = rtArea.height - __stScreenInfo.nTextBoxInsideGap * 2;
	return rtText;
}


void JMChattControl::DrawTextBox(Canvas* pCanvas, String strText, Rectangle rtArea, Color colorText, Color colorBack, Color colorOutline)
{


	AppLog("3333DrawMultiLineText");
	DrawFillRoundRectangle(pCanvas, rtArea, colorBack, colorOutline);

	Rectangle rtText;

	rtText = GetTextAreaInTextBox(rtArea);


	DrawMultiLineText(pCanvas, strText, rtText, colorText, colorBack);

}


void JMChattControl::DrawMultiLineText(Canvas* pCanvas, String strText, Rectangle rtArea, Color colorText, Color colorBack)
{

	result r = E_SUCCESS;

	EnrichedText* pEnrichedText = null;
	TextElement* pTextElement1 = null;
	pEnrichedText = new EnrichedText();
	r = pEnrichedText->Construct(Dimension(rtArea.width, rtArea.height));
    if (IsFailed(r)) {
		return;
    }
    pEnrichedText->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
    pEnrichedText->SetVerticalAlignment(TEXT_ALIGNMENT_TOP);
    pEnrichedText->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
    pEnrichedText->SetTextAbbreviationEnabled(false);

	// Create a TextElement and set attributes.
	pTextElement1 = new TextElement();
	r = pTextElement1->Construct(strText);
	if (IsFailed(r)) {
		return;
	}
	pTextElement1->SetTextColor(colorText);
    pTextElement1->SetFont(__stScreenInfo.fontText);
    // Add the TextElement to the EnrichedText
    pEnrichedText->Add(*pTextElement1);
    pCanvas->SetBackgroundColor(colorBack);



    // Draw the EnrichedText at the specified Point
    pCanvas->DrawText(Point(rtArea.x, rtArea.y), *pEnrichedText);
    // Clean up
    pEnrichedText->RemoveAllTextElements(true);
    delete pEnrichedText;
}


EnrichedText* JMChattControl::StringToEnrichedText(String strText, Color colorText)
{
	result r = E_SUCCESS;


	int nTextWidth = __stScreenInfo.nTextBoxWidth - (__stScreenInfo.nTextBoxInsideGap * 2);
	Dimension dimText;

	__stScreenInfo.fontText.GetTextExtent(strText, strText.GetLength(), dimText);
	if( dimText.width < nTextWidth )
		nTextWidth = dimText.width;

	EnrichedText* pEnrichedText = null;
	TextElement* pTextElement1 = null;
	pEnrichedText = new EnrichedText();
	r = pEnrichedText->Construct(Dimension(nTextWidth, __stScreenInfo.rtScreen.height));
	if (IsFailed(r)) {
		return null;
	}
	pEnrichedText->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
	pEnrichedText->SetVerticalAlignment(TEXT_ALIGNMENT_TOP);
	pEnrichedText->SetTextWrapStyle(TEXT_WRAP_WORD_WRAP);
	pEnrichedText->SetTextAbbreviationEnabled(false);

	// Create a TextElement and set attributes.
	pTextElement1 = new TextElement();
	r = pTextElement1->Construct(strText);
	if (IsFailed(r)) {
		return null;
	}
	pTextElement1->SetTextColor(colorText);
	pTextElement1->SetFont(__stScreenInfo.fontText);
	// Add the TextElement to the EnrichedText
	pEnrichedText->Add(*pTextElement1);


	pEnrichedText->SetSize(nTextWidth, pEnrichedText->GetTotalLineHeight());

	return pEnrichedText;
}


void JMChattControl::FilteringViewAreaValue()
{

	if( __stScreenInfo.nViewAreaBottom > __stScreenInfo.nTotalElementHeight )
		__stScreenInfo.nViewAreaBottom = __stScreenInfo.nTotalElementHeight;


	if( __stScreenInfo.nTotalElementHeight > __stScreenInfo.rtScreenNow.height ) {
		if( __stScreenInfo.nViewAreaBottom < __stScreenInfo.rtScreenNow.height )
			__stScreenInfo.nViewAreaBottom = __stScreenInfo.rtScreenNow.height;
	}
}


bool JMChattControl::IsElementInViewArea(Rectangle rtElement)
{
	if( rtElement.y > __stScreenInfo.nViewAreaBottom )
		return false;
	if( rtElement.y + rtElement.height < __stScreenInfo.nViewAreaTop )
		return false;

	return true;
}


Rectangle JMChattControl::ChangeRightRectangleToNormal(Rectangle rtArea)
{
	Rectangle rtRight;

	rtRight = rtArea;

	if( rtArea.x < 0 )
		rtRight.x = __stScreenInfo.rtScreenNow.width + rtArea.x;
	rtRight.y = rtArea.y - __stScreenInfo.nViewAreaTop;

	return rtRight;
}


Rectangle JMChattControl::GetTimeAreaFromTextBox(Rectangle rtTextBox, bool bIsI)
{
	Rectangle rtTime;

	if( bIsI ) {
		rtTime.x = rtTextBox.x - __stScreenInfo.nTimeAreaWidth;
	}

	else {
		rtTime.x = rtTextBox.x + rtTextBox.width;
	}
	if(isfeedback == false)
	{
	rtTime.width = __stScreenInfo.nTimeAreaWidth;
	rtTime.y = rtTextBox.y + rtTextBox.height - (int)(__stScreenInfo.nTimeAreaHeight * 1.1);
	rtTime.height = __stScreenInfo.nTimeAreaHeight;
	} else {
		rtTime.width = __stScreenInfo.nTimeAreaWidth;
		rtTime.y = rtTextBox.y + rtTextBox.height - (int)(__stScreenInfo.nTimeAreaHeight * 1.1);
		rtTime.height = __stScreenInfo.nTimeAreaHeight;
	}

	return rtTime;
}

void JMChattControl::DrawTimeText(Canvas* pCanvas, Rectangle rtText, DateTime timeSend)
{
	String strTime;
	int nHour=0;


	nHour = timeSend.GetHour();
	if( nHour > 12 ) {
		nHour -= 12;
		strTime.Format(50, L"PM %d:%02d", nHour, timeSend.GetMinute());
	}
	else {
		strTime.Format(50, L"AM %d:%02d", nHour, timeSend.GetMinute());
	}
	Point tmp;
	tmp.x= rtText.GetTopLeft().x-10;
	tmp.y= rtText.GetTopLeft().y-10;
	pCanvas->SetForegroundColor(__stScreenInfo.colorTextTime);
	pCanvas->SetBackgroundColor(__stScreenInfo.colorTextBackTime);
	pCanvas->SetFont(__stScreenInfo.fontTime);
	pCanvas->DrawText(tmp, strTime);
}


void JMChattControl::AddIndexToNeedLoadImageArray(int nIndex)
{
	__pArrayNeedLoadImage->Add(*(new Integer(nIndex)));
}


void JMChattControl::OnTimerExpired(Timer& timer)
{

	if( &timer == __pTimerRedraw ) {

		if( __stScreenInfo.bNeedRedraw ) {

			this->RequestRedraw();
			__stScreenInfo.bNeedRedraw = false;
		}

		else if( __pArrayNeedLoadImage->GetCount() > 0 ) {

			bool bLoad = LoadImageInArray();

			if( bLoad )

				this->RequestRedraw();
		}

		__pTimerRedraw->Start(DF_TIMER_INTERVAL_REDRAW);
	}

	else if( &timer == __pTimerAutoSlide ) {

		__stScreenInfo.fSlideSpeed -= __stScreenInfo.fSlideSpeedDecrease;

		if( (__stScreenInfo.fSlideSpeed > 0.f && __stScreenInfo.fSlideSpeedDecrease > 0.f) ||
				(__stScreenInfo.fSlideSpeed < 0.f && __stScreenInfo.fSlideSpeedDecrease < 0.f)	) {
			//AppLog(">>> OnTimerExpired - %0.f", __stScreenInfo.fSlideSpeed);

			__stScreenInfo.nSlideDistance = (int)__stScreenInfo.fSlideSpeed;

			__stScreenInfo.bNeedRedraw = true;

			__pTimerAutoSlide->Start(DF_TIMER_INTERVAL_REDRAW);
		}

		else {

			__stScreenInfo.fSlideSpeed = 0.f;

			__stScreenInfo.nSlideDistance = 0;

			__stScreenInfo.bNeedRedraw = true;
		}
	}
}


void JMChattControl::SetImageRectToSize(Rectangle &rtImage, Bitmap* pImage)
{
	if( pImage == null )
		return;
	int nImageWidth=0, nImageHeight=0;
	nImageWidth = pImage->GetWidth();
	nImageHeight = pImage->GetHeight();

	rtImage.width = (int)((float)rtImage.height * (float)nImageWidth / (float)nImageHeight / 2) ;

	if( rtImage.x < 0 ) {
		rtImage.x = (rtImage.width + __stScreenInfo.nTextBoxMarginI) * -1;
	}
}


void JMChattControl::DrawElementBackAndTime(Canvas* pCanvas, stCHATT_DATA* pChattData, Rectangle rtTextBox)
{

	AppLog("3333DrawElementBackAndTime");
	Rectangle rtTime, rtText;
	Color colorTextBack, colorTextOutline;

	if( pChattData->bISend ) {

		colorTextBack = __stScreenInfo.colorTextBackI;
		colorTextOutline = __stScreenInfo.colorTextOutlineI;
	}

	else {


		colorTextBack = __stScreenInfo.colorTextBackYou;
		colorTextOutline = __stScreenInfo.colorTextOutlineYou;

	}


	rtTime = GetTimeAreaFromTextBox(rtTextBox, pChattData->bISend);

	DrawFillRoundRectangle(pCanvas, rtTime, __stScreenInfo.colorTextBackTime, __stScreenInfo.colorTextOutlineTime);

	rtText = GetTextAreaInTimeArea(rtTime);

	DrawTimeText(pCanvas, rtText, pChattData->timeSend);


	DrawFillRoundRectangle(pCanvas, rtTextBox, colorTextBack, colorTextOutline);


}


void JMChattControl::AddDataText(DateTime timeSend, String strText, bool bISend, bool bRedraw)
{
	isfeedback = false;

	AppLog("3333AddDataText");
	isimage = false;
	if( IsChangedDate(timeSend) ) {

		AddDataDate(timeSend);
	}

	Color colorText;
	stCHATT_DATA* pChattData = new stCHATT_DATA;

	pChattData->isImage=false;

	pChattData->nDataType = DATA_TYPE_TEXT;

	pChattData->timeSend = timeSend;

	pChattData->bISend = bISend;

	pChattData->pBitmapImage = null;

	pChattData->pBitmapCapture = null;


	if( bISend )
		colorText = __stScreenInfo.colorTextI;

	else
		colorText = __stScreenInfo.colorTextYou;


	pChattData->pEnrichedText = StringToEnrichedText(strText, colorText);

	pChattData->rtElementBox.y = __stScreenInfo.nTotalElementHeight + __stScreenInfo.nElementGapY;
	pChattData->rtElementBox.height = pChattData->pEnrichedText->GetHeight() + __stScreenInfo.nTextBoxInsideGap * 2;
	pChattData->rtElementBox.width = pChattData->pEnrichedText->GetWidth() + __stScreenInfo.nTextBoxInsideGap * 2;

	if( bISend )

		pChattData->rtElementBox.x = (pChattData->rtElementBox.width + __stScreenInfo.nTextBoxMarginI) * -1;

	else {

		pChattData->rtElementBox.x = __stScreenInfo.nTextBoxMarginYou;

		pChattData->rtElementBox.y += __stScreenInfo.nYouNameHeight;

		__stScreenInfo.nTotalElementHeight += __stScreenInfo.nYouNameHeight;
	}


	__pArrayChattData->Add(*(Object*)pChattData);


	__stScreenInfo.nTotalElementHeight += (pChattData->rtElementBox.height + __stScreenInfo.nElementGapY);

	__stScreenInfo.nViewAreaBottom = __stScreenInfo.nTotalElementHeight;

	if( bRedraw )
		this->RequestRedraw();
}
void JMChattControl::AddDataFeedback(DateTime timeSend, String contents, bool bIsend, bool bRedraw)
{


	isfeedback = true;
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	if( IsChangedDate(timeSend) )
	{

			AddDataDate(timeSend);
	}
	stCHATT_DATA* pChattData = new stCHATT_DATA;
	Color colorText;
	String strText;

	strText.Append(L"\"");
	strText.Append(contents);
	strText.Append(L"\"");
	strText.Append(L" 이 표현좀 읽어줘 ~");

	pChattData->isImage=false;

		pChattData->nDataType = DATA_TYPE_TEXT;

		pChattData->timeSend = timeSend;

		pChattData->bISend = bIsend;

		pChattData->pBitmapImage = null;

		pChattData->pBitmapCapture = null;


		if( bIsend )
			colorText = __stScreenInfo.colorTextI;

		else
			colorText = __stScreenInfo.colorTextYou;


		pChattData->pEnrichedText = StringToEnrichedText(strText, colorText);

		pChattData->rtElementBox.y = __stScreenInfo.nTotalElementHeight + __stScreenInfo.nElementGapY;

		pChattData->rtElementBox.width = 428;

		if( bIsend )
		{
			pChattData->rtElementBox.height = pChattData->pEnrichedText->GetHeight() + __stScreenInfo.nTextBoxInsideGap * 2;
			pChattData->rtElementBox.x = (pChattData->rtElementBox.width + __stScreenInfo.nTextBoxMarginI) * -1;
		}

		else {
			pChattData->rtElementBox.height = pChattData->pEnrichedText->GetHeight() + __stScreenInfo.nTextBoxInsideGap * 2 + 50;
			pChattData->rtElementBox.x = __stScreenInfo.nTextBoxMarginYou;

			pChattData->rtElementBox.y += __stScreenInfo.nYouNameHeight;

			__stScreenInfo.nTotalElementHeight += __stScreenInfo.nYouNameHeight + 100;
		}

		feed_back = new Button();
		feed_back->Construct(Rectangle(pChattData->rtElementBox.x-1, pChattData->rtElementBox.y+ pChattData->rtElementBox.height - 60, 432,  110));
		feed_back->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"voice_feedback1.png"));
		feed_back->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"voice_feedback1.png"));
		AddControl(feed_back);


		__pArrayChattData->Add(*(Object*)pChattData);

		feed_back_count[feed_back_cnt++] = __pArrayChattData->GetCount()-1;


		__stScreenInfo.nTotalElementHeight += (pChattData->rtElementBox.height + __stScreenInfo.nElementGapY);

		__stScreenInfo.nViewAreaBottom = __stScreenInfo.nTotalElementHeight;


	if( bRedraw )
		this->RequestRedraw();

}

void JMChattControl::ReDrawFeedback()
{
			AppResource* pAppResource = Application::GetInstance()->GetAppResource();
			feed_back->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"voice_feedback2.png"));
			feed_back->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"voice_feedback2.png"));
			feed_back->Draw();
}
void JMChattControl::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{



	switch(actionId)
	{



	}

}
void JMChattControl::AddDataImage(DateTime timeSend, String strImageFile, bool bISend, bool bRedraw)
{

	AppLog("3333AddDataImage");
	isimage = true;
	if( IsChangedDate(timeSend) )
	{

		AddDataDate(timeSend);
	}

	stCHATT_DATA* pChattData = new stCHATT_DATA;

	pChattData->isImage=true;
	pChattData->nDataType = DATA_TYPE_IMAGE;

	pChattData->timeSend = timeSend;

	pChattData->strImageFile = strImageFile;

	pChattData->bISend = bISend;

	pChattData->pBitmapImage = null;

	pChattData->pBitmapCapture = null;


	pChattData->rtElementBox.y = __stScreenInfo.nTotalElementHeight + __stScreenInfo.nElementGapY;
	pChattData->rtElementBox.height = __stScreenInfo.nImageBoxMaxHeight + 70;
	pChattData->rtElementBox.width = __stScreenInfo.nImageBoxMaxHeight + 50;


	if( bISend )
		pChattData->rtElementBox.x = (pChattData->rtElementBox.width + __stScreenInfo.nTextBoxMarginI) * -1;

	else {

		pChattData->rtElementBox.x = __stScreenInfo.nTextBoxMarginYou +50;

		pChattData->rtElementBox.y += __stScreenInfo.nYouNameHeight ;

		__stScreenInfo.nTotalElementHeight += __stScreenInfo.nYouNameHeight;

	}


	__pArrayChattData->Add(*(Object*)pChattData);


	__stScreenInfo.nTotalElementHeight += (pChattData->rtElementBox.height + __stScreenInfo.nElementGapY);

	__stScreenInfo.nViewAreaBottom = __stScreenInfo.nTotalElementHeight;

	if( bRedraw )
		this->RequestRedraw();
}


bool JMChattControl::IsChangedDate(DateTime timeSend)
{
	int nElementCount=0;


	nElementCount = __pArrayChattData->GetCount();

	if( nElementCount < 1 )
		return true;

	int nNewYear=0, nNewMonth=0, nNewDate=0, nLastYear=0, nLastMonth=0, nLastDate=0;
	stCHATT_DATA* pChattData = null;

	nNewYear = timeSend.GetYear();
	nNewMonth = timeSend.GetMonth();
	nNewDate = timeSend.GetDay();


	pChattData = (stCHATT_DATA*)(__pArrayChattData->GetAt(nElementCount-1));

	nLastYear = pChattData->timeSend.GetYear();
	nLastMonth = pChattData->timeSend.GetMonth();
	nLastDate = pChattData->timeSend.GetDay();


	if( nNewYear == nLastYear && nNewMonth == nLastMonth && nNewDate == nLastDate )
		return false;

	return true;
}


void JMChattControl::AddDataDate(DateTime timeSend)
{
	AppLog("33333AddDataDate");
	stCHATT_DATA* pChattData = new stCHATT_DATA;

	pChattData->nDataType = DATA_TYPE_DATE;

	pChattData->timeSend = timeSend;

	pChattData->pBitmapImage = null;

	pChattData->pBitmapCapture = null;


	String strDayOfWeek = GetDayOfWeekString(pChattData->timeSend);

	pChattData->strText.Format(50, L"%04d. %02d. %02d ", pChattData->timeSend.GetYear(), pChattData->timeSend.GetMonth(), pChattData->timeSend.GetDay());
	pChattData->strText.Append(strDayOfWeek);


	pChattData->rtElementBox.y = __stScreenInfo.nTotalElementHeight + __stScreenInfo.nElementGapY;
	pChattData->rtElementBox.height = __stScreenInfo.nTimeAreaHeight;
	pChattData->rtElementBox.x = __stScreenInfo.nTextBoxMarginDate;
	pChattData->rtElementBox.width = __stScreenInfo.rtScreen.width - __stScreenInfo.nTextBoxMarginDate * 2;


	__pArrayChattData->Add(*(Object*)pChattData);


	__stScreenInfo.nTotalElementHeight += (pChattData->rtElementBox.height + __stScreenInfo.nElementGapY);
}


String JMChattControl::GetDayOfWeekString(DateTime timeDate)
{
	String strDayOfWeek=L"";


	int nDayOfWeek = GetDayOfWeek(timeDate);

	switch( nDayOfWeek ) {
	case 0 :
		strDayOfWeek = L"Sat";
		break;
	case 1 :
		strDayOfWeek = L"Sun";
		break;
	case 2 :
		strDayOfWeek = L"Mon";
		break;
	case 3 :
		strDayOfWeek = L"Tue";
		break;
	case 4 :
		strDayOfWeek = L"Wed";
		break;
	case 5 :
		strDayOfWeek = L"Thu";
		break;
	default :
		strDayOfWeek = L"Fri";
		break;
	}
	return strDayOfWeek;
}


int JMChattControl::GetDayOfWeek(DateTime timeDate)
{
	Calendar* pCalendar_FirstDay = Calendar::CreateInstanceN();
	pCalendar_FirstDay->SetTime(timeDate);

	int nDayOfWeek = pCalendar_FirstDay->GetTimeField(TIME_FIELD_DAY_OF_WEEK);
	return nDayOfWeek;
}


void JMChattControl::DrawChattDataDate(Canvas* pCanvas, stCHATT_DATA* pChattData)
{
	Rectangle rtTextBox, rtText;
	Dimension dimText;


	rtTextBox = ChangeRightRectangleToNormal(pChattData->rtElementBox);
	rtTextBox.y = 0;


	DrawFillRoundRectangle(pCanvas, rtTextBox, __stScreenInfo.colorTextBackTime, __stScreenInfo.colorTextOutlineTime);

	rtText = GetTextAreaInTimeArea(rtTextBox);


	__stScreenInfo.fontTime.GetTextExtent(pChattData->strText, pChattData->strText.GetLength(), dimText);
	rtText.x = (rtTextBox.width - dimText.width) / 2;
	rtText.width = dimText.width;

	Point timetmp;
	timetmp.x = rtText.GetTopLeft().x + 10;
	timetmp.y = rtText.GetTopLeft().y - 10;


	pCanvas->SetForegroundColor(__stScreenInfo.colorTextTime);
	pCanvas->SetBackgroundColor(__stScreenInfo.colorTextBackTime);
	pCanvas->SetFont(__stScreenInfo.fontTime);
	pCanvas->DrawText(timetmp, pChattData->strText);
}

// Touch Pressed
void JMChattControl::OnTouchPressed(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{


	if( touchInfo.GetPointId() != 0 )
		return;


	if( (int)__stScreenInfo.fSlideSpeed != 0 ) {
		__stScreenInfo.fSlideSpeed = 0.f;
		__pTimerAutoSlide->Cancel();
	}


	if( __pArrayNeedLoadImage->GetCount() > 0 ) {
		__pArrayNeedLoadImage->RemoveAll(false);
	}


	__stScreenInfo.nSelectedImageIndex = GetImageIndexByPoint(currentPosition);


	__stScreenInfo.pointTouchPrev = currentPosition;

}

// Touch Moved
void JMChattControl::OnTouchMoved(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{

	if( touchInfo.GetPointId() != 0 )
		return;


	if( __stScreenInfo.nTotalElementHeight < __stScreenInfo.rtScreenNow.height ) {

		__stScreenInfo.pointTouchPrev = currentPosition;
		return;
	}


	SystemTime::GetTicks(__stScreenInfo.nTimeTickTouchMoved);


	__stScreenInfo.fSlideSpeed = __stScreenInfo.pointTouchPrev.y - currentPosition.y;

	__stScreenInfo.nSlideDistance += (int)(__stScreenInfo.fSlideSpeed);

	__stScreenInfo.pointTouchPrev = currentPosition;


	__stScreenInfo.bNeedRedraw = true;

}


void JMChattControl::OnTouchReleased(const Tizen::Ui::Control &source, const Tizen::Graphics::Point &currentPosition, const Tizen::Ui::TouchEventInfo &touchInfo)
{

	if( touchInfo.GetPointId() != 0 )
		return;

	long long nTicks;

	SystemTime::GetTicks(nTicks);

	if( (nTicks - __stScreenInfo.nTimeTickTouchMoved) > 100 )

		__stScreenInfo.fSlideSpeed = 0.f;


	if(	(int)__stScreenInfo.fSlideSpeed != 0 ) {

		if( (__stScreenInfo.fSlideSpeed > 0.f && __stScreenInfo.fSlideSpeedDecrease < 0.f) ||
				(__stScreenInfo.fSlideSpeed < 0.f && __stScreenInfo.fSlideSpeedDecrease > 0.f) ) {
			__stScreenInfo.fSlideSpeedDecrease *= -1.f;
		}

		__pTimerAutoSlide->Start(DF_TIMER_INTERVAL_REDRAW);
	}

	else {

		__stScreenInfo.bNeedRedraw = true;
	}


	if( __stScreenInfo.nSelectedImageIndex >= 0 ) {

		long nSelectedIndex = GetImageIndexByPoint(currentPosition);

		if( __stScreenInfo.nSelectedImageIndex == nSelectedIndex ) {

			ArrayList* __pArraySelectedElement = new ArrayList();

			__pArraySelectedElement->Construct();

			__pArraySelectedElement->Add(*(new Long(nSelectedIndex)));

			Container* pParent = this->GetParent();
			pParent->SendUserEvent(REQUEST_JCHATT_SELECT_IMAGE, (IList*)__pArraySelectedElement);

		}
	}

}


long JMChattControl::GetImageIndexByPoint(Point point)
{
	long i=0;
	stCHATT_DATA* pChattData = null;
	Rectangle rtElementBox;


	for(i=__stScreenInfo.nViewAreaStartIndex ; i <= __stScreenInfo.nViewAreaEndIndex ; i++) {
		pChattData = (stCHATT_DATA*)(__pArrayChattData->GetAt(i));


		rtElementBox = ChangeRightRectangleToNormal(pChattData->rtElementBox);


		if( rtElementBox.Contains(point) ) {
			return i;
		}
	}
	return -1;
}


String JMChattControl::GetImageFileName(long nIndex)
{



	stCHATT_DATA* pChattData = null;
	pChattData = (stCHATT_DATA*)(__pArrayChattData->GetAt(nIndex));




	//String strFileName;
	String strFileName = pChattData->strImageFile;

	return strFileName;
}


void JMChattControl::DrawBackground(Canvas* pCanvas)
{

	if( __stScreenInfo.pBitmapBackground ) {
		pCanvas->DrawBitmap(__stScreenInfo.rtScreen, *__stScreenInfo.pBitmapBackground);
	}

	else {
		pCanvas->FillRectangle(__stScreenInfo.colorBackground, __stScreenInfo.rtScreen);
	}
}


void JMChattControl::SetBackColor(Color colorBackground, bool bRedraw)
{
	__stScreenInfo.colorBackground = colorBackground;

	if( __stScreenInfo.pBitmapBackground ) {
		delete __stScreenInfo.pBitmapBackground;
		__stScreenInfo.pBitmapBackground = null;
	}


	DrawBackground(__pCanvasBack);

	if( bRedraw )
		this->RequestRedraw();
}


void JMChattControl::SetBackImage(Bitmap* strImageFileName, bool bRedraw)
{

	__stScreenInfo.pBitmapBackground = strImageFileName;


	DrawBackground(__pCanvasBack);

	if( bRedraw )
		this->RequestRedraw();
}


result JMChattControl::OnDraw(void)
{
	result r = E_SUCCESS;


	if( __pCanvasMain == null )
		__pCanvasMain = GetCanvasN();


	__stScreenInfo.rtScreenNow = this->GetBounds();

	if( __stScreenInfo.nSlideDistance != 0 ) {

		__stScreenInfo.nViewAreaBottom += __stScreenInfo.nSlideDistance;

		FilteringViewAreaValue();
	}


	__stScreenInfo.nViewAreaTop = __stScreenInfo.nViewAreaBottom - __stScreenInfo.rtScreenNow.height;
	if( __stScreenInfo.nViewAreaTop < 0 )
		__stScreenInfo.nViewAreaTop = 0;

	if( __pCanvasBack ) {
		__pCanvasMain->Copy(Point(__stScreenInfo.rtScreen.x,__stScreenInfo.rtScreen.y), *__pCanvasBack, __stScreenInfo.rtScreen);
	}


	DrawChattData(__pCanvasMain);

	if( __stScreenInfo.nSlideDistance != 0 ) {

		__stScreenInfo.nSlideDistance = 0;
	}

	return r;
}


void JMChattControl::DrawChattData(Canvas* pCanvas)
{
	int i=0, nDataCount=0;
	stCHATT_DATA* pChattData = null;
	Rectangle rtTextBox, rtText, rtTime;


	__stScreenInfo.nViewAreaStartIndex = -1;

	__stScreenInfo.nViewAreaEndIndex = -1;


	nDataCount = __pArrayChattData->GetCount();
	for(i=nDataCount-1 ; i >= 0 ; i--)
	{

		pChattData = (stCHATT_DATA*)(__pArrayChattData->GetAt(i));


		if( !IsElementInViewArea(pChattData->rtElementBox) ){

			if( __stScreenInfo.nViewAreaStartIndex >= 0 )
				break;
			continue;
		}


		if( __stScreenInfo.nViewAreaStartIndex < 0 )
			__stScreenInfo.nViewAreaStartIndex = i;
		else if( __stScreenInfo.nViewAreaStartIndex > i )
			__stScreenInfo.nViewAreaStartIndex = i;

		if( __stScreenInfo.nViewAreaEndIndex < 0 )
			__stScreenInfo.nViewAreaEndIndex = i;


		if( pChattData->pBitmapCapture == null ) {

			CreateElementCaptureImage(i);
		}


		rtTextBox.x = 0;
		rtTextBox.width = pChattData->pBitmapCapture->GetWidth();
		rtTextBox.height = pChattData->pBitmapCapture->GetHeight();
		rtTextBox.y = pChattData->rtElementBox.y - __stScreenInfo.nViewAreaTop;

		if( pChattData->nDataType != DATA_TYPE_DATE && !pChattData->bISend )
			rtTextBox.y -= __stScreenInfo.nYouNameHeight;


		for(int k=0; k<feed_back_cnt; k++)
		{
		if(feed_back_count[k] == i)
		{
			if(pChattData->bISend== false)
			{
			if(feed_back)
			{

				feed_back->SetBounds(rtTextBox.x + 135, rtTextBox.y - 203, 432, 110);
				feed_back->RequestRedraw();

			}
			}
		}

		}
		pCanvas->DrawBitmap(rtTextBox, *pChattData->pBitmapCapture);


		if( pChattData->nDataType == DATA_TYPE_IMAGE ) {

			if( __stScreenInfo.nSlideDistance == 0 && pChattData->pBitmapImage == null ) {

				AddIndexToNeedLoadImageArray(i);
			}
		}
	}
}


void JMChattControl::CreateElementCaptureImage(long nIndex)
{

	stCHATT_DATA* pChattData = (stCHATT_DATA*)(__pArrayChattData->GetAt(nIndex));

	rtCanvas.x = 0;
	rtCanvas.y = 0;
	rtCanvas.width = __stScreenInfo.rtScreen.width;
	rtCanvas.height = pChattData->rtElementBox.height;


	if( pChattData->nDataType != DATA_TYPE_DATE && !pChattData->bISend ) {
		rtCanvas.height += __stScreenInfo.nYouNameHeight;
	}


	Canvas *pCanvas = new Canvas();
	pCanvas->Construct(rtCanvas);


	if( pChattData->nDataType == DATA_TYPE_TEXT ) {

		DrawChattDataText(pCanvas, pChattData);

	}

	else if( pChattData->nDataType == DATA_TYPE_IMAGE ) {

		DrawChattDataImage(pCanvas, pChattData);
	}

	else if( pChattData->nDataType == DATA_TYPE_DATE ) {

		DrawChattDataDate(pCanvas, pChattData);
	}


	if( pChattData->pBitmapCapture ) {
		delete pChattData->pBitmapCapture;
		pChattData->pBitmapCapture = null;
	}

	pChattData->pBitmapCapture = new Bitmap();
	pChattData->pBitmapCapture->Construct(*pCanvas, rtCanvas);
	delete pCanvas;
	pCanvas = null;
}


void JMChattControl::DrawYouPhotoAndName(Canvas* pCanvas, stCHATT_DATA* pChattData, Rectangle rtTextBox)
{
	Point pointYouName;
	Rectangle rtPhoto;


	pointYouName.x = __stScreenInfo.nPhotoBoxMarginYou + __stScreenInfo.nYouPhotoBoxHeight + 30;
	pointYouName.y = rtTextBox.y;

	pCanvas->SetFont(__stScreenInfo.fontText);
	pCanvas->SetForegroundColor(__stScreenInfo.colorTextYou);
	pCanvas->DrawText(pointYouName, __stScreenInfo.strYouName);


	rtPhoto.x = __stScreenInfo.nPhotoBoxMarginYou;
	rtPhoto.width = __stScreenInfo.nYouPhotoBoxHeight;
	rtPhoto.y = pointYouName.y;
	rtPhoto.height = __stScreenInfo.nYouPhotoBoxHeight;

	pCanvas->DrawBitmap(rtPhoto, *__stScreenInfo.pBitmapYouPhoto);

}

void JMChattControl::DrawMyPhotoAndName(Canvas* pCanvas, stCHATT_DATA* pChattData, Rectangle rtTextBox)
{
/*
	Point pointMyName;
	Rectangle rtPhoto;


	pointYouName.x = rtTextBox.x;
	pointYouName.y = rtTextBox.y;

	pCanvas->SetFont(__stScreenInfo.fontText);
	pCanvas->SetForegroundColor(__stScreenInfo.colorTextYou);
	pCanvas->DrawText(pointYouName, __stScreenInfo.strYouName);


	rtPhoto.x = __stScreenInfo.nPhotoBoxMarginYou;
	rtPhoto.width = __stScreenInfo.nYouPhotoBoxHeight;
	rtPhoto.y = pointYouName.y;
	rtPhoto.height = __stScreenInfo.nYouPhotoBoxHeight;

	pCanvas->DrawBitmap(rtPhoto, *__stScreenInfo.pBitmapYouPhoto);
*/
}

void JMChattControl::DrawChattDataText(Canvas* pCanvas, stCHATT_DATA* pChattData)
{
	Rectangle rtTextBox, rtText, rtTime;


	rtTextBox = ChangeRightRectangleToNormal(pChattData->rtElementBox);
	rtTextBox.y = 0;


	if( !pChattData->bISend ) {

		DrawYouPhotoAndName(pCanvas, pChattData, rtTextBox);
		rtTextBox.y += __stScreenInfo.nYouNameHeight;
	}

	DrawElementBackAndTime(pCanvas, pChattData, rtTextBox);


	rtText = GetTextAreaInTextBox(rtTextBox);



	pCanvas->DrawText(rtText.GetTopLeft(), *pChattData->pEnrichedText);
}


void JMChattControl::DrawChattDataImage(Canvas* pCanvas, stCHATT_DATA* pChattData)
{
	Rectangle rtTextBox, rtText, rtTime;
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	rtTextBox = ChangeRightRectangleToNormal(pChattData->rtElementBox);
	rtTextBox.y = 0;


	if( !pChattData->bISend ) {

		DrawYouPhotoAndName(pCanvas, pChattData, rtTextBox);
		rtTextBox.y += __stScreenInfo.nYouNameHeight;
	}


	DrawElementBackAndTime(pCanvas, pChattData, rtTextBox);

	pChattData->pBitmapImage = pAppResource->GetBitmapN(L"voice_pb1.png");
	AppLog("ffffffffff");
	if( pChattData->pBitmapImage ) {

		rtText = GetImageBoxArea(rtTextBox);

		pCanvas->DrawBitmap(rtText, *pChattData->pBitmapImage );
	}
}


bool JMChattControl::LoadImageInArray()
{
	int nArrayCount=0, nIndex=0;

	nArrayCount = __pArrayNeedLoadImage->GetCount();

	if( nArrayCount < 1 )
		return false;


	Integer* pIndex = static_cast<Integer*>(__pArrayNeedLoadImage->GetAt(nArrayCount-1));

	nIndex = pIndex->ToInt();

	__pArrayNeedLoadImage->RemoveAt(nArrayCount-1);


	stCHATT_DATA* pChattData = (stCHATT_DATA*)(__pArrayChattData->GetAt(nIndex));

	if( pChattData->strImageFile.GetLength() < 1 )
		return false;

	if( pChattData->pBitmapImage )
		return false;



	//pChattData->strImageFile = L"";
	if( pChattData->pBitmapImage == null )
		return false;


	SetImageRectToSize(pChattData->rtElementBox, pChattData->pBitmapImage);


	CreateElementCaptureImage(nIndex);


	delete pChattData->pBitmapImage;
	pChattData->pBitmapImage = null;

	return true;
}

