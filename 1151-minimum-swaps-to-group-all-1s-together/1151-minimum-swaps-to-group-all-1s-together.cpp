class Solution {
public:
    int minSwaps(vector<int>& data) {
        int cnt=0;
        for(auto a:data){
            if(a==1)cnt++;
        }
       if(cnt==1||cnt==0) return 0;
        int p=0;
        for(int i=0;i<cnt;i++){
            if(data[i]==1)p++;
        }
        int ans=p;
        for(int i=cnt;i<data.size();i++){
            p=p+data[i]-data[i-cnt];
           // cout<<t<<" "<<i<<endl;
            ans=max(ans,p);
        }
      //  cout<<ans;
        return cnt-ans;
    }
};