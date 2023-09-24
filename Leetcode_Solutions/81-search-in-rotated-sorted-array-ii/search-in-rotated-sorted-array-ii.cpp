class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return true;

            if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;high--;
                continue;
            }
            if(nums[low] <= nums[mid])
            {
                //here we can say that the left part is sorted
                if(nums[low] <= target && nums[mid] >= target)
                {
                    //element exists within bounds
                    high = mid-1;
                }
                else
                {   
                    low = mid+1;
                }
            }
            else
            {
                //here we can say that the right part is sorted
                if(nums[mid] <= target && nums[high] >= target)
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
        }
        return false;
    }
};