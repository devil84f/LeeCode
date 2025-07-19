#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ȽϺ�������������
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// �ж�b�Ƿ���a�����ļ���
int isSubfolder(const char *a, const char *b) {
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    return (*a == '\0' && *b == '/');
}

char **removeSubfolders(char **folder, int folderSize, int *returnSize) {
    // ���ļ���·����������
    qsort(folder, folderSize, sizeof(char *), compare);
    
    char **result = (char **)malloc(folderSize * sizeof(char *));
    *returnSize = 0;
    
    // ��һ���ļ���һ���������ļ���
    result[(*returnSize)++] = folder[0];
    
    for (int i = 1; i < folderSize; i++) {
        // ��鵱ǰ�ļ����Ƿ���ǰһ����������ļ���
        if (!isSubfolder(result[*returnSize - 1], folder[i])) {
            result[(*returnSize)++] = folder[i];
        }
    }
    
    return result;
}

// ���Ժ���
void testRemoveSubfolders() {
    // ��������1
    char *folder1[] = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    int folderSize1 = 5;
    int returnSize1;
    char **result1 = removeSubfolders(folder1, folderSize1, &returnSize1);
    printf("Test Case 1:\n");
    for (int i = 0; i < returnSize1; i++) {
        printf("%s\n", result1[i]);
    }
    free(result1);
    
    // ��������2
    char *folder2[] = {"/a", "/a/b/c", "/a/b/d"};
    int folderSize2 = 3;
    int returnSize2;
    char **result2 = removeSubfolders(folder2, folderSize2, &returnSize2);
    printf("\nTest Case 2:\n");
    for (int i = 0; i < returnSize2; i++) {
        printf("%s\n", result2[i]);
    }
    free(result2);
    
    // ��������3
    char *folder3[] = {"/a/b/c", "/a/b/ca", "/a/b/d"};
    int folderSize3 = 3;
    int returnSize3;
    char **result3 = removeSubfolders(folder3, folderSize3, &returnSize3);
    printf("\nTest Case 3:\n");
    for (int i = 0; i < returnSize3; i++) {
        printf("%s\n", result3[i]);
    }
    free(result3);
}

int main() {
    testRemoveSubfolders();
    return 0;
}
