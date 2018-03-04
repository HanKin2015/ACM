#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        int a = 25, b = 20, c = 15;
        long long ans[a * b * c], tag = 0;
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                for(int k = 0; k < c; k++) {
                    //ans[tag] = pow(2, i) * pow(3, j);
                    //ans[tag++] *= pow(5, k);
                    ans[tag++] = pow(2, i) * pow(3, j) * pow(5, k);
                }
            }
        }
        sort(ans, ans + a * b * c);
        return ans[index - 1];
    }
};

int main()
{
    Solution HanKin;
    cout << HanKin.GetUglyNumber_Solution(1500) << endl;
    return 0;
}
