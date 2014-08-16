/*
 * PartnerSearchItem.cpp
 *
 *  Created on: Aug 16, 2014
 *      Author: Gants
 */



#include "PartnerSearchItem.h"
#include "AppResourceId.h"
#include "SceneRegister.h"


static TableView *table_view = null;

result
PartnerSearchItem::OnDraw()
{

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	pCanvas = new Canvas();
	pCanvas = this->GetCanvasN();

	pCanvas->FillRectangle(Color(246,246,246,255), Rectangle(0,0,this->GetWidth(),this->GetHeight()));
	pCanvas->FillRectangle(Color(255,255,255,255), Rectangle(50,10,620,240));


	Dimension Dim_Location;

	Font *pFont = new Font;
	Font *pFont2 = new Font;
	Font *pFont3 = new Font;

	pFont->Construct(FONT_STYLE_PLAIN, 40);
	pFont2->Construct(FONT_STYLE_PLAIN, 30);
	pFont3->Construct(FONT_STYLE_PLAIN, 25);


	EnrichedText *pEnrichedText = new EnrichedText();
	TextElement* pTextElement = new TextElement();

	EnrichedText *pEnrichedText2 = new EnrichedText();
	TextElement* pTextElement2 = new TextElement();

	EnrichedText *pEnrichedText3 = new EnrichedText();
	TextElement* pTextElement3 = new TextElement();
	String tmp;

	pCanvas->DrawBitmap(Rectangle( 225, 95, 50, 30),*pAppResource->GetBitmapN(str_nation));
	pCanvas->DrawBitmap(Rectangle( 230, 145, 39, 39),*pAppResource->GetBitmapN(str_hobby));




	//pCanvas->DrawBitmap(Rectangle(90, 40, 100, 100), *pAppResource->GetBitmapN(str_profile));




		pTextElement->Construct(str_name);

		pFont->GetTextExtent(pTextElement->GetText(), pTextElement->GetText().GetLength(), Dim_Location);
		pEnrichedText->Construct(Dim_Location);
	    pEnrichedText->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
		pEnrichedText->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
		pEnrichedText->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
		pEnrichedText->SetTextAbbreviationEnabled(true);

		pTextElement->SetTextColor(Color(40,40,40,255));

		pTextElement->SetFont(*pFont);
		pEnrichedText->Add(*pTextElement);
		pCanvas->DrawText(Point(225, 40), *pEnrichedText);



		pTextElement2->Construct(str_nation_language.GetPointer());

		pFont2->GetTextExtent(pTextElement2->GetText(), pTextElement2->GetText().GetLength(), Dim_Location);
		pEnrichedText2->Construct(Dim_Location);
		pEnrichedText2->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
		pEnrichedText2->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
		pEnrichedText2->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
		pEnrichedText2->SetTextAbbreviationEnabled(true);

		pTextElement2->SetTextColor(Color(140,140,140,255));

		pTextElement2->SetFont(*pFont2);
		pEnrichedText2->Add(*pTextElement2);
		pCanvas->DrawText(Point(280, 94), *pEnrichedText2);




		pTextElement3->Construct(str_hobby_what.GetPointer());

		pFont3->GetTextExtent(pTextElement3->GetText(), pTextElement3->GetText().GetLength(), Dim_Location);
		pEnrichedText3->Construct(Dim_Location);
		pEnrichedText3->SetHorizontalAlignment(TEXT_ALIGNMENT_LEFT);
		pEnrichedText3->SetVerticalAlignment(TEXT_ALIGNMENT_MIDDLE);
		pEnrichedText3->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
		pEnrichedText3->SetTextAbbreviationEnabled(true);

		pTextElement3->SetTextColor(Color(140,140,140,255));

		pTextElement3->SetFont(*pFont3);
		pEnrichedText3->Add(*pTextElement3);
		pCanvas->DrawText(Point(280, 149), *pEnrichedText3);





	return true;

}



bool
PartnerSearchItem::Construct(const Rectangle& rect)
{
	result r = Container::Construct(rect, true, true);
	return true;
}

int
PartnerSearchItem::GetPanelHeight()
{
	return panel_height;
}
void
PartnerSearchItem::Initialize(String _name, String _profile, String _nation, String _nation_language, String hobby,
		String phobby_what, String content, TableView *pb, TableViewItem *pItem, int __index)
{


	/*
	 *
	String			 str_name;
	String			 str_profile;
	String			str_nation;
	String			str_nation_language;
	String			hobby;
	String			phobby_what;
	String 			str_contents;
	Canvas 			*pCanvas;
	Bitmap			*profile_iamge;
	Bitmap			*national_flag_image;
	Bitmap			* hobby_pic;
	int 			_index;
	TableViewItem	*pvi;
	ListView* 		__pListView;
	Rectangle		content_area;
	 */
	panel_height = this->GetHeight();
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	Dimension tmp_dim;
	str_name = _name;
	str_profile=_profile;
	str_nation=_nation;
	str_nation_language=_nation_language;
	str_hobby=hobby;
	str_hobby_what=phobby_what;
	str_contents=content;

	national_flag_image = pAppResource->GetBitmapN(str_nation);
	profile_iamge = pAppResource->GetBitmapN(str_profile);
	hobby_pic = pAppResource->GetBitmapN(L"hobby.png");
	_index = __index;
	pvi = pItem;

	if(table_view==null)
		table_view = pb;
	content_area.SetBounds(30,30,this->GetWidth()-60, this->GetHeight()-60);

	Introduce_Button = new Button();
	Introduce_Button->Construct(Rectangle(50,206, 620, 54),L"");
	Introduce_Button->SetActionId(ID_INTRODUCE_BUTTON);
	Introduce_Button->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"introduce1.png"));
	Introduce_Button->AddActionEventListener(*this);
	AddControl(Introduce_Button);

	Button* bprofile;
	bprofile = new Button();
	bprofile->Construct(Rectangle(90, 40, 100, 100));
	bprofile->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(str_profile));
	bprofile->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(str_profile));
	bprofile->SetActionId(IDC_BUTTON_PROFILE);
	bprofile->AddActionEventListener(*this);
	AddControl(bprofile);
	//104,51
	Friend_Add = new Button();
	Friend_Add->Construct(Rectangle(89, 150, 104, 51 ));
	Friend_Add->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"partner_plus.png"));
	Friend_Add->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"partner_plus.png"));
	Friend_Add->SetActionId(IDC_BUTTON_PARTNER_PLUS);
	Friend_Add->AddActionEventListener(*this);
	AddControl(Friend_Add);
}




void
PartnerSearchItem::OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here


}

void
PartnerSearchItem::OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
PartnerSearchItem::OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	// TODO: Add your implementation codes here

}

void
PartnerSearchItem::OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}

void
PartnerSearchItem::OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{



}


void
PartnerSearchItem::OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{
	//SceneManager* pSceneManager = SceneManager::GetInstance();



}

void
PartnerSearchItem::OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
{

}

void
PartnerSearchItem::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
    switch (actionId)
    {
    case ID_INTRODUCE_BUTTON:

    		if(introduce_open==false)
    		{

    			Introduce_Button->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"introduce2.png"));
    			Introduce_Button->Draw();

    			introduce_open = true;
    			/*
    			toast = new Toast();
    			toast->Construct(Rectangle(30,1100 ,660,70), L"종인이 토스트", 2000);

    			Rectangle(0,0,720,260);
    			*/
    			int reset_index = _index+1;
    			int plus=0;


    			panel_height+=240;
    			pvi->SetBounds(Rectangle(0,0,720, panel_height));
    			this->SetBounds(Rectangle(0,0,720, panel_height));
    			/*
    			arr_cal[_index] = 1;
    			if(!_index==0)
    			{
    			for(int i=0; i<_index; i++)
    			{
    				plus+=arr_cal[i];
    			}
    			}
    			AppLog("!!!!!!!%d",plus);
    			*/
    			extend_panel = new ScrollPanel();

    			extend_panel->Construct(Rectangle(50,260,620,240));

    			extend_panel->SetBackgroundColor(Color(224,224,224));
    			__EditArea = new EditArea();
    			__EditArea->Construct(Rectangle(20,20,580,130));
    			__EditArea->SetText(str_contents);
    			__EditArea->SetTextSize(28.5f);
    			__EditArea->SetKeypadEnabled(false);
    			__EditArea->SetColor(EDIT_STATUS_NORMAL, Color(224,224,224,255));
    			__EditArea->SetColor(EDIT_STATUS_DISABLED, Color(224,224,224,255));
    			__EditArea->SetColor(EDIT_STATUS_PRESSED, Color(224,224,224,255));
    			__EditArea->SetColor(EDIT_STATUS_HIGHLIGHTED, Color(224,224,224,255));
    			__EditArea->SetViewModeEnabled(true);
    			//256,68
    			chat_onetoone = new Button();
    			chat_onetoone->Construct(Rectangle(182, 160 ,256,68));
    			chat_onetoone->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"chat_one_to_one.png"));
    			chat_onetoone->SetActionId(IDC_BUTTON_ONE_TO_ONE);
    			chat_onetoone->AddActionEventListener(*this);

    			extend_panel->AddControl(__EditArea);
    			extend_panel->AddControl(chat_onetoone);
    			AddControl(extend_panel);
    			table_view->RefreshAllItems();



    		} else if(introduce_open ==true) {


    			Introduce_Button->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"introduce1.png"));
    			Introduce_Button->Draw();

    			panel_height-=240;
    			pvi->SetBounds(Rectangle(0,0,720, panel_height));
    			this->SetBounds(Rectangle(0,0,720, panel_height));
    			chat_onetoone->Destroy();
    			__EditArea->Destroy();
    			extend_panel->Destroy();
    			table_view->RefreshAllItems();
    			introduce_open = false;


    		}
    	break;

    case IDC_BUTTON_PROFILE:
    	break;
    case IDC_BUTTON_ONE_TO_ONE:
    	toast = new Toast();
    	toast->Construct(Rectangle(30,1100 ,660,70), L"1:1 채팅으로 넘어갑니다", 2000);
    	break;
    case IDC_BUTTON_PARTNER_PLUS:
    	if(isFriend_add_clicked == false)
    	{
    		toast = new Toast();
    		toast->Construct(Rectangle(30,1100 ,660,70), L"친구요청을 완료하였습니다", 2000);
    		Friend_Add->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"partner_wait.png"));
    		Friend_Add->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"partner_wait.png"));
    		Friend_Add->Draw();
    		isFriend_add_clicked = true;
    	} else {
    		Friend_Add->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"partner_plus.png"));
    		Friend_Add->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"partner_plus.png"));
    		Friend_Add->Draw();


    		toast = new Toast();
    		toast->Construct(Rectangle(30,1100 ,660,70), L"친구요청을 취소하였습니다", 2000);
    		isFriend_add_clicked = false;
    	}
    	break;
    default:
        break;
    }
}




ListItemBase*
PartnerSearchItem::CreateItem(int index, int itemWidth)
{
    // Creates an instance of CustomItem

    CustomItem* pItem = new CustomItem();
    ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
/*
    switch (index % 4)
    {
    case 0:
        {
            style = LIST_ANNEX_STYLE_NORMAL;
            pItem->Construct(Dimension(itemWidth,50), style);
            pItem->AddElement(Rectangle(0, 0, itemWidth, 50), 555, L"Home", true);
        }
        break;
    case 1:
        {
            style = LIST_ANNEX_STYLE_NORMAL;
            pItem->Construct(Dimension(itemWidth,50), style);
            pItem->AddElement(Rectangle(0, 0, 150, 50), 555, L"Home", true);
        }
        break;
    case 2:
        {
            style = LIST_ANNEX_STYLE_NORMAL;
            pItem->Construct(Dimension(itemWidth,50), style);
            pItem->AddElement(Rectangle(0, 0, 150, 50), 555, L"Home", true);
        }
        break;
    case 3:
        {
            style = LIST_ANNEX_STYLE_NORMAL;
            pItem->Construct(Dimension(itemWidth,50), style);
            pItem->AddElement(Rectangle(0, 0, 150, 50), 555, L"Home", true);
        }
        break;
    default:
        break;
    }
*/
    return pItem;
}


int
PartnerSearchItem::GetItemCount(void)
{
    return 15;
}

bool
PartnerSearchItem::DeleteItem(int index, ListItemBase* pItem, int itemWidth)
{
    delete pItem;
    pItem = null;
    return true;
}

void
PartnerSearchItem::DrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap &bitmap)
{
   BufferInfo bufferInfo;
   int x;
   int y;
   int offset;
   byte srcR;
   byte srcG;
   byte srcB;
   byte destR;
   byte destG;
   byte destB;
   int alphaLevel;
   int srcLevel;
   int destLevel;
   int r;
   int g;
   int b;
   unsigned short color16;
   unsigned short* pBuffer16;
   unsigned long* pBuffer32;
   int bufferWidth;
   int bufferX1;
   int bufferY1;
   int bufferX2;
   int bufferY2;
   int x1;
   int y1;
   int x2;
   int y2;
   int width;
   int height;

   canvas.DrawBitmap(rect, bitmap);
   canvas.Lock(bufferInfo);

   x1 = rect.x;
   y1 = rect.y;
   width  = rect.width;
   height = rect.height;

   x2 = x1 + width - 1;
   y2 = y1 + height - 1;

   bufferX1 = 0;
   bufferY1 = 0;
   bufferX2 = bufferX1 + bufferInfo.width - 1;
   bufferY2 = bufferY1 + bufferInfo.height - 1;

   if (x1 > bufferX2 || x2 < bufferX1)
   {
      return;
   }
   if (y1 > bufferY2 || y2 < bufferY1)
   {
      return;
   }
   if (x1 < bufferX1)
   {
      x1 = bufferX1;
   }
   if (x2 > bufferX2)
   {
      x2 = bufferX2;
   }
   if (y1 < bufferY1)
   {
      y1 = bufferY1;
   }
   if (y2 > bufferY2)
   {
      y2 = bufferY2;
   }
   width  = x2 - x1 + 1;
   height = y2 - y1 + 1;

   bufferWidth = bufferInfo.width;
   int k = 0;
   if (bufferInfo.bitsPerPixel == 16)
   {
      color16 = static_cast< unsigned short >(COLOR32ToCOLOR16 (color.GetRGB32()));
      pBuffer16 = static_cast< unsigned short* >(bufferInfo.pPixels);
      alphaLevel = 100 - static_cast< int >(static_cast< float >(color.GetAlpha() / 2.56));
      srcLevel = alphaLevel;
      destLevel = 100 - alphaLevel;

      srcR = static_cast< byte >(color16 >> 11);
      srcG = static_cast< byte >((color16 >> 6) & 0x001F);
      srcB = static_cast< byte >(color16 & 0x001F);

      for (y = y1; y < y1 + height; y++)
      {
         for (x = x1; x < x1 + width; x++)
         {
        	k = ((y-y1)-height/2)*((y-y1)-height/2) + ((x-x1)-height/2) * ((x-x1)-height/2);
        	k = sqrt(k);
        	if(k>(height/2))
        	{
				offset = bufferWidth * y + x;
				destR = static_cast< byte >(pBuffer16[offset] >> 11);
				destG = static_cast< byte >((pBuffer16[offset] >> 6) & 0x001F);
				destB = static_cast< byte >(pBuffer16[offset] & 0x001F);
				r = (destR * destLevel + srcR * srcLevel) / 100;
				g = (destG * destLevel + srcG * srcLevel) / 100;
				b = (destB * destLevel + srcB * srcLevel) / 100;
				destR = static_cast< byte >(r);
				destG = static_cast< byte >(g);
				destB = static_cast< byte >(b);
				pBuffer16[offset] = static_cast< unsigned short >((destR << 11) | (destG << 6) | (destB));
        	}
         }
      }
   }
   else if (bufferInfo.bitsPerPixel == 32)
   {
      pBuffer32 = static_cast< unsigned long* >(bufferInfo.pPixels);

      for (y = y1; y < y1 + height; y++)
      {
         for (x = x1; x < x1 + width; x++)
         {
         	k = ((y-y1)-height/2)*((y-y1)-height/2) + ((x-x1)-height/2) * ((x-x1)-height/2);
         	k = sqrt(k);
         	if(k>(height/2))
         	{
 				offset = bufferWidth * y + x;
 				pBuffer32[offset] = color.GetRGB32();
         	}
         }
      }
   }

   canvas.Unlock();
}


