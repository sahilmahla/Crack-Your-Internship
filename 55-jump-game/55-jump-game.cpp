class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxRange = 0;
        if(nums.size() == 1) return true;
        for(int i = 0;i<nums.size()-1;i++){
            maxRange = max(maxRange,nums[i]+i);
            
            if(maxRange == i){
                return false;
            }
        }
        return true;
    }
};