/*
* @Author: CucumicsMelon
* @Date: 2019-03-25 09:51:32
 * @Last Modified by: CucumicsMelon
 * @Last Modified time: 2019-04-01 11:54:51
*/

/*
 update:相较于上次，多了收缩空间函数，以及copy-constructor函数
 */
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
const int increment = 50;
const int decrement=1;
int a[maxn], b[maxn]; //两个中介数组
enum State            //枚举变量定义状态，成功或失败
{
	Yes = true,
	No = false
};
class CSet
{
private:
	int *p = NULL;
	int size;
	int quantity; //容量
public:
	CSet() : p(0), size(0), quantity(0) {}
	CSet(const CSet& q)//copy-constructor
	{
		size =0; quantity = 0;
		for (int i = 0; i<q.size; i++) this->AddItem(q.p[i]);
	}
	CSet(int *a, int num)//从数组中添加元素
	{
		size = 0; quantity = 0;
		for (int i = 0; i<num; ++i) this->AddItem(*(a+i));
	}
	~CSet() {}
    void Shrink(int dec);
	State IsExist(int x);
	State IsEqual(CSet &);
	void RemoveItem(int x);
	CSet Intersection(CSet &);
	CSet Union(CSet &);
	State AddItem(int x);
	void inflate(int inc);
	void Print();
};
State CSet::IsExist(int x)//判断是否存在
{
	for (int i = 0; i < size; i++)
	{
		if (p[i] == x)
			return Yes;
	}
	return No;
}
void CSet::inflate(int inc)//动态申请内存
{
	int NewQuantity = quantity + inc;//新容量
	int *b = new int[NewQuantity];
	for (int i = 0; i < quantity; ++i)
		b[i] = p[i];
	delete[] p;
	p = b;
	quantity = NewQuantity;
}
void CSet::Shrink(int dec)//释放内存
{
    int NewQuantity = quantity-dec;//新容量
	int *b = new int[NewQuantity];
	for (int i = 0; i < quantity; ++i)
		b[i] = p[i];
	delete[] p;
	p = b;
	quantity = NewQuantity;
}
void CSet::Print()//输出元素
{
	if (size == 0) {//若set为空
		puts("没有元素！");
		return;
	}
	for (int i = 0; i<size; ++i)
		printf("%d%c", this->p[i], (i == size - 1) ? '\n' : ' ');
}
State CSet::IsEqual(CSet &P)
{
	if (P.size != size)//判断两个set size是否相同
		return No;
	else
	{
		mem(a, 0);
		mem(b, 0); //初始化a,b两个暂存数组
		for (int i = 0; i < size; ++i)
			a[i] = p[i], b[i] = P.p[i];
		sort(a, a + size);
		sort(b, b + size);
		for (int i = 0; i < size; i++)//挨个元素比较，若有不同元素返回结果：不同
		{
			if (a[i] != b[i])
				return No;
		}
		return Yes;
	}
}
void CSet::RemoveItem(int x)
{
	int pos;
	for (int i = 0; i < size; ++i) //寻找要删除的元素的位置
	{
		if (p[i] == x)
		{
			pos = i;
			break;
		}
	}
	for (int i = pos; i < size - 1; ++i)
		p[i] = p[i + 1]; //将其后元素依次向前移动
	size--;
    while(quantity>size)//若内存过多，则释放多余内存。
     Shrink(decrement);
}
State CSet::AddItem(int x)
{
	//判断是否超过内存限制，如果超过则申请内存
	while (size >= quantity)
		inflate(increment);
	//cout<<"hhh"<<endl;
	//rep(i,0,size) dbg(p[i]);
	for (int i = 0; i < size; ++i) //判断是否已经存在
	{
		if (p[i] == x)
		{
			cerr << "已包含该元素！" << endl; return No;
		}
	}
	//cout<<"hhhh"<<endl;
	//dbg(quantity);
	p[size++] = x;
	return Yes;
}
CSet CSet::Intersection(CSet &q)//求交集
{
	mem(a, 0);
	mem(b, 0);
	for (int i = 0; i < size; ++i)
		a[i] = p[i];
	for (int i = 0; i < q.size; ++i)
		b[i] = q.p[i];
	sort(a, a + size);
	sort(b, b + q.size);
	if ((*this).IsEqual(q))//如果完全相等，直接返回
		return q;
	else
	{
		CSet Ans;
		for (int i = 0; i < size; ++i)//对每个元素扫描判断
		{
			int flag = 0;//标志是否存在相等元素
			for (int j = 0; j < q.size; ++j)
			{
				if (p[i] == q.p[i])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)//若相等，则加入新的set中
				Ans.AddItem(p[i]);
		}
		return Ans;
	}
}
CSet CSet::Union(CSet &q)//求并集
{
	if ((*this).IsEqual(q))//如果相等，返回
		return q;
	else
	{
		mem(a, 0);
		mem(b, 0);
		//放入一个数组中，排序，去重
		for (int i = 0; i < size; ++i)
			a[i] = p[i];
		for (int i = 0; i < q.size; ++i)
			a[size + i] = q.p[i];
		sort(a, a + size + q.size);
		int num = 0;
		b[0] = a[0];
		//去重
		for (int i = 1; i < size + q.size; ++i)
		{
			if (a[i] == b[num])
				continue;
			else
			{
				b[++num] = a[i];
			}
		}
		CSet Ans;
		for (int i = 0; i < num; ++i)
			Ans.AddItem(b[i]);
		return Ans;
	}
}
int main()
{
	int a[5] = { 1,2,3,4,5 };
	CSet S1(a, 3), S2(a, 5), S3(S2);
	S2.RemoveItem(3);
	(S1.Intersection(S2)).Print();
	return 0;
}