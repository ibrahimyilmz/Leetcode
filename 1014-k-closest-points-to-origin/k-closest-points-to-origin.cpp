class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> q;

        for (vector<int> vec : points) {
            int distSquared = pow(vec[0], 2) + pow(vec[1], 2);

            q.push({distSquared, vec[0], vec[1]});
            if (q.size() > k) q.pop();
        }
        vector<vector<int>> vec;
        while (!q.empty()) {
            vector<int> top = q.top();
            vec.push_back({top[1], top[2]});
            q.pop();
        }
        return vec;
    }
};