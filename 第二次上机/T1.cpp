/*
 * @Author: CucumicsMelon 
 * @Date: 2019-03-18 10:16:23 
 * @Last Modified by: CucumicsMelon
 * @Last Modified time: 2019-03-18 15:16:41
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
const int increment = 100;
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
    ~CSet(){}
    State IsExist(int x);
    State IsEqual(CSet &);
    void RemoveItem(int x);
    CSet Intersection(CSet &);
    CSet Union(CSet &);
    State AddItem(int x);
    void inflate(int inc);
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
    for (int i = 0; i < quantity; ++i)//按字节更新实现泛型，虽然本题使用的是Int
        b[i] = p[i];
    delete[] p;
    p = b;
    quantity = NewQuantity;
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
}
State CSet::AddItem(int x)
{
    //判断是否超过内存限制，如果超过则申请内存
    if (size == quantity)
        inflate(increment);
    //cout<<"hhh"<<endl;
    //rep(i,0,size) dbg(p[i]);
    for (int i = 0; i < size; ++i) //判断是否已经存在
    {
        if (p[i] == x)
            {cerr << "已包含该元素！" << endl;return No;}
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
    CSet qaq,qaq1;
    int n,x;
    cin>>n;
    for(int i=0;i<n;++i) {cin>>x;cout<<qaq.AddItem(x)<<endl;}
    for(int i=0;i<n;++i) {cin>>x;qaq1.AddItem(x);}
    cout<<qaq.IsEqual(qaq1)<<endl;
}