/*
 * @Author: CucumicsMelon
 * @Date: 2019-03-18 12:46:40
 * @Last Modified by: CucumicsMelon
 * @Last Modified time: 2019-03-18 15:17:01
 */
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define rep(i, m, n) for (int i = m; i <= n; ++i)
#define ll long long
#define mem(a, b) memset(a, b, sizeof(a))
#ifndef ONLINE_JUDGE
#define dbg(x) cout << #x << "=" << x << endl;
#else
#define dbg(x)
#endif
#define INF 0x3f3f3f3f
class CSmart
{
	private:
     int *p;//该指针变量用于指示是否显式调用析构函数
    public:
      static int sum;
      CSmart(){
          sum++;
          p=new int;
          printf("%d object%c\n",sum,((sum<=1)?'\0':'s'));
      }
      ~CSmart(){
          if(this->p!=NULL)//如果为NULL，说明已经调用析构函数，堆内存被释放，则不进行--操作
          {
              delete(this->p);
              this->p=NULL;
              sum--;
              printf("%d object%c\n",sum,sum<=1?'\0':'s');
          }
      }
};
int CSmart::sum=0;
void DoSomething()
{
    CSmart s;
}
CSmart s1;
int main()
{
    CSmart s2;
    DoSomething();
    CSmart *s3=new CSmart;
    delete s3;
    s2.~CSmart();
}
