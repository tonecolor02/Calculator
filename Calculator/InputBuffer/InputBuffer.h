//
//  InputBuffer.h
//  Calculator
//
//  Created by USER on 2019. 1. 16..
//  Copyright © 2019년 USER. All rights reserved.
//

#ifndef InputBuffer_h
#define InputBuffer_h

#include <stdio.h>

typedef struct __InputBuffer {
    char* input[100];
    double temp[100];
    
    int idx;
    int curPosition;

} Buffer;
// typedef struct InputBuffer Buffer;

void initStringBuffer(Buffer *ptrBuffer);
void initDoubleBuffer(Buffer *ptrBuffer);

void addString(Buffer *ptrBuffer, char* input);
void addStringIdx(Buffer *ptrBuffer, char* input, int idx);
void addDouble(Buffer *ptrBuffer, double temp);

void clearBuffer(void);

#endif /* InputBuffer_h */
