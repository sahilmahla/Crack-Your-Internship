// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int arr[], int n, int k)
    {
       unordered_map<int,int> um;
       long long count=0;
       
       for(int i=0;i<n;i++)
       {
           arr[i]=arr[i]%k; 
           um[arr[i]]++;
       }

       for(int i=0;i<n;i++)
       {
           if(k-arr[i]<k && arr[i]+arr[i]!=k)
           {
               if(um.find(k-arr[i])!=um.end())
               {
                   count=count+um[k-arr[i]]*um[arr[i]];
                   um.erase(arr[i]);
               }
           }
           else if(k-arr[i]==k || arr[i]+arr[i]==k) 
               {
                   count=count+(um[arr[i]]*(um[arr[i]]-1))/2;
                   um.erase(arr[i]);
               }
           
       }
       return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends