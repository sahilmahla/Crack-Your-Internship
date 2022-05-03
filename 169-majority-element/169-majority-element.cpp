class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = 0;
        for(auto it:nums){
            if(count<=0){
                ele = it;
            }
            if(it == ele){
                count++;
            }else{
                count--;
            }

        }
        return ele;
    }
};