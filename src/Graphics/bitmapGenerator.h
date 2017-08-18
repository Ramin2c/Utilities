//
//  bitmapGenerator.h
//  Utilities.Graphics
//
//  Created by Ramin on 2017-08-18.
//
//

#ifndef bitmapGenerator_h
#define bitmapGenerator_h

#include <stdio.h>
#include "graphicTypes.h"
#include <CGBitmapContext.h>
#include <ImageIO/ImageIO.h>
#include <UTCoreTypes.h>

extern "C"
CGImageRef generateBitmap(argb* buffer, size_t width, size_t height, UInt8 bitsPerComponent, UInt8 bytesPerRow);

extern "C"
UInt8* generateBitmapRawData(argb* buffer, size_t width, size_t height, UInt8 bitsPerComponent, UInt8 bytesPerRow);

#endif /* bitmapGenerator_h */
