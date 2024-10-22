class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int c=0;
        int i=0,j=0;
        int cnt=0;
        int pre=0;
        while(j<n){
            if(nums[j]%2!=0){
                c++;
                pre=0;
            }
            while(c==k){
                pre++;
                if(nums[i]%2!=0){
                    c--;
                }
                i++;
            }
            cnt+=pre;
            j++;
        }
        return cnt;
    }
};