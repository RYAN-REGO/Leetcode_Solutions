class Solution {
public:
    int findDays(vector<int>& weights, int cap)
    {
        int day = 1, load = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            day += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += weights[i];
        }
    }
        //total days to load ship will all the weights acc to given capacity
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        int high = 0;
        for(int i = 0; i < weights.size(); i++)
        {
            //max weights out of all
            low = max(low, weights[i]);
            //summation of all weights
            high += weights[i];
        }
        int ans = 0;
        while(low <= high)
        {
            int mid = low + (high-low) / 2;
            int reqDays = findDays(weights, mid);
            if(reqDays <= days)
            {
                //taking less days
                //decrease the capacity
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