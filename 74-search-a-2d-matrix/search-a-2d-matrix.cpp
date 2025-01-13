class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0) return false;

        int left = 0;
        int right = m - 1;
        int row = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                row = mid;
                break;
            }

            else if (target < matrix[mid][0]) {
                right = mid - 1;
            }

            else if (target >= matrix[mid][0]) {
                left = mid + 1;
            }
        }

        if (row == -1) return false;

        left = 0;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[row][mid] == target) {
                return true;;
            }

            else if (matrix[row][mid] > target) {
                right = mid - 1;
            }

            else if (matrix[row][mid] < target) {
                left = mid + 1;
            }
        }
        return false;

    }
};