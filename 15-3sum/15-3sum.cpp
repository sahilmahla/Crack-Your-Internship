class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> s;
        int n = nums.size();
        if(n == 0) return s;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<n-2;i++){
       //     if(i > 0 && nums[i] == nums[i - 1])  continue;
            int low = i+1;
            int high = n-1;
        
            while(low<high){
                int two_sum = nums[low] + nums[high]+nums[i];
                
                if(two_sum > 0){
                    high--;
                }
                else if(two_sum < 0){
                    low++;
                }
                else{
                    vector<int> q;
                    q.push_back(nums[i]);
                    q.push_back(nums[low]);
                    q.push_back(nums[high]);
                    s.push_back(q);
                    
                    while(low<high && nums[low] == q[1]) low++;
                    while(low<high && nums[high] == q[2]) high--;
                }
            }
            while(i+1<n && nums[i+1] == nums[i]) i++;
        }
        return s;
    }
};