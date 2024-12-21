class Solution {
public:
    bool isOperator(string str) {
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        for (string token : tokens) {
            if (isOperator(token) && !numbers.empty()) {
                int num2 = numbers.top();
                numbers.pop();
                if (numbers.empty()) {
                    numbers.push(num2);
                    continue;
                }
                int num1 = numbers.top();
                numbers.pop();
                if (token == "+") {
                    int res = num1 + num2;
                    numbers.push(res);
                }
                else if (token == "-") {
                    int res = num1 - num2;
                    numbers.push(res);
                }
                else if (token == "*") {
                    int res = num1 * num2;
                    numbers.push(res);
                }
                else if (token == "/") {
                    int res = num1 / num2;
                    numbers.push(res);
                }
            }
            else if (!isOperator(token)) {
                numbers.push(stoi(token));
            }
        }
        return numbers.top();
    }
};