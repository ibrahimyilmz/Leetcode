class Solution {
private:
    vector<vector<int>> res;
    int n;
    void backtrack(vector<int>& candidates, int target, vector<int>& curr, int j) {
        if (target == 0) {
            res.push_back(curr);
        }
        if (target < 0) {
            return;
        }

        for (int i = j ; i < n ; i++) {

            if (i > j && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], curr, i + 1);

            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> curr;
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, curr, 0);

        return res;
    }
};