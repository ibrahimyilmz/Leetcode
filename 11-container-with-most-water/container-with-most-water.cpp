class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;

        int l = 0;
        int r = height.size() - 1;
        while (l < r) {
            int h = min(height[l], height[r]);
            int widht = r - l;
            max = std::max(max, h * widht);

            if (height[l] < height[r]) l++;
            else r--;
        }
        return max;
    }
};