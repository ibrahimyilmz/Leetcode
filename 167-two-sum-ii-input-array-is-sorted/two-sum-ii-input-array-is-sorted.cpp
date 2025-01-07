class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l != r) {
            int num1 = numbers[l];
            int num2 = numbers[r];

            int res = num1 + num2;
            if (res < target) {
                l++;
            }
            else if (res > target) {
                r--;
            }

            else if (res == target) {
                return {l + 1, r + 1};
            }
        }
        return {1,1};
    }
};