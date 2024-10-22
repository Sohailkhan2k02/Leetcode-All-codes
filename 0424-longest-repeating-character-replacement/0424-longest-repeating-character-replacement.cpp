class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        // unordered_map<char,int>mpp;
        int mpp[26]={0};
        int i=0,j=0;
        int mxx=0,len=0;
        while(j<n){
            mpp[s[j]-'A']++;
            mxx=max(mxx,mpp[s[j]-'A']);
            while((j-i+1)-mxx>k){
                mpp[s[i]-'A']--;
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};