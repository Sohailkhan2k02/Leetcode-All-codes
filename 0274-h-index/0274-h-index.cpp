class Solution {
public:
    bool f(int h, vector<int>&citations, int n){
        int cnt=0;
        for(int i=0; i<n; i++){
            if(citations[i]>=h){
                cnt++;
            }
            if(cnt>=h) return true;
        }
        return false;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int l=1,h=*max_element(citations.begin(),citations.end());
        int res=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(f(m,citations,n)){
                res=m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return res;
    }
};