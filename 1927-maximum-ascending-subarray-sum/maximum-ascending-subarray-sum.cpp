class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int curr = nums[0];
        int max = nums[0];

        for (int i = 1 ; i < nums.size() ; i++) {
            if (nums[i] <= nums[i - 1]) {
                curr = nums[i];
            }

            else if (nums[i] > nums[i - 1]) {
                curr += nums[i];
            }

            max = std::max(curr, max);
        }

        return max;
    }
};