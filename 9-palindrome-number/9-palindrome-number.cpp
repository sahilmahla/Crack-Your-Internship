class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long int k = 0;
        long long int xx = x;
        long long int i = 0;
        while(x){
            k = (k*10) + x%10 ;
            x = x/10;
            
          //  cout<<k<<" "<<i<<"\n";
            i++;
        }
      //  cout<<xx<<" "<<k;
        return xx==k;
    }
};