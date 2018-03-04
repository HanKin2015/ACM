#include <bits/stdc++.h>
using namespace std;

char mat[2005][2005];
int dp_row[2005][2005], dp_column[2005][2005];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    memset(dp_row, 0, sizeof(dp_row));
    memset(dp_column, 0, sizeof(dp_column));
    getchar();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            //cin >> mat[i][j];
            scanf("%c", &mat[i][j]);
            if(mat[i][j] == '.') {
                dp_row[i][j] = dp_row[i][j - 1] + 1;
                dp_column[i][j] = dp_column[i - 1][j] + 1;
            }
        }
        getchar();
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dp_row[i][j] >= k) ans++;
            if(dp_column[i][j] >= k) ans++;
        }
    }
    if(k == 1) ans /= 2;
    cout << ans << endl;
    return 0;
}


