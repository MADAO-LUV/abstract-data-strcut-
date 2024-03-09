/*
1.使用链式存储实现队列（带头结点版）
2.基本操作：增，删，改，查，创
*/
#include <stdio.h>
#include <stdlib.h>

//队列的链式实现
typedef struct LinkNode {
	int data; //链式队列结点
	struct LinkNode* next;
}LinkNode;

//链式队列
typedef struct {
	LinkNode* front, * rear;//队列的队头和队尾指针
}LinkQueue;


//初始化队列（带头结点）
void InitNode(LinkQueue& Q) {
	//初始化时 front，rear都指向头结点
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//判断是否为空？
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}

//新元素的入队
void EnQueue(LinkQueue& Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;//存入数据
	s->next = NULL;
	Q.rear->next = s; //新结点插入到rear之后
	Q.rear = s; //修改表尾指针
}

//队头元素出队（带头结点）
bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == Q.rear) {
		return false;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = Q.front->next;//头结点的后继结点
	Q.front->next = s->next;
	if (Q.rear == s) {
		Q.rear = Q.front; //若头结点是最后一个结点时
	}
	x = s->data; //获取队头结点的数据
	free(s);
	return true;
}

//查找队头元素
int GetFrontNode(LinkQueue Q) {
	return Q.front->data;
}

//查找结点
LinkNode* GetNode(LinkQueue Q,int i) {
	if (Q.front == Q.rear || i < 1)
	{
		return NULL; //没有该结点或错误
	}
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	p = Q.front;
	int j = 0;
	//到队尾结点前截止
	while (p != NULL && j < i) {
		p = p->next;
	}
	return p;
}


//修改目标值的数据
bool ChangeNode(LinkQueue& Q, int x,int e) {
	if (Q.front == Q.rear) {
		return false;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = GetNode(Q, x);//查找到相应的值，我这里进行函数的封装
	s->data = x;
	return true;
}

int main(void) {
	return 0;
}