class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> ans;
        bool flag = false;
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                if(i != j && nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        return ans;
    }
};