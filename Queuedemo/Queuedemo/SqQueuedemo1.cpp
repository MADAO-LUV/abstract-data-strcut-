/*

���У�Queue�� ��ֻ������һ�˽��в��룬����һ��ɾ�������Ա�

��Ҫ�����ͷ����β���ն���
˳��洢

rear ָ���βԪ�صĺ�һ��λ��
front ָ���ͷԪ��

���������size ���� tag�������Ƿ���������������ж�
tag=1 ��ʾ�ոռ������ tag=0 ��ʾ�ոճ���
*/
#include <stdio.h>
#define MAXSIZE 10
//����һ��˳�����
typedef struct {
	int data[MAXSIZE];
	int front, rear; //ͷβָ��
	int size;
}SqQueue;

//��ʼ������
bool SqQueueInit(SqQueue& Q) {
	Q.front = Q.rear = 0;
	Q.size = 0; //���еĴ�С��ֵΪ0
	return true;
}

//�ж��Ƿ�Ϊ�ն���
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
		return false; //�ж϶����Ƿ�������
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	Q.size++; //���еĴ�С������
	return true;
}

//����
bool DeQueue(SqQueue& Q, int& e) {
	if (Q.size == 0) {
		return false; //�ж�Ϊ��
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	Q.size--;
	return true;
}

//���ͷԪ��
int GetElem(SqQueue Q) {
	if (Q.size == 0) {
		return 0; //��Ϊ�նӣ�����0
	}
	int a;
	a = Q.data[Q.front];
	return a;
}

//����Ԫ�ص�����
int AllQueue(SqQueue Q) {
	return Q.size;
}