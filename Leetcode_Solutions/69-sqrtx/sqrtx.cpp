class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1 || x == 2 || x == 3) return 1;


        int low = 2;
        int high = x-1;
        int ans = -1;

        while(low <= high)
        {
            long mid = low + (high-low)/2;

            if(mid*mid <= x)
            {
                //possible ans
                //keep pushing to right
                ans = mid;
                low = mid+1;
            }
            else
            {
                //keep moving to left i.e. decrease
                high = mid-1;
            }
        }
        return ans;
    }
};