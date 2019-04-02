#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define maxn 500000+5
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
string s;//用于存储每一个读入的字符串
int main()
{
    freopen("in.txt","r",stdin);
    int num=0;//num表示word数量
    while(cin>>s)
    {
        int l=s.length();
        int flag=0;//用来表示是word还是数字串，1为word，0为数字或数字串
        rep(i,0,l-1)//循环判断是不是word
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')) 
            {
                flag=1;break;
            }
        }
        if(flag) num++;
    }
    cout<<num<<endl;
}