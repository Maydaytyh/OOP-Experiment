/*
* @Author: CucumicsMelon
* @Date: 2019-03-25 10:24:26
 * @Last Modified by: CucumicsMelon
 * @Last Modified time: 2019-03-25 11:40:37
*/
/*思路：
   用一个指针保存唯一的实例，无法在外部直接新建实例，只能使用外部接口（函数），函数中会判断是否已经存在实例。
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
class Single_ton {
private:
	Single_ton()//设置为私有成员函数确保无法被外部直接调用，也就是能不能new一个对象得看我内部调用是否允许。
	{
		puts("Yeah!You have done it sucessfully!\n");//每当调用构造函数时会提示创造对象成功
	}
public:
	static Single_ton *Object;//静态成员储存第一次构造出的对象

	~Single_ton() {
	}
	static Single_ton *Create_Object()
	{
		puts("WoW!You try to create an object!\n");//你正在试图创造对象！
		if (Object == NULL)//如果还没有创造过
		{
			Object=new Single_ton();//此处调用构造函数
		}
		else puts("Haha!You failed! There exactly existed an object!\n");//如果已经创造过了，不好意思，你失败了
		return Object;
	}
};
Single_ton* Single_ton::Object = NULL;//对静态变量初始化
int main()
{
	//Single_ton SS;
	//Single_ton::Object = new Single_ton();
	Single_ton S1 = *(Single_ton::Create_Object());//成功
	Single_ton S2 = *(Single_ton::Create_Object());//失败
	//查看运行结果可以知道，构造函数只被调用了一次，即如果试图多次调用构造，返回的都是一样的值。
}