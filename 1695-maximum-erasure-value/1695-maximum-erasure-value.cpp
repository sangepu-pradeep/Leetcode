class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      int st=0; int n=nums.size();
       vector<int>prefix(n+1);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }
        int ans=0; int sum=0; unordered_map<int,int>mp;
        for(int i=0;i<=nums.size();i++){
            if(i==nums.size()){
                 ans=max(ans,prefix[i]-prefix[st]); continue;
            }
            if(mp.count(nums[i])&&st<=mp[nums[i]]){
                ans=max(ans,prefix[i]-prefix[st]);
                sum=prefix[i]-prefix[st];
                st=mp[nums[i]]+1; 
            }
            mp[nums[i]]=i; ;
           // ans=max(ans,sum);
        }
        return ans;
    }
};