class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            //now check which part is sorted in order to apply binary search
            if(nums[left] <= nums[mid])
            {
                if(nums[left] <= target && nums[mid] >= target)
                {
                    //lies in this part
                    right = mid-1;
                }
                else
                {
                    //exit to the right part
                    left = mid+1;
                }
            }
            else
            {
                //right part is sorted
                if(nums[mid] <= target && nums[right] >= target)
                {
                    left = mid+1;
                }
                else
                {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};