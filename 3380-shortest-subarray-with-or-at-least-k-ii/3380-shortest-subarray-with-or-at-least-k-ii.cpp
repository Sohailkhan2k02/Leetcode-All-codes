class Solution {
public:
    void f1(int &val,int &_or,vector<int>&mpp){
        _or=_or|val;
        for(int i=0; i<30; i++){
            if(val&(1<<i)){
                mpp[i]+=1;
            }
        }
    }
    void f2(int &val, int &_or, vector<int>&mpp){
        for(int i=0; i<30; i++){
            if(val&(1<<i)){
                mpp[i]-=1;
            }
            if(mpp[i]==0) _or=_or&(~(1<<i));
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        vector<int>mpp(30,0);
        int len=INT_MAX,_or=0;
        while(j<n){
            f1(nums[j],_or,mpp);
            while(i<=j && _or>=k){
                len=min(len,j-i+1);
                f2(nums[i],_or,mpp);
                i++;
            }
            j++;
        }
        return len==INT_MAX?-1:len;
    }
};