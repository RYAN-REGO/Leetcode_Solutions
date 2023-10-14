class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int  n = nums.size();
        int sum = 0;
        int right = 0;
        unordered_map<int, int> mpp;
        int count = 0;

        while(right < n)
        {
            sum += nums[right];

            if(sum == goal) count++;
            //find the required number in the map
            if(mpp.find(sum - goal) != mpp.end())
            {
                //we have a prefix sum
                count += mpp[sum-goal];
            }
            mpp[sum]++;
            right++;
        }
        return count;
    }
};