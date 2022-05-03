class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n==0) return res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int front = j+1;
                int back = n-1;
                int curtarget = target - nums[i] - nums[j];
                while(front<back){
                    int two_sum = nums[front]+nums[back];
                    
                    if(two_sum > curtarget){
                        back--;
                    }
                    else if(two_sum < curtarget){
                        front++;
                    }
                    else{
                        vector<int> q;
                        q.push_back(nums[i]);
                        q.push_back(nums[j]);
                        q.push_back(nums[front]);
                        q.push_back(nums[back]);
                        res.push_back(q);
                        
                        while(front<back && nums[front] == q[2]) ++front;
                        while(front<back && nums[back] == q[3]) --back;
                    }
                    
                }
                while(j + 1 < n && nums[j + 1] == nums[j]) ++j;
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return res;
    }
};