class Solution {
public:
    int fun(int n,vector<int>& dp){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        if(n&1 != 0){
            return dp[n] = 1+fun(n/2,dp);
        }else{
            return dp[n] = fun(n/2,dp);
        }
    }
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        vector<int> dp(n+1,-1);
        
        for(int i = 0;i<=n;i++){
            res[i] = fun(i,dp);
        }
        
        return res;
    }
};