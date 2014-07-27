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

#ifndef _IMAGE_MANAGER_H_
#define _IMAGE_MANAGER_H_

#include <FGraphics.h>

#define GALLERY_IMAGE_COUNT 11

class GalleryImageManager
{
public:
	GalleryImageManager(void);
	~GalleryImageManager(void);
	
	Tizen::Graphics::Bitmap* GetBitmap(int index);
	Tizen::Graphics::Bitmap* GetScaledBitmapN(int index, int width, int height);
	void GetCenterAlighBounds(int i, Tizen::Graphics::Rectangle frameRect, Tizen::Graphics::Rectangle& imgRect, int style);

public:
	static const RequestId REQUEST_ID_GALLERY_VIEW = 701;
	static const RequestId REQUEST_ID_IMAGE_VIEW = 702;
	static const RequestId REQUEST_ID_IMAGE_VIEW_SLIDE_SHOW = 703;
	static const RequestId REQUEST_ID_SLIDE_SHOW_START = 704;
	static const RequestId REQUEST_ID_SLIDE_SHOW_PAUSE = 705;
	static const RequestId REQUEST_ID_SLIDE_SHOW_RESTART = 706;

	static const int SCALE_STYLE_FIT = 1;
	static const int SCALE_STYLE_FILL = 2;
	
private:
	Tizen::Graphics::Bitmap* __pBitmap[GALLERY_IMAGE_COUNT];
};

#endif // _IMAGE_MANAGER_H_