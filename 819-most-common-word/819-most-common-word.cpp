class Solution {
public:
    bool valid(char c){
       // return c==' '||c==';'||c==','||c=='!'||c=='''||c=='?'||c=='.';
        return isalpha(c)==0;
    }
    string mostCommonWord(string p, vector<string>& banned) {
        unordered_map<string,int>mpb;
        for(auto a:banned){
            mpb[a]++;
        }
        
        unordered_map<string,int>mp;
      for(int i=0;i<p.size();i++){
          if(valid(p[i])==0){
              string temp;
              while(i<p.size()&&valid(p[i])==0){
                 // if(isalpha(p[i])==0){i++;continue;}
                  char c=tolower(p[i]);
                  temp.push_back(c);i++;
              }
              
             if(mpb[temp]==0) mp[temp]++; 
          }         
      }  
        int mx=0;string ans;
        for(auto a:mp){
            if(mx<a.second){
                ans=a.first;mx=a.second;
            }
        }
        return ans;
    }
};