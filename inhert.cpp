/*************************************************************************
	> File Name: lrr-5.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2016年11月07日 星期一 19时03分16秒
 ************************************************************************/

#include <iostream>
using namespace std;
#include "test.h"
class A
{
	public:
		void set(int num)
		{
			_num = num;
		}
		int get()
		{
			return _num;
		}
		void get_twice()
		{
			cout<<2*_num<<endl;
		}
	private:
		int _num;
};
class B : public A
{
	private:
		int _num;
};

class C : public A
{
	private:
		int _num;
};
void add(A b,A c)
{
	cout<<"this is b.get() : "<<b.get()<<endl;
	cout<<"this is c.get() : "<<c.get()<<endl;
	cout<<"b & c add is : "<<b.get()+c.get()<<endl;
}
int main()
{
	A a;
	B b;
	C c;
	a.set(4);
//	a.get();
	b.set(5);
//	b.get();
	c.set(6);
//	c.get();
	add(b,c);
	return 0;
}

