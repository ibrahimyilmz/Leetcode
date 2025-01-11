class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false;
        if (k == s.size()) return true;

        vector<int> freq(26, 0);
        int odd = 0;

        for (auto & ch : s) freq[ch - 'a']++;

        for (int i = 0 ; i < 26 ; i++) {
            if (freq[i] % 2 == 1) odd++;
        }

        if (odd > k) return false;

        return true;
    }
};