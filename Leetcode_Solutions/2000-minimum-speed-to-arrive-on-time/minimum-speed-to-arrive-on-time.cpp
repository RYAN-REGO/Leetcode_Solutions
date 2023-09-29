class Solution {
public:
    bool isPossible(vector<int>& dist, int speed, double hour)
    {
        double ans = 0;
        for(int i = 0; i < dist.size(); i++)
        {
            //both dist and speed are int so the result will also be int
            //hence to convert it into double mul by 1.0
            ///OR double d = double(dist[i]) / double(speed);
            double d = dist[i] * 1.0 / speed;
            if(i == dist.size() - 1) ans += d;
            else ans = ans + ceil(d);
            if(ans > hour) return false;
        }
        if(ans <= hour) return true;
        //possible to reach on time
        else return false;
        //not possible to reach on time
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int n = dist.size();
        if(hour < n - 1) return -1;
        int low = 1;
        int high = 1e7;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            //find the total hrs at speed mid
            if(isPossible(dist, mid, hour))
            {
                //if possible then it can be our answer
                //but try for evan smaller
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
    }
};