class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int prefix = 0;
        int totalCount = 0;
        int even = 1;
        int odd = 0;
        const int MOD = 1e9 + 7;

        for (int i = 0 ; i < arr.size() ; i++) {
            prefix += arr[i];

            if (prefix % 2 == 1) {
                totalCount += even;
                odd++;
            }

            else if (prefix % 2 == 0) {
                totalCount += odd;
                even++;
            }

            totalCount %= MOD;
        }
        return totalCount;
    }
};