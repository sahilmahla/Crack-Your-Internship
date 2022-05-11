// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
string largestNumber(int n, int sum)
    {
        int i;
        string str;
        if(sum/9 > n )
        return "-1";
        else
        {
        int cnt=0;
        int d=sum/9;
        for(int i=0; i<sum/9; i++)
        { 
            str+="9";
            cnt++;
        }
        int r=sum%9;
        
        if(r!=0)
        {
        string s=to_string(r);
        str=str+s;
        d++;
        cnt++;
        }
        for(int i=0; i<n-d; i++)
        {
            str=str+ "0";
            cnt++;
        }
        if(cnt>n)
        return "-1";
        else
        return str;
        }
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends