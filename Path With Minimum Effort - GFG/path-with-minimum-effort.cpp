//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        while(!pq.empty()){
            auto it = pq.top();
            
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            if(r== n-1 && c == m-1) return diff;
            for(int i = 0;i<4;i++){
                int nr = r + dr[i];
                int nc = c +dc[i];
                if(nc>=0 && nc<m && nr>=0 && nr <n){
                    int newEf = max(abs(heights[r][c] - heights[nr][nc]),diff);
                    if(newEf < dist[nr][nc]){
                        dist[nr][nc] = newEf;
                        pq.push({newEf,{nr,nc}});
                        
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends