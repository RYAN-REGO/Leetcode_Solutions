class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int prod = 1;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
        //if(nums[i] < k) cnt++;
            for(int j = i; j < n; j++)
            {
                prod *= nums[j];
                if(prod < k) cnt++;
                //if prod goes greater than k no need of going further
                else break;
            }
            prod = 1;
        }
        return cnt;
    }
};