/*
这一个cpp是用来实现tag的操控
*/
#include <stdio.h>
#define MAXSIZE 10
typedef struct {
	int data[MAXSIZE];
	int front, rear;
	int tag; //加入的时候为1，减少的时候为0
 }SqQueue;


//初始化列表
bool InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
	Q.tag = 0;
	return true;
}


//入队
bool Enqueue(SqQueue& Q, int e) {
	if (Q.rear == Q.rear && Q.tag) {
		return false; //已经满队列了
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}


//出队
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.rear == Q.front && Q.tag == 0) {
		return false; //为空
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}

//返回队头元素
int GetElem(SqQueue Q) {
	if (Q.rear == Q.front && Q.tag == 0) {
		return 0; //为空
	}
	else
	{
		int e = Q.data[Q.front];
		return e;
	}
	
}