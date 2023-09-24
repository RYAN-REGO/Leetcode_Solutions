
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1;
        int sum=0,ans=0;
        for(auto i:nums)
        {
            sum=(sum+i%k+k)%k;
            if(mp.find(sum)!=mp.end())
            {
                ans+=mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};

