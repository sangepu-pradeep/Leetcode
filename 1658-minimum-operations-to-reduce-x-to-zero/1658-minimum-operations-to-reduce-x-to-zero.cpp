class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0; int n=nums.size();
        for(auto a:nums)sum+=a;
        int target=sum-x; unordered_map<int,int>mp;
        vector<int>prefix(n+1);  int a=0; int b=-3;
       mp[0]=0; if(target==0) return n;
        for(int i=1;i<=nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i-1];
            int t=prefix[i]-target;
            if(mp.count(t)){
                //i,mp[t]=i-1;             
                if(i-mp[t]>b-a){
                      a=mp[t];b=i; 
                }
            }
            mp[prefix[i]]=i;
        }
      // cout<<b<<" "<<a;
        int ans=b-a;
        if(ans<0) return -1;
        return n-ans;
    }
};