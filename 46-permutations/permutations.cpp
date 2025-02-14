class Solution {
private:
    vector<vector<int>> res;
    int n;
    void backtrack(vector<int>& nums, int j) {
        if (j == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = j ; i < n ; i++) {
            swap(nums[j], nums[i]);
            backtrack(nums, j + 1);
            swap(nums[j], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();

        backtrack(nums, 0);
        return res;
    }
};