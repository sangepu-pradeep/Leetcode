class Solution {
public:
    double fun(double x, int n){
        if(n==0) return (double)1;
        if(n%2==0) {
            double t=fun(x,n/2);
            return t*t;
        }
        return x*fun(x,n-1);
    }
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n==INT_MIN){
            return (1.0/x)*myPow(x,n+1);
        }
        if(n<0) return 1.0/fun(x,-n);
        return fun(x,n);
    }
};