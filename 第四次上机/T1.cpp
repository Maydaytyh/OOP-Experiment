/*
* @Author: CucumicsMelon
* @Date: 2019-04-01 09:53:17
 * @Last Modified by: CucumicsMelon
 * @Last Modified time: 2019-04-02 16:59:37
*/
//#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Frame//框架类
{
private:
	int id, weight;
public:
	friend istream &operator>>(istream &, Frame &);
	friend ostream &operator<<(ostream &, Frame &);
	Frame operator=(Frame &a)
	{
		id = a.id; weight = a.weight;
		return *this;
	}
	Frame() {};
	~Frame() {};
};
class Cardoor//车门类
{
private:
	string color;
	int num;
public:
	friend istream &operator>>(istream &, Cardoor &);
	friend ostream &operator<<(ostream &, Cardoor &);
	Cardoor operator=(Cardoor &a)
	{
		color = a.color; num = a.num;
		return *this;
	}
	Cardoor() {};
	~Cardoor() {};
};
class Tyre//轮胎类
{
private:
	int num;
public:
	friend ostream &operator<<(ostream &, Tyre &);
	friend istream &operator>>(istream &, Tyre &);
	Tyre operator=(Tyre &a)
	{
		num = a.num;
		return *this;
	}
	Tyre() {};
	~Tyre() {};
};
class Vehicle//汽车类
{
private:
	Frame f;
	Cardoor d;
	Tyre t;
public:
	friend ostream &operator<<(ostream &os, Vehicle &a);
	friend istream &operator>>(istream &in, Vehicle &a);
	Vehicle() {}
	Vehicle(Frame & a, Cardoor &b, Tyre &c)
	{
		f = a; d = b; t = c;
	}
	~Vehicle() {}
};
//对输入流进行重载
istream &operator >>(istream &in, Vehicle &a)
{
	in >> a.f >> a.d >> a.t;
	return in;
}
istream &operator>>(istream &in, Frame &a)
{
	in >> a.id >> a.weight;
	return in;
}
istream &operator>>(istream &in, Cardoor &c)
{
	in >> c.num;
	in >> c.color;
	return in;
}
istream &operator>>(istream &in, Tyre &a)
{
	in >> a.num;
	return in;
}
//对输出流进行重载
ostream &operator<<(ostream &out, Frame &a)
{
	out << "ID: " << a.id << endl;
	return out;
}
ostream &operator<<(ostream &out, Cardoor &a)
{
	out << "Number of door: ";
	out << a.num << endl;
	return out;
}
ostream &operator<<(ostream &out, Tyre &a)
{
	out << "Number of Tyre: " << a.num << endl;
	return out;
}
ostream &operator<< (ostream &out, Vehicle &a)
{
	out << a.f << a.d << a.t;
	return out;
}

int main()
{
	Frame Fra;
	cin >> Fra;
	Cardoor Door;
	cin >> Door;
	Tyre T;
	cin >> T;
	Vehicle V(Fra, Door, T);
	cout << V;
	return 0;
}