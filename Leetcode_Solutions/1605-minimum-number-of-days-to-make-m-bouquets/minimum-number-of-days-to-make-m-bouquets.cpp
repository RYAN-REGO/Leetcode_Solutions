class Solution {
public:
    bool isPossible(vector<int>& v, int day, int m, int k)
    {
        int count = 0;
        int bouqets = 0;
        int n = v.size();
        for(int i = 0; i < n; i++)
        {
            if(v[i] <= day)
            {
                count++;
            }
            else
            {   
                bouqets += (count/k);
                count = 0;
            }
        }
        bouqets += (count/k);
        return bouqets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //edge case impossible case
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size(); //size of the array
        if (val > n) return -1;

        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini;
        int high = maxi;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(isPossible(bloomDay, mid, m, k))
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