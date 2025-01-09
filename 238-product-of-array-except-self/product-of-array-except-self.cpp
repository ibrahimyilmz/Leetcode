class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), nums[0]);

        for (int i = 1 ; i < nums.size() ; i++) {
            prefix[i] = prefix[i - 1] * nums[i];
        }

        for (int i = nums.size() - 2 ; i > 0 ; i--) {
            nums[i] = nums[i + 1] * nums[i];
        }

        int pre = nums[0];
        for (int i = 0 ; i < nums.size() ; i++) {
            int num = 1;

            if (i != 0) num *= pre;
            pre = prefix[i];

            if (i != nums.size() - 1) num *= nums[i + 1];

            nums[i] = num;
        }
        return nums;
    }
};