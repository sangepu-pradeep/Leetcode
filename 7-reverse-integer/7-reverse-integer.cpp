class Solution {
public:
    int reverse(int x) {
         bool b=x<0?1:0;
        x=abs(x);
         string p=to_string(x);
          
            int i=0;int j=p.size()-1;
        while(i<j){
            swap(p[i],p[j]);i++;j--;
        }
            long t=stol(p);
      if(b){
          t*=-1;
          if(t<INT_MIN) return 0;
          return t;
      }
            if(t>INT_MAX) return 0;
            return t;
    }
};