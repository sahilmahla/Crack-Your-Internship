class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int third_ele = INT_MIN;
        for(int i = nums.size()-1;i>=0;i--){
            int it = nums[i];
            if(it<third_ele) return true;
            while(!st.empty() && st.top() < it){
                third_ele = st.top();
                st.pop();
            }
            st.push(it);
        }
        return false;
    }
};