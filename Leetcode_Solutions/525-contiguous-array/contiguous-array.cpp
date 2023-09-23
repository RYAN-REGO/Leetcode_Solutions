class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        //generic sliding window approach cannot be applied and ATMOST concepts has to be applied(sliding window mod)
        //prefix Sum solution
        int n = nums.size();
        int right = 0;
        int sum = 0;
        int maxLen = INT_MIN;
        unordered_map<int, int> mpp;

        while(right < n)
        {
            if(nums[right] == 0) sum--;
            if(nums[right] == 1) sum++;

            if(sum == 0)
            {
                maxLen = max(maxLen, right+1);
            }
            if(mpp.find(sum) != mpp.end())
            {
                maxLen = max(maxLen, right-mpp[sum]);
            }
            else
            {
                mpp[sum] = right;
            }
            right++;
        }
        if(maxLen < 0) return 0;
        else return maxLen;
    }
};