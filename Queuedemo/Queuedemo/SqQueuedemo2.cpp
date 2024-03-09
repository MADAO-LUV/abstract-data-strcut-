/*
��һ��cpp������ʵ��tag�Ĳٿ�
*/
#include <stdio.h>
#define MAXSIZE 10
typedef struct {
	int data[MAXSIZE];
	int front, rear;
	int tag; //�����ʱ��Ϊ1�����ٵ�ʱ��Ϊ0
 }SqQueue;


//��ʼ���б�
bool InitQueue(SqQueue& Q) {
	Q.front = Q.rear = 0;
	Q.tag = 0;
	return true;
}


//���
bool Enqueue(SqQueue& Q, int e) {
	if (Q.rear == Q.rear && Q.tag) {
		return false; //�Ѿ���������
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}


//����
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.rear == Q.front && Q.tag == 0) {
		return false; //Ϊ��
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}

//���ض�ͷԪ��
int GetElem(SqQueue Q) {
	if (Q.rear == Q.front && Q.tag == 0) {
		return 0; //Ϊ��
	}
	else
	{
		int e = Q.data[Q.front];
		return e;
	}
	
}