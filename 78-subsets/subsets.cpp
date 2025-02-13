class Solution {
private:
    void helper(int n, int j, vector<vector<int>> &res, vector<int>& curr, vector<int>& nums) {
        if (j == n) {
            auto it = find(res.begin(), res.end(), curr);
            if (it == res.end())
                res.push_back(curr);
            return;
        }
        for (int i = j; i < n ; i++) {
            helper(n , i + 1, res, curr, nums);

            curr.push_back(nums[i]);

            helper(n, i + 1, res, curr, nums);

           curr.pop_back(); 
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        
        helper(nums.size(), 0, res, curr, nums);
        return res;
    }
};