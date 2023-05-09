class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int col, vector <vector<int>> &ans){
        int r=sr, c=sc;     //Initial row(sr) and column (sc) ke duita variable r, c te rkhbo
        ans[r][c] = color;  //Initial cell tar color  obviously change hobei naile ques e eita dtona
        int n=image.size(), m=image[0].size();

        if(r+1>=0 && r+1<n && c>=0 && c<m && image[r+1][c] == col && ans[r+1][c] != color){
            dfs(image, r+1, c, color, col, ans);
        }

        if(r>=0 && r<n && c+1>=0 && c+1<m && image[r][c+1] == col && ans[r][c+1] != color){
            dfs(image, r, c+1, color, col, ans);
        }

        if(r-1>=0 && r-1<n && c>=0 && c<m && image[r-1][c] == col && ans[r-1][c] != color){
            dfs(image, r-1, c, color, col, ans);
        }

        if(r>=0 && r<n && c-1>=0 && c-1<m && image[r][c-1] == col && ans[r][c-1] != color){
            dfs(image, r, c-1, color, col, ans);
        }
        
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int col = image[sr][sc];    //Initial color ta ke 'col' variable e rakhbo
        vector <vector<int>> ans = image;   //Ans vector
        dfs(image, sr, sc, color, col, ans); //Calling the dfs func
        return ans;
    }
};
