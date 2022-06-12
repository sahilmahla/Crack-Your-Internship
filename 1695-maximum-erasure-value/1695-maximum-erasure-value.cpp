class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 1;
        int sum = nums[i];
        int ms = sum;
        set<int> st;
        st.insert(nums[0]);
        while(i<n-1 && j<n){
            
            bool is_in  = st.find(nums[j]) != st.end();
            
            if(!is_in){
                sum += nums[j];
                st.insert(nums[j]);
                j++;
                ms = max(ms,sum);
            }else{
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            
        }
        
        return ms;
    }
};