#include <iostream>
#include <cstring>
using namespace std;

//���ַ�����BFS��DFS�����鼯

bool matrix[505][505];
bool vis[505];

void bfs() {

}

void dfs(int root, int N) {
    for(int i = 0; i < N; i++) {

    }
}

void union_find_set() {

}

int main()
{
    int T, N, M;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        int a, b;
        memset(matrix, 0, sizeof(matrix));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < M; i++) {
            cin >> a >> b;
            matrix[a][b] = matrix[b][a] = 1;
        }

    }
    return 0;
}
