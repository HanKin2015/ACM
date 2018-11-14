/*
�����⣺http://hihocoder.com/problemset/problem/1450?sid=1416458
���߷�ʵ���Ҳ��������д��ˡ�
�ο���https://blog.csdn.net/u283056051/article/details/53980832
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
const double eps = 1e-5;
const double PI = atan(1) * 4;

struct node {
    int x, y;
};

// ���߷�
string RayCasting(node p, node poly[], int n)
{
    bool flag = false;
    // ��β����n����
    for (int i = 0, j = n - 1; i < n; j = i, i++) {
        int sx = poly[i].x, sy = poly[i].y;
        int ex = poly[j].x, ey = poly[j].y;
        // 1���ж�p��Ͷ���ζ����Ƿ��غ�
        if ((p.x == sx && p.y == sy) || (p.x == ex && p.y == ey)) return "on";
        // 2����һ��ˮƽ���ߣ��жϱ����ϵ��Ƿ����������࣬���������ĵ����϶�
        if ((sy < p.y && ey >= p.y) || (sy >= p.y && ey < p.y)) {
            // 3���ж�p���Ƿ��ڶ���α��ϣ�б�ʹ�ʽ���������α�����ʽ�����㣩
            double x = sx + (p.y - sy) * (ex - sx) * 1.0 / (ey - sy);  // ע�����Ϊ0�����������������
            if (abs(x - p.x) < eps) return "on";
            // ˮƽ�����������ߣ�����һ�ξͱ任
            if (x > p.x) flag = !flag;
        }
        // ������һ�����
        if (sy == p.y && ey == p.y) {
            if ((p.x > sx && p.x < ex) || (p.x > ex && p.x < sx)) return "on";
        }
    }
    return flag ? "in" : "out";
}

// ��ת����
string WindingNumber(node p, node poly[], int n)
{
    double sum = 0;  // ��ת������
    // ��β����n����
    for (int i = 0, j = n - 1; i < n; j = i, i++) {
        int sx = poly[i].x, sy = poly[i].y;
        int ex = poly[j].x, ey = poly[j].y;
        // 1���ж�p��Ͷ���ζ����Ƿ��غϻ��ڶ���α��ϣ���ʼ�Ŀ϶�����
        //if ((p.x == sx && p.y == sy) || (p.x == ex && p.y == ey) || (p.x - sx) * (ey - sy) == (p.y - sy) * (ex - sx)) return "on";
        if((sx - p.x) * (p.x - ex) >= 0 && (sy - p.y) * (p.y - ey) >= 0 && (p.x - sx) * (ey - sy) == (p.y - sy) * (ex - sx)) return "on";

        // 2����н�(ʹ��atan2�������ص���ָ��λ�ǣ�����ʱatan2 �� atan �ȶ���)
        double angle = atan2(sy - p.y, sx - p.x) - atan2(ey - p.y, ex - p.x);
        //cout << "angle = " << angle << endl;
        // 3��ȷ���нǲ�����ȡֵ��Χ��-PI��PI��
        if (angle >= PI) angle -= 2 * PI;
        else if (angle <= -PI) angle += 2 * PI;
        sum += angle;
    }
    //cout << "sum = " << sum << endl;
    // 4�������ת��
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
