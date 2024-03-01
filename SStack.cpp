#include <stdio.h>
#define MAXSIZE 10 //定义栈中元素的最大个数

//顺序栈
typedef struct {
	int data[MAXSIZE]; //静态数组存放栈中元素
	int top;   //栈顶指针
}SqStack;

//初始化栈操作 设指针为-1
void InitSqStack(SqStack& s) {
	s.top = -1; 
}

//判断栈是否为空
bool IsEmpty(SqStack s) {
	if (s.top == -1) {
		return true;
	}
	else
	{
		return false;
	}
}

//入栈操作1.
bool Push(SqStack& s, int e) {
	if (s.top == MAXSIZE - 1) {
		return false; // 判断是否满栈
	}
	s.top = s.top + 1;
	s.data[s.top] = e;
	return true;
}

//入栈操作2.
bool Push1(SqStack& s, int e) {
	if (s.top == MAXSIZE - 1) {
		return false;
	}
	s.data[++s.top] = e; //其实就是操作1的结合体
	return true;
}


//出栈操作1.
bool Pop(SqStack& s, int& e) {
	if (s.top == -1) {
		return false;
	}
	e = s.data[s.top];
	s.top = s.top - 1;
	return true;
}

//出栈操作2.
bool Pop1(SqStack& s, int& e) {
	if (s.top == -1) {
		return false;
	}
	e = s.data[s.top--];
	return true;
}


//读取栈顶元素
bool GetElem(SqStack s, int& e) {
	if (s.top == -1) {
		return false; //如果为空栈，返回false
	}
	e = s.data[s.top];
	return true;
}

bool ChangeNode(SqStack& s, int i, int e) {
	if (s.top == -1) {
		return false; //为空栈
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