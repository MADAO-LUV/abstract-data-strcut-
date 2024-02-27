#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
//LinkList L ����һ��ָ�������һ������ָ��
typedef struct LNode {
	Elemtype data; //�������
	struct LNode* next; //ָ��ָ����һ�����
}LNode,*LinkList;

//��ʼ��һ��ͷ���
bool initList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}


//�ڽ��n�Ա߲���һ��Ԫ��
bool InsertNextNode(LNode* p, Elemtype e) {
	if (p == NULL) {
		return false;//���ָ�����Ϊ��ʱ
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false; //�ڴ�����ʧ�� ��Щ����ڴ治��ʱ����
	}
	s->data = e;
	s->next = p->next;
	p->next = s;

	return true;
}

//�ڱ��еĵ�i��λ�ò���ָ��λ��
bool ListInsert(LinkList& L, int i, Elemtype e) {
	if (i < 1) {
		return false;
	}
	LNode* p = L;
	int j = 0;//��ͷ�ڵ㿪ʼ����
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}//�ҵ� i-1��λ�ã���������Ľڵ�
	if (p == NULL) {
		return false;// iֵ���Ϸ�ʱ
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));//����һ��ռ�
	s->data = e;//������Ҫ������
	s->next = p->next;
	p->next = s; //�����s���ӵ�p֮��

	return true;
}


bool InsertPointNode(LNode* p, Elemtype e) {
	if (p == NULL) {
		return false; //����ý��Ϊ��ʱ������
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false;
	}
	//���½��s���뵽p�ĺ���
	s->next = p->next;
	p->next = s;
	//�ڰ�p��ֵ��s����ôs����ǰ��p p�����ֵ������ǰ��Ľ��
	s->data = p->data;
	p->data = e;

	return true;
}

bool ListDelete(LinkList& L, int i, Elemtype &e) {
	if (i < 1) {
		return false; //Խ�籨��
	}
	LNode* p = L;
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* s = p->next;//Ҫɾ����λ���ϵĽ��
	e = s->data;//����Ҫɾ���Ľ�������
	p->data = s->data;
	p->next = s->next;
	free(s);
	return true;

}

//ɾ��ָ����� p
bool DeleteNode(LNode* p) {
	if (p == NULL) {
		return false;
	}
	LNode* s = p->next;
	p->data = p->next->data;
	p->next = s->next;
	free(s);
	return true;
}

LNode* Getelem(LinkList L, int i) {
	if (i < 0) {
		return NULL;
	}
	LNode* p = L;
	int j = 0;
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	return p;
}

LNode* LocateElem(LinkList L, Elemtype e) {
	LNode* p = L->next;//��Ϊͷ�ڵ�û��ֵ
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;//�ҵ��󷵻ظý��ָ�룬���򷵻�NULL
}


//β�巨����������
LNode* LinkList_List_tail(LinkList& L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = L;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;//ָ�����һ�����
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

//ͷ�巨����������
LinkList List_HeadInsert(LinkList& L) {
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));//����һ���½ڵ�
		s->data = x;
		s->next = L->next;
		L->next = s;   //���½�������У�LΪͷ���
		scanf("%d", &x);
	}
	return L;

}


int main()
{

	return 0;
}