#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int T, N, B;
    cin >> T;
    while(T--) {
        cin >> N >> B;
        int per[105], sum = 0, money[105];
        for(int i = 0; i < N; i++) {
            cin >> per[i];
        }
        for(int i = 0; i < B; i++) {
            cin >> money[i];
        }
        sort(per, per + N);
        int ans = 0;
        int vis[105];
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < B; j++) {
                if(!vis[j]) {
                    if(per[i] >= money[j]) {
                        vis[j] = 1;
                        ans++;
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

