class Solution {
public:
    int findLsum(vector<int> &a, int capacity)
{
    int partitions = 1;
    int load = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(load + a[i] > capacity)
        {
            partitions += 1;
            load = a[i];
        }
        else
        {
            load += a[i];
        }
    }
    return partitions;
}
    int splitArray(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        maxi = max(maxi, nums[i]);
        sum += nums[i];
    }
    int low = maxi;
    int high = sum;

    while(low <= high)
    {
        //permissible amount for each block
        int mid = low + (high - low) / 2;

        int partitions = findLsum(nums, mid);
        if(partitions <= k)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return low;
    }
};