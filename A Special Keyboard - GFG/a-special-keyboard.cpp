// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
         int t=0,c=0;
        for(int i=0;i<S2.size();i++)
        {
            for(int j=0;j<26;j++)
            {
                if(S1[j]==S2[i])
                {
                   t+=abs(j-c);
                   c=j;
                   break;
                }
            }
        }
        return t;       // code here
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends