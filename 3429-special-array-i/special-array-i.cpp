class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }

        for (int i = 1; i < nums.size() ; i++) {
            int num = nums[i] - nums[i - 1];
            num = abs(num);

            if (num % 2 == 0) {
                return false;
            }
        }
        return true;
    }
};