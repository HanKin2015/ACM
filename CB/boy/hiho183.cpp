#include <iostream>
#include <cstring>
using namespace std;

int N, MAP[1000][1000], vis[1000][1000];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};

void dfs(int x, int y) {
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < 100 && 0 <= ny && ny < 100 && vis[nx][ny] == 0) dfs(nx, ny);
    }
    return ;
}

int main()
{
    memset(MAP, 0, sizeof(MAP));
    cin >> N;
    while(N--) {
        int x, y;
        cin >> x >> y;
        MAP[x][y] = 1;
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < 1000; j++) {
                vis[i][j] = MAP[i][j];
            }
        }
        int cnt = 0;
        for(int i = 0; i < 1000; i++) {
            for(int j = 0; j < 1000; j++) {
                if(MAP[i][j] == 1) {
                        cout << 1<< endl;
                    dfs(i, j);
                    cout << 2<< endl;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
