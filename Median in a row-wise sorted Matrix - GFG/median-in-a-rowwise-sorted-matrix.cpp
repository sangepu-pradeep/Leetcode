//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
  bool fun(int mid,vector<vector<int>> &m, int k){
      int r=m.size(); int c=m[0].size(); int sum=0;
      for(int i=0;i<r;i++){
          int t=upper_bound(m[i].begin(),m[i].end(),mid)-m[i].begin();
          sum+=t;
      }
      if(sum>k) return 1;
      return 0;
  }
    int median(vector<vector<int>> &m, int R, int C){
      int l=1; int h=2000;
      int ans=1; int k=(R*C)/2;
      while(l<=h){
          int mid=(l+h)/2;
          if(fun(mid,m,k)){
              ans=mid; h=mid-1;
          }
          else l=mid+1;
      }
      return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends