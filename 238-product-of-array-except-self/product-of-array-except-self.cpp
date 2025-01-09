class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), nums[0]);
        vector<int> suffix(nums.size(), nums[nums.size() - 1]);

        for (int i = 1 ; i < nums.size() ; i++) {
            prefix[i] = prefix[i - 1] * nums[i];
        }

        for (int i = nums.size() - 2 ; i > 0 ; i--) {
            suffix[i] = suffix[i + 1] * nums[i];
        }

        vector<int> res(nums.size());
        for (int i = 0 ; i < nums.size() ; i++) {
            int num = 1;

            if (i != 0) num *= prefix[i - 1];

            if (i != nums.size() - 1) num *= suffix[i + 1];

            res[i] = num;
        }
        return res;
    }
};