class Solution {
public:
    double dis(int x, int y, int i, int j){
         int p=(x-i)*(x-i)+(y-j)*(y-j);
        double t=sqrt(p);
       // t=(int)t;
            return t;
    }
    double fun(vector<vector<int>>&t, int x, int y, int r){
        double ans=0; double uu=(double)r;
        for(auto a:t){
            double d=dis(a[0],a[1],x,y);
            if(d>uu)continue;
           double temp=((double)a[2])/(1.0+dis(a[0],a[1],x,y));
            temp=(int)temp;
            ans+=temp;
        }
      //  ans=(int)ans;
        return ans;
    }
    vector<int> bestCoordinate(vector<vector<int>>& towers, int r) {
       
       int c1=0; int c2=0; int mx=0;
        for(int i=0;i<=50;i++){
            for(int j=0;j<=50;j++){
                int temp=0;
                for(auto a:towers){
                    double d=sqrt(pow(a[0]-i,2)+pow(a[1]-j,2));
                    if(d>r)continue;
                    double rr=(a[2]*1.0)/(1+d);
                    temp+=(int)rr;
                }
                if(mx<temp){
                    mx=temp;c1=i;c2=j;
                }
                
            }
        }
        return {c1,c2};
    }
};