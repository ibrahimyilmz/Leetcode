class Solution {
private:
    vector<vector<int>> res;
    int n;
    void backtrack(vector<int>& candidates, int target, vector<int>& curr, int j) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(curr);
        }

        for (int i = j ; i < n ; i++) {
            curr.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], curr, i);

            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> curr;

        backtrack(candidates, target, curr, 0);

        return res;
    }
};