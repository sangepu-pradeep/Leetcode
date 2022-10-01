class Solution {
public:
    double fun(double x, int n){
        if(n==0) return 1;
        if(n==1) return x;
        if(n==-1) return (1/x);
         double t=fun(x,n/2);
        if(n%2==0){
           
            return t*t;
        }
        if(n<0) return (1/x)*t*t;
        return x*t*t;
    }
    double myPow(double x, int n) {
         return fun(x,n);
    }
};