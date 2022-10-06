class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        int i = 0;
        while(i<n){
             if(!st.empty() && st.top() > 0 && asteroids[i]<0 ){
                 if(!st.empty() && abs(st.top()) > abs(asteroids[i])){
                    i++;
                 }
                 else if(!st.empty() && abs(st.top()) == abs(asteroids[i])){
                     st.pop();
                     i++;
                 }
                 else{
                     st.pop();
                 }
             }else{
                 st.push(asteroids[i]);
                 i++;
             }
           
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};