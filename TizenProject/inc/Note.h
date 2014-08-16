/*
 * Note.h
 *
 *  Created on: Aug 16, 2014
 *      Author: pji
 */

#ifndef NOTE_H_
#define NOTE_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FUiIme.h>
#include <FGraphics.h>
#include <gl.h>
#include <FMedia.h>
#include "TimeLineItem.h"
#include "CustomPanel.h"


using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Base::Collection;


class NoteItem
	: public Tizen::Ui::Controls::Panel
	, public Tizen::Ui::ITouchEventListener
{
private:
	    EnrichedText* pEnrichedText;
	    EnrichedText* pEnrichedText2;
	    TextElement* pTextElement1;
	    TextElement* pTextElement2;
	    Dimension	dimension;
	    int height;
	    bool del_check;
	    Rectangle del_button;
	    Label	  *del_button_label;

	    TableView *pv;
public:
		virtual result	OnDraw()
		{
			Canvas *pCanvas = this->GetCanvasN();


			pCanvas->FillRectangle(Color(255,255,255,255), Rectangle(20,20,this->GetWidth(),height));
			pCanvas->DrawText(Point(40,40), *pEnrichedText);
			pCanvas->DrawText(Point(40,45+pEnrichedText->GetHeight()), *pEnrichedText2);


		}
		void Construct(String eng_Text, String kor_Text, int width, TableViewItem* pItem, bool delcheck,  TableView *pb)
		{
			AppResource* pAppResource = Application::GetInstance()->GetAppResource();
		    Dimension tmp_dim;
		    Font font;
		    font.Construct(FONT_STYLE_PLAIN, 30);
		    pv = pb;
		    del_check = delcheck;
		    font.GetTextExtent(eng_Text, eng_Text.GetLength(), tmp_dim);

		    pEnrichedText = new EnrichedText();
		    pEnrichedText->Construct(Dimension(width, ((tmp_dim.width / width)+1) * 40));
		    pEnrichedText->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);

		    pTextElement1 = new TextElement();
		    pTextElement1->Construct(eng_Text);
		    pTextElement1->SetFont(font);
		    pTextElement1->SetTextColor(Color::GetColor(COLOR_ID_BLUE));

		    font.GetTextExtent(kor_Text, kor_Text.GetLength(), tmp_dim);

		    del_button = Rectangle(620,50,47,47);
		    pEnrichedText2 = new EnrichedText();
		    pEnrichedText2->Construct(Dimension(width, (((tmp_dim.width / width)+1) * 40)));
		    pEnrichedText2->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);

		    pTextElement2 = new TextElement();
		    pTextElement2->Construct(kor_Text);
		    pTextElement2->SetFont(font);
		    pTextElement2->SetTextColor(Color(170,170,170,255));

		    pEnrichedText->Add(*pTextElement1);
		    pEnrichedText2->Add(*pTextElement2);

		    height = pEnrichedText->GetHeight() + pEnrichedText2->GetHeight() + 70;



		    Panel::Construct(Rectangle(0,0,width, height));
		    Panel::SetBackgroundColor(Color(246,246,246,255));

		    dimension.width = width;
		    dimension.height = height;

		    if(del_check == true)
		    {
				del_button_label = new Label;
				del_button_label->Construct(del_button, " ");
				del_button_label->SetBackgroundBitmap(*pAppResource->GetBitmapN(L"word_del_button.png"));
				del_button_label->AddTouchEventListener(*this);
				AddControl(del_button_label);
		    }
		}



		Dimension GetDimension()
		{
			return dimension;
		}
		void Destroy()
		{

		}

protected:
	virtual void OnTouchDoublePressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
	{
	}
	virtual void OnTouchFocusIn(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
	{
	}
	virtual void OnTouchFocusOut(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
	{
	}
	virtual void OnTouchLongPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
	{
	}
	virtual void OnTouchMoved(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
	{
	}
	virtual void OnTouchPressed(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
	{
	}
	virtual void OnTouchReleased(const Tizen::Ui::Control& source, const Tizen::Graphics::Point& currentPosition, const Tizen::Ui::TouchEventInfo& touchInfo)
	{
		//지우
	}

};

class Note
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
    , public Tizen::Ui::Controls::ITableViewItemProvider
    , public  Tizen::Ui::Controls::ITableViewItemEventListener
    , public Tizen::Ui::ITextEventListener

{
public:
		Note(void);
	virtual ~Note(void);
	bool Initialize(void);

private:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);


public:
    // ISearchBarEventListener
    virtual void OnTextValueChanged(const Tizen::Ui::Control& source);
    virtual void OnTextValueChangeCanceled(const Tizen::Ui::Control& source){};

	virtual void 	OnTableViewContextItemActivationStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewContextItem *pContextItem, bool activated);
	virtual void 	OnTableViewItemReordered (Tizen::Ui::Controls::TableView &tableView, int itemIndexFrom, int itemIndexTo);
	virtual void 	OnTableViewItemStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewItem *pItem, Tizen::Ui::Controls::TableViewItemStatus status);

    virtual int GetItemCount(void);
    virtual Tizen::Ui::Controls::TableViewItem* CreateItem(int itemIndex, int itemWidth);
    virtual bool DeleteItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
    virtual void UpdateItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem);
    virtual int GetDefaultItemHeight(void);

private:
    static const int ID_FORMAT_STRING = 500;
    Tizen::Ui::Controls::SearchBar* __pSearchBar;
    Tizen::Ui::Controls::ListView*  __pSearchBarListView;
	ArrayList  		ArrCustomPanel;
	Panel			*head;
	EditField		*serach_field;

	Button*			button_garbage_can;
	Button*			button_flag;
	Button*			button_note_word;

	bool			del_check;
	String			result_word[100];
	int				result_word_cnt;
	TableView* 		TimelineTableView;

	String word[30];

};


#endif /* NOTE_H_ */
