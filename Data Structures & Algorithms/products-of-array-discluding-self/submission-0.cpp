class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        // don't work for list with zero
        int allpdt = 1;
        for (auto n : nums) {
            if (n==0) continue;
            allpdt *= n;
        }
        vector<int> result;
        for (auto n : nums) {
            if (n!=0)
                result.emplace_back(allpdt/n);
            else
                result.emplace_back(allpdt);
        }
        return result;
        */
        auto print = [](vector<int>& n) {
            cout << "[";
            for (auto i: n) cout << i << ", ";
            cout << "]";
        };
        vector<int> prepdt(nums.size());
        int pdt = 1;
        prepdt.emplace_back(pdt);
        for (int i = 0; i < nums.size(); ++i) {
            prepdt[i] = pdt;
            pdt *= nums[i];
        }
        //print(prepdt);
        vector<int> sufpdt(nums.size());
        int spdt = 1;
        //int sidx = 0;
        for (int i = nums.size() - 1; i >=0; --i) {
            sufpdt[i] = spdt;
            spdt *= nums[i];
        }
        //print(sufpdt);
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            result.emplace_back(prepdt[i] * sufpdt[i]);
        }
        return result;
    }
};
