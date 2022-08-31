class Solution {
public:
    void fun(int i, vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,vector<int>&vis){
        if(i==nums.size()){
            ans.push_back(temp);
            return ;
        }
       for(int k=0;k<nums.size();k++){
           if(vis[k]==0){
               temp.push_back(nums[k]);
               vis[k]=1;
               fun(i+1,nums,temp,ans,vis);
               vis[k]=0;
               temp.pop_back();
           }
       } 
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
       vector<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(n);
        fun(0,nums,temp,ans,vis);
        return ans;
    }
};