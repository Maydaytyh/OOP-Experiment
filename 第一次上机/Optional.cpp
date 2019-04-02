#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 500000 + 5
#define pa pair<ll, int>
#define pi acos(-1)
#define maxm 30000
#define ll long long
#define eps 1e-6
#define mod 1000000007
#define mian main
#define inf 1000000000
#define rep(i, n, m) for (int i = n; i <= m; ++i)
#define per(i, n, m) for (int i = n; i >= m; --i)
#define mem(a, b) memset(a, b, sizeof a)
#ifndef ONLINE_JUDGE
#define dbg(x) cout << #x << "=" << x << endl;
#else
#define dbg(x)
#endif
int a[maxn];
void *convert(void *Add, int num, int value)//num为要改变的字节的个数，value为每个字节的目标值
{
    char* mid=(char*) Add;//强制转换成一个字节
    while (num--) //执行num个字节
    {
        *mid++=(char) value;
    }
    return Add;
}
int main()
{
    int n;//数据个数
    cin >> n;
    rep(i, 0, n - 1) cin >> a[i];
    void *p = (void *)a; //将a地址转换为无类型
    convert(p, 12, 9);   //按位进行转换
    rep(i, 0, n - 1) cout << a[i] << endl;
}