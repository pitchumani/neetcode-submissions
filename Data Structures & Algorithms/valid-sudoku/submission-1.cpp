class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rowset;
        unordered_map<int, unordered_set<int>> colset;
        unordered_map<int, unordered_set<int>> sqset;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char val = board[i][j];
                if (val == '.') continue;
                int sqidx = 3 * (i / 3) + (j / 3);
                if (sqset[sqidx].find(val) == sqset[sqidx].end()) sqset[sqidx].emplace(val);
                else return false;
                if (rowset[i].find(val) == rowset[i].end()) rowset[i].emplace(val);
                else return false;
                if (colset[j].find(val) == colset[j].end()) colset[j].emplace(val);
                else return false;
            }
        }

        return true;
    }
};
