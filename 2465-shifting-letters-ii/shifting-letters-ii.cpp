class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size();
        vector<int> prefix(s.size() + 1, 0);

        for (int i = 0 ; i < n ; i++) {
            vector<int> vec = shifts[i];
            int start = vec[0];
            int end = vec[1];
            int dir = vec[2];

            if (dir == 1) {
                prefix[start]++;
                prefix[end + 1]--;
            }
            else {
                prefix[start]--;
                prefix[end + 1]++;
            }
        }

        for (int i = 1; i < prefix.size(); i++) {
            prefix[i] += prefix[i - 1];
        }
        
        string res = "";
        for (int i = 0 ; i < s.size() ; i++) {
            int move = prefix[i];       
            char ch = s[i];
            ch = (ch - 'a' + move) % 26;  
            if (ch < 0) ch += 26;         
            s[i] = ch + 'a';
        }
        return s;
    }
};