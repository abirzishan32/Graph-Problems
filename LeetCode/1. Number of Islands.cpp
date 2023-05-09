class Solution {
public:

    void bfs(int row, int col, vector <vector <int>> &vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        int n=grid.size();
        int m=grid[0].size();
        queue <pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            if(r+1>=0 && r+1<n && c>=0 && c<m && grid[r+1][c] == '1' && !vis[r+1][c]){
                vis[r+1][c] = 1;
                q.push({r+1, c});
            }

            if(r-1>=0 && r-1<n && c>=0 && c<m && grid[r-1][c] == '1' && !vis[r-1][c]){
                vis[r-1][c] = 1;
                q.push({r-1, c});
            }

            if(r>=0 && r<n && c+1>=0 && c+1<m && grid[r][c+1] == '1' && !vis[r][c+1]){
                vis[r][c+1] = 1;
                q.push({r, c+1});
            }

            if(r>=0 && r<n && c-1>=0 && c-1<m && grid[r][c-1] == '1' && !vis[r][c-1]){
                vis[r][c-1] = 1;
                q.push({r, c-1});
            }



        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int cnt=0;
        vector <vector<int>> vis(n, vector<int> (m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j, vis, grid);
                }
            }
        }
        return cnt;
    }
    
};
