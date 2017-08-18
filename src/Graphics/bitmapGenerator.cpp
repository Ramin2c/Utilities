//
//  bitmapGenerator.cpp
//  Utilities.Graphics
//
//  Created by Ramin on 2017-08-18.
//
//

#include "bitmapGenerator.h"

CGImageRef generateBitmap(argb* buffer, size_t width, size_t height, UInt8 bitsPerComponent, UInt8 bytesPerRow, CFStringRef format){
    
    char* rgba = (char*)malloc(width*height*4);
    for(int i=0; i < width*height; ++i) {
        rgba[4*i] = buffer[i].r;
        rgba[4*i+1] = buffer[i].g;
        rgba[4*i+2] = buffer[i].b;
        rgba[4*i+3] = buffer[i].a;
    }
    
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef bitmapContext = CGBitmapContextCreate(
                                                       rgba,
                                                       width,
                                                       height,
                                                       bitsPerComponent,
                                                       bytesPerRow,
                                                       colorSpace,
                                                       kCGImageAlphaNoneSkipLast);
    CFRelease(colorSpace);
    
    CGImageRef cgImage = CGBitmapContextCreateImage(bitmapContext);
    
    //up to here, fix the dest creation
    CGImageDestinationRef dest = CGImageDestinationCreateWithData(url, type, 1, 0);
    
    CGImageDestinationAddImage(dest, cgImage, 0);
    
    CFRelease(cgImage);
    CFRelease(bitmapContext);
    CGImageDestinationFinalize(dest);
    free(rgba);
}
