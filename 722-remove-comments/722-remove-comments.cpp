class Solution {
public:
      vector<string> removeComments(vector<string>& s) {
       bool l=0; int d=0;vector<string>ans; string prev;
        for(int j=0;j<s.size();j++){
             string temp; bool op=0;
            for(int i=0;i<s[j].size();i++){
                if(s[j][i]=='/'&&i+1<s[j].size()&&s[j][i+1]=='/'&&d==0){
                   
                    break;
                }
               else if(s[j][i]=='/'&&i+1<s[j].size()&&s[j][i+1]=='*'){
                   if(d==1){ continue;}
                    d=1;i++; prev=temp;op=1;temp="";
                }
               else  if(s[j][i]=='*'&&i+1<s[j].size()&&s[j][i+1]=='/'){
                   if(d==0){
                       if(i+2<s[j].size()&&s[j][i+2]=='/'){
                           temp.push_back('*');
                          break; 
                       }else {
                           {temp+="*/";i++;continue;}
                       }
                   }
                    d=0;i++;  op=0; temp=prev;prev="";
                }
                else if(d==0) temp.push_back(s[j][i]);
            }
         
            if(temp.size()&&op==0){
                ans.push_back(temp);
            }
        }
          return ans;
    }
};