class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n+1);
        
        unordered_map<int,int>mp;
         mp[0]=0;
        for(int i=1;i<=n;i++){
            prefix[i]=nums[i-1]+prefix[i-1];
            int p=prefix[i]%k;
           
            if(mp.count(p)){
               
                int t=mp[p];
                // cout<<i<<" "<<t<<endl;
                if(i-t>1){return 1;}
               // else if(t==0&&i-t>1) return 1;
            }
           if(mp.count(p)==0) mp[p]=i;
        }
        return 0;
            
    }
};