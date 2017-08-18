//
//  types.h
//  Utilities.Collection
//
//  Created by Ramin on 2017-08-18.
//
//

#ifndef collectionTypes_h
#define collectionTypes_h

struct buffer{
    void* data;
    size_t size;
    buffer *next;
};

struct fixedSizebuffer{
    void* data;
    buffer *next;
};

#endif /* collectionTypes_h */
