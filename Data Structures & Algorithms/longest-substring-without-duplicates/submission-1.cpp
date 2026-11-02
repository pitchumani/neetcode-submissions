class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int max = 0, left = 0, curr_max = 0;
        unordered_map<char, int> cmap;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            auto it = cmap.find(c);
            if (it == cmap.end()) {
                cmap[c] = i;
                curr_max++;
            } else {
                left = left < it->second ? it->second : left;
                it->second = i;
                curr_max = i - left;
            }
            if (curr_max > max) max = curr_max;
        }
        return max;
    }
};
