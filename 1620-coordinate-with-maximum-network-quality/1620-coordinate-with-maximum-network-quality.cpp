class Solution {
public:
   
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