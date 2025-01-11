class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false;

        unordered_map<char, int> hash;

        for (char c : s) {
            hash[c]++;
        }

        int odd = 0;
        int even = 0;
        for (auto element : hash) {
            if (element.second % 2  == 0) even++;
            else if (element.second % 2 == 1) odd++;
        }

        if (odd > k) return false;

        return true;
    }
};