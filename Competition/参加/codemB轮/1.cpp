#include <bits/stdc++.h>
#define maxn 1005
using namespace std;

struct node {
    int x, y, z;
    int hour, minu;
    double seco;
//    node(int x, int y, int z, int hour, int minu, double seco) {
//        this->x = x;
//        this->y = y;
//        this->z = z;
//        this->hour = hour;
//        this->minu = minu;
//        this->seco = seco;
//    }
};

bool cmp(node a, node b) {
    if(a.hour == b.hour) {
        if(a.minu == b.minu) {
            return a.seco < b.seco;
        }
        return a.minu < b.minu;
    }
    return a.hour < b.hour;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int x, y, z;
    //string t;
    node t[maxn];
    int HH, MM;
    double SS;
    char ch;
    for(int i = 0; i < k; i++) {
        cin >> x >> y >> z;
        cin >> HH;
        cin >> ch;
        cin >> MM;
        cin >> ch;
        cin >> SS;
        //t[i] = node(x, y, z, HH, MM, SS);
        t[i].x = x;
        t[i].y = y;
        t[i].z = z;
        t[i].minu = MM;
        t[i].hour = HH;
        t[i].seco = SS;
    }
    sort(t, t + k, cmp);
    int max_k, max_cnt = 0;
    int cnt = 0;
    int mat[505][505]; //记录ij房间的人数
    memset(mat, 0, sizeof(mat));
    for(int i = 0; i < k; i++) {
        if(t[i].z == 1) {
            mat[t[i].x][t[i].y]--;
            if(mat[t[i].x][t[i].y] == 0) cnt--;
        }
        else {
            if(mat[t[i].x][t[i].y] == 0) cnt++;
            mat[t[i].x][t[i].y]++;
            if(cnt >= max_cnt) {
                max_cnt = cnt;
                max_k = i;
            }
        }
    }
    memset(mat, 0, sizeof(mat));
    for(int i = 0; i <= max_k; i++) {
        if(t[i].z == 1) mat[t[i].x][t[i].y]--;
        else mat[t[i].x][t[i].y]++;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mat[i][j]) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    return 0;
}
