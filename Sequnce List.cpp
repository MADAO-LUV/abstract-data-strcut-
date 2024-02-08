//ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>

//�궨��
#define MAXSIZE 100
#define OK 1 //�ɹ���־
#define ERROR 0 //ʧ�ܱ�־

typedef int ElemType;
typedef int  status; //���������ͣ�����ֵ������ ��ֵ�Ǻ������״̬���� ��ok��
//˳������ݽṹ
typedef struct
{
	ElemType* elem;
	int length;
}Sqlist;

status InitList(Sqlist* L) {
	//����ַ���׵�ַ��ֵ��L->elem
	L->elem = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
//��ȡһ����̬�洢�ռ�
	if (!L->elem) {
		return ERROR;
	} // �洢����ʧ��
	L->length = 0;
	return OK;
}

//�ж��Ƿ�Ϊ��
int IsEmpty(Sqlist *L) {
	if (L->length == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//������Ա�
void ClearList(Sqlist* L) {
	L->length = 0;
}


//�������Ա�
void Destorylist(Sqlist* L) {
	if (L->elem) {
		free(L);
	}
}

//����һ��Ԫ��λ��
status InsertList(Sqlist* L, int i, ElemType e) {
	if (i<1 || i > L->length + 1) {
		return ERROR;
	}
	if (L->length == MAXSIZE) {
		return ERROR;
	}
	//�������ж��Ƿ�Խ��������Ա��Ƿ�����
	for ( int j = L->length-1; j >= i-1; j--) {
		L->elem[j+1] = L->elem[j];
	}
	L->elem[i - 1] = e;
	L->length++;
	return OK;
	}


//ɾ��һ��Ԫ�ص�Ϊλ��
status DeletList(Sqlist* L, int i, ElemType *e) {
	if (i < 1 || i > L->length + 1) {
		return ERROR;
	}

	if (L->length == 0) {
		return ERROR;
	}
	*e = L->elem[i - 1]; //ȡ��λ��i��Ԫ��
	if (i < L->length) {
		for (int j = i; j < L->length; j++) {
			L->elem[j-1] = L->elem[j];
		}
		L->length--;
		return OK;
	}
}

int length(Sqlist* L) {
	return L->length;
}

void OutPut(Sqlist *L) {
	printf("��ǰ˳���ĳ���:%d\n", L->length);
	for (int i = 0; i < L->length; i++) {
		printf("%d", L->elem[i]);
	}
	printf("\n");
}


int Locate(Sqlist* L, ElemType x) {
	for (int i = 0; i < L->length; i++) {
		if (L->elem[i] == x) {
			return i + 1;
		}
		return 0; //ѭ��������˵������ʧ��
	}
}

//��λ����
status Getelem(Sqlist* L, int i, ElemType* e) {
	if (i < 1 || i > L->length) {
		printf("����λ�÷Ƿ�������ʧ��\n");
		return ERROR;
	}
	else {
		*e = L->elem[i - 1];
		return *e;
	}
}


//����˳���
int CreatList(Sqlist* L,ElemType a[],int n) {
	if (n > MAXSIZE) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		L->elem[i] = a[i];
	}
	L->length = n;
	return OK;
}

int main() {
	Sqlist L;
	int k, l;
	InitList(&L);
	OutPut(&L);
	int a[6] = { 1,2,3,4,5,6 };
	CreatList(&L, a, 6);
	OutPut(&L);
	InsertList(&L, 3, 5);
	OutPut(&L);
	ElemType v = 0;
	k = Getelem(&L, 4,&l);
	printf("%d", k);
	return 0;
}