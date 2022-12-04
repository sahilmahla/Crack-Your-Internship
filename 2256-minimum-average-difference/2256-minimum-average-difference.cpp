class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        // vector<long long int> prefix(n);
        // vector<long long int> suffix(n);
        // prefix[0] = nums[0];
        // for(int i = 1;i<n;i++){
        //     prefix[i] = nums[i] + prefix[i-1];
        // }
        // suffix[n-1] = nums[n-1]; 
        // for(int i = n-2;i>=0;i--){
        //     suffix[i] = nums[i]+suffix[i+1];
        // }
        // for(auto it:prefix){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        //  for(auto it:suffix){
        //     cout<<it<<" ";
        // }
        //cout<<"\n";
        
        long long int ss = 0;
        for(auto it: nums){
            ss += it;
        }
        int index = -1;
        long long int cs = 0;
        vector<long long int> res(n);
        long long int cans = INT_MAX,ans = INT_MAX;
        for(int i = 0;i<n;i++){
            cs += nums[i];
            long long int b = 0;
            if(i+1<n) b = (ss-cs)/(n-i-1);
            cans = abs((cs/(i+1)) - b);
            res[i] = cans;
            //ans = min(ans,cans);
            if(cans<ans){
                index = i;
                ans = cans;
            } 
        }
        // int index = -1;
        // for(int i =0;i<n;i++){
        //     if(res[i]<ans){
        //         index = i;
        //         ans = res[i];
        //     }
        // }
        return index;
    }
};