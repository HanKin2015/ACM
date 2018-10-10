#include <bits/stdc++.h>
#include <iomanip>
#define LL long long
using namespace std;

const int maxn = 1e6 + 5;
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int w, h;
        cin >> w >> h;
        char mat[45][45];
        int sx, sy, direct;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                cin >> mat[i][j];
                if (mat[i][j] == 'S') {
                    sx = i;
                    sy = j;
                    if (sx == 0) direct = 2;
                    else if (sy == 0) direct = 1;
                    else if (sx == w - 1) direct = 0;
                    else direct = 3;
                }
            }
        }
        int cnt = 0;
        //cout << sx << ' ' << sy << endl;
        //cout << direct << endl;
        while (1) {
            int nx = sx + dir[direct][0], ny = sy + dir[direct][1];
            //cout << nx << ' ' << ny << endl;
            if (nx < 0 || nx >= w || ny < 0 || ny >= h || mat[nx][ny] == '#') direct = (direct + 1) % 4;
            else if (mat[nx][ny] == 'E') {
                cout << cnt << endl;
                break;
            }
            else {
                sx = nx;
                sy = ny;
                cnt++;
                direct = (direct - 1) % 4;
                cout << nx << ' ' << ny << endl;
            }
        }
    }
    return 0;
}

/*
2
5 5
#####
#...#
#...#
#.#.#
#E#S#
9 5
#########
#.#.#.#.#
S.......E
#.#.#.#.#
#########

7
17
*/
