class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int n=image.size(),m=image[0].size();
        q.push({sr,sc});
        int c=image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            vis[i][j]=1;

            for(int k=0; k<4; k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !vis[nrow][ncol] && image[nrow][ncol]==c){
                    vis[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        image[sr][sc]=color;
        return image;
    }
};