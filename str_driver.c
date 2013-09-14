 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "str_struct.h"

int main(int argc, char *argv[]) {
    Str *testStr1 = Str_new();
    Str *testStr2 = Str_newWith("hello world!");
    
    testStr1->set(testStr1, "bye world!");
    
    printf("%s\n", testStr2->str);
    printf("%s\n", testStr1->str);
    
    char *temp = NULL;
    temp = (char *) calloc(10, sizeof(char));
    int i;
    for (i=0; i < 10; i++) {
        sprintf(temp, "loop %d", i);
        testStr1->set(testStr1, temp);
        printf("%s\n", testStr1->str);
    }
    
    Str_dispose(testStr2);
    Str_dispose(testStr1);
    
    Str *strA = Str_newWith("a big brown fox jumped over the lazy dog.");
    Str *strB = Str_newWith("a big brown fox jumped over the lazy dog.");
    
    if (strA->isEqual(strA, strB)) {
        printf("matched!\n");
    }
    
    strB->set(strB, "a BiG brown FoX jumped over the LAZY dog.");
    
    if (!strA->isEqual(strA, strB)) {
        printf("no match!!!\n");
    } 
    
    Str_dispose(strA);
    Str_dispose(strB);
    
    strA = Str_newWith("a big brown fox jumped over the lazy dog.");
    strB = Str_newWith("a BiG brown FoX jumped over the LAZY dog.");
    
    if (strA->isEqualIgnoreCase(strA, strB)) {
        printf("matched\n");
    } else {
        printf("no match!!!\n");
    }
    
    strA->toUpper(strA);
    strB->toLower(strB);
    
    printf("%s\n", strA->str);
    printf("%s\n", strB->str);
    
    Str_dispose(strA);
    Str_dispose(strB);
    
    strA = Str_new();
    for (i=0; i < 10; i++) {
        strA->setWithFormat(strA, "formatted: %d", i);
        printf("%s\n", strA->str);
    }
    Str_dispose(strA);
    
    strB = Str_newWithFormat("this %s of %1.3f", "is life", 3.142677388722);
    printf("%s\n", strB->str);
    Str_dispose(strB);
    
    strA = Str_newWithFormat("     this %s of %1.3f", "is life", 3.142677388722);
    printf("%s\n", strA->str);
    strA->leftTrim(strA);
    printf("%s\n", strA->str);
    Str_dispose(strA);
    
    strA = Str_newWith("   ");
    printf("%s<-\n", strA->str);
    strA->leftTrim(strA);
    printf("%s<-\n", strA->str);
    Str_dispose(strA);
    
    strA = Str_new();
    printf("%s<-\n", strA->str);
    strA->leftTrim(strA);
    printf("%s<-\n", strA->str);
    Str_dispose(strA);
    
    strA = Str_newWithFormat("     this %s of %1.3f     ", "is life", 3.142677388722);
    printf("%s<-\n", strA->str);
    strA->trim(strA);
    printf("%s<-\n", strA->str);
    Str_dispose(strA);
    
    strA = Str_newWith("a big brown fox jumped over the lazy dog.");
    printf("%s<-\n", strA->str);
    printf("%s<-\n", (strA->sub(strA, 3, 0))->str);
    printf("%s<-\n", (strA->sub(strA, 5, 11))->str);
    printf("%s<-\n", (strA->sub(strA, 25, 50))->str);
    Str_dispose(strA);
    
    strA = Str_newWith("these");
    strB = Str_newWith(" strings");
    strA->append(strA, strB);
    printf("%s\n", strA->str);
    Str_dispose(strB);
    Str_dispose(strA);
    
    strA = Str_newWith("a big brown fox jumped over the lazy dog.");
    if (strA->has(strA, "jum")) {
        printf("jum: found it\n");
    }
    
    if (!strA->has(strA, "banana")) {
        printf("banana: not found\n");
    }
    
    printf("%s<-\n", strA->str);
    // printf("01234567890123456789012345678901234567890\n");
    int *beginIndices = (int *) calloc(1, sizeof(int));
    // int *beginIndices = NULL;
    int count = strA->find(strA, "o", &beginIndices);
    
    if (count > 0) {
        int i;
        for (i=0; i < count; i++) {
            // printf("beginIndices[%d]: %d\n", i, beginIndices[i]);
            if (beginIndices[i] == 0) {
                printf("%c%c...", strA->str[beginIndices[i]], strA->str[beginIndices[i]+1]);
            } else if (beginIndices[i]+1 >= strA->length) {
                printf("...%c%c", strA->str[beginIndices[i]-1], strA->str[beginIndices[i]]);
            } else {
                printf("...%c%c%c...", strA->str[beginIndices[i]-1], strA->str[beginIndices[i]], strA->str[beginIndices[i]+1]);
            }
        }
    }
    printf("\n");
    free(beginIndices);
    Str_dispose(strA);
    
    return 0;
}
