class Solution {
public:
    int fun(int n){
        int ans=0;
        while(n){
            int p=(n%10);
            ans+=(p*p);
        n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        int a=n; int b=n;
        do{
            a=fun(a);
            b=fun(fun(b));
        }while(a!=b);
            if(a==b&&a!=1) return false;
        return 1;
    }
};