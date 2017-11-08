#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define maxn 10005
#define LL long long
using namespace std;

int n, m;
char arr[105][105], brr[105][105], crr[105][105];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

void dfs(int x, int y) {
    arr[x][y] = '0';
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == '1') dfs(nx, ny);
    }
    return ;
}

void dfs0(int x, int y) {
    brr[x][y] = '1';
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && brr[nx][ny] == '0') dfs0(nx, ny);
    }
    return ;
}

int main()
{
    while(cin >> n >> m) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> arr[i][j];
                crr[i][j] = brr[i][j] = arr[i][j];
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == '1') {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        if(cnt == 1) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(brr[i][j] == '0') {
                        dfs0(i, j);
                        sum++;
                    }
                }
            }
            if(sum == 1) {
                cout << 1 << endl;
            }
            else if(sum == 2) {
                bool f = false;
                for(int i = 0; i < m; i++){
                    if(crr[0][i] == 1) {
                        for(int j = 0; j < m; j++) {
                            if(crr[n-1][j] == 1) {
                                cout << 1 << endl;
                                f = true;
                                break;
                            }
                        }
                        break;
                    }
                }
                if(!f) {
                    cout << 0 << endl;
                }
            }
            else {
                cout << 0 << endl;
            }
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}



