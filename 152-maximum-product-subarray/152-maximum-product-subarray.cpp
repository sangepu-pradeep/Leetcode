class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int mx=nums[0];int p=1; int n=nums.size();
        vector<int>dp(n); int neg=1e9;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
         p*=nums[i];
            if(p<0){
                if(neg<i){
                   mx=max(mx,p/dp[neg]);
                }
            }
            mx=max(mx,p);
            if(p<0&&neg==1e9) neg=i;
    if(p==0){ neg=1e9;p=1;}
          dp[i]=p;
        }
        return mx;
    }
};