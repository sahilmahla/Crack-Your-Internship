class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int n = cardPoints.size();
        int i = 0,j = 0;
         k = n-k;
        if(k == 0)return sum;
        int minSum = INT_MAX,curSum = 0;
        while(j<n){
            curSum += cardPoints[j];
            if((j-i)+1<k){
                j++;
            }else{
                minSum = min(minSum,curSum);
                curSum -=  cardPoints[i];
                i++;
                j++;
            }
        }
        cout<<minSum;
        return sum-minSum;
    }
};