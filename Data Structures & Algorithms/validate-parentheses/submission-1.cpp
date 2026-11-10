class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> parenthesesStack;
        parenthesesStack.push(s[0]);
        char lastP = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (parenthesesStack.empty()) {
                lastP = 0;
            } else {
                lastP = parenthesesStack.top();
            }
            switch (s[i]) {
                case ')':
                    if (lastP == '(') {
                        parenthesesStack.pop();
                    } else {
                        parenthesesStack.push(s[i]);
                    }
                break;
                case ']':
                    if (lastP == '[') {
                        parenthesesStack.pop();
                    } else {
                        parenthesesStack.push(s[i]);
                    }
                break;
                case '}':
                    if (lastP == '{') {
                        parenthesesStack.pop();
                    } else {
                        parenthesesStack.push(s[i]);
                    }
                break;
                default:
                    parenthesesStack.push(s[i]);
            }
        }
        if (parenthesesStack.empty()) return true;
        return false;
    }
};
