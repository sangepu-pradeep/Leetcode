class Solution {
public:

    bool hasAllCodes(string s, int k) {
       int p=1<<k; int sz=s.size();
        if(sz-k+1<p) return 0;
        // cout<<(sz-k+1);
        // return 0;
        unordered_map<int,int>mp; int cnt=0;
         int temp=0; int m=1;
        for(int i=k-1;i>=0;i--){
            int t=s[i]=='1'?1:0;
            temp+=t*m;
            m*=2;
        }
     //   cout<<temp;
        if(temp<p&&mp[temp]==0){
            cnt++;
        }
        mp[temp]=1; m/=2;
        for(int i=k;i<s.size();i++){
            temp-=(s[i-k]-'0')*m;
            temp*=2;
            temp+=(s[i]-'0');
              if(temp<p&&mp[temp]==0){
                   cnt++;
               //   cout<<temp<<endl;
                  mp[temp]=1;
             }
        }
      //  cout<<cnt;
        if(cnt==p)return 1;
        return 0;
    }
};