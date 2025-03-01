class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans(n, 0);
        int count = 0;
        for (int i = 0 ; i < n ; i++) {
            freq[A[i]]++;
            freq[B[i]]++;

            ans[i] = count;
            if (freq[A[i]] == 2) {
                ans[i]++;
            }
            if (freq[B[i]] == 2 && A[i] != B[i]) {
                ans[i]++;
            }
            count = ans[i];
        }
        return ans;
    }
};