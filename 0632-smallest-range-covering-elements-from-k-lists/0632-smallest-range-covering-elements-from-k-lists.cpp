class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        int maxi=INT_MIN,mini=INT_MAX;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i][0],{i,0}});
            maxi=max(maxi,nums[i][0]);
        }
        mini=pq.top().first;
        int a=mini,b=maxi;
        while(pq.size()==n){
            int val=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(col+1<nums[row].size()){
                pq.push({nums[row][col+1],{row,col+1}});
                maxi=max(maxi,nums[row][col+1]);
                mini=pq.top().first;

                if(b-a>maxi-mini){
                    a=mini;
                    b=maxi;
                }
            }
        }
        return {a,b};
    }
};