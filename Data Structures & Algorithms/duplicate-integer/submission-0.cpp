class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash_map;
        for (auto &n : nums) {
            auto it = hash_map.find(n);
            if (it == hash_map.end()) {
                hash_map[n] = 1;
            } else {
                return true;
            }
        }
        return false;
    }
};