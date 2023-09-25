class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mini = INT_MAX;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[low] <= nums[mid])
            {
                //left part is sorted
                //hence just pick the first element and move to next part
                mini = min(mini, nums[low]);
                low = mid+1;
            }
            else
            {
                //right part is sorted
                mini = min(mini, nums[mid]);
                high = mid-1;
            }
        }
        return mini;
    }
};