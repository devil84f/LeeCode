#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* makeFancyString(char* s) {
    int len = strlen(s);
    char *ret = (char *)malloc(sizeof(char) * (len + 1)); // +1 for null terminator
    if (len == 0) {
        ret[0] = '\0';
        return ret;
    }
    
    int num = 0;
    int count = 1;
    ret[num++] = s[0];
    
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i-1]) {
            count++;
        } else {
            count = 1;
        }
        
        if (count < 3) {
            ret[num++] = s[i];
        }
    }
    
    ret[num] = '\0'; // null-terminate the string
    return ret;
}

// Test function
void testMakeFancyString(char* input, char* expected) {
    char* output = makeFancyString(input);
    if (strcmp(output, expected)) {
        printf("Test Failed!\n");
        printf("Input:    \"%s\"\n", input);
        printf("Output:   \"%s\"\n", output);
        printf("Expected: \"%s\"\n", expected);
    } else {
        printf("Test Passed: \"%s\" -> \"%s\"\n", input, output);
    }
    free(output); // Don't forget to free the allocated memory
}

int main() {
    // Test cases
    testMakeFancyString("leeetcode", "leetcode");
    testMakeFancyString("aaabaaaa", "aabaa");
    testMakeFancyString("aab", "aab");
    testMakeFancyString("aaaaa", "aa");
    testMakeFancyString("", "");
    testMakeFancyString("abc", "abc");
    testMakeFancyString("aaaabbbcc", "aabbcc");
    
    return 0;
}
