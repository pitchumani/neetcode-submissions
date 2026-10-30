class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> listStrMaps;
        for (int i = 0; i < strs.size(); ++i) {
            auto s = strs[i];
            std::sort(s.begin(), s.end());
            //auto it = listStrMaps.find(s);
            listStrMaps[s].push_back(i);
        }
        vector<vector<string>> result;
        
        for (auto it = listStrMaps.begin(); it != listStrMaps.end(); ++it) {
            vector<string> l;
            for (auto &i : it->second) {
                l.push_back(strs[i]);
            }
            result.push_back(l);
        }
        return result;
    }
};
