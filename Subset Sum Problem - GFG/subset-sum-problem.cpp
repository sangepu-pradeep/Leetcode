//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool M_compute(int i, int sum, vector<int>& arr,vector<vector<int>>& M){
      
        if(M[i][sum]==-1){
            if(sum<arr[i-1]){ // Here arr[i-1] is ith element(Si) in array
            M[i][sum]= M_compute(i-1,sum,arr,M);
            }
            else{
          M[i][sum]=(M_compute(i-1,sum,arr,M) || M_compute(i-1,sum-arr[i-1],arr,M));
            }
        }
        return M[i][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
       int n=arr.size();
       vector<vector<int>>M(n+1,vector<int>(sum+1));
       for(int i=0;i<=n;i++){
           for(int j=0;j<=sum;j++){
               if(i==0){
                   if(j==0) M[i][j]=1;
                   else M[i][j]=0;
               }else M[i][j]=-1; // Here -1 is what I treat as empty
           }
       }
        return M_compute(n,sum,arr,M);
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