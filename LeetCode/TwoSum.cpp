#include <bits/stdc++.h>
using namespace std;

class Solution;

int main()
{
    string str = "hjksahkdjhskd";
    //str[4] = '\0\n';
    string s = str.substr(0, 5);
    cout << s << endl;

    //Solution hankin;
    int arr[4] = {2, 7, 11, 15};
    vector<int> nums(arr, arr + 4);
    //vector<int> ans = hankin.twoSum(nums, 9);
    //cout << ans[0] << ' ' << ans[1] << endl;

    vector<int> ans = Solution()::twoSum(nums, 9);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);     // 一开始RE，原来是vector下标访问时需先分配空间

        int len = nums.size();
        unordered_map<int, int> vis;
        for (int i = 0; i < len; i++) vis[nums[i]] = i + 1;
        for (int i = 0; i < len; i++) {
            int tmp = target - nums[i];
            if (tmp != nums[i] && vis[tmp]) {
                ans[0] = i;
                ans[1] = vis[tmp] - 1;
                break;
            }
        }
        return ans;
    }
};
