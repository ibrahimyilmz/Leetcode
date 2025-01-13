class Solution {
public:
    bool canBeValid(string s, string locked) {
        int length = s.size();
        if (length % 2 == 1) return false;

        stack<int> flex, lock;

        for (int i = 0 ; i < s.size() ; i++) {
            if (locked[i] == '0') flex.push(i);
            else if (s[i] == '(') lock.push(i);
            else {
                if (!lock.empty()) lock.pop();
                else if (!flex.empty()) flex.pop();
                else return false;
            }
        }

        while (!flex.empty() && !lock.empty()) {
            if (flex.top() > lock.top()) {
                flex.pop();
                lock.pop();
            }
            else {
                return false;
            }
        }

        if (!lock.empty()) return false;

        return true;
    }
};