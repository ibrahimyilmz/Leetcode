class Solution {
public:
    int eat(vector<int>& piles, int k) {
        int hour = 0;
        for (int i : piles) {
            hour += ceil(static_cast<double>(i) / k);
        }
        return hour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max = *max_element(piles.begin(), piles.end());

        int low = 1;
        int high = max;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int time = eat(piles, mid);
            if (time <= h) {
                high = mid;
            }

            if (time > h) {
                low = mid + 1;
            }
        }
        return low;
    }
};