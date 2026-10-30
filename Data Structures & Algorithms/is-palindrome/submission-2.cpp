class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if (n == 1) return true;
        int fidx = 0;
        int ridx = n - 1;
        while (fidx < ridx) {
            if (!std::isalnum(s[fidx])) {
                ++fidx;
                continue;
            }
            if(!std::isalnum(s[ridx])) {
                --ridx;
                continue;
            }
            /*
            if ((s[fidx] >= 'A' && s[fidx] <= 'Z') ||
                (s[fidx] >= 'a' && s[fidx] <= 'z')) {

                if (std::toupper(s[fidx]) != std::toupper(s[ridx])) {
                    return false;
                }
            } else if (s[fidx] != s[ridx]) { return false; }
            */
            if (std::toupper(s[fidx]) != std::toupper(s[ridx])) {
                return false;
            }
            fidx++;
            ridx--;
        }
        return true;
    }
};
