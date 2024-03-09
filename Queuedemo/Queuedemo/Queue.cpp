/*
队列（Queue） 是只允许在一端进行插入，在另一端删除的线性表

重要术语：队头，队尾，空队列
顺序存储 

rear 指向队尾元素的后一个位置
front 指向队头元素
*/
#include <stdio.h>
#define MAXSIZE 10
typedef int Elemtype;

//进行SqQueue的定义
typedef struct {
	Elemtype data[MAXSIZE];
	int front, rear; // 定义头指针，尾指针
}SqQueue;

//初始化顺序队列（循环队列）
bool SqQueueInit(SqQueue& Q) {
	Q.front = Q.rear = 0;
	return true;
}

//判断是否为空表
bool IsEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {
		return true; //判断为空表
	}
	else {
		return false;
	}
}

//入队
bool Enqueue(SqQueue& Q, Elemtype e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) {
		//判断是否满队
		return false;
	}
	Q.data[Q.front] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}

//出队
bool Dequeue(SqQueue& Q, Elemtype &e) {
	if (Q.front == Q.rear){
		return false;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}

//计算元素的个数
Elemtype CountQueue(SqQueue Q) {
	int a,s;
	a = (Q.front + MAXSIZE - Q.rear) % MAXSIZE;
	s = MAXSIZE - a;
	return s;
}


int GetElem(SqQueue Q) {
	if (Q.rear == Q.front) {
		return 0; //若为空队，返回0
	}
	int a;
	a = Q.data[Q.front];
	return a;
}

int main() {
	SqQueue Q;
	SqQueueInit(Q);
	int a,s;
	for (int i = 0; i < 9; i++) {
		scanf_s("%d", &a);
		Enqueue(Q, a);
	}
	s = CountQueue(Q);
	printf("%d", s);
	GetElem(Q);
	return 0;
}