class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int num : nums) {
            hash[num]++;
        }

        vector<vector<int>> vec(nums.size() + 1);

        for (auto entry : hash) {
            vec[entry.second].push_back(entry.first);
        }

        vector<int> result;
        for (int freq = nums.size(); freq > 0; --freq) {
            for (int num : vec[freq]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};