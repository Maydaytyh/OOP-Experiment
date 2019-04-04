#ifndef MyString
#define Mystring
#include <iostream>
using namespace std;
class MyString
{
  private:
	char *ch = NULL;
	int len; //当前长度
	int cap; //当前容量
  public:
	int length()
	{
		return len;
	}
	MyString()
	{
		len = cap = 0;
		ch = NULL;
	}
	MyString(const MyString &a) //拷贝构造函数
	{
		if (a.cap > cap)
			inflate(a.cap - cap);
		len = a.len;
		for (int i = 0; i <= len; ++i)
			ch[i] = a.ch[i];
	}
	int Get_len()
	{
		return len;
	}
	MyString(const char *);				   //无长度，仅字符串的构造函数
	MyString &operator=(const MyString &); //重载等号,相当于拷贝构造函数
	MyString &operator=(const char *);	 //重载等号,给字符串赋值
	char operator[](int pos)
	{
		if (pos < 0 || pos > len)
		{
			cout << "下标范围出错！返回第一个元素！";
			return ch[0];
		}
		else
			return ch[pos];
	}
	//析构函数，如果ch指向的空间未被释放则释放
	~MyString()
	{
		if (ch != NULL)
			delete[] ch;
	}
	MyString operator+(const char *);					 //重载加法
	MyString(const char *, const int);					 //有长度，用字符串构造
	int Find(const char *);								 //查找一个string
	int Find(const char);								 //查找一个字符
	void inflate(int inc);								 //申请空间
	void shrink(int dec);								 //释放多余空间
	MyString Mid(int a, int b);							 //取子区间
	void Check();										 //检查剩余空间是否过多，以超过为界限
	friend MyString operator+(MyString &, MyString &);   //友元函数加法，两个MyString类
	friend MyString operator+(const char *, MyString &); //友元函数加法，一个MyString和一个字符串
	friend ostream &operator<<(ostream &, MyString &);   //重载输出流
};
//未给出长度的构造
MyString::MyString(const char *s)
{
	int len_1 = 0;
	while (s[len_1] != '\0')
		len_1++;
	if (len_1 > cap)
	{
		inflate(len_1 - cap);
	}
	for (int i = 0; i < len_1; ++i)
		ch[i] = s[i];
	ch[len_1] = '\0';
	len = len_1;
	Check();
}
//有长度构造MyString
MyString::MyString(const char *s, int len_2)
{
	if (len_2 > cap)
	{
		inflate(len_2 - cap);
	}
	for (int i = 0; i < len_2; ++i)
		ch[i] = s[i];
	len = len_2;
	ch[len] = '\0';
	Check();
}
//重载等号
MyString &MyString::operator=(const MyString &a)
{
	if (cap < a.cap)
		inflate(a.cap - cap);
	len = a.len;
	for (int i = 0; i < len; ++i)
		ch[i] = a.ch[i];
	ch[len] = '\0';
	return *this;
}
//重载等号
MyString &MyString::operator=(const char *a)
{
	int len_a = 0;
	while (a[len_a] != '\0')
		len_a++;
	if (cap < len_a)
		inflate(len_a - cap);
	len = len_a;
	for (int i = 0; i < len; ++i)
		ch[i] = a[i];
	ch[len] = '\0';
	return *this;
}
//重载加法，字符串加给一个MyString
MyString MyString ::operator+(const char *s)
{
	int len_3 = 0;
	while (s[len_3] != '\0')
		len_3++;
	int len_4 = len_3 + len;
	char *s1 = new char[len_4 + 1];
	for (int i = 0; i < len; ++i)
		s1[i] = ch[i];
	for (int i = 0; i < len_3; ++i)
		s1[i + len] = s[i];
	s1[len_4] = '\0';
	delete[] s;
	s = s1;
	return MyString(s, len_4);
}
//重载加法，两个MyString
MyString operator+(MyString &s1, MyString &s2)
{
	int len_5 = s1.len + s2.len;
	char *s = new char[len_5 + 1];
	for (int i = 0; i < s1.len; ++i)
		s[i] = s1.ch[i];
	for (int i = 0; i < s2.len; ++i)
		s[s1.len + i] = s2.ch[i];
	s[len_5] = '\0';
	return MyString(s, len_5);
}
//重载加法，MyString和字符数组
MyString operator+(const char *ss, MyString &s)
{
	int len_6 = 0;
	while (ss[len_6] != '\0')
		len_6++;
	int len_7 = len_6 + s.len;
	char *s_new = new char[len_7 + 1];
	for (int i = 0; i < len_6; ++i)
		s_new[i] = ss[i];
	for (int i = 0; i < s.len; ++i)
		s_new[i + len_6] = s.ch[i];
	s_new[len_7] = '\0';
	delete[] s.ch;
	s.ch = s_new;
	return MyString(s_new, len_7);
}
//重载输出流
ostream &operator<<(ostream &out, MyString &a)
{
	for (int i = 0; i < a.len; ++i)
		out << a.ch[i];
	return out;
}
//申请空间
void MyString::inflate(int inc)
{
	int Newcap = cap + inc;
	char *b = new char[Newcap + 1];
	for (int i = 0; i < len; ++i)
		b[i] = ch[i];
	delete[] ch;
	ch = b;
	cap = Newcap;
}
//收缩空间
void MyString::shrink(int dec)
{
	int Newcap = cap - dec; //新容量
	char *b = new char[Newcap + 1];
	for (int i = 0; i < len; ++i)
		b[i] = ch[i];
	delete[] ch;
	ch = b;
	cap = Newcap;
}
//检查是否剩余空间过多
void MyString::Check()
{
	if (cap - len > 50)
		shrink(cap - len - 50);
}
//查找子串函数
int MyString::Find(const char *s)
{
	int pos = -1; //pos为返回值，没找到则返回-1.
	int len_s = 0;
	while (s[len_s] != '\0')
		len_s++;
	if (len_s > len) //如果查找的子串长度长于子串
	{
		pos = -1;
		return pos;
	}
	int i = 0;
	while (i <= len - len_s + 1)
	{
		if (ch[i] == s[0]) //第一位相同进行匹配
		{
			int flag = 1, j;
			for (j = 0; j < len_s; ++j)
			{
				if (s[j] != ch[i + j])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				pos = i;
				break;
			}
			i = j;
		}
		else
			i++;
	}
	return pos;
}
int MyString::Find(const char c)
{
	int pos = -1;
	for (int i = 0; i < len; ++i)
	{
		if (ch[i] == c)
		{
			pos = i;
			break;
		}
	}
	return pos;
}
MyString MyString::Mid(int a, int b)
{
	char *s = new char[b + 1];
	for (int i = 0; i < b; ++i)
		s[i] = ch[a + i];
	s[b] = '\0';
	return MyString(s, b);
}
#endif