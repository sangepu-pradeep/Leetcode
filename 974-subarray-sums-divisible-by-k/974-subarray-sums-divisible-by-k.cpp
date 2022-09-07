class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int,int>mp;
        mp[0]=1; int sum=0;int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
           ans+=mp[(sum%k+k)%k];
            mp[(sum%k+k)%k]++;
        }
        return ans;
    }
};