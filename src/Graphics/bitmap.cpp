//
//  bitmap.cpp
//  Utilities.Graphics
//
//  Created by Ramin on 2017-08-18.
//
//

#ifdef __APPLE__

#include "bitmap.h"

CGImageRef* generateCGBitmap(const argb* buffer, size_t width, size_t height, UInt8 bitsPerComponent, UInt8 bytesPerRow, CFStringRef typeIdentifier){
    
    //TODO replace malloc and free with new and delete
    //TODO Add error logging support
    
    long imageSize = width * height;
    char* rgba = (char*)malloc(imageSize * 4); //times the planecount
    for(int i=0; i < imageSize; ++i) {
        rgba[4*i] = buffer[i].red;
        rgba[4*i+1] = buffer[i].green;
        rgba[4*i+2] = buffer[i].blue;
        rgba[4*i+3] = buffer[i].alpha;
    }
    
    CGColorSpaceRef colorSpace =     CGColorSpaceCreateWithName(kCGColorSpaceGenericRGB); //CGColorSpaceCreateDeviceRGB();
    CGContextRef bitmapContext = CGBitmapContextCreate(
                                                       rgba,
                                                       width,
                                                       height,
                                                       bitsPerComponent,
                                                       bytesPerRow,
                                                       colorSpace,
                                                       kCGImageAlphaLast);
    if(!bitmapContext){
        free(colorSpace);
        return NULL;
    }
    CFRelease(colorSpace);
    
    CGImageRef cgImage = CGBitmapContextCreateImage(bitmapContext);
    
    //up to here, fix the dest creation
    CFDataRef dataRef = CFDataCreateWithBytesNoCopy(NULL, rgba, imageSize, kCFAllocatorNull);
    CGImageDestinationRef dest = CGImageDestinationCreateWithData(dataRef, typeIdentifier, 1, 0);
    
    CGImageDestinationAddImage(dest, cgImage, 0);
    
    CFRelease(cgImage);
    CFRelease(bitmapContext);
    CGImageDestinationFinalize(dest);
    free(rgba);
    
    return &cgImage;
}

#endif // __APPLE__
