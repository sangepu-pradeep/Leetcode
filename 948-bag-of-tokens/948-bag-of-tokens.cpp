class Solution {
public:
   
    int bagOfTokensScore(vector<int>& t, int p) {
        int i=0; int j=t.size()-1;
        sort(t.begin(),t.end());
        int curr=0;  int ans=0;
        while(i<=j){
            if(p>=t[i]){
                p-=t[i];
                i++;curr++;
            }
            else if(curr){
                curr--;p+=t[j];j--;
            }else break;
            
            ans=max(ans,curr);
        }
        return ans;
    }
};