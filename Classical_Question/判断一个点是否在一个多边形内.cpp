/*
测试题：http://hihocoder.com/problemset/problem/1450?sid=1416458
射线法实在找不出哪里有错了。
参考：https://blog.csdn.net/u283056051/article/details/53980832
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const double eps = 1e-5;
const double PI = atan(1) * 4;

struct node {
    int x, y;
};

// 射线法
string RayCasting(node p, node poly[], int n)
{
    bool flag = false;
    // 首尾相连n条边
    for (int i = 0, j = n - 1; i < n; j = i, i++) {
        int sx = poly[i].x, sy = poly[i].y;
        int ex = poly[j].x, ey = poly[j].y;
        // 1、判断p点和多边形顶点是否重合
        if ((p.x == sx && p.y == sy) || (p.x == ex && p.y == ey)) return "on";
        // 2、做一条水平射线，判断边两断点是否在射线两侧，并令穿过顶点的点在上端
        if ((sy < p.y && ey >= p.y) || (sy >= p.y && ey < p.y)) {
            // 3、判断p点是否在多边形边上，斜率公式或者三角形比例公式（方便）
            double x = sx + (p.y - sy) * (ex - sx) * 1.0 / (ey - sy);  // 注意除数为0，不可能有这种情况
            if (abs(x - p.x) < eps) return "on";
            // 水平向右作的射线，穿过一次就变换
            if (x > p.x) flag = !flag;
        }
        // 忽略了一种情况
        if (sy == p.y && ey == p.y) {
            if ((p.x > sx && p.x < ex) || (p.x > ex && p.x < sx)) return "on";
        }
    }
    return flag ? "in" : "out";
}

// 回转数法
string WindingNumber(node p, node poly[], int n)
{
    double sum = 0;  // 回转度数和
    // 首尾相连n条边
    for (int i = 0, j = n - 1; i < n; j = i, i++) {
        int sx = poly[i].x, sy = poly[i].y;
        int ex = poly[j].x, ey = poly[j].y;
        // 1、判断p点和多边形顶点是否重合或在多边形边上，开始的肯定错了
        //if ((p.x == sx && p.y == sy) || (p.x == ex && p.y == ey) || (p.x - sx) * (ey - sy) == (p.y - sy) * (ex - sx)) return "on";
        if((sx - p.x) * (p.x - ex) >= 0 && (sy - p.y) * (p.y - ey) >= 0 && (p.x - sx) * (ey - sy) == (p.y - sy) * (ex - sx)) return "on";

        // 2、求夹角(使用atan2函数返回的是指方位角，计算时atan2 比 atan 稳定。)
        double angle = atan2(sy - p.y, sx - p.x) - atan2(ey - p.y, ex - p.x);
        //cout << "angle = " << angle << endl;
        // 3、确保夹角不超过取值范围（-PI到PI）
        if (angle >= PI) angle -= 2 * PI;
        else if (angle <= -PI) angle += 2 * PI;
        sum += angle;
    }
    //cout << "sum = " << sum << endl;
    // 4、计算回转数
    return round(sum / (2 * PI)) == 0 ? "out" : "in";

}
/*
2
0 1 -1 0 1 0 0 2
0 0 0 1 1 0 1 1

1
10 2 7 6 10 9 10 7
*/

int main()
{
    //freopen("test.txt", "r", stdin);
    node p, poly[maxn];
    int n = 3, T;
    cin >> T;
    while (T--) {
        cin >> p.x >> p.y;
        for (int i = 0; i < n; i++) {
            cin >> poly[i].x >> poly[i].y;
        }
        string res1 = RayCasting(p, poly, 3);
        string res2 = WindingNumber(p, poly, 3);
        if (res1 != res2) {
            cout << "Wrong-" << res1 << res2 << endl;
            cout << p.x << ' ' << p.y;
            for (int i = 0; i < n; i++) {
                cout << ' ' << poly[i].x << ' ' << poly[i].y;
            }
            return 0;
        }
        else if (res1 == "out") cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    fclose(stdin);
    return 0;
}
