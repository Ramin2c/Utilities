//
//  fifo.h
//  Utilities.Collection
//
//  Created by Ramin on 2017-07-07.
//  Copyright © 2017 Ramin. All rights reserved.
//

#ifndef fifo_h
#define fifo_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "collectionTypes.h"

extern "C"
bool canReadQueue();

extern "C"
void enqueue(buffer *buf);

extern "C"
buffer* dequeue();

extern "C"
buffer* createBuffer(void* data, size_t size);

extern "C"
buffer* getHead();

extern "C"
buffer* getRear();

#endif /* fifo_h */
