class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        int result = 0;
        for (auto &tok : tokens) {
            int val1, val2;
            if ((tok == "+")  || (tok == "-") || (tok == "*") || (tok == "/")) {
                val2 = values.top();
                values.pop();
                val1 = values.top();
                values.pop();
            }
            if (tok == "+") {
                values.push(val1+val2);
            } else if (tok == "-") {
                values.push(val1-val2);
            } else if (tok == "*") {
                values.push(val1*val2);
            } else if (tok == "/") {
                values.push(val1/val2);
            } else {
                values.push(stoi(tok));
            }
        }
        if (values.empty() || values.size() > 1) throw std::logic_error("Incorrect handling");
        return values.top();
    }
};
