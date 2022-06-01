class Solution {
public:
    int diry[8]={1,1,-1,-1,2,2,-2,-2};
    int dirx[8]={2,-2,2,-2,1,-1,1,-1};
    int minKnightMoves(int x1, int y1) {
       queue<pair<int,int>>q;
        map<pair<int,int>,bool>mp; int cnt=0;
        q.push({0,0});//mp[{0,0}]=1;
        bool vis[607][607];
        memset(vis,0,sizeof(vis));
        if(x1==1&&y1==1)return 2;
        while(q.size()){
            int t=q.size();
            while(t--){
                auto a=q.front();q.pop();
            if(a.first==x1&&a.second==y1) return cnt;
            for(int i=0;i<8;i++){
                int x=a.first+dirx[i];
                int y=a.second+diry[i];
                //if(x1*x<0||y1*y<0)continue;
                 int g=x; int h=y;
                 g=x<0?abs(x)+301:x;
                h=y<0?abs(y)+301:y;
                if(vis[g][h]==0){
                    q.push({x,y});
                   vis[g][h]=1;
                }
            }
            
          }
            cnt++;
        }
        return cnt;
    }
};