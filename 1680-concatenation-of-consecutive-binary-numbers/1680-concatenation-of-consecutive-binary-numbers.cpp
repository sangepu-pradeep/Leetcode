class Solution {
public:
    int mod=1e9+7;
    int fun(int n){
        int t=0;
        while(n){
            n/=2;t++;
        }
        return t;
    }
    int concatenatedBinary(int n) {
        long p=1; long ans=0;
        for(int i=n;i>=1;i--){
            ans+=((long)i*p); ans=ans%mod;
           int t=(fun(i));
            p=p*(long)pow(2,t);
            p=p%mod;
        }
        return (int)ans;
    }
};