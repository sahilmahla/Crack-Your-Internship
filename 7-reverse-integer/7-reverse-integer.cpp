class Solution {
public:
    int reverse(int x) {
        bool f = false;
        if(x<0)f = true;
        long long int n = 0;
        while(x){
            n =n*10 + x%10;
            x = x/10;
        }
        if(n<pow(-2,31) || n>pow(2,31))
            return 0;
//         if(f == true) 
//             return -1*n;
        return n;
    }
};