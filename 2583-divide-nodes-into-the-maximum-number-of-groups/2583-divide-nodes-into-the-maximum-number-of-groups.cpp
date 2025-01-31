class Solution {
    int bfs(int node,vector<vector<int>>& adj){
        int dis=0;
        vector<int>vis(adj.size(),0);
        queue<int>q;
        q.push(node);
        vis[node]=1;

        while(!q.empty()){
            int sz = q.size();
            dis++;
            while (sz--) {
                int node = q.front();
                q.pop();
                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        q.push(it);
                        vis[it]=1;
                    } 
                }
            }
        }
        return dis;
    }
    vector<int> isBipartite(int node,vector<vector<int>>& adj, vector<int>& vis) {
        int clr = 0;
        vector<int>comp;
        queue<int> q;
        q.push(node);
        vis[node] = clr;
        while (!q.empty()) {
            int sz = q.size();
            clr = !clr;
            while (sz--) {
                int node = q.front();
                q.pop();
                comp.push_back(node);
                for (auto it : adj[node]) {
                    if (vis[it] == -1) {
                        vis[it] = clr;
                        q.push(it);
                    } else if (vis[it] == !clr)
                        return {};
                }
            }
        }
            return comp;
        }

    public:
        int magnificentSets(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n + 1);
            for (auto e : edges) {
                int u = e[0], v = e[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            vector<int> vis(n + 1, -1);
            vector<vector<int>>components(n+1);
            for (int i = 1; i <= n; i++) {
                if (vis[i] == -1) {
                    vector<int>comp=isBipartite(i,adj, vis);
                        if(comp.size()==0)
                        return -1;
                    else
                    components.push_back(comp);
                    // cout<<comp.size()<<endl;
                }
            }
            int tot=0;
            for(auto comp:components){
                int maxi=0;
                for(int i:comp){
                    int curr=bfs(i,adj);
                    maxi=max(maxi,curr);
                }
                tot+=maxi;
            }
            return tot;
        }
    };