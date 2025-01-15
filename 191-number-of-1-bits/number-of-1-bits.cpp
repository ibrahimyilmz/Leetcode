class Solution {
public:
    int hammingWeight(int n) {
        if (n == 0) return 0;

        int ans = 1;

        while (n != 1) {
            if (n % 2 == 1) ans++;

            n = n / 2;
        }
        return ans;
    }
};