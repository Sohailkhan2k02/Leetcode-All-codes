class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        if(k==1) return (n*(n+1))/2;
        // unordered_map<int,int>mpp;
        int mpp[26]={0};
        int i=0,j=0;
        int cnt=0;
        while(j<n){
            mpp[s[j]-'a']++;
            while(mpp[s[j]-'a']>=k){
                cnt+=n-j;
                mpp[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};