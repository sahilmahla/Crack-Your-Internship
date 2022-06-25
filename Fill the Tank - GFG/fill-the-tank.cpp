// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
	static const int N = 1e5 + 1;
	int n ;
	unordered_map<int, vector<int>> gr;
	bool flg = 0;

	long long dfs(int curr, int par, int* cap) {
		long long ans = 0;
		long long children = 0;
		for (int x : gr[curr]) {
			if (x != par) {
				children++;
				long long re = dfs(x, curr, cap);
				if (re > 1e18) {
					flg = 1;
				}
				if (flg) return ans;
				ans = max(ans, re);
			}
		}
		long long res = cap[curr - 1];
		res += (children * ans);
		return res;
	}

	long long minimum_amount(vector<vector<int>> &Edges, int n, int start, int *cap) {
		// Code here
		this->n = n;
		// build graph
		for (vector<int> edge : Edges) {
			int s = edge[0], e = edge[1];
			gr[s].push_back(e);
			gr[e].push_back(s);
		}
		long long res = dfs(start, -1, cap);
		if (res > 1e18 || flg) return -1;
		return res;
	}
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends