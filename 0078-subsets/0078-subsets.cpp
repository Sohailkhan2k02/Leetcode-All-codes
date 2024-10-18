class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        for(int mask=0; mask<1<<n; mask++){
            vector<int>ds;
            for(int i=0; i<n; i++){
                if(mask&(1<<i)){
                    ds.push_back(nums[i]);
                }
            }
            res.push_back(ds);
        }
        return res;
    }
};