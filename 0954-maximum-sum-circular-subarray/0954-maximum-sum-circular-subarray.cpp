class Solution {
public:
    int f1(vector<int>&nums){
        int maxi=INT_MIN,sum=0;
        for(auto i:nums){
            sum+=i;
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }
    int f2(vector<int>&nums){
        int mini=INT_MAX,sum=0;
        for(auto i:nums){
            sum+=i;
            mini=min(mini,sum);
            if(sum>0) sum=0;
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxi=f1(nums);
        if(maxi<0) return maxi;
        int mnn=f2(nums);
        int t=accumulate(nums.begin(),nums.end(),0);
        int mini=t-mnn;
        return max(maxi,mini);
    }
};