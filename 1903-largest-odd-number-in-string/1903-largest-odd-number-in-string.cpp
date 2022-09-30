class Solution {
public:
    string largestOddNumber(string num) {
        
        int n = num.size();
        string res = "";
        for(int i = n-1;i>=0;i--){
            if( (num[i]-'0') % 2 != 0){
                res = num.substr(0,i+1);
                break;
            }
        }
        
        return res;
    }
};