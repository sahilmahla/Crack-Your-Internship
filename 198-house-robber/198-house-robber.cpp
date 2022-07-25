class Solution {
public:
    int dp[105];
    int fun(vector<int>& nums,int k){
        if(k==0){
            return 0;
        }
        if(k==1){
            return nums[k-1];
        }
        if(dp[k] != -1) return dp[k];
        return dp[k] = max(nums[k-1]+fun(nums,k-2),fun(nums,k-1));
    }
    int rob(vector<int>& nums) {
        
        int k = nums.size();
        memset(dp, -1, sizeof(dp));
        return fun(nums,k);
        
    }
};