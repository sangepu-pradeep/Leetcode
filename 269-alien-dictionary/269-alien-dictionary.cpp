class Solution {
public:

    map<char,bool> vis; map<char,bool>curr; stack<char>st;
    bool dfs(map<char,vector<char>>&g,char node){
        vis[node]=true;curr[node]=true;
        for(auto it:g[node]){
            if(!vis[it]&&dfs(g,it)) return true;
            else if(curr[it]) return true;
        }
        curr[node]=false;
        st.push(node);
        return false;
        
    }
    string alienOrder(vector<string>& words) {
            map<char,vector<char>> g;
        for(auto i:words){
            for(auto j:i){
               g.insert({j,{}});
            }
        }
       
       for(int i=0;i<words.size()-1;i++){
          string word1=words[i]; string word2=words[i+1]; 
           if(word1.size()>word2.size()&&word1.find(word2)==0){
               return "";
           }
           for(int j=0;j<min(word1.size(),word2.size());j++){
               if(word1[j]!=word2[j]){
                   g[word1[j]].push_back(word2[j]); break;
               }
           }
               
       }
       curr.clear(); vis.clear();
        for(auto node:g){
            vis.insert({node.first,false});
            curr.insert({node.first,false});
        }
        st={};
        for(auto node:g){
            if(!vis[node.first]&&dfs(g,node.first)) return "";
        }
         string ans; 
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};