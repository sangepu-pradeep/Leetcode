class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>vis(26);vector<string>ans;
        for(auto a:words2){
            vector<int>temp(26);
            for(auto t:a){
                temp[t-'a']++;
            }
            for(int i=0;i<26;i++){
                vis[i]=max(vis[i],temp[i]);
            }
        }
        for(auto a:words1){
            bool b=0;
            vector<int>temp(26);
            for(auto t:a){
             temp[t-'a']++;
            }
            for(int i=0;i<26;i++){
                if(temp[i]<vis[i]){b=1;break;}
            }
            if(b==0) ans.push_back(a);
        }
        return ans;
    }
};