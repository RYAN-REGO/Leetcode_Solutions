class Solution {
public:
    int atmostSubarray(vector<int>& nums, int goal)
    {
        if(goal < 0) return 0;

        int sum = 0;
        int i = 0, j = 0, count = 0;

        while(j < nums.size())
        {
            sum += nums[j];
            while(sum > goal)
            {
                //decrement the sum
                sum -= nums[i];
                i++;
            }
            count += (j-i) + 1;
            j++;

        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //Sliding window Solution
        return atmostSubarray(nums,goal) - atmostSubarray(nums, goal - 1);
    }
};