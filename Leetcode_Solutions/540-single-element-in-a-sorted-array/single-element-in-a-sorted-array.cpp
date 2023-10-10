class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int left = 0;
        int right = n-1;

        if(nums[left] != nums[left+1]) return nums[left];
        if(nums[right] != nums[right-1]) return nums[right];
        while(left <= right)
        {
            
            int mid = left + (right - left) / 2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
            {
                return nums[mid];
            }

            if(mid % 2 == 1 && nums[mid] == nums[mid-1] || mid % 2 == 0 && nums[mid] == nums[mid+1])
            {
                //even odd 
                //we are the left side
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return -1;
    }
};