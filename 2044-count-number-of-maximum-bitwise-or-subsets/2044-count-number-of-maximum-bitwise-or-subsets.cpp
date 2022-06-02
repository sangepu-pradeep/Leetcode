class Solution {
public:
    int fun(int mask, vector<int>&nums, int mx){
        int n=nums.size();
        if(mask==1<<n) return 0;
        int temp=0;
        for(int i=0;i<n;i++){
           if(mask&(1<<i)) {
               temp|=nums[i];
           } 
        }
       int p=fun(mask+1,nums,mx);
        if(temp==mx)p++;
        return p;
    }
    int countMaxOrSubsets(vector<int>& nums) {
         int temp=0;
        for(auto a:nums){
            temp|=a;
        }
        return fun(0,nums,temp);
    }
};