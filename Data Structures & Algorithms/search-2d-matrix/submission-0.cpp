class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto &row : matrix) {
            if (row[0] > target) return false;
            if (row[row.size()-1] >= target) {
                auto it = std::find(row.begin(), row.end(), target);
                if (it != row.end()) return true;
                return false;
            }
        }
        return false;
    }
};
