class Solution {
public:
    bool fun(int i,vector<int>&nums){
        for(int k=i;k<nums.size();k++){
            if(k+1<nums.size()&&nums[k+1]<nums[k]) return 0;
        }
        return 1;
    }
    bool checkPossibility(vector<int>& nums) {
        int b=0;
        for(int i=0;i<nums.size();i++){
            if(i+1<nums.size()&&nums[i]>nums[i+1]){
               int t=nums[i];
                if((i-1>=0&&nums[i+1]>=nums[i-1])||i==0){
                   nums[i]=nums[i+1];
                    if(fun(i,nums)) return 1;
                    nums[i]=t;
                }
                nums[i+1]=nums[i];
                return fun(i,nums);
            }
        }
        return 1;
    }
};