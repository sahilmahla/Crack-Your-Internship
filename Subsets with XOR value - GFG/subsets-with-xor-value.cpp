// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    int helper(vector<int>arr,vector<vector<int>>&dp,int K,int i)
    {
        if(i==arr.size())
            return K==0;
        if(dp[i][K]!=-1)
            return dp[i][K];
        
        else
        {
            int op1=helper(arr,dp,K,i+1);
            int op2=helper(arr,dp,K^arr[i],i+1);
            return dp[i][K]=op1+op2;
        }
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        vector<vector<int>>dp(N,vector<int>(1000,-1));
        
        return helper(arr,dp,K,0);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends