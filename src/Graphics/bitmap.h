//
//  bitmap.h
//  Utilities.Graphics
//
//  Created by Ramin on 2017-08-18.
//
//

// Bitmap manipulation based on Apple Core Graphics (Quartz 2D) engine and
// vImage framework. Only available then to Apple.

#ifdef __APPLE__

#ifndef bitmap_h
#define bitmap_h

#include <stdio.h>
#include "graphicTypes.h"
#include <CGBitmapContext.h>
#include <ImageIO/ImageIO.h>
#include <UTCoreTypes.h>

extern "C"
CGImageRef* generateCGBitmap(const argb* buffer, size_t width, size_t height, UInt8 bitsPerComponent, UInt8 bytesPerRow, CFStringRef typeIdentifier);

extern "C"
UInt8* generateCGBitmapRawData(const argb* buffer, size_t width, size_t height, UInt8 bitsPerComponent, UInt8 bytesPerRow);

#endif /* bitmap_h */

#endif //__APPLE__
