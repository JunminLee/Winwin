/*
 * CommentItem.cpp
 *
 *  Created on: Aug 15, 2014
 *      Author: pji
 */
#include "CommentItem.h"

result
CommentItem::OnDraw()
{
	pCanvas = this->GetCanvasN();

	pCanvas->FillRectangle(Color(255,255,255,255), Rectangle(0,0,this->GetWidth(), this->GetHeight()));
	pCanvas->DrawBitmap(Rectangle(30,5,100,100), *profile_image);
	pCanvas->FillRectangle(Color(230,230,230,255), Rectangle(30,this->GetHeight()-10, this->GetWidth()-60, 5));

	pCanvas->DrawText(Point(180, 20), *enriched_text1);
	pCanvas->DrawText(Point(500, 20), *enriched_text3);
	pCanvas->DrawText(Point(180, 50), *enriched_text2);
}

bool
CommentItem::Construct(const Rectangle& rect)
{
	result r = Container::Construct(rect, true, true);
	return r;
}
void
CommentItem::Initialize(String name, String time, String comment, String bitmap_path)
{
	Font font;
    font.Construct(FONT_STYLE_PLAIN, 25);

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	profile_image = pAppResource->GetBitmapN(L"tizen.png");

	enriched_text1 = new EnrichedText();
	enriched_text2 = new EnrichedText();
	enriched_text3 = new EnrichedText();

	enriched_text1->Construct(Dimension(400,30));
	enriched_text1->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
	enriched_text1->SetTextAbbreviationEnabled(true);

	enriched_text2->Construct(Dimension(500,30));
	enriched_text2->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
	enriched_text2->SetTextAbbreviationEnabled(true);

	enriched_text3->Construct(Dimension(150,30));
	enriched_text3->SetTextWrapStyle(TEXT_WRAP_CHARACTER_WRAP);
	enriched_text3->SetTextAbbreviationEnabled(true);

	text_element_name = new TextElement();
	text_element_time = new TextElement();
	text_element_comment = new TextElement();


	text_element_name->Construct(name);
	text_element_time->Construct(time);
	text_element_comment->Construct(comment);

	text_element_name->SetFont(font);
	text_element_time->SetFont(font);
	text_element_time->SetTextColor(Color(200,200,200,255));
	text_element_comment->SetFont(font);

	enriched_text1->Add(*text_element_name);
	enriched_text2->Add(*text_element_comment);
	enriched_text3->Add(*text_element_time);

//	this->RequestRedraw(true);

}




