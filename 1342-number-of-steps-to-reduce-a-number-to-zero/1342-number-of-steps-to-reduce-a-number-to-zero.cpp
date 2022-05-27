class Solution {
public:
    int numberOfSteps(int num) {
        if(!num) return 0;
        int c1 = 0,c2=0;
        
        while(num){
            if(num&1){
                c1++;
            }else{
                c2++;
            }
            num = num>>1;
        }
        
        return 2*c1-1+c2;
    }
};