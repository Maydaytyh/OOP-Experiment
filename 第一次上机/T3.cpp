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
class Circle
{
  private:
    double X, Y, R;//分别表示圆心横纵坐标及半径

  public:
    void SetXYR(double, double, double);//为圆心横纵坐标，半径设置初值
    double GetX(){
        return X;
    }//外部调用X
    double GetY(){
        return Y;
    }//外部调用Y
    double GetR(){
        return R;
    }//外部调用R
    double Distance(const Circle &);//获取两圆心距离
};
void Circle::SetXYR(double a, double b, double c)
{
    X = a, Y = b, R = c;
}
double Circle::Distance(const Circle &p)
{
    return sqrt((X - p.X) * (X - p.X) + (Y - p.Y) * (Y - p.Y));
}
int main()
{
    Circle P, Q;
    double a1,b1,c1,a2,b2,c2;
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    P.SetXYR(a1,b1,c1);
    Q.SetXYR(a2,b2,c2);
    double Px=P.GetX(),Py=P.GetY(),Pr=P.GetR();
    double Qx=Q.GetX(),Qy=Q.GetY(),Qr=Q.GetR();
   // dbg(Px);dbg(Qx);dbg(Py);dbg(Qy);
    if (Px ==Qx  && Qy == Py)
        cout << "Concentric circles\n";//如果圆心重合，则为同心圆
    else
    {
        double Minus = fabs(Pr - Qr);//半径之差
        double Dis = P.Distance(Q);//求得间距
        double add = Pr+ Qr;//半径之和
        if (add < Dis)
            cout << "seperation\n";//半径之和大于圆心距离，相离
        else if (add == Dis)
            cout << "externally tangent\n";//半径之和等于圆心距离，外切
        else if (Minus == Dis)
            cout << "intenally tangent\n";//半径之差等于圆心距离，内切
        else if (Minus > Dis)
            cout << "Contain\n";//半径之差大于圆心距离，相含
        else cout<<"intersection\n";//其余情况为相交
    }
}