class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n+1);
        for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+nums[i-1];
         int sum=prefix[n];
        for(int i=0;i<=n;i++){
            if(i+1<=n&&prefix[i]==sum-prefix[i+1]){
                return i;
            }
          //  else if(i==n&&prefix[i]==)
        }
        return -1;
    }
};