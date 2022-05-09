// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
 bool isValid(int ni, int nj, int n)
    {
        return ni >= 0 && ni < n && nj >= 0 && nj < n;
    }
    double findProb(int N, int start_x, int start_y, int steps)
    {
        vector<vector<double>> curr(N, vector<double>(N, 0.0)), next(N,    vector<double>(N, 0.0));
        double ans = 0.0;
        curr[start_x][start_y] = 1.0;
        for (int m = 1; m <= steps; m++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (curr[i][j] != 0.0)
                    {
                        int ni = 0, nj = 0;
                        ni = i - 2;
                        nj = j + 1;
                        if (isValid(ni, nj, N))
                            next[ni][nj] += curr[i][j] * 0.125;
                        ni = i - 1;
                        nj = j + 2;
                        if (isValid(ni, nj, N))
                            next[ni][nj] += curr[i][j] * 0.125;
                        ni = i + 1;
                        nj = j + 2;
                        if (isValid(ni, nj, N))
                            next[ni][nj] += curr[i][j] * 0.125;
                        ni = i + 2;
                        nj = j + 1;
                        if (isValid(ni, nj, N))
                            next[ni][nj] += curr[i][j] * 0.125;
                        ni = i - 1;
                        nj = j - 2;
                        if (isValid(ni, nj, N))
                            next[ni][nj] += curr[i][j] * 0.125;
                        ni = i + 1;
                        nj = j - 2;
                        if (isValid(ni, nj, N))
                            next[ni][nj] += curr[i][j] * 0.125;
                        ni = i + 2;
                        nj = j - 1;
                        if (isValid(ni, nj, N))
                            next[ni][nj] += curr[i][j] * 0.125;
                        ni = i - 2;
                        nj = j - 1;
                        if (isValid(ni, nj, N))
                            next[ni][nj] += curr[i][j] * 0.125;
                    }
                }
            }
            curr = next;
            next = vector<vector<double>>(N, vector<double>(N, 0.0));
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ans += curr[i][j];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends