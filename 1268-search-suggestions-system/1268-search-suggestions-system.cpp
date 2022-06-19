class Solution {
public:
  struct TrieNode{
       vector<int>b;
      TrieNode*a[26];
      TrieNode(){
          for(int i=0;i<26;i++)a[i]=NULL;
      }
  };
    TrieNode*root;
    void insert(string &s, int t){
        TrieNode*temp=root;
        for(auto a:s){
            int ind=a-'a';
            if(temp->a[ind]==NULL) temp->a[ind]=new TrieNode();
            temp=temp->a[ind];
            if(temp->b.size()<3) temp->b.push_back(t);         
        }
    }
   vector<vector<string>>fun(string &s, vector<string>&p){
        vector<vector<string>>ans; TrieNode*temp=root;
        for(auto a:s){
            int ind=a-'a';
            if(temp->a[ind]==NULL) return ans;
            temp=temp->a[ind];
            vector<string>k;
            for(auto h:temp->b) k.push_back(p[h]);
            if(k.size()==0) return ans;
            ans.push_back(k);
        }
       return ans;
    }
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        root=new TrieNode();
        sort(p.begin(),p.end());
        for(int i=0;i<p.size();i++){
            insert(p[i],i);
        }
        auto t= fun(s,p);
        while(t.size()<s.size())t.push_back({});
        return t;
    }
};