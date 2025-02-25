class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return true;

        bool smaller = false;
        for (int i = 1 ; i < n ; i++) {
            if (nums[i] < nums[i - 1]) {
                if (smaller) return false;
                smaller = true;
            }
        }

        if (nums[0] < nums[n - 1] && smaller) {
            return false;
        }

        return true;
    }
};