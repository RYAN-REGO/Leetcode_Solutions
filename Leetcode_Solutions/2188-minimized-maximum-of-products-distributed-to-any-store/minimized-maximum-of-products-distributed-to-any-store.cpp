class Solution {
public:
    //most important is ceil
    int findNoStores(vector<int>& v, int prodPerStore)
    {
        int count = 0;
        for(int i = 0; i < v.size(); i++)
        {
            count += ceil((double)v[i] / (double)prodPerStore);
        }
        return count;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s = quantities.size();
        if(n == 1) return quantities[0]; 
        int low = 1;
        int high = INT_MIN;
        for(int i = 0; i < s; i++)
        {
            high = max(high, quantities[i]);
        }
        int ans = 0;
        //we have the lower and upper bound
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int noOfStores = findNoStores(quantities, mid);
            if(noOfStores <= n)
            {
                //less number of stores are catered than required
                //lessen the number of products provided per store
                //low = mid+1;
                ans = mid;
                high = mid-1;
            }
            else
            {   
                //high = mid-1;
                low = mid+1;
            }
        }
        return ans;
    }
};