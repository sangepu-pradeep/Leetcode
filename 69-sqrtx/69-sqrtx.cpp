class Solution {
public:
    int mySqrt(int x) {
       long l=1; long h=x; long ans=1;
        if(x==0) return 0;
        while(l<=h){
            long mid=(l+h)/2;
           long p=mid;
            if(p==x/mid) return mid;
            else if(p>x/mid)h=mid-1;
            else {l=mid+1;ans=mid;}
          
        }
        return (int)ans;
    }
};