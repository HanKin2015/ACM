#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        /*思路错误*/
//        int L = 0, R = array.size() - 1;
//        while(L <= R) {
//            int mid = (L + R) / 2;
//            if(array[mid][mid] == target) return true;
//            else if(array[mid][mid] > target) R = mid - 1;
//            else L = mid + 1;
//        }
        /*find不能在嵌套的容器中使用*/
        //vector<vector<int> >::iterator it = find(array.begin(), array.end(), target);
        //if(it == array.end()) return false;

        for(int i = 0; i < array.size(); i++) {
            vector<int>::iterator it = find(array[i].begin(), array[i].end(), target);
            if(it != array[i].end()) return true;
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




