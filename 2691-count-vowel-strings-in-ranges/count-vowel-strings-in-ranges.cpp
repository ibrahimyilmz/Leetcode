class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size() + 1, 0);

        for (int i = 1 ; i < words.size() + 1; i++) {
            string word = words[i - 1];
            char first = word[0];
            char last = word[word.size() - 1];
            if (isVowel(first) && isVowel(last)) {
                prefix[i] = prefix[i - 1] + 1;
            }
            else {
                prefix[i] = prefix[i - 1];
            }
        }

        vector<int> result(queries.size());
        for (int i = 0 ; i < queries.size() ; i++) {
            vector<int> vec = queries[i];
            result[i] = prefix[vec[1] + 1] - prefix[vec[0]]; 
        }
        return result;
    }
};