class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (auto& s: strs) {
            auto ssz = s.size();
            string szstr;
            if (ssz < 10) szstr += '0';
            if (ssz < 100) szstr += '0';
            szstr += std::to_string(ssz);
            result += szstr;
            result.append(s);
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        for (int i = 0; i < s.size();) {
            string szstr = s.substr(i, 3);
            i += 3;
            auto sz = std::stoi(szstr);
            result.emplace_back(s.substr(i, sz));
            i += sz;
        }
        return result;
    }
};
