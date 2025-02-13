class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});

        for (int i : nums) {
            vector<vector<int>> newSubsets;
            for (vector<int> vec : res) {
                vector<int> add = vec;
                add.push_back(i);
                newSubsets.push_back(add);
            }
            for (vector<int> vec : newSubsets) {
                res.push_back(vec);
            }
        }
        return res;
    }
};