class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int sum = 0;
        int minLen = INT_MAX;

        while(r < n)
        {
            sum += nums[r];

            //if sum goes greater than target control it
            while(sum >= target)
            {
                if(sum >= target)
                {
                    minLen = min(minLen, (r-l)+1);
                    sum -= nums[l];
                    l++;
                }
            }
            //keep incrementing the sum
            r++;
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};
