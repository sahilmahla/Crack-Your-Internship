// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
 int maxFrequency(string s)
    {
    	string temp;
    	for(int i=1;i<s.size();i++){
    	    if(s.substr(0,i)==s.substr(s.size()-i,i)){
    	       temp=s.substr(0,i);
    	       break;
    	    }
    	}
    	if(temp.size()==0)
    	    return 1;
    	
    	int ans=0;
    	
    	for(int i=0;i<s.size();i++){
    	    if(temp==s.substr(i,temp.size()))
    	           ans++;
    	}
    	
    return ans;
    	
    }
};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
   		Solution obj;
   		cout << obj.maxFrequency(str) << "\n";
   	}
    return 0;
}  // } Driver Code Ends