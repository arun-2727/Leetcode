class Solution {
    void dfs(int i,int j,int m,int n,vector<vector<int>>&grid ,int k,long long& sum)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)return;
        sum+=grid[i][j];
        grid[i][j]=0;
        dfs(i-1,j,m,n,grid,k,sum);
        dfs(i+1,j,m,n,grid,k,sum);
        dfs(i,j-1,m,n,grid,k,sum);
        dfs(i,j+1,m,n,grid,k,sum);
        return ;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]!=0)
                {   
                    long long sum=0;
                    dfs(i,j,m,n,grid,k,sum); 
                    if(sum%k==0)
                    {
                        cnt++;
                    }               
                }
            }
        }
        return cnt;
    }
};