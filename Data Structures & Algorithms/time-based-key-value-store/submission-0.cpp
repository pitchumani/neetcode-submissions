class TimeMap {
    unordered_map<string, map<int, string>> data;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto it = data.find(key);
        if (it != data.end()) {
            it->second[timestamp] = value;
        } else {
            data[key][timestamp] = value;
        }
    }
    
    string get(string key, int timestamp) {
        auto it = data.find(key);
        if (it == data.end()) return "";
        auto s_it = it->second.find(timestamp);
        if (s_it != it->second.end()) {
            return s_it->second;
        }
        auto prev = it->second.end();
        for (auto v_it = it->second.begin(); v_it != it->second.end(); ++v_it) {
            if (v_it->first <= timestamp) {
                prev = v_it;
                continue;
            }
            break;
        }
        return prev == it->second.end() ? "" : prev->second;
    }
};
