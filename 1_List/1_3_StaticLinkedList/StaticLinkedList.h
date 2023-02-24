#ifndef STATICLINKEDLIST_H
#define STATICLINKEDLIST_H

//线性表的静态链表存储结构定义
typedef int ElemType;
#define MAXSIZE 1000
typedef struct {
    ElemType data;
    int cur;//游标
} Component, StaticLinkedList[MAXSIZE];

//======================操作定义=========================
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;//函数的类型，值为上面的函数结果状态码
//======================================================

//静态链表初始化操作
/*
    将一维数组space中各分量链成一备用链表
    space[0].cur为备用链表的头指针，值为0表示为空指针
*/
Status InitList(StaticLinkedList space) {
    for (int i = 0; i < MAXSIZE - 1; i++) {
        //数组第一个元素，也就是备用链表头指针，存放备用链表第一个结点位置。也就是指向第二个位置
        //然后每一个数组元素的cur都存放自己的下一个位置的下标
        space[i].cur = i + 1;
    }
    //同时，数组的最后一个元素，cur存放第一个有值的元素的下标，此时静态链表为空，存放0
    space[MAXSIZE-1].cur = 0;
    return OK;
}

#endif