// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
int findSubString(string str)
    {
        // Your code goes here 
        int n = str.length();
        int ans = n, j = 0;
        
        map<char, int> mp, T;
        
        for(char it : str)
        mp[it]++;
        
        for(int i=0; i<n; i++)
        {
            T[str[i]]++;
            
            while(mp.size() == T.size())
            {
                ans = min(ans, i-j+1);
                T[str[j]]--;
                
                if(T[str[j]] == 0)
                T.erase(str[j]);
                
                j++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends