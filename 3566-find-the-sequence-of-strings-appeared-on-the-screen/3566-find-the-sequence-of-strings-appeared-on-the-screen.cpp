class Solution {
public:
    vector<string> stringSequence(string target) {
        int n=target.size();
        string r=target;
        vector<string>res;
        int i=n-1;
        res.push_back(r);
        while(r!=" "){
            while(r[i]!='a'){
                r[i]=((r[i]-'a'-1+26)%26)+'a';
                res.push_back(r);
            }
            r.pop_back();
            if(r!=""){
                res.push_back(r);
            }
            if(i>=0){ 
                i--;
            }
            if(i<0) break;
        }
        sort(res.begin(),res.end());
        return res;
    }
};