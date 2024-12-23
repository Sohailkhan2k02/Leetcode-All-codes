/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int cnt=0;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int N=q.size();
            vector<int>temp;
            while(N--){
                TreeNode* curr=q.front(); q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                temp.push_back(curr->val);
            }
            unordered_map<int,int>mpp;
            vector<int>sorted=temp;
            sort(sorted.begin(),sorted.end());
            for(int i=0;i<temp.size(); i++){
                mpp[temp[i]]=i;
            }
            for(int i=0; i<temp.size(); i++){
                if(temp[i]!=sorted[i]){
                    cnt++;
                    int correctIdx=mpp[sorted[i]];
                    mpp[temp[i]]=correctIdx;
                    mpp[sorted[i]]=i;
                    swap(temp[correctIdx],temp[i]);
                }
            }
            level++;
        }
        return cnt;
    }
};