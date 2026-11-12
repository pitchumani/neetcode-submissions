class Solution {
public:
    int findMin(vector<int> &nums) {
        int sz = nums.size();
        if (sz == 1) return nums[0];
        if (sz == 2) return min(nums[0], nums[1]);
        int left = 0, right = sz - 1;
        int prevLeft = nums[left++];
        int prevRight = nums[right--];
        bool isLeftChanged = false, isRightChanged = false;
        for (;left < right;) {
            if (prevLeft < nums[left]) {
                prevLeft = nums[left++];
            } else {
                return nums[left];
            }
            if (prevRight > nums[right]) {
                prevRight = nums[right--];
            } else {
                return prevRight;
            }
        }
        if (prevLeft > nums[left]) return nums[left];
        else if (prevRight < nums[right]) return prevRight;
        return nums[0];
    }
};
