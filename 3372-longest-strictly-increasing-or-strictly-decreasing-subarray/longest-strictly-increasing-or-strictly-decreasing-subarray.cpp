class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 1;

        bool inc = false;
        bool dec = false;
        int curr = 1;
        int max = 1;

        for (int i = 1 ; i < nums.size() ; i++) {
            if (nums[i] == nums[i - 1]) {
                inc = false;
                dec = false;
                curr = 1;
            }

            else if (nums[i] < nums[i - 1]) {
                if (inc) {
                    inc = false;
                    dec = true;
                    curr = 1;
                }
                dec = true;
                curr++;
            }

            else if (nums[i] > nums[i - 1]) {
                if (dec) {
                    dec = false;
                    inc = true;
                    curr = 1;
                }
                inc = true;
                curr++;
            }

            max = std::max(curr, max);
        }

        return max;
    }
};