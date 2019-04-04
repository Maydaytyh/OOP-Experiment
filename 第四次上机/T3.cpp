/*
 * @Author: CucumicsMelon 
 * @Date: 2019-04-02 08:52:35 
 * @Last Modified by: CucumicsMelon
 * @Last Modified time: 2019-04-02 09:06:18
 */
#include <bits/stdc++.h>
#include"MyString.h"
using namespace std;
class InternetURL
{
private:
	MyString Url;

public:
	InternetURL(const MyString &);
	InternetURL() {};
	MyString GetDomain();
	MyString GetDomainCountry();
	MyString GetDomainType();
};
InternetURL::InternetURL(const MyString &a)
{
	Url = a;
}
//获取域名，判断第几个斜线
MyString InternetURL::GetDomain()
{
	int len = Url.Get_len();
	int num = 0, pos;
	for (int i = 0; i < len; ++i)
	{
		if (Url[i] == '/')
			num++;
		if (num == 3)
		{
			pos = i;
			break;
		}
	}
	return Url.Mid(0, pos);
}
//获取域名国家，因为国家代码均为两个字符，所以返回获取的域名的后两位即可
MyString InternetURL::GetDomainCountry()
{
	MyString Domain = GetDomain();
	int len = Domain.Get_len();
	return Domain.Mid(len - 2, 2);
}
//获取域名类型，截取最后两个点中间的子串
MyString InternetURL::GetDomainType()
{
	MyString Domain = GetDomain();
	int len = Domain.Get_len();
	int num = 0, pos_1, pos_2;
	int flag = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		if (Domain[i] == '.')
			num++;
		if (flag&&num == 1)
			pos_1 = i, flag = 0;
		if (num == 2)
		{
			pos_2 = i;
			break;
		}
	}
	return Domain.Mid(pos_2 + 1, pos_1 - pos_2 - 1);
}
int main()
{
	InternetURL URL("http://jwc.bit.edu.cn/dlpy/142963.htm"), s2;

	cout << URL.GetDomain() << endl; // The result is:  http://jwc.bit.edu.cn

	cout << URL.GetDomainCountry() << endl; // The result is:  cn

	cout << URL.GetDomainType() << endl; // The result is:  edu
}
