#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
//LinkList L 声明一个指向单链表第一个结点的指针
typedef struct LNode {
	Elemtype data; //存放数据
	struct LNode* next; //指针指向下一个结点
}LNode,*LinkList;

//初始化一个头结点
bool initList(LinkList& L) {
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		return false;
	}
	L->next = NULL;
	return true;
}


//在结点n旁边插入一个元素
bool InsertNextNode(LNode* p, Elemtype e) {
	if (p == NULL) {
		return false;//如果指定结点为空时
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false; //内存申请失败 有些情况内存不足时发生
	}
	s->data = e;
	s->next = p->next;
	p->next = s;

	return true;
}

//在表中的第i个位置插入指定位置
bool ListInsert(LinkList& L, int i, Elemtype e) {
	if (i < 1) {
		return false;
	}
	LNode* p = L;
	int j = 0;//从头节点开始除法
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}//找到 i-1的位置，返回那里的节点
	if (p == NULL) {
		return false;// i值不合法时
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));//申请一块空间
	s->data = e;//赋予想要的数据
	s->next = p->next;
	p->next = s; //将结点s连接到p之后

	return true;
}


bool InsertPointNode(LNode* p, Elemtype e) {
	if (p == NULL) {
		return false; //如果该结点为空时，错误
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false;
	}
	//把新结点s插入到p的后面
	s->next = p->next;
	p->next = s;
	//在把p的值给s，那么s就以前的p p获得新值，就是前插的结点
	s->data = p->data;
	p->data = e;

	return true;
}

bool ListDelete(LinkList& L, int i, Elemtype &e) {
	if (i < 1) {
		return false; //越界报错
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
	LNode* s = p->next;//要删除的位置上的结点
	e = s->data;//返回要删除的结点的数据
	p->data = s->data;
	p->next = s->next;
	free(s);
	return true;

}

//删除指定结点 p
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
	LNode* p = L->next;//因为头节点没有值
	while (p != NULL && p->data != e) {
		p = p->next;
	}
	return p;//找到后返回该结点指针，否则返回NULL
}


//尾插法建立单链表
LNode* LinkList_List_tail(LinkList& L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode* s, * r = L;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;//指向最后一个结点
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList& L) {
	LNode* s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));//创建一个新节点
		s->data = x;
		s->next = L->next;
		L->next = s;   //将新结点插入表中，L为头结点
		scanf("%d", &x);
	}
	return L;

}


int main()
{

	return 0;
}