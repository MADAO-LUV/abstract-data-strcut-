/*
���У�Queue�� ��ֻ������һ�˽��в��룬����һ��ɾ�������Ա�

��Ҫ�����ͷ����β���ն���
˳��洢

rear ָ���βԪ��
front ָ���ͷԪ��
*/
#include <stdio.h>
#define MAXSIZE 10

//����SqQueue�Ķ���
typedef struct {
	int data[MAXSIZE];
	int front, rear; // ����ͷָ�룬βָ��
	int size;
}SqQueue;

//��ʼ������
bool QueueInit(SqQueue& Q) {
	Q.front = 0;
	Q.rear = MAXSIZE - 1; //�����ָ��ָ���ͷ��һ��λ��
	Q.size = 0;
	return true;
}

//�ж��Ƿ�Ϊ��
bool IsEmpty(SqQueue Q) {
	if (Q.size == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

//���
bool EnQueue(SqQueue& Q, int e) {
	if (Q.size == MAXSIZE) {
		return false; //�������
	}
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.data[Q.rear] = e;
	return true;
}

//����
bool DeQueue(SqQueue& Q, int &e) {
	if (Q.size == 0) {
		return false;
	}
	int e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}

//��ö�ͷԪ��
int GetElem(SqQueue Q) {
	return Q.data[Q.front];
}

//�������
int QueueSize(SqQueue Q) {
	return Q.size;
}