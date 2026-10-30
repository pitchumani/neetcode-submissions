class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int max_len = 0;
        int curr_len = 0;
        int curr = -1;
        for (auto n : numset) {
            if (!numset.count(n-1)) {
                curr_len = 1;
                curr = n;
            }
            while(numset.count(curr+1)) {
                curr_len++;
                curr++;
            }
            max_len = curr_len > max_len ? curr_len : max_len;
        }
        return max_len;
    }
};
