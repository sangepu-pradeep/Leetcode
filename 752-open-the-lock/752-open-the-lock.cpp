class Solution {
public:
    int dir[2]={1,-1};
//     int fun(string &temp, string &target, unordered_map<string,int>&mp, unordered_map<string,int>&vis){
//         if(temp==target) return 0;

//      int ans=INT_MAX;
       
//         return ans;
        
//     }
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,int>mp;
        for(auto a:deadends)mp[a]=1;
        unordered_map<string,int>vis;
   
    queue<string>q;  int dis=0;
        if(mp["0000"]) return -1;
        q.push("0000");
        while(q.size()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                 auto a=q.front(); 
                if(a==target) return dis;
                q.pop();
                
                for(int i=0;i<4;i++){
                    for(int j=0;j<2;j++){
                        int p=a[i]-'0';
                        char c=((p+dir[j]+10)%10)+'0';
                        a[i]=c;
                        if(vis[a]==0&&mp[a]==0){
                            vis[a]=1;q.push(a);
                        }
                        a[i]=p+'0';
                    }
                }
            }
            dis++;
        }
        if(q.size()) return dis;
        return -1;
       
    }
};