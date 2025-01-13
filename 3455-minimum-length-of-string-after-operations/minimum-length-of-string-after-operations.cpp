class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        int length = 0;
        for (char ch : s) {
            freq[ch - 'a']++;
            length++;
        }

        for (int i = 0 ; i < 26 ; i++) {
            if (freq[i] > 2) {
                length -= freq[i];
                while (freq[i] > 2) {
                    freq[i] -= 2;
                }
                length += freq[i];
            }

        }
        return length;
    }
};