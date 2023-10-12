class Solution {
public:
    int findDays(vector<int> &wts, int cap)
    {
        int load = 0, day = 1;
        for(int i = 0; i < wts.size(); i++)
        {
            if(load + wts[i] > cap)
            {
                //next day shipping
                day++;
                load = wts[i];
            }
            else
            {   
                load += wts[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int reqDays = findDays(weights, mid);

            if(reqDays <= days)
            {
                //possible ans but we have to find the least
                ans = mid;
                high = mid-1;
            }
            else
            {
                //increase the capacity
                low = mid+1;
            }
        }
        return ans;
    }
};