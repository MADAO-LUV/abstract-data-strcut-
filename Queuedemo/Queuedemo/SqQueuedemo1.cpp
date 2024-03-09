/*

队列（Queue） 是只允许在一端进行插入，在另一端删除的线性表

重要术语：队头，队尾，空队列
顺序存储

rear 指向队尾元素的后一个位置
front 指向队头元素

不过会加入size 或是 tag来进行是否队满来进行条件判断
tag=1 表示刚刚加入队列 tag=0 表示刚刚出队
*/
#include <stdio.h>
#define MAXSIZE 10
//声明一个顺序队列
typedef struct {
	int data[MAXSIZE];
	int front, rear; //头尾指针
	int size;
}SqQueue;

//初始化队列
bool SqQueueInit(SqQueue& Q) {
	Q.front = Q.rear = 0;
	Q.size = 0; //队列的大小初值为0
	return true;
}

//判断是否为空队列
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
		return false; //判断队列是否满队列
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.size++; //队列的大小先增加
	return true;
}

//出队
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.size == 0) {
		return false; //判断为空
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.size--;
	return true;
}

//查队头元素
int GetElem(SqQueue Q) {
	if (Q.size == 0) {
		return 0; //若为空队，返回0
	}
	int a;
	a = Q.data[Q.front];
	return a;
}

//返回元素的总数
int AllQueue(SqQueue Q) {
	return Q.size;
}