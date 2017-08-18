//
//  fifo.c
//  Utilities.Collection
//
//  Created by Ramin on 2017-08-18.
//  Copyright © 2017 Ramin. All rights reserved.
//

#include "fifo.h"

static buffer* head = NULL;
static buffer* rear = NULL;

buffer* createBuffer(void* data, size_t size){
    buffer *buf = (buffer*)malloc(sizeof(buffer));
    buf->data = data;
    buf->size = size;
    buf->next = NULL;
    return buf;
}

bool canReadQueue(){
    if (head == NULL)
        return false;
    else 
        return true;
}
void enqueue(buffer *buf){
    //if the queue is empty, the added buffer should be both head and rear    
    if (head == NULL){
        head = buf;
        rear = buf;
    }
    //otherwise, it is the new rear
    else{
        rear->next = buf;
        rear = buf;
    }
}

buffer* dequeue(){
    //if the queue is empty
    if (head == NULL)
        return NULL;
    //otherwise, the next item is the new head
    else{
        buffer* tmp = head;
        head = tmp->next;
        return tmp;
    }
}
