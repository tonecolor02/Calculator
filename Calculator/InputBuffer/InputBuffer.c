//
//  InputBuffer.c
//  Calculator
//
//  Created by USER on 2019. 1. 16..
//  Copyright © 2019년 USER. All rights reserved.
//
#include <stdio.h>
#include "InputBuffer.h"

void initStringBuffer(Buffer *ptrBuffer){
    (ptrBuffer->idx) = 0;
    (ptrBuffer->curPosition) = -1;
}

void initDoubleBuffer(Buffer *ptrBuffer){
    (ptrBuffer->idx) = 0;
    (ptrBuffer->curPosition) = -1;
}

void addString(Buffer *ptrBuffer, char* input) {
    ptrBuffer->input[ptrBuffer->idx] = input;
    (ptrBuffer->idx)++;
}

void addStringIdx(Buffer *ptrBuffer, char* input, int idx) {
    ptrBuffer->input[idx] = input;
}

void addDouble(Buffer *ptrBuffer, double temp) {
    ptrBuffer->temp[ptrBuffer->idx] = temp;
    (ptrBuffer->idx)++;
}

