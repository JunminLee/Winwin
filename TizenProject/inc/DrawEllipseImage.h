/*
 * DrawEllipseImage.h
 *
 *  Created on: Jul 29, 2014
 *      Author: Gants
 */

#ifndef DRAWELLIPSEIMAGE_H_
#define DRAWELLIPSEIMAGE_H_

#include "tizenx.h"

using namespace Tizen::Graphics;
using namespace Tizen::Base;

#define RED32(color32) static_cast< byte >(0x00F8 & (color32 >> 16))
#define GREEN32(color32) static_cast< byte >(0x00FC & (color32 >> 8))
#define BLUE32(color32) static_cast< byte >(0x00F8 & color32)

#define RGB888ToCOLOR16(red, green, blue) \
                       (static_cast< unsigned short >((static_cast< byte >(blue>>3) \
                       |(static_cast< unsigned short >(static_cast< byte >(green>>2))<<5)) \
                       |((static_cast< unsigned short > (static_cast< byte >((red>>3))<<11)))))

#define COLOR32ToCOLOR16(color32) RGB888ToCOLOR16(RED32(color32), GREEN32(color32), BLUE32(color32))

class DrawEllipseImage
{
public:
	void TransDrawEllipseImage(Canvas& canvas, const Color& color, const Rectangle& rect, const Bitmap& bitmap)
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
	//example
	//in Ondraw Function, DrawEllipseImage(canvas, Color(255,255,255,255),Rectangle(rect.x + 30, rect.y + 30, 100, 100), *pAppResource->GetBitmapN(L"tizen.png"));
};



#endif /* DRAWELLIPSEIMAGE_H_ */
