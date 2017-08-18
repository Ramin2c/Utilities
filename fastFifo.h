//
//  fastFifo.h
//  Utilities.Collection
//
//  Created by Ramin on 2017-08-18.
//
//


// fastFifo.h is intended to enable faster data enqueu and dequeu
// by fixing the size of data buffer and skipping some /if/ checks
// This is the developers' responsibility to make sure the inserted data are
// all of the same size.

#ifndef fastFifo_h
#define fastFifo_h

#include <stdio.h>
#include "collectionTypes.h"

extern "C"
fixedSizebuffer* initQueue(void* root, size_t dataBufferSize);

extern "C"
size_t getDataBufferSize();

extern "C"
void setDataBufferSize(size_t value);

extern "C"
fixedSizebuffer* createBuffer(void* data, size_t size);

extern "C"
bool canReadQueue();

extern "C"
void enqueue(buffer *buf);

extern "C"
fixedSizebuffer* dequeue();

extern "C"
fixedSizebuffer* getHead();

extern "C"
fixedSizebuffer* getRear();

#endif /* fastFifo_h */
