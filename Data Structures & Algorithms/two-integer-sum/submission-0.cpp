class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diffMap;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            auto it = diffMap.find(nums[i]);
            if (it != diffMap.end()) {
                vector<int> res;
                res.emplace_back(it->second);
                res.emplace_back(i);
                return res;
            }
            diffMap[diff] = i;
        }
        return vector<int>();
    }
};
