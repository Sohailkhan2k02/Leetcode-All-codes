class Solution {
public:
    void f(int ind, vector<int>nums, vector<vector<int>>&res){
        int n=nums.size();
        if(ind==n){
            res.push_back(nums);
            return;
        }

        // unordered_set<int>st;

        for(int i=ind; i<n; i++){
            // if(st.find(nums[i])!=st.end()) continue;
            // st.insert(nums[i]);
            if(i!=ind && nums[i]==nums[ind]) continue;
            swap(nums[ind],nums[i]);
            f(ind+1,nums,res);
            // swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        f(0,nums,res);
        return res;
    }
};