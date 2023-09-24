
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

	int subarraysDivByK(vector<int>& nums, int k) {
  map<int,int>map;
map[0]=1;
int sum=0,count=0;
for (int i=0;i<nums.size();i++){
    sum =sum+nums[i];
    int remainder=(sum%k);
    if(remainder<0){
    remainder=remainder+k;
    }
    count=count+map[remainder];
    map[remainder]++;
}
return count;
}