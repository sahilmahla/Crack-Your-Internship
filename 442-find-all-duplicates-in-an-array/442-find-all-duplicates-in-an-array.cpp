class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        if(n==1) return v;
        for(int i = 0;i<n;i++){
            
            if(nums[abs(nums[i])-1] < 0){
                v.push_back(abs(nums[i]));
            }
            else{
                nums[abs(nums[i])-1] *= -1;
            }
        }
        return v;
    }
};