class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int fidx = 0;
        int ridx = numbers.size() - 1;
        while (fidx < ridx) {
            if (numbers[fidx] + numbers[ridx] == target) {
                return vector<int>{fidx+1, ridx+1};
            }
            if (numbers[fidx] + numbers[ridx] > target) --ridx; 
            else if (numbers[fidx] + numbers[ridx] < target) ++fidx;
        }
    }
};
