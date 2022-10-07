class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<isConnected[i].size();j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        
        vector<int> visited(n,-1);
        vector<int> res;
        int count = 0;
        queue<int> q;
        
        for(int i = 0;i<n;i++){
            
            if(visited[i] == -1){
                count++;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    res.push_back(node);
                    for(auto it:adj[node]){
                        if(visited[it] == -1){
                            visited[it] = 1;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return count;
    }
};