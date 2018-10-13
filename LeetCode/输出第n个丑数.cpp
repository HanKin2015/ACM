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

/*

def GetUglyNumber_Solution(self, index):
        res=[2**i*3**j*5**k  for i in range(30)  for j in range(20)   for k in range(15)]
        res.sort()
        return res[index-1] if index else 0

    int x = i + j
    for i in range(23):
        for

    链接：https://www.nowcoder.com/questionTerminal/6aa9e04fc3794f68acf8778237ba065b
来源：牛客网

return sorted([2**i*3**j*5**k  for i in range(30)  for j in range(20)   for k in range(15)])[index-1] if index else 0
*/
