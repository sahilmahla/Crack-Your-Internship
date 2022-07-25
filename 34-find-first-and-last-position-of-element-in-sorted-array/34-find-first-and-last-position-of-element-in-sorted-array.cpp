class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        
        int l = 0,h = nums.size()-1;
        
        while(l<=h){
            int mid = l+(h-l)/2;
            
            if(target == nums[mid] ){
                res[1] = mid;
                l = mid+1;
            }
            else if(target > nums[mid]){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        l = 0,h = nums.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            // cout<<l<<'ind '<<"\n";
            // if(target == nums[mid]){
            //     cout<<nums[mid-1]<<"-"<<mid<<"-"<<nums[mid]<<"\n";
            // }
            if(target == nums[mid]){
                
                res[0] = mid;
                h = mid-1;
            }
            else if(target > nums[mid]){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }        
        
        
        return res;
    }
};