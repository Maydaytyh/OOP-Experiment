#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000006
int sum[MAXN];
int y[MAXN];
int sa[MAXN];
int Rank[MAXN];
int height[MAXN];
char s[MAXN];
int n;
bool cmp(int i,int j,int k)
{
    return Rank[i]==Rank[j]&&Rank[i+k]==Rank[j+k];
}
void make_sa(){
    int i,j;
    n=strlen(s+1);
    int m=128;
    for(i=1;i<=n;++i)
    {
        Rank[i]=s[i];
        sum[s[i]]++;
    }
    for(i=1;i<=m;++i) sum[i]+=sum[i-1];
    for(i=0;i>0;i--) {
        sa[sum[Rank[i]]]=i;
        sum[rank[i]]--;
    }
}
int main()
{
    int i;
    scanf("%s",s+1);

}