class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            else if (nums[mid] > target) {
                high = mid - 1;
            }

            else if (nums[mid] < target) {
                low = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};