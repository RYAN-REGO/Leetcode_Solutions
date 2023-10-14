class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;

        while(right < nums.size())
        {
            if(nums[right] == 0)
            {
                k--;
            }
            if(k < 0)
            {
                if(nums[left] == 0)
                {
                    //we are removing one zero from the left
                    //so might as well add k
                    k++;
                }
                left++;
            }
            right++;
        }
        return right - left;
    }
};