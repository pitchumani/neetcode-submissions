class Solution {
public:
    int bsearch(int left, int right, int t, vector<int>& list) {
        if (left > right) return -1;
        int mid = left + (right - left) / 2;
        if (list[mid] == t) return mid;
        return list[mid] < t ? bsearch(mid+1, right, t, list)
                             : bsearch(left, mid-1, t, list);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        //if (n==0) return -1;       
        return bsearch(0, n-1, target, nums);
    }
};
