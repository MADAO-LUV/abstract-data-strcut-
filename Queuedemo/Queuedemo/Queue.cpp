/*
���У�Queue�� ��ֻ������һ�˽��в��룬����һ��ɾ�������Ա�

��Ҫ�����ͷ����β���ն���
˳��洢 

rear ָ���βԪ�صĺ�һ��λ��
front ָ���ͷԪ��
*/
#include <stdio.h>
#define MAXSIZE 10
typedef int Elemtype;

//����SqQueue�Ķ���
typedef struct {
	Elemtype data[MAXSIZE];
	int front, rear; // ����ͷָ�룬βָ��
}SqQueue;

//��ʼ��˳����У�ѭ�����У�
bool SqQueueInit(SqQueue& Q) {
	Q.front = Q.rear = 0;
	return true;
}

//�ж��Ƿ�Ϊ�ձ�
bool IsEmpty(SqQueue Q) {
	if (Q.front == Q.rear) {
		return true; //�ж�Ϊ�ձ�
	}
	else {
		return false;
	}
}

//���
bool Enqueue(SqQueue& Q, Elemtype e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) {
		//�ж��Ƿ�����
		return false;
	}
	Q.data[Q.front] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}

//����
bool Dequeue(SqQueue& Q, Elemtype &e) {
	if (Q.front == Q.rear){
		return false;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return true;
}

//����Ԫ�صĸ���
Elemtype CountQueue(SqQueue Q) {
	int a,s;
	a = (Q.front + MAXSIZE - Q.rear) % MAXSIZE;
	s = MAXSIZE - a;
	return s;
}


int GetElem(SqQueue Q) {
	if (Q.rear == Q.front) {
		return 0; //��Ϊ�նӣ�����0
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