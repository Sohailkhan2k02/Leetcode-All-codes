class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        for(int mask=0; mask<1<<n; mask++){
            vector<int>ds;
            for(int i=0; i<n; i++){
                if(mask&(1<<i)){
                    ds.push_back(nums[i]);
                }
            }
            st.insert(ds);
        }
        vector<vector<int>>res(st.begin(),st.end());
        return res;
    }
};