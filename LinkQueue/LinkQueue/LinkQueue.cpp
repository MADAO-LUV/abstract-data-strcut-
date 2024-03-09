/*
1.����ʽ�洢ʵ�ֶ��У�����ͷ��㣩
2.������������������ɾ���飬�п�
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct LinkNode {
	int data; //��ʽ���н��
	struct LinkNode* next;
}LinkNode;

//��ʽ����
typedef struct {
	LinkNode* front, * rear;
}LinkQueue;

//��ʼ������
void InitNode(LinkQueue& Q) {
	//��ʼʱ front��rear��ָ��NULL
	Q.front = NULL;
	Q.rear = NULL;
}

//�ж��Ƿ�Ϊ�գ�
bool IsEmpty(LinkQueue Q) {
	if (Q.front == NULL) {
		return true;
	}
	else {
		return false;
	}
}

//���
void EnQueue(LinkQueue& Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if (Q.front == NULL) { //�ڿն����в����һ��Ԫ��
		Q.front = s; //�޸ĶԶ�ͷ��βָ��
		Q.rear = s;
	}
	else
	{
		Q.rear->next = s; //�½����뵽rear���֮��
		Q.rear = s; //�޸�rearָ��
	}
}


//����
bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == NULL) {
		return false; //�ն�
	}
	LinkNode* p = Q.front; //pָ��˴γ��ӵĽ��
	x = p->data; //�ñ���x���ض�ͷԪ��
	Q.front = p->next;
	if (Q.rear == p) {
		Q.front = NULL;
		Q.rear = NULL;
	}
	free(p); //�ͷŽ��ռ�
	return true;
}

//����ͷ���Ԫ��
int GetElem(LinkQueue Q) {
	if (Q.front == NULL) {
		return 0; //Ϊ�ն�
	}
	return Q.front->data;
}

//�޸�ͷ����ֵ
bool ChangeNode(LinkQueue& Q, int e) {
	if (Q.front == NULL) {
		return false; //��Ϊ�ն�
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = Q.front;
	Q.front = s->next;
	e = s->data;
	free(s); //�ͷŽ���ڴ�
	return true;
}