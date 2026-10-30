class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto &n : nums) freq[n]++;
        vector<std::pair<int, int>> freq_list(freq.begin(), freq.end());
        std::sort(freq_list.begin(), freq_list.end(),
                    [](const auto& a, const auto& b){ return a.second > b.second; });
        vector<int> topk;
        int idx = 0;
        for(int idx = 0; idx < k; ++idx) {
            topk.emplace_back(freq_list[idx].first);
        }
        return topk;
    }
};
