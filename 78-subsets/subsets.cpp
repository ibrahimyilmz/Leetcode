class Solution {
private:
    vector<vector<int>> output;
    int n;
    void backtrack(int first, vector<int> curr, vector<int>& nums) {
        output.push_back(curr);

        for (int i = first ; i < n ; i++) {
            curr.push_back(nums[i]);

            backtrack(i + 1, curr, nums);

            curr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        backtrack(0, curr, nums);
        return output;
    }
};