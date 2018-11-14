/*
在三角形内部的点形成的都是钝角三角形
点在x,y的中间并不能判断
*/

#include <bits/stdc++.h>
#define LL long double
using namespace std;

const double eps = 1e-5;
LL Heron(LL a, LL b, LL c)
{
    return 0.25 * sqrt((a + b + c) * (a + b - c) * (a + c - b) * (b + c - a));
}

LL Distance(LL x1, LL y1, LL x2, LL y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        LL x[4], y[4];
        for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];
        LL s = 0;
        for (int i = 1; i <= 2; i++) {
            for (int j = i + 1; j < 4; j++) {
                LL a = Distance(x[0], y[0], x[i], y[i]), b = Distance(x[0], y[0], x[j], y[j]), c = Distance(x[i], y[i], x[j], y[j]);
                s += Heron(a, b, c);
            }
        }
        LL a = Distance(x[1], y[1], x[2], y[2]), b = Distance(x[1], y[1], x[3], y[3]), c = Distance(x[2], y[2], x[3], y[3]);
        //cout << s << ' ' << Heron(a, b, c) << endl;
        if (abs(s - Heron(a, b, c)) < eps) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

/*
输入的都是整数，三角形面积计算s=0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
所有面积里都有这个0.5，去掉这个0.5对结果不影响，于是面积计算出来就是整数，没有精度问题了。
向量法求面积。
*/
#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL area(LL x1,LL y1,LL x2,LL y2,LL x3,LL y3)
{
    return abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
}

int main()
{
    LL Px, Py, Ax, Ay, Bx, By, Cx, Cy;
    LL S, S1, S2, S3;
    LL t;
    for(cin>>t;t>0;t--)
    {
        cin>>Px>>Py>>Ax>>Ay>>Bx>>By>>Cx>>Cy;
        S  = area(Ax, Ay, Bx, By, Cx, Cy);
        S1 = area(Px, Py, Ax, Ay, Bx, By);
        S2 = area(Px, Py, Ax, Ay, Cx, Cy);
        S3 = area(Px, Py, Bx, By, Cx, Cy);
        if(S1+S2+S3<=S)cout<<"YES\n";else cout<<"NO\n";
    }
    return 0;
}

/*
还有个简单的方法，判断三条边的向量与P跟三个点连接的向量的叉积，如果三个叉积值同正负，则在三角形内。
*/

#define G(v,_) scanf("%ld",&v),v-=_;
main(T){long p,P,a,A,b,B,c,C,x,y,z;for(G(T,0)T--;puts(((-x|-y|-z)&(x|y|z))<0?"NO":"YES")){G(p,0)G(P,0)G(a,p)G(A,P)G(b,p)G(B,P)G(c,p)G(C,P)x=a*B-b*A;y=b*C-c*B;z=c*A-a*C;}return 0;}

