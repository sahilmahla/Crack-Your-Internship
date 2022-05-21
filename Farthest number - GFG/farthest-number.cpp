// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    vector<int> farNumber(int n,vector<int> arr){
        //code here
        int s[n];
        s[n-1] = arr[n-1];
        
        for(int i = n-2;i>=0;i--){
            s[i] = min(s[i+1],arr[i]);
        }
        vector<int> v;
        for(int i = 0;i<n;i++){
            int l = i+1,h = n-1,ans = -1;
            
            while(l<=h){
                int mid = l+(h-l)/2;
                
                if(s[mid]<arr[i]){
                    l = mid+1;
                    ans = mid;
                }else{
                    h = mid-1;
                }
            }
            v.push_back(ans);
        }
        
        return v;
        
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends