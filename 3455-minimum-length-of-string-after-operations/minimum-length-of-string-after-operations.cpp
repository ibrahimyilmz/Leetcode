class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int length = 0;
        for (int i = 0 ; i < 26 ; i++) {
            if (freq[i] % 2 == 1) length += 1;
            else if (freq[i] % 2 == 0 && freq[i] != 0) length += 2;
        }
        return length;
    }
};