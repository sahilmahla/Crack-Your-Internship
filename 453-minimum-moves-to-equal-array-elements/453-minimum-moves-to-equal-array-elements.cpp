class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int m = nums[0];
        int c = 0;
        
        for(auto it:nums){
            c+= it-m;
        }
        return c;
    }
};