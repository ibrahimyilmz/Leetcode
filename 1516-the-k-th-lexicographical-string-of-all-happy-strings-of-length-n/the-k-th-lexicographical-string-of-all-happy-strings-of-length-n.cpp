class Solution {
private:
    string res;
    void helper(int n, int& k, string curr) {
        if (curr.size() == n) {
            k--;
            if (k == 0) {
                res = curr;
            }
            return;
        }

        if (k == 0) {
            return;
        }
        
        char ch = 'a';
        for (int i = 0 ; i < 3 ; i++) {

            if (curr.size() > 0 && curr[curr.size() - 1] == ch + i) {
                continue;
            }

        curr += ch + i;
        helper(n, k, curr);
        curr.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        helper(n, k, "");
        return res;
    }
};