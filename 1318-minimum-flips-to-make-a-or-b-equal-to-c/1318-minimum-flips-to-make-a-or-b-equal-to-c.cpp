class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        for(int i=0;i<31;i++){
            int a1=(a>>i)&(1);
            int b1=(b>>i)&(1);
            int c1=(c>>i)&(1);
            if(c1!=(a1|b1)){
               // cout<<c1<<" "<<a1<<" "<<b1<<endl;
                if(c1==0) cnt+=(a1+b1);
                else cnt++;
            }
        }
        return cnt;
    }
};