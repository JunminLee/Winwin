#include "Note.h"

#include "AppResourceId.h"

#include "SceneRegister.h"

#include "CustomPanel.h"

#include "CommentItem.h"

#include "Toast.h"

using namespace Tizen::Base;

using namespace Tizen::App;

using namespace Tizen::Ui;

using namespace Tizen::Ui::Controls;

using namespace Tizen::Ui::Scenes;

using namespace Tizen::Graphics;

using namespace Tizen::Media;

Note::Note(void)

{

}

Note::~Note(void)

{

}

bool

Note::Initialize(void)

{

	result r = Construct(
			FORM_STYLE_NORMAL | FORM_STYLE_PORTRAIT_INDICATOR);

	TryReturn(r == E_SUCCESS, false, "Failed to construct form");

	return true;

}

result

Note::OnInitializing(void)

{

	result r = E_SUCCESS;

// TODO: Add your initialization code here



	AppResource* pAppResource = Application::GetInstance()->GetAppResource();

	head = new Panel();

	head->Construct(Rectangle(0, 0, this->GetWidth(), 96));

	head->SetBackgroundColor(Color(0, 181, 238, 255));

	button_note_word = new Button();

	button_note_word->Construct(Rectangle(32, 31, 136, 33));

	button_note_word->SetNormalBackgroundBitmap(
			*pAppResource->GetBitmapN(L"note_word_button.png"));

	button_note_word->AddActionEventListener(*this);

	button_note_word->SetActionId(50);
//
	AppLog("11");
	button_garbage_can = new Button();

	button_garbage_can->Construct(Rectangle(539, 20, 38, 51));

	button_garbage_can->SetNormalBackgroundBitmap(
			*pAppResource->GetBitmapN(L"garbage_can.png"));

	button_garbage_can->AddActionEventListener(*this);

	button_garbage_can->SetActionId(51);

	button_flag = new Button();

	button_flag->Construct(Rectangle(646, 29, 38, 43));

	button_flag->SetNormalBackgroundBitmap(
			*pAppResource->GetBitmapN(L"flag_button.png"));

	button_flag->AddActionEventListener(*this);

	button_flag->SetActionId(52);

	head->AddControl(button_note_word);

	head->AddControl(button_garbage_can);

	head->AddControl(button_flag);

// Setup back event listener

	SetFormBackEventListener(this);

// Get a button via resource ID

	//image_panel->Construct(Rectangle(96,0,this->GetWidth(), 500));
	//image_panel->

	del_check = false;

	word[0] = L"Aove";
	word[1] = L"He can only learn";
	word[2] = L"to love by loving.";
	word[3] = L"bove";
	word[4] = L"ce can only learn";
	word[5] = L"do love by loving.";
	word[6] = L"eove";
	word[7] = L"fe can only learn";
	word[8] = L"go love by loving.";
	word[9] = L"hove";
	word[10] = L"ye can only learn";
	word[11] = L"uo love by loving.";
	word[12] = L"iove";
	word[13] = L"ze can only learn";
	word[14] = L"vo love by loving.";
	word[15] = L"move";
	word[16] = L"le can only learn";
	word[17] = L"po love by loving.";
	word[18] = L"oove";
	word[19] = L"te can only learn";
	word[20] = L"ro love by loving.";
	word[21] = L"dove";
	word[22] = L"se can only learn";
	word[23] = L"ao love by loving.";
	word[24] = L"aove";
	word[25] = L"fe can only learn";
	word[26] = L"jo love by loving.";



    // Creates an instance of SearchBar
	serach_field = new EditField;

	serach_field->Construct(Rectangle(10, 110, this->GetWidth()-20, 50),EDIT_FIELD_STYLE_NORMAL,INPUT_STYLE_OVERLAY );
	serach_field->AddTextEventListener(*this);
	serach_field->SetBackgroundBitmap(EDIT_STATUS_NORMAL, *pAppResource->GetBitmapN(L"search_bar.png"));
	serach_field->SetBackgroundBitmap(EDIT_STATUS_PRESSED, *pAppResource->GetBitmapN(L"search_bar.png"));
	serach_field->SetBackgroundBitmap(EDIT_STATUS_HIGHLIGHTED, *pAppResource->GetBitmapN(L"search_bar.png"));

	TimelineTableView = new TableView();

	TimelineTableView->Construct(
			Rectangle(0, 170, GetClientAreaBounds().width,
					GetClientAreaBounds().height - 96), true,
					TABLE_VIEW_SCROLL_BAR_STYLE_FADE_OUT  );

	TimelineTableView->SetItemProvider(this);
	//TimelineTableView->SetBackgroundColor(Color(246,246,246,255));

	TimelineTableView->AddTableViewItemEventListener(*this);

	// Adds the TableView to the form


	AddControl(TimelineTableView);


	// Adds the TableView to the form
	AddControl(serach_field);
	AddControl(head);

	result_word_cnt = 27;

	for(int i=0; i<result_word_cnt; i++)
		result_word[i] = word[i];

	return r;

}

result

Note::OnTerminating(void)

{

	result r = E_SUCCESS;



// TODO: Add your termination code here

	return r;

}

void

Note::OnActionPerformed(const Tizen::Ui::Control& source,
		int actionId)

		{

	SceneManager* pSceneManager = SceneManager::GetInstance();

	AppAssert(pSceneManager);

	switch (actionId)

	{
	case 51:
	{
		if(del_check == false)
		{
			del_check = true;
		}
		else
		{
			del_check = false;
		}
		TimelineTableView->UpdateTableView();
	}
	break;
	}
}




void

Note::OnFormBackRequested(Tizen::Ui::Controls::Form& source)

{

	UiApp* pApp = UiApp::GetInstance();

	AppAssert(pApp);

	pApp->Terminate();

}

void

Note::OnSceneActivatedN(
		const Tizen::Ui::Scenes::SceneId& previousSceneId,

		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		Tizen::Base::Collection::IList* pArgs)

		{

// TODO: Activate your scene here.

}

void

Note::OnSceneDeactivated(
		const Tizen::Ui::Scenes::SceneId& currentSceneId,

		const Tizen::Ui::Scenes::SceneId& nextSceneId)

		{

// TODO: Deactivate your scene here.

}



void
Note::OnTextValueChanged(const Tizen::Ui::Control& source)
{


	int search_length = 0;
	String search_str;
	String word_tmp;
	search_length = serach_field->GetText().GetLength();
	search_str = serach_field->GetText();

	AppLog("search_str : %S , search_length : %d", search_str.GetPointer(), search_length);

	if(search_length == 0)
	{
		result_word_cnt = 27;
		for(int i = 0; i<27; i++)
			result_word[i] = word[i];
	}
	else
	{
		result_word_cnt = 0;
		for(int i=0; i<30; i++)
		{
			if(word[i].GetLength() >= search_length)
			{

				word_tmp = word[i];
				word_tmp.Remove(search_length, word[i].GetLength()-search_length);
			}
			if(search_str.Equals(word_tmp) == true)
			{
				AppLog("search : %S", word[i].GetPointer());
				result_word[result_word_cnt++] = word[i];
			}
			word_tmp.Clear();

		}
	}

	TimelineTableView->RemoveAllControls();
	TimelineTableView->UpdateTableView();


}
void
Note::OnTableViewContextItemActivationStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewContextItem *pContextItem, bool activated)
{

}
void
Note::OnTableViewItemReordered (Tizen::Ui::Controls::TableView &tableView, int itemIndexFrom, int itemIndexTo)
{

}
void
Note::OnTableViewItemStateChanged (Tizen::Ui::Controls::TableView &tableView, int itemIndex, Tizen::Ui::Controls::TableViewItem *pItem, Tizen::Ui::Controls::TableViewItemStatus status)
{
	AppLog("changed!");
}
//IListViewItemProvider
TableViewItem*
Note::CreateItem(int itemIndex, int itemWidth)
{
    // Creates an instance of CustomItem
	TableViewAnnexStyle style = TABLE_VIEW_ANNEX_STYLE_NORMAL;

	TableViewItem* pItem = new TableViewItem();
	NoteItem *np = new NoteItem;
    // Gets texts of the search bar

	AppLog("del_check : %d", del_check);
	np->Construct(result_word[itemIndex], L"한글을 사랑합시다!!", itemWidth, pItem, del_check, TimelineTableView);

	pItem->Construct(np->GetDimension(), style);
	pItem->AddControl(np);


            /*
    else if (inputText.CompareTo(L"b") == 0 || inputText.CompareTo(L"B") == 0)
    {
        switch (index%3)
        {
        case 0:
            {
                pItem->Construct(Dimension(itemWidth,100), style);
                pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"bonge", true);
            }
            break;
        case 1:
            {
                pItem->Construct(Dimension(itemWidth,100), style);
                pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"bnpyo", true);
            }
            break;
        case 2:
            {
                pItem->Construct(Dimension(itemWidth,100), style);
                pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"bkueon", true);
            }
            break;
        default:
            break;
        }
    }
    else
    {
        pItem->Construct(Dimension(itemWidth,100), style);
        pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"default", true);
    }*/

    return pItem;
}

bool
Note::DeleteItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem)
{
    delete pItem;
    pItem = null;
    return true;
}

void
Note::UpdateItem(int itemIndex, Tizen::Ui::Controls::TableViewItem* pItem)
{

}
int
Note::GetDefaultItemHeight(void)
{

}
int
Note::GetItemCount(void)
{
    return result_word_cnt;
}
