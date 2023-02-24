#include <stdio.h>
#include "SqList.h"

int main() {
    SqList *L = (SqList*)malloc(sizeof(SqList));

    ListInsert(L,1,0);
    ListInsert(L,2,1);
    ListInsert(L,3,2);
    ListInsert(L,4,3);
    ListInsert(L,5,4);
    printSqList(L);

    int tmp = 0;
    GetElem(*L,3,&tmp);
    printf("The element in the third position: tmp = %d\n",tmp);

    ListDelete(L,5,&tmp);
    printf("After delete the element in the fifth position, tmp = %d\n",tmp);
    printSqList(L);

    return 0;
}