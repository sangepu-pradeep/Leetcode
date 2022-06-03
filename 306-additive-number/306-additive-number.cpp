class Solution {
public:
    bool fun(long f, long s, int i, string &num){
      long ans=f+s;
        if(i>=num.size()) return 0;
        string temp=num.substr(i);
        string fn=to_string(ans);
        if(temp.size()<fn.size()) return 0;
        string ff=temp.substr(0,fn.size());
       // string tt=
       // cout<<ff<<" "<<temp;
        if(fn==ff){
            long h=ans;
       //   cout<<temp<<endl;
            if(i+fn.size()==num.size()) return 1;
            if(num[i+fn.size()]=='0') return 0;
          //  cout<<s<<" "<<h<<endl;
            bool b=fun(s,h,i+fn.size(),num);
            if(b==1) return 1;
        }
        return 0;
    }
    bool isAdditiveNumber(string num) {
        int n=num.size();
          // return fun(1,99,3,num);
       // cout<<b;
       
   // return fun(12,0,3,num);
       for(int i=0;i<min(17,n);i++){
           string p=num.substr(0,i+1);
           if(p.size()>1&&p[0]=='0')continue;
           long f=stol(p);
           for(int j=i+1;j<min(17,n);j++){
             
             string q=num.substr(i+1,j-i);
               if(q.size()>1&&q[0]=='0')continue;
               long s=stol(q);
               //  cout<<f<<" "<<s<<" "<<(j+1)<<endl;
             
              bool b= fun(f,s,j+1,num);
               if(b==1) { return 1;}
           }
       }
        return 0;
    }
};