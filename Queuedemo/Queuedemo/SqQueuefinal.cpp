/*
队列（Queue） 是只允许在一端进行插入，在另一端删除的线性表

重要术语：队头，队尾，空队列
顺序存储

rear 指向队尾元素
front 指向队头元素
*/
#include <stdio.h>
#define MAXSIZE 10

//进行SqQueue的定义
typedef struct {
	int data[MAXSIZE];
	int front, rear; // 定义头指针，尾指针
	int size;
}SqQueue;

//初始化队列
bool QueueInit(SqQueue& Q) {
	Q.front = 0;
	Q.rear = MAXSIZE - 1; //将这个指针指向队头后一个位置
	Q.size = 0;
	return true;
}

//判断是否为空
bool IsEmpty(SqQueue Q) {
	if (Q.size == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

//入队
bool EnQueue(SqQueue& Q, int e) {
	if (Q.size == MAXSIZE) {
		return false; //如果队满
	}
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.data[Q.rear] = e;
	return true;
}

//出队
bool DeQueue(SqQueue& Q, int &e) {
	if (Q.size == 0) {
		return false;
	}
	int e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}

//获得队头元素
int GetElem(SqQueue Q) {
	return Q.data[Q.front];
}

//计算个数
int QueueSize(SqQueue Q) {
	return Q.size;
}