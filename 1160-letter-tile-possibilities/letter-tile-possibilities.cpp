class Solution {
private:
    int helper(vector<int> &freq) {
        int count = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) {
                continue;
            }

            count++;
            freq[i]--;
            count += helper(freq);
            freq[i]++;
        }

        return count;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);

        for (char ch : tiles) {
            freq[ch - 'A']++;
        }

        return helper(freq);
    }
};