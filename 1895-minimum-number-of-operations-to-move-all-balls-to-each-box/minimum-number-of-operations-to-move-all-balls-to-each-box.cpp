class Solution {
public:
    vector<int> minOperations(string boxes) {
        int size = boxes.size();
        if (size == 1) {
            return {0};
        }

        vector<int> left(size, 0);
        vector<int> right(size, 0);
        int addFactor = 0;
        for (int i = 1 ; i < size ; i++) {
            if (boxes[i - 1] == '1') addFactor++;
            left[i] = left[i - 1] + addFactor;

        }

        addFactor = 0;
        for (int i = size - 2; i >= 0 ; i--) {
            if (boxes[i + 1] == '1') addFactor++;
            right[i] = right[i + 1] + addFactor;
        }

        vector<int> answer(size, 0);
        for (int i = 0 ; i < size ; i++) {
            answer[i] = left[i] + right[i];
        }
        return answer;
    }
};