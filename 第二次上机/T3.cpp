/*
 * @Author: CucumicsMelon 
 * @Date: 2019-03-18 13:16:02 
 * @Last Modified by: CucumicsMelon
 * @Last Modified time: 2019-03-18 15:19:32
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
class IntChar{
    private: 
     int Bin[4][8];//用于存储每个字符的二进制形式
     char chr[4];
    public:
     IntChar(char ss[])
     {
        for(int i=0;i<strlen(ss);++i) chr[i]=ss[i];
     }
     ~IntChar(){}
     void ASC_Print();
     void Convert_Binary(int a[]);//用于二进制转换
     void Binary_Print();
     void Int_Print();
}; 
void IntChar::Convert_Binary(int a[])//二进制转换操作
{
    for(int i=0;i<4;++i)//对于每个数，进行对从2^7到2^1进行按位与操作，得到二进制表示
    {
        int muti=128;//代表2的次幂
        for(int j=0;j<8;++j)
        {
            if(a[i]&muti) Bin[i][j]=1;
            else Bin[i][j]=0;
            muti>>=1;
        }
    }
}
void IntChar::ASC_Print()//按字符类型输出
{
    printf("%s\n",chr);
}
void IntChar::Binary_Print()//按二进制形式输出
{
    int a[4];//临时数组，存储四个字符的ascii码
    for(int i=0;i<strlen(chr);++i) a[i]=(int)chr[i];
    if(strlen(chr)<4) 
    {
        for(int i=strlen(chr);i<4;++i) a[i]=0;
    }
    Convert_Binary(a);//先进行二进制转换
    for(int i=0;i<4;++i) 
    {
        for(int j=0;j<4;++j)
         printf("%d",Bin[i][j]);
         printf(" ");
        for(int j=4;j<8;++j)
          printf("%d",Bin[i][j]);
        printf(" ");
    }
    puts("");
}
void IntChar::Int_Print()//将所得的4*8位二进制数整个转换为整数类型
{
    int muti=1;//累乘器
    ll ans=0;//储存最终结果
    for(int i=3;i>=0;i--)
    {
        for(int j=7;j>=0;--j)
          {
              ans+=muti*Bin[i][j];
              muti<<=1;
          }
    }
    printf("%lld\n",ans);
}
int main()
{
    IntChar IC("Love");
    IC.ASC_Print();
    IC.Binary_Print();
    IC.Int_Print();
}