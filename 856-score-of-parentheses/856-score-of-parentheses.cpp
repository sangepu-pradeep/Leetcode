class Solution {
public:
     int scoreOfParentheses(string s) {
     int prev=0; int ans=0;
         stack<int>st;
         for(int i=0;i<s.size();i++){
             if(s[i]=='('){
                 st.push(-1); continue;
             }
             int temp=0;
           while(st.size()&&st.top()!=-1){ temp+=st.top();st.pop();} 
             st.pop();
             if(temp==0) temp++;
             else temp*=2;
             if(st.size())st.push(temp);
             else ans+=temp;
         }
         return ans;
    }
};