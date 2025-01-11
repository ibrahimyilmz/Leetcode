class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26);

        for (string str : words2) {
            vector<int> temp(26, 0);
            for (char c : str) {
                temp[c - 'a']++;
            }
            for (int i = 0 ; i < 26 ; i++) {
                count[i] = max(count[i], temp[i]);
            }
        }

        vector<string> res;
        for (string str : words1) {
            vector<int> temp(26, 0);
            for (char c : str) {
                temp[c - 'a']++;
            }

            bool isUniversal = true;
            for (int i = 0 ; i < 26 ; i++) {
                if (temp[i] < count[i]) {
                    isUniversal = false;
                }
            }
            if (isUniversal) res.push_back(str);
        }
        return res;
    }
};