#include <stdio.h>
#define MAXSIZE 10 //����ջ��Ԫ�ص�������

//˳��ջ
typedef struct {
	int data[MAXSIZE]; //��̬������ջ��Ԫ��
	int top;   //ջ��ָ��
}SqStack;

//��ʼ��ջ���� ��ָ��Ϊ-1
void InitSqStack(SqStack& s) {
	s.top = -1; 
}

//�ж�ջ�Ƿ�Ϊ��
bool IsEmpty(SqStack s) {
	if (s.top == -1) {
		return true;
	}
	else
	{
		return false;
	}
}

//��ջ����1.
bool Push(SqStack& s, int e) {
	if (s.top == MAXSIZE - 1) {
		return false; // �ж��Ƿ���ջ
	}
	s.top = s.top + 1;
	s.data[s.top] = e;
	return true;
}

//��ջ����2.
bool Push1(SqStack& s, int e) {
	if (s.top == MAXSIZE - 1) {
		return false;
	}
	s.data[++s.top] = e; //��ʵ���ǲ���1�Ľ����
	return true;
}


//��ջ����1.
bool Pop(SqStack& s, int& e) {
	if (s.top == -1) {
		return false;
	}
	e = s.data[s.top];
	s.top = s.top - 1;
	return true;
}

//��ջ����2.
bool Pop1(SqStack& s, int& e) {
	if (s.top == -1) {
		return false;
	}
	e = s.data[s.top--];
	return true;
}


//��ȡջ��Ԫ��
bool GetElem(SqStack s, int& e) {
	if (s.top == -1) {
		return false; //���Ϊ��ջ������false
	}
	e = s.data[s.top];
	return true;
}

bool ChangeNode(SqStack& s, int i, int e) {
	if (s.top == -1) {
		return false; //Ϊ��ջ
	}
	while (s.top != i-1) {
		s.top--;
	}
	s.data[s.top] == e;
	return true;
}

void PrintAll(SqStack s) {
	while (s.top > -1) {
		printf("%d ", s.data[s.top--]);
	}
}



int main()
{
	SqStack s;
	InitSqStack(s);
	int x;
	scanf_s("%d", &x);
	while (x != 10) {
		Push(s, x);
		scanf_s("%d", &x);
	}
	PrintAll(s);

	return 0;
}