/*
1.ʹ����ʽ�洢ʵ�ֶ��У���ͷ���棩
2.��������������ɾ���ģ��飬��
*/
#include <stdio.h>
#include <stdlib.h>

//���е���ʽʵ��
typedef struct LinkNode {
	int data; //��ʽ���н��
	struct LinkNode* next;
}LinkNode;

//��ʽ����
typedef struct {
	LinkNode* front, * rear;//���еĶ�ͷ�Ͷ�βָ��
}LinkQueue;


//��ʼ�����У���ͷ��㣩
void InitNode(LinkQueue& Q) {
	//��ʼ��ʱ front��rear��ָ��ͷ���
	Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next = NULL;
}

//�ж��Ƿ�Ϊ�գ�
bool IsEmpty(LinkQueue Q) {
	if (Q.front == Q.rear) {
		return true;
	}
	else {
		return false;
	}
}

//��Ԫ�ص����
void EnQueue(LinkQueue& Q, int x) {
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;//��������
	s->next = NULL;
	Q.rear->next = s; //�½����뵽rear֮��
	Q.rear = s; //�޸ı�βָ��
}

//��ͷԪ�س��ӣ���ͷ��㣩
bool DeQueue(LinkQueue& Q, int& x) {
	if (Q.front == Q.rear) {
		return false;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = Q.front->next;//ͷ���ĺ�̽��
	Q.front->next = s->next;
	if (Q.rear == s) {
		Q.rear = Q.front; //��ͷ��������һ�����ʱ
	}
	x = s->data; //��ȡ��ͷ��������
	free(s);
	return true;
}

//���Ҷ�ͷԪ��
int GetFrontNode(LinkQueue Q) {
	return Q.front->data;
}

//���ҽ��
LinkNode* GetNode(LinkQueue Q,int i) {
	if (Q.front == Q.rear || i < 1)
	{
		return NULL; //û�иý������
	}
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));
	p = Q.front;
	int j = 0;
	//����β���ǰ��ֹ
	while (p != NULL && j < i) {
		p = p->next;
	}
	return p;
}


//�޸�Ŀ��ֵ������
bool ChangeNode(LinkQueue& Q, int x,int e) {
	if (Q.front == Q.rear) {
		return false;
	}
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s = GetNode(Q, x);//���ҵ���Ӧ��ֵ����������к����ķ�װ
	s->data = x;
	return true;
}

int main(void) {
	return 0;
}