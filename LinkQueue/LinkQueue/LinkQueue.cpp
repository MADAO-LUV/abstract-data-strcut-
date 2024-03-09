/*
1.用链式存储实现队列（不带头结点）
2.基本操作：创，增，删，查，判空
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode {
	int data; //链式队列结点
	struct LinkNode* next;
}LinkNode;

//链式队列
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

//初始化队列
void InitNode(LinkQueue& Q) {
	//初始时 front，rear都指向NULL
	Q.front = NULL;
	Q.rear = NULL;
}

//判断是否为空？
bool IsEmpty(LinkQueue Q) {
	if (Q.front == NULL) {
		return true;
	}
	else {
		return false;
	}
}

//入队
void EnQueue(LinkQueue& Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL) { //在空队列中插入第一个元素
		Q.front = s; //修改对队头队尾指针
		Q.rear = s;
	}
	else
	{
		Q.rear->next = s; //新结点插入到rear结点之后
		Q.rear = s; //修改rear指针
	}
}


//出队
bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == NULL) {
		return false; //空队
	}
	LinkNode* p = Q.front; //p指向此次出队的结点
	x = p->data; //用变量x返回队头元素
	Q.front = p->next;
	if (Q.rear == p) {
		Q.front = NULL;
		Q.rear = NULL;
	}
	free(p); //释放结点空间
	return true;
}

//返回头结点元素
int GetElem(LinkQueue Q) {
	if (Q.front == NULL) {
		return 0; //为空队
	}
	return Q.front->data;
}

//修改头结点的值
bool ChangeNode(LinkQueue& Q, int e) {
	if (Q.front == NULL) {
		return false; //若为空队
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = Q.front;
	Q.front = s->next;
	e = s->data;
	free(s); //释放结点内存
	return true;
}