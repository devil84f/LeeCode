/*
 * @Author: LiNing
 * @Date: 2025-02-21 17:28:20
 * @LastEditors: LiNing
 * @LastEditTime: 2025-02-21 17:54:01
 * @FilePath: \LeeCode_Modularization\Stacks_Queues\LeeCode150\LeeCode150.c
 * @Description: 
 * Copyright (c) 2025 by ${git_name_email}, All Rights Reserved. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isNumber(char* token) {
    return strlen(token) > 1 || ('0' <= token[0] && token[0] <= '9');
}

int evalRPN(char** tokens, int tokensSize) {
    int n = tokensSize;
    int stk[n], top = 0;
    for (int i = 0; i < n; i++) {
        char* token = tokens[i];
        if (isNumber(token)) {
            stk[top++] = atoi(token);
        } else {
            int num2 = stk[--top];
            int num1 = stk[--top];
            switch (token[0]) {
                case '+':
                    stk[top++] = num1 + num2;
                    break;
                case '-':
                    stk[top++] = num1 - num2;
                    break;
                case '*':
                    stk[top++] = num1 * num2;
                    break;
                case '/':
                    stk[top++] = num1 / num2;
                    break;
            }
        }
    }
    return stk[top - 1];
}

int main () {
    char *tokens1[] = {"2", "1", "+", "3", "*"};
    int size1 = sizeof(tokens1) / sizeof(tokens1[0]);
    printf("%d\n", evalRPN(tokens1, size1)); // Êä³ö: 9

    char *tokens2[] = {"4", "13", "5", "/", "+"};
    int size2 = sizeof(tokens2) / sizeof(tokens2[0]);
    printf("%d\n", evalRPN(tokens2, size2)); // Êä³ö: 6

    return 0;
}
