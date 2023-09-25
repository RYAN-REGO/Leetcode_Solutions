class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //consider the edge cases
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 1;
        int high = n-2;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] >= nums[mid + 1] && nums[mid] >= nums[mid-1])
            {
                return mid;
            }
            if(nums[mid] >= nums[mid-1] && nums[mid] <= nums[mid+1])
            {
                //4 5 6 - > increasing curve
                //peak is yet to appear
                //it is on the right side
                low = mid+1;
            }
            else
            {
                //6 5 4 - > decreasing curve
                //peak has already appeared 
                //it was on the left
                high = mid-1;
            }
        }
        return -1;
    }
};