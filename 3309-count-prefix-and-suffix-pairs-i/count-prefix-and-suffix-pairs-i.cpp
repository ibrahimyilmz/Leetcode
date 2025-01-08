class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0 ; i < words.size() - 1; i++) {
            string prefix = words[i];
            for (int j = i + 1 ; j < words.size() ; j++) {
                string word = words[j];

                if (word.find(prefix) == 0 && word.rfind(prefix) == word.size() - prefix.size())
                    count++;
            }
        }
        return count;
    }
};