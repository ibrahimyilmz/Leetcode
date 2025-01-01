class Solution {
public:
    int maxScore(string s) {
        int ones = 0;

        for (char c : s) {
            if (c == '1') ones++;
        }

        int zeros = 0;
        int max = 0;

        for (int i = 0 ; i < s.size() - 1; i++) {
            char c = s[i];
            if (c == '0') zeros++;
            else if (c == '1') ones--;

            if (ones + zeros > max) {
                max = ones + zeros;
            }
        }
        return max;
    }
};