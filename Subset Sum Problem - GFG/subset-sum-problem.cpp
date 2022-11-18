//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool fun(int i, int sum, vector<int>&arr,vector<vector<int>>&dp){
      
        if(dp[i][sum]==-1){
            if(sum<arr[i-1]){ // Here arr[i-1] is ith element(Si) in array
            dp[i][sum]=fun(i-1,sum,arr,dp);
            }
            else{
                dp[i][sum]=(fun(i-1,sum,arr,dp) || fun(i-1,sum-arr[i-1],arr,dp));
            }
        }
        return dp[i][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
       int n=arr.size();
       vector<vector<int>>dp(n+1,vector<int>(sum+1));
       for(int i=0;i<=n;i++){
           for(int j=0;j<=sum;j++){
               if(i==0){
                   if(j==0) dp[i][j]=1;
                   else dp[i][j]=0;
               }else dp[i][j]=-1; // Here -1 is what I treat as empty
           }
       }
        return fun(n,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends