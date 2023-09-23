class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Replace all odd with 1 and even with 0
        for(auto &num:nums)
            if(num%2)
                num=1;
            else
                num=0;
        
        // Now find the subarray with sum at most k and k-1
        return atMost(nums,k)-atMost(nums,k-1);
    }
    int atMost(vector<int>&nums,int k)
    {
        int i=0;
        int j=0;
        int result=0;
        int sum=0;
        // Variable size window problem
        while(j<nums.size())
        {
            // Do pre-calculation
            sum+=nums[j];
            
           
                while(sum>k)
                {
                    // remove calculation for i
                    sum-=nums[i];
                    i++;
                }
                // store result
                result+=j-i+1;
                j++;
            
        }
        return result;
    }
};
