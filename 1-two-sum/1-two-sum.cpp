class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> output;int c=0;
     for(int i=0;i<nums.size();i++)
        {   
            int k=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==target-k)
                {
                    c=1;
                    output.push_back(i);
                    output.push_back(j);
                    break;
                }
            }

            if(c==1)
            {
                break;
            }
        }

        return output;        
    }
};