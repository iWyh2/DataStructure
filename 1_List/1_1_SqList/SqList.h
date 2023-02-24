#ifndef SQLIST_H
#define SQLIST_H

//线性表顺序存储结构定义
#define MAXSIZE 20
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

//======================操作定义=========================
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;//函数的类型，值为上面的函数结果状态码
//======================================================

/*
    获得元素操作
    初始条件: 顺序线性表L已存在，1 <= i <= ListLength(L)
    操作结果: 用e返回L中第i个元素的值
*/
Status GetElem(SqList L, int i, ElemType *e) {
    //获取的位置不在范围内
    if (L.length == 0 || i < 1 || i > L.length) {
        return ERROR;
    }
    //用e接收要获取的元素
    *e = L.data[i-1];
    return OK;
}

/*
    插入元素操作
    初始条件: 顺序线性表L已存在，1 <= i <= ListLength(L)
    操作结果: 在L中第i个位置之前插入新的数据元素e，且L的长度+1
*/
Status ListInsert(SqList *L, int i, ElemType e) {
    //表已满
    if (L->length == MAXSIZE) {
        return ERROR;
    }
    //插入的位置不在范围内
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    //如果插入位置不在表尾
    if (i < L->length) {
        for (int k = L->length - 1; k >= i - 1; k--) {
            //将要插入的位置后的元素向后移动一位
            L->data[k+1] = L->data[k];
        }
    }
    //那么在表尾插入
    L->data[i-1] = e;
    //线性表长度+1
    L->length++;
    return OK;
}

/*
    删除元素操作
    初始条件: 顺序线性表L已存在，1 <= i <= ListLength(L)
    操作结果: 删除L中第i个位置的元素，并用e返回其值，且L的长度-1
*/
Status ListDelete(SqList *L, int i, ElemType *e) {
    //表为空
    if (L->length == 0) {
        return ERROR;
    }
    //删除的位置不在范围内
    if (i < L->length || i < 1) {
        return ERROR;
    }
    //先用e接收要删除的元素
    *e = L->data[i-1];
    //如果删除的不是最后的元素，还需要移动位置“补满空格”
    if (i < L->length) {
        for (int k = i; k < L->length; k++) {
            //将删除的位置后面的元素前移一位，[覆盖实现删除]
            L->data[k-1] = L->data[k];
        }
    }
    //如果删除最后那个元素，那么直接返回要删除的元素，不需要移动补满
    //最终表长-1
    L->length--;
    return OK;
}
//print操作
#include <stdio.h>
void printSqList(SqList* L) {
    if(L->length == 0) {
        printf("False!\n");
        return;
    }
    printf("SqList:[");
    for(int i = 0; i < L->length; i++) {
        printf(" %d ",L->data[i]);
    }
    printf("] -> [length:%d capacity:%d]\n",L->length,MAXSIZE);
}
#endif