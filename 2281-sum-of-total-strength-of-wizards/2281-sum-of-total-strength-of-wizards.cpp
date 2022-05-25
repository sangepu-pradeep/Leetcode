class Solution {
public:
  //  using long=int;
  //  typedef int long;
    int totalStrength(vector<int>& s) {
        int n=s.size();long ans=0;
        vector<long>ls(n+1); vector<long>rs(n+1);
        vector<long>lm(n+1);vector<long>rm(n+1);int mod=1e9+7;
        for(long i=1;i<=s.size();i++){
           ls[i]=(ls[i-1]+s[i-1])%mod;
            lm[i]=(lm[i-1]%mod+((i)*s[i-1])%mod)%mod;
        }
        for(long i=n-1;i>=0;i--){
            rs[i]=(rs[i+1]+s[i])%mod;
            rm[i]=rm[i+1]%mod+((n-i)*s[i])%mod;
        }
       stack<int>st;
       for(int i=0;i<=n;i++){
           while(st.size()&&(i==n||s[st.top()]>=s[i])){
               int pivot=st.top(); st.pop();
               int left=st.size()?st.top()+1:0;
               int right=i-1;
               // left - pivot- right
              long left_sum=(((lm[pivot+1]-lm[left])%mod-((left)*(ls[pivot+1]-ls[left])))%mod+mod)%mod;
               
               long right_sum=(((rm[pivot+1]-rm[right+1])-((n-1)-right)*(ls[right+1]-ls[pivot+1]))%mod+mod)%mod;
             //  cout<<right_sum<<endl;
               long sum=((right_sum*(pivot-left+1))%mod+(left_sum*(right-pivot+1)%mod))%mod;
              // cout<<sum;
               ans=(ans+sum*s[pivot])%mod;
           }
           st.push(i);
       }
        return ans;
    }
};