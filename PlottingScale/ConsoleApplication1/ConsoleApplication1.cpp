// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class A
{
public:
	virtual void setA() = 0;
private:

};

class B:public A
{
public:
	B(){}
	~B(){}
	virtual void setA(){}
private:

};


int _tmain(int argc, _TCHAR* argv[])
{
	A *a = new B;
	return 0;
}

