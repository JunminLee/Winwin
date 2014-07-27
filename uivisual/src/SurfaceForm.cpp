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

#include "SurfaceForm.h"

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Animations;
using namespace Tizen::Ui::Controls;

SurfaceForm::SurfaceForm(void)
	: __pOriginal(null)
{
	for (int i = 0; i < ROW * COL; i++)
	{
		__pShared[i] = null;
	}
}

SurfaceForm::~SurfaceForm(void)
{
}

result
SurfaceForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	Header* pHeader = Form::GetHeader();
	pHeader->SetStyle(HEADER_STYLE_TITLE);
	pHeader->SetTitleText(L"Surface & content bounds");
	
	Rectangle clientRect = GetClientAreaBounds();
	FloatRectangle originalRect(clientRect.x + (PADDING / 2.0f), clientRect.y + PADDING, ELEMENT_WIDTH, ELEMENT_HEIGHT);
	FloatRectangle sharedRect(originalRect.x, originalRect.y + originalRect.height + PADDING, ELEMENT_WIDTH, ELEMENT_HEIGHT);

	Frame* pFrame = UiApp::GetInstance()->GetFrame(L"UiVisualElement");
	DisplayContext* pDisplayContext = pFrame->GetDisplayContext();

	VisualElementSurface surface;
	surface.Construct(*pDisplayContext, Dimension(IMAGE_WIDTH, IMAGE_HEIGHT));

	AppResource* pAppResource = AppResource::GetInstance();
	if (pAppResource != null)
	{
		String imgName(L"img0.jpg");
		Bitmap* pBitmap = pAppResource->GetBitmapN(imgName);
		if (pBitmap != null)
		{
			Bitmap scaledBitmap;
			scaledBitmap.Construct(*pBitmap, Rectangle(0, 0, pBitmap->GetWidth(), pBitmap->GetHeight()));
			scaledBitmap.Scale(Dimension(IMAGE_WIDTH, IMAGE_HEIGHT));

			Canvas canvas;
			BufferInfo bufferInfo;
			surface.GetBufferInfo(bufferInfo);
			canvas.Construct(bufferInfo);
			canvas.DrawBitmap(Point(0, 0), scaledBitmap);

			delete pBitmap;
			pBitmap = null;
		}
	}

	__pOriginal = new (std::nothrow) VisualElement();
	__pOriginal->Construct();
	__pOriginal->SetName(L"Original");
	__pOriginal->SetBounds(originalRect);
	__pOriginal->SetShowState(true);
	__pOriginal->SetSurface(&surface);
	_pFormElement->AttachChild(__pOriginal);

	for(int x = 0; x < ROW; x++)
	{
		for(int y = 0; y < COL; y++)
		{
			int i = x * COL + y;
			String name;
			name.Format(10, L"Shared%d", i);
			__pShared[i] = new (std::nothrow) VisualElement();
			__pShared[i]->Construct();
			__pShared[i]->SetName(name);
			__pShared[i]->SetBounds(FloatRectangle(
					sharedRect.x + (x * (sharedRect.width + PADDING)),
					sharedRect.y + (y * (sharedRect.height + PADDING)),
					sharedRect.width,
					sharedRect.height
					));
			__pShared[i]->SetShowState(true);
			__pShared[i]->SetSurface(&surface);
			_pFormElement->AttachChild(__pShared[i]);
		}
	}

	AddTouchEventListener(*this);

	return r;
}

void
SurfaceForm::OnActionPerformed(const Control& source, int actionId)
{
	static bool toggle = false;
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_CONTENT_BOUNDS:
		if (toggle)
		{
			ShareSurface(SHARE_STYLE_CLONE);
		}
		else
		{
			ShareSurface(SHARE_STYLE_SPLIT);
		}
		break;

	default:
		break;
	}
	toggle = !toggle;
}

void
SurfaceForm::ShareSurface(int style)
{
	AnimationTransaction::Begin();

	for(int x = 0; x < ROW; x++)
	{
		for(int y = 0; y < COL; y++)
		{
			int i = x * COL + y;
			FloatRectangle rect(0.0f, 0.0f, 1.0f, 1.0f);
			VisualElementSurface* pSurface = __pOriginal->GetSurfaceN();
			Dimension surfaceSize = pSurface->GetSize();

			if(style == SHARE_STYLE_SPLIT)
			{
				rect.SetBounds(x * 1.0f / static_cast<float>(ROW), y * 1.0f / static_cast<float>(COL), 1.0f / static_cast<float>(ROW), 1.0f / static_cast<float>(COL));
			}

			__pShared[i]->SetContentBounds(rect);

			delete pSurface;
			pSurface = null;
		}
	}

	AnimationTransaction::Commit();

	_pFormElement->InvalidateRectangle(null);
}

void
SurfaceForm::InitializeFooter(void)
{
	FooterItem  item;
	item.Construct(ID_FOOTER_BUTTON_CONTENT_BOUNDS);
	item.SetText(L"Change content bounds");

	Footer* pFooter = Form::GetFooter();
	pFooter->AddItem(item);
	pFooter->AddActionEventListener(*this);
}
