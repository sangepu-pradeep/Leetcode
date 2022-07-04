class Solution {
public:
    
    int candy(vector<int>& r) {
        int n=r.size();
       vector<int>ans(n,1);
        for(int i=1;i<n;i++){
           if(r[i]>r[i-1]) ans[i]=ans[i-1]+1;
            else ans[i]=1;
        }
        int sum=0;
       for(int i=n-2;i>=0;i--){
           if(r[i+1]<r[i]) {
               int t=ans[i+1]+1;
               ans[i]=max(ans[i],t);
           }
           
       }
       for(auto a:ans)sum+=a;
        return sum;
        
    }
};