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

#include <FApp.h>
#include <FBase.h>
#include <FMedia.h>
#include <FIoDirectory.h>

#include "GalleryImageManager.h"

using namespace Tizen::Base;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::Io;
using namespace Tizen::App;

GalleryImageManager::GalleryImageManager(void)
{
	String imgName;
	String fullPath;

	for (int i = 0; i < GALLERY_IMAGE_COUNT; i++)
	{
		__pBitmap[i] = null;

		imgName.Format(10, L"img%d.jpg", i);

		fullPath = App::GetInstance()->GetAppRootPath();
		fullPath.Append(L"res/screen-density-high/");
		fullPath += imgName;

		Image* pImage = new (std::nothrow) Image();
		pImage->Construct();
		__pBitmap[i] = pImage->DecodeN(fullPath, BITMAP_PIXEL_FORMAT_ARGB8888);
	}
}

GalleryImageManager::~GalleryImageManager(void)
{
	for (int i = 0; i < GALLERY_IMAGE_COUNT; i++)
	{
		delete __pBitmap[i];
		__pBitmap[i] = null;
	}
}

Bitmap*
GalleryImageManager::GetBitmap(int index)
{
	return __pBitmap[index];
}

Bitmap*
GalleryImageManager::GetScaledBitmapN(int index, int width, int height)
{
	Bitmap* pBitmap = null;

	pBitmap = new (std::nothrow) Bitmap();
	if (pBitmap)
	{
		pBitmap->Construct(*__pBitmap[index], Rectangle(0, 0, __pBitmap[index]->GetWidth(), __pBitmap[index]->GetHeight()));
		pBitmap->Scale(Dimension(width, height));
	}

	return pBitmap;
}

void
GalleryImageManager::GetCenterAlighBounds(int index, Rectangle frameRect, Rectangle& imgRect, int style)
{
	int width = __pBitmap[index]->GetWidth();
	int height = __pBitmap[index]->GetHeight();

	int panX = 0, panY = 0;
	float ratioW = 0.0f, ratioH = 0.0f, scaleFactor = 0.0f, scaledW = 0.0f, scaledH = 0.0f;

	ratioW = (float)frameRect.width / (float)width;
	ratioH = (float)frameRect.height / (float)height;

	if (style == SCALE_STYLE_FIT)
	{
		if (ratioW < ratioH )
		{
			scaleFactor = ratioW;
		}
		else
		{
			scaleFactor = ratioH;
		}

		scaledW = width * scaleFactor;
		scaledH = height * scaleFactor;

		if (frameRect.width > width * scaleFactor)
		{
			panX = (int)((frameRect.width - (int)(width * scaleFactor)) / 2);
		}

		if (frameRect.height > height * scaleFactor)
		{
			panY = (int)((frameRect.height - (int)(height * scaleFactor)) / 2);
		}
	}
	else if (style == SCALE_STYLE_FILL)
	{
		if (ratioW > ratioH)
		{
			scaleFactor = ratioW;
		}
		else
		{
			scaleFactor = ratioH;
		}

		scaledW = width * scaleFactor;
		scaledH = height * scaleFactor;

		if ( frameRect.width < width * scaleFactor )
		{
			panX = -(int)(((int)(width * scaleFactor) - frameRect.width) / 2);
		}

		if ( frameRect.height > height * scaleFactor )
		{
			panY = -(int)(((int)(height * scaleFactor) - frameRect.height) / 2);
		}
	}

	imgRect.x = panX;
	imgRect.y = panY;
	imgRect.width = scaledW;
	imgRect.height = scaledH;
}
