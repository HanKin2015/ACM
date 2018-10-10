#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 +5;

vector<int> stateOfLights(int days, int* lights)
{
    vector<int> ans(8), tmp(10);
    tmp[0] = 0, tmp[9] = 0;
    for (int i = 1; i <= 8; i++) tmp[i] = *(lights + i - 1);
    while (days) {
        for (int i = 1; i <= 8; i++) {
            if (tmp[i - 1] == tmp[i + 1]) ans[i - 1] = 0;
            else ans[i - 1] = 1;
        }
        for (int i = 1; i <= 8; i++) tmp[i] = ans[i - 1];
        days--;
    }
    //for (int i : ans) cout << i << ' ';
    return ans;
}

int main()
{
    int days, lights[10];
    cin >> days;
    lights[0] = 0;
    lights[9] = 0;
    for (int i = 1; i <= 8; i++) cin >> lights[i];
    stateOfLights(days, lights);
    return 0;
}
/*
1
1 0 0 0 0 1 0 0
*/


