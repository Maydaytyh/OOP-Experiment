/*
* @Author: CucumicsMelon
* @Date: 2019-03-25 11:40:35
* @Last Modified by: CucumicsMelon
* @Last Modified time: 2019-03-25 15:57:19
*/
/*思路：
  数组存数，标志存符号，分情况处理即可。
在写的过程中因为初始化调了不少时间的bug,希望以后不会再有这样的错误。*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
#define rep(i, m, n) for (int i = m; i <= n; ++i)
#define ll long long
#define mem(a, b) memset(a, b, sizeof(a))
#ifndef ONLINE_JUDGE
#define dbg(x) cout << #x << "=" << x << endl;
#else
#define dbg(x)
#endif
#define INF 0x3f3f3f3f
class LINT {
private:
	char num[150] = { '\0' };//储存运算数
	int sign;//符号位标志正负
public:
	LINT(char s[], int sig)//构造LINT
	{
		if (sig == -1)
		{
			sign = -1;
			int num_begin = 0;
			if (s[0] == '-') num_begin = 1;
			for (int i = num_begin; i<strlen(s); ++i) num[i - num_begin] = s[i];
		}
		else
		{
			sign = 1;
			for (int i = 0; i<strlen(s); ++i) num[i] = s[i];
		}
	}
	LINT Add(LINT& L);
	LINT Minus(LINT& L);
	void Print();
};
void LINT::Print()
{
	if (sign == -1) putchar('-');
	// cout<<strlen(num)<<endl;
	for (int i = 0; i<strlen(num); ++i) printf("%c", num[i]);
}
LINT LINT::Add(LINT& L)//实现大数加法
{
	LINT xx = LINT(num, 1), yy = LINT(L.num, 1);//两个操作数的正数形式
	if ((sign == -1 && L.sign == 1)) 
		return L.Minus(xx);//若this为负数，返回减法值
	else if (sign == 1 && L.sign == -1) 
		return Minus(yy);//若L为负数，返回减法值
	else if (sign == -1 && L.sign == -1) //若都为减法，对正数形式加法然后取负值即可
	{
		LINT K = xx.Add(yy);
		//cout<<strlen(K.num)<<endl;
		return LINT(K.num, -1);
		//return K;
	}
	else//均为正数则进行普通的高精度加法即可
	{
		int c[150];
		int lena = strlen(num), lenb = strlen(L.num), lenc = 0;
		int a[150], b[150];
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = lena - 1; i >= 0; --i) a[lena - i - 1] = num[i] - '0';
		for (int i = lenb - 1; i >= 0; --i) b[lenb - i - 1] = L.num[i] - '0';
		int i = 0, j = 0;
		int bonus = 0;//存进位
		while (lenc<lena || lenc<lenb)
		{
			c[lenc] = a[lenc] + b[lenc] + bonus;
			bonus = c[lenc] / 10;
			c[lenc] %= 10;
			lenc++;
		}
		if (bonus != 0) c[lenc++] = bonus;
		char d[150] = { '\0' };//转为字符数组返回
		for (int i = 0; i<lenc; ++i) d[i] = c[lenc - i - 1] + '0';
		d[lenc] = '\0';
		return LINT(d, 1);
	}
}
LINT LINT::Minus(LINT &L)//构造减法，保证两个操作数均为正数
{
	int lena = strlen(num), lenb = strlen(L.num);
	int c[150]; char d[150] = { '\0' };
	//int lenc=0;
	if (strcmp(num, L.num) == 0) //如果相等，直接返回0
	{
		d[0] = '0';
		return LINT(d, 0);
	}
	else if ((lena<lenb)||(lena==lenb&&strcmp(num,L.num)<0)) return LINT(L.Minus(*(this)).num, -1);//若左数小于右数，换一下位置操作
	else//若左操作数大于右操作数直接进行操作即可
	{
		int a[150], b[150];
		memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
        memset(c,0,sizeof(c));
		int la = 0, lb = 0;
		for (int i = 0; i<lena; ++i) a[la++] = num[lena - i - 1] - '0';
		for (int i = 0; i<lenb; ++i) b[lb++] = L.num[lenb - i - 1] - '0';
		for (int i = 0; i<la; ++i)
		{
			if (a[i]<b[i]) { a[i]+=10; a[i + 1]--; }
			c[i] = a[i] - b[i];
		}
		while (c[la] == 0 && la>1) la--;
		for (int i = 0; i <= la; ++i) d[i] = c[la - i] + '0';//构造字符数组
		return LINT(d, lena);
	}
}
int main()
{
	char a[150], b[150];
	scanf("%s", a); scanf("%s", b);
	int siga = 1, sigb = 1;
	if (a[0] == '-') siga = -1;
	if (b[0] == '-') sigb = -1;
	LINT A(a, siga), B(b, sigb);
	LINT X = A.Add(B);
	X.Print();
}
