class Solution {
public:
    void printS(int ind, vector<vector<int>>& ds, vector<int>& nums, int n, vector<int>& level)
    {
        if(ind == n)
        {
            ds.push_back(level);
            return;
        }
        level.push_back(nums[ind]);
        printS(ind + 1, ds, nums, n, level);
        level.pop_back();
        printS(ind + 1, ds, nums, n, level);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        //answer variable
        vector<vector<int>> ds;
        vector<int> level;
        printS(0, ds, nums, n, level);

        return ds;
    }
};