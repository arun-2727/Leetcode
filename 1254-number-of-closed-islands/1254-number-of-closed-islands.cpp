class Solution {
    bool dfs(vector<vector<int>>&grid, int i,int j, int n, int m)
    {
        if(i<0 || i>=n || j<0 || j>=m )return false;
        if(grid[i][j]==1)return true;
        grid[i][j]=1;
        bool down=dfs(grid,i+1,j,n,m);
        bool up=dfs(grid,i-1,j,n,m);
        bool right=dfs(grid,i,j+1,n,m);
        bool left=dfs(grid,i,j-1,n,m);
        
        return up&&right&&left&&down;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    if(dfs(grid,i,j,n,m))cnt++;

                }

            }
        }
        return cnt;
    }
};