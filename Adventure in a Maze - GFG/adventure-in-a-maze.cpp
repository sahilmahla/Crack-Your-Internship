// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
vector<int> FindWays(vector<vector<int>>&m) {
		int n = m.size();
		int mod = 1e9 + 7;
		vector < vector<pair<int, int>>> dp(n, vector < pair<int, int>>(n, {0, 0}));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				//Intially We are at this point
				if (i == 0 && j == 0) {
					dp[i][j].first = 1;
					dp[i][j].second = m[i][j] ;
				}
				//first row
				else if (i == 0) {
//we could reached this point according to matrix as it is not 2.
//we need to check whether left previous is possiblicy reached.
					if (m[i][j - 1] != 2 && dp[i][j - 1].first != 0) {
						dp[i][j].first = dp[i][j - 1].first;
						dp[i][j].second += dp[i][j - 1].second + m[i][j];
					}
//else condition
//if  left previous is 2 we would have not reached this place.
//so both their values are already set zero in defination.Will remain same
				}
//first coloum
				else if (j == 0) {
//we could reached this point according to matrix as it is not 2.
//we need to check whether top previous is possiblicy reached.
					if (m[i - 1][j] != 1 && dp[i - 1][j].first != 0) {
						dp[i][j].first = dp[i - 1][j].first;
						dp[i][j].second += dp[i - 1][j].second + m[i][j];
					}
//else condition
//if  top previous is 1 we would have not reached this place.
//so both their values are already set zero in defination.Will remain same
				}
//Other than first row and coloum
				else {
//check prev top is possible to reach
//Also check prev top element is reached.
					if (m[i - 1][j] != 1 && dp[i - 1][j].first != 0) {
						dp[i][j].first += dp[i - 1][j].first;
						dp[i][j].second = max(dp[i][j].second, dp[i - 1][j].second + m[i][j]);
					}
//check prev left is possible to reach
//Also check prev left element is reached.
					if (m[i][j - 1] != 2 && dp[i][j - 1].first != 0) {
						dp[i][j].first += dp[i][j - 1].first;
						dp[i][j].second = max(dp[i][j].second, dp[i ][j - 1].second + m[i][j]);

					}
				}
				dp[i][j].first %= mod;
				dp[i][j].second %= mod;
			}
		}

		return {dp[n - 1][n - 1].first, dp[n - 1][n - 1].second};
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends