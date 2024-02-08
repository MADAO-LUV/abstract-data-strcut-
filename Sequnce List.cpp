//头文件
#include <stdio.h>
#include <stdlib.h>

//宏定义
#define MAXSIZE 100
#define OK 1 //成功标志
#define ERROR 0 //失败标志

typedef int ElemType;
typedef int  status; //函数的类型，返回值的类型 其值是函数结果状态代码 如ok等
//顺序表数据结构
typedef struct
{
	ElemType* elem;
	int length;
}Sqlist;

status InitList(Sqlist* L) {
	//基地址的首地址赋值给L->elem
	L->elem = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
//获取一个动态存储空间
	if (!L->elem) {
		return ERROR;
	} // 存储分配失败
	L->length = 0;
	return OK;
}

//判断是否为空
int IsEmpty(Sqlist *L) {
	if (L->length == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

//清空线性表
void ClearList(Sqlist* L) {
	L->length = 0;
}


//销毁线性表
void Destorylist(Sqlist* L) {
	if (L->elem) {
		free(L);
	}
}

//插入一个元素位置
status InsertList(Sqlist* L, int i, ElemType e) {
	if (i<1 || i > L->length + 1) {
		return ERROR;
	}
	if (L->length == MAXSIZE) {
		return ERROR;
	}
	//以上是判断是否越界或是线性表是否满了
	for ( int j = L->length-1; j >= i-1; j--) {
		L->elem[j+1] = L->elem[j];
	}
	L->elem[i - 1] = e;
	L->length++;
	return OK;
	}


//删除一个元素的为位置
status DeletList(Sqlist* L, int i, ElemType *e) {
	if (i < 1 || i > L->length + 1) {
		return ERROR;
	}

	if (L->length == 0) {
		return ERROR;
	}
	*e = L->elem[i - 1]; //取出位置i的元素
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
	printf("当前顺序表的长度:%d\n", L->length);
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
		return 0; //循环结束，说明查找失败
	}
}

//按位查找
status Getelem(Sqlist* L, int i, ElemType* e) {
	if (i < 1 || i > L->length) {
		printf("查找位置非法，查找失败\n");
		return ERROR;
	}
	else {
		*e = L->elem[i - 1];
		return *e;
	}
}


//建立顺序表
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