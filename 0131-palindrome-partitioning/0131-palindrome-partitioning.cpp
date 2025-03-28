class Solution {
public:
    bool isPal(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void f(int ind, string &s, vector<string>&ds, vector<vector<string>>&res){
        int n=s.size();
        if(ind==n){
            res.push_back(ds);
            return;
        }

        for(int i=ind; i<n; i++){
            string sub=s.substr(ind,i-ind+1);
            if(isPal(sub)==false) continue;
            ds.push_back(sub);
            f(i+1,s,ds,res);
            ds.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>res;
        vector<string>ds;
        f(0,s,ds,res);
        return res;
    }
};