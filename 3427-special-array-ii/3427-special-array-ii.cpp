class Solution {
public:
    // I WAS FED UP WITH RUNTIME ERROR WHAT I DID WAS CORRECT BUT I DIDNT TAKE CARE OF 
    // NEGATIVE INDEXES IN THE PREFIX ARRAY AS WE ARE FINDING THE LENGTH SO
    // PRE[V-1] CAN BE NEGATIVE AS THE QUERIES CAN BE 0 SO PRE[0-1] CAN CAUSE RUNTIME EROR
    // SO THEREFORE WE HAVE INCLUDE IF PRE [V-1] IS <0 THEN 0 ELSE TAKE THAT INDEX
    // SAME WITH PRE[U-1];
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>pre(n,0);
        for(int i=0; i<n-1; i++){
            if((nums[i]%2==0) == (nums[i+1]%2==0)){
                pre[i]=1;
            }
        }
        for(int i=1; i<n; i++){
            pre[i]+=pre[i-1];
        }
        // for(int i=0; i<n; i++){
        //     cout<<pre[i]<<" ";
        // }

        vector<bool>res(queries.size(),true);
        for(int i=0; i<queries.size();i++){
            int u=queries[i][0],v=queries[i][1];
            int pre1=(u>0)? pre[u-1]:0;
            int pre2=(v>0)? pre[v-1]:0;
            if(pre2-pre1>0){
                res[i]=false;
            }
        }
        return res;
    }
};