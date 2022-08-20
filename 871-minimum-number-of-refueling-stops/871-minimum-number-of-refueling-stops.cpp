class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int count=0; 
        int maxWeCanReach=startFuel;
        int index=0;
        priority_queue<int>maxHeap; 
        
        while(maxWeCanReach<target) 
        {
         while(index<stations.size() && stations[index][0]<=maxWeCanReach)
            {
                maxHeap.push(stations[index][1]);
                index++;
            }
            
            if(maxHeap.empty()) 
                return -1;
            
            int getMaxFuel=maxHeap.top();
            maxHeap.pop();
            
            maxWeCanReach +=getMaxFuel;
            count++;
        }
        
        return count;
    }
};