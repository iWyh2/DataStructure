#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//线性表的单链表存储结构
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node* LinkedList;

//======================操作定义=========================
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;//函数的类型，值为上面的函数结果状态码
//======================================================

//单链表的读取
/*
    算法思路:
    1.声明一个指针p指向链表的第一个节点，初始化j从1开始
    2.当j<i，就遍历链表，让p的指针向后移动，不断指向下一节点，j累加1
    3.若链表末尾p为空，则说明第i个节点不存在
    4.否则就成功找到，返回节点p的数据
*/
Status GetElem(LinkedList L, int i, ElemType *e) {
    //声明一个指针p
    LinkedList p;
    //让指针p指向链表第一个节点
    p = L->next;
    //声明一个计数器j，同步此时为第一个节点
    int j = 1;
    //p不为空，且计数器j不等于i，循环不停，[最终p指向第i个节点]
    while (p && j < i) {
        //让p指向下一个节点
        p = p->next;
        //j计数
        ++j;
    }
    //如果第i个节点不存在
    if (!p || j > i) {
        return ERROR;
    }
    //返回第i个节点的值
    *e = p->data;
    return OK;
}

//单链表的插入
/*
    算法思路:
    1.声明一指针p指向链表头结点，初始化j从1开始
    2.当j<i时，就遍历链表，让p的指针向后移动，不断指向下一结点，j累加1
    3.若到链表末尾p为空，则说明第i个结点不存在
    4.否则查找成功，在系统中生成一个空结点s
    5.将数据元素e赋值给s->data
    6.单链表的插入标准语向 s->next=p->next; p->next=s
    7.返回成功
*/
#include <stdlib.h>
Status ListInsert(LinkedList *L, int i, ElemType e) {
    //声明一指针p指向链表头结点，初始化j从1开始
    LinkedList p = *L;
    int j = 1;
    //遍历链表，让p的指针向后移动，不断指向下一结点，j累加1
    for (; p && j < i; j++) {
        p = p->next;
    }
    //若到链表末尾p为空，则说明第i个结点不存在
    if (!p || j > i) {
        return ERROR;
    }
    //否则生成新节点s，并存储数据e
    Node *s = (Node*)malloc(sizeof(Node));
    s->data = e;
    //插入节点
    s->next = p->next;
    p->next = s;
    return OK;
}

//单链表的删除
/*
    算法思路:
    1.声明一指针p指向链表头结点，初始化j从1开始
    2.当j<i时，就遍历链表，让p的指针向后移动，不断指向下一结点，j累加1
    3.若到链表末尾p为空，则说明第i个结点不存在
    4.否则查找成功，将欲删除的节点p->next赋值给q
    5.单链表删除标准语句: p->next = q->next
    6.将q结点中的数据赋值给e，作为返回
    7.释放q节点
    8.返回成功
*/
Status ListDelete(LinkedList *L, int i, ElemType *e) {
    LinkedList q;
    //声明一指针p指向链表头结点，初始化j从1开始
    LinkedList p = *L;
    int j = 1;
    //遍历链表，让p的指针向后移动，不断指向下一结点，j累加1，最终指向第i-1个节点
    for (; p->next && j < i; j++) {
        p = p->next;
    }
    //若到链表末尾p为空，则说明第i个结点不存在
    if (!(p->next) || j > i) {
        return ERROR;
    }
    //删除节点
    q = p->next;
    p->next = q->next;
    //先返回值
    *e = q->data;
    //释放
    free(q);
    return OK;
}

//单链表的整表创建
/*
    算法思路:
    1.声明一指针p和计数器变量i
    2.初始化一空链表L
    3.让L的头结点指向NULL（创建一个带头结点的单链表）
    4.循环 := 生成新节点给p;随机生成数字赋值给p的数据域;将p插入到头结点与前一新节点之间
*/
//头插法
#include <time.h>
void CreatedListHead(LinkedList *L, int n) {
    //声明一指针p
    LinkedList p;
    //初始化随机种子
    srand(time(0));
    //建立一个带头结点为NULL的单链表
    *L = (LinkedList)malloc(sizeof(Node));
    (*L)->next = NULL;
    //遍历生成随机数
    for (int i = 0; i < n; i++) {
        //生成新节点给p
        p = (Node*)malloc(sizeof(Node));
        //随机生成数字赋值给p的数据域
        p->data = rand() % 100 + 1;
        //将p插入到新结点之前
        p->next = (*L)->next;
        //将p插入到头结点之后，成为第一个节点
        (*L)->next = p;
    }
}
//尾插法
void CreateListTail(LinkedList *L, int n) {
    //声明指针p,r
    LinkedList p, r;
    //初始化随机种子
    srand(time(0));
    //建立一个单链表
    *L = (LinkedList)malloc(sizeof(Node));
    //r指向单链表尾节点
    r = *L;
    //遍历生成随机数
    for (int i = 0; i < n; i++) {
        //生成新节点给p
        p = (Node*)malloc(sizeof(Node));
        //随机生成数字赋值给p的数据域
        p->data = rand() % 100 + 1;
        //将p插入到尾结点r之后
        r->next = p;
        //将r重新指向新的尾结点p
        r = p;
    }
    //最终将尾结点指向NULL，表示链表结束
    r->next = NULL;
}

//单链表的整表删除
/*
    算法思路:
    1.声明节点p和q
    2.将第一个节点赋值给p
    3.循环 := 将下一节点赋值给q;释放p;将q赋值给p
*/
Status ClearList(LinkedList *L) {
    //声明节点p和q
    LinkedList p,q;
    //将第一个节点赋值给p
    p = (*L)->next;
    while (p) {
        //先将下一节点赋值给q
        q = p->next;
        //释放p
        free(p);
        //将q赋值给p，也就是p指向下一节点继续删除释放
        p = q;
    }
    //最终将头结点指向NULL表示为空链表
    (*L)->next = NULL;
    return OK;
}

#endif