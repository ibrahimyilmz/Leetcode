class Solution {
public:
    int eat(vector<int>& piles, int k) {
        int hour = 0;
        for (int i : piles) {
            hour += i / k;
            hour += i % k != 0 ? 1 : 0; 
        }
        return hour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = -1;
        for (int i = 0 ; i < n ; i++) {
            max = std::max(max, piles[i]);
        }

        int low = 1;
        int high = max;
        int mid;
        while (low < high) {
            mid = low + (high - low) / 2;

            if (eat(piles, mid) <= h) {
                high = mid;
            }

            if (eat(piles, mid) > h) {
                low = mid + 1;
            }
        }
        return low;
    }
};