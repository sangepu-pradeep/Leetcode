class Solution {
public:
    int minMoves2(vector<int>& nums) {
       int mn=INT_MAX; int mx=INT_MIN;
        long total=0;
          for(auto a:nums){
            total+=a;
          }
       // int l=mn; int h=mx; int ans=INT_MAX;
        int n=nums.size();
       sort(nums.begin(),nums.end());
        long sum=0; long ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            long l=i; long r=n-1-i;
            long rs=total-sum-(long)nums[i];
          long t= (rs-r*(long)nums[i])+(i*(long)nums[i]-sum);
             if(t<ans) ans=t; sum+=nums[i];
        }
        return (int)ans;
    }
};