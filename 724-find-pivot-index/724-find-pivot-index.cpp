class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        long long int sum =  nums[0];
        vector<int> pre(n);
        
        pre[0] = nums[0];
        for(int i = 1;i<n;i++){
            pre[i] = pre[i-1]+nums[i];
            sum += nums[i];
        }
        for(int i=0;i<n;i++){
            long long int l = 0;
            if(i>=1) l = pre[i-1];
            long long int r = sum-pre[i];
            if(l == r){
                return i;
            }
        }     
        return -1;
    }
};