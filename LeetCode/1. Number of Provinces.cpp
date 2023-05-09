class Solution {
public:

    void dfs(int src, vector<vector<int>>&isConnected, vector<bool>& vis) {
        vis[src] = true;
        for(int i=0; i<isConnected[src].size(); i+=1) {
            if(isConnected[src][i] == 1 && vis[i] == false) {
                dfs(i, isConnected, vis);
            }
        }
  }


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector <vector<int>> adj(n);
        vector <bool> vis(n,false);
        
        
        
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, isConnected, vis);
            }
        }
        return cnt;

    }
};
