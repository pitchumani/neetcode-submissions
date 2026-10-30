class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> diffMap;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            auto it = diffMap.find(nums[i]);
            if (it == diffMap.end()) {
                diffMap[diff] = i;
                continue;
            }
                vector<int> res;
                res.emplace_back(it->second);
                res.emplace_back(i);
                return res;            
        }
        return vector<int>();
    }
};
