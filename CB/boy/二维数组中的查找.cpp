#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int L = 0, R = array.size() - 1;
        while(L <= R) {
            int mid = (L + R) / 2;
            if(array[mid][mid] == target) return true;
            else if(array[mid][mid] > target) R = mid - 1;
            else L = mid + 1;
        }
        return false;
    }
};

int main()
{
    Solution HanKin;
    vector<vector<int> > array = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    bool ans = HanKin.Find(7, array);
    cout << boolalpha << ans << endl;
    return 0;
}


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


