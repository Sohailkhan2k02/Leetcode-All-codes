class Solution {
public:
    const int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int total = 0;
        vector<int> pow2(n+1,1);
        for(int i = 1;i <= n;i++){
            pow2[i] = (pow2[i-1] * 2LL) % mod;
        }
        for(int i = 0;i < nums.size();i++){
            int pres = nums[i];
            int lo = i,hi = n-1,mid,ans = -1;
            while(lo <= hi){
                mid = (lo + hi)/2;
                if(nums[i] + nums[mid] <= target){
                    ans = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            if(ans == -1) continue;
            // cout<<i<<" "<<ans<<endl;
            int res = pow2[ans - i];
            total = (total % mod + res % mod) % mod;
        }
        return total;
    }
};