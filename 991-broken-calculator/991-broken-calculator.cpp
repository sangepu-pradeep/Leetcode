class Solution {
public:
    int fun(int x, int y){
        int cnt=0;
        while(y>x) x=2*x,cnt++;
        
        return x-y+cnt;
    }
    int brokenCalc(int X, int Y) {
     int ans=0;
        while(Y>X){
            ans++;
            if(Y%2==1) Y++;
            else Y/=2;
        }
        return ans+X-Y;
    }
};