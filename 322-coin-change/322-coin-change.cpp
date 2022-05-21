class Solution {
public:
    long long int dp[14][100001];
    
    long long int helper(vector<int>& c, int m,int n){
        if(m<0 && n>0) return INT_MAX;
        if(n==0) return 0;
        if(n<0) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n]= min(1+ helper(c,m,n-c[m]),helper(c,m-1,n));
    }
    
    int coinChange(vector<int>& c, int n) {
        int m=c.size();
        dp[m+1][n+1];
        for(int i=0;i<c.size();i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        long long int ans= helper(c,m-1,n);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};