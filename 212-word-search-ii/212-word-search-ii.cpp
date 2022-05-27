
class Solution {
public:
    struct Trie{
        int e;Trie* v[26];
        Trie(){
            for(int i=0;i<26;i++)v[i]=NULL;
           e=0;
        }
    };
    Trie*root;
    int dirx[4]={1,-1,0,0};
    int diry[4]={0,0,-1,1};
    bool valid(int x, int y, int r, int c){
        return (x<r&&x>=0&&y<c&&y>=0);
    }
    void dfs(int i, int j, vector<vector<char>>&b,vector<vector<int>>&vis, Trie*temp,int r, int c, int d){
        if(d==10) return;
        vis[i][j]=1;
        int ind=b[i][j]-'a';
        if(temp->v[ind]==NULL)temp->v[ind]=new Trie();
        temp=temp->v[ind];
        for(int t=0;t<4;t++){
            int x=i+dirx[t]; int y=j+diry[t];
            if(valid(x,y,r,c)&&vis[x][y]==0)dfs(x,y,b,vis,temp,r,c,d+1);
        }
        vis[i][j]=0;
    }
  void fun(vector<vector<char>>&b){
      int r=b.size(); int c=b[0].size();
      vector<vector<int>>vis(r+1,vector<int>(c+1));
      Trie*temp=root;
      for(int i=0;i<r;i++){
          for(int j=0;j<c;j++){
              dfs(i,j,b,vis,temp,r,c,0);
          }
      }
  }
    bool find(Trie*root, string&a){
        Trie*temp=root;
        for(int i=0;i<a.size();i++){
            int ind=a[i]-'a';
            if(temp->v[ind]==NULL) return 0;
            temp=temp->v[ind];
        }
        if(temp==NULL) return 0;
        return 1;
    }
   
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        int r=b.size(); int c=b[0].size(); vector<string>ans;
        root=new Trie();
        fun(b);
      
        for(auto a:w){
            if(find(root,a))
            ans.push_back(a);
        }
        return ans;
    }
};