//
//  main.c
//  Calculator
//
//  Created by USER on 2019. 1. 14..
//  Copyright © 2019년 USER. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InputBuffer.h"

#define EMPTY 0
#define PLUS 1
#define MINUS 2
#define MULTIPLY 3
#define DIVISION 4

#define INPUT_COUNT 1000

double plus(char *data);
double minus(char *data);
double multiply(char *data);
double division(char *data);

void calculator(Buffer *buffer);

int main(int argc, const char * argv[]) {
    
    char input[INPUT_COUNT];
    
    Buffer buffer;
    initStringBuffer(&buffer);
    
    while(1) {
        printf("input : ");
        scanf("%s", input);
        
        char* temp = (char*)calloc((size_t)INPUT_COUNT, sizeof(char));
        
        memcpy((char*)temp, input, sizeof(char) * INPUT_COUNT);
        addString(&buffer, temp);
        
        if (!strcmp("=", temp)) {
            calculator(&buffer);
            break;
        }
        
//      while (getchar() != '\n');
    }
    
    return 0;
}

void calculator(Buffer *buffer) {
    char* previous = NULL;
    char* now = NULL;
    
    int calculation = EMPTY;
    
    Buffer calculationBuffer;
    Buffer tempBuffer;
    
    initStringBuffer(&calculationBuffer);
    initDoubleBuffer(&tempBuffer);
    
    for (int i =0; i < (buffer->idx); i ++) {
        char* inputTemp = (buffer-> input[i]);
        printf("%s ", inputTemp);
        
        double *value = (double*)malloc(sizeof(double));
        double result;
        now = inputTemp;
        
        if(previous == NULL){
            previous = inputTemp;
            
            result = atof(now);
            value = &result;
            addDouble(&tempBuffer, *value);
            continue;
        } else {
            
            if(calculation == EMPTY) {
                if (!strcmp("+", inputTemp)) calculation = PLUS;
                if (!strcmp("-", inputTemp)) calculation = MINUS;
                if (!strcmp("*", inputTemp)) calculation = MULTIPLY;
                if (!strcmp("/", inputTemp)) calculation = DIVISION;
                continue;
            } else {
                
                switch (calculation) {
                    case MULTIPLY:
                        addString(&calculationBuffer, "*");
                        break;
                    case DIVISION:
                        addString(&calculationBuffer, "/");
                        break;
                    case PLUS:
                        addString(&calculationBuffer, "+");
                        break;
                    case MINUS:
                        addString(&calculationBuffer, "-");
                        break;
                        
                    default:
                        break;
                }
                result = atof(now);
                value = &result;
                addDouble(&tempBuffer, *value);
                
                // 입력후 초기화 하는 부분
                previous = inputTemp;
                calculation = EMPTY;
                now = NULL;
            }
        }
    }
    
    double result[1000];
    int resultIdx = 0;
    char* afterCal = NULL;
    double resultValue;
    
    for(int i =0; i < calculationBuffer.idx; i++) {
        afterCal = calculationBuffer.input[i];
        if(i == 0) {
            result[resultIdx] = tempBuffer.temp[0];
            resultIdx++;
            result[resultIdx] = tempBuffer.temp[1];
            continue;
        }
        
        if (!strcmp("*", afterCal)) {
            resultValue = result[resultIdx] * tempBuffer.temp[i + 1];
            result[resultIdx] = resultValue;
            continue;
        }
            
        else if (!strcmp("/", afterCal)) {
            resultValue = result[resultIdx] / tempBuffer.temp[i + 1];
            result[resultIdx] = resultValue;
            continue;
        }
        
        else {
            resultValue = tempBuffer.temp[i + 1];
            resultIdx++;
            result[resultIdx] = resultValue;
        }
    }
    
    // 재활용을 위한 변수 초기화
    resultIdx = 1;
    afterCal = NULL;
    resultValue = result[0];
    
    for(int i = 0; i< calculationBuffer.idx; i++) {
        afterCal = calculationBuffer.input[i];
        if (!strcmp("*", afterCal)) continue;
        if (!strcmp("/", afterCal)) continue;
        
        if (!strcmp("+", afterCal)) resultValue = resultValue + result[resultIdx];
        if (!strcmp("-", afterCal)) resultValue = resultValue - result[resultIdx];
        resultIdx++;
    }
    
    printf("%f\n", resultValue);
}
