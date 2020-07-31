class Solution
{
public:
    int ans = 0, m, n;
    int numIslands(vector<vector<char> > &grid)
    {
        m = grid.size();
        if (!m)
            return 0;
        n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1')
                {
                    ans++;
                    bfs(i, j, grid);
                }
        return ans;
    }
    void bfs(int i, int j, vector<vector<char> > &grid)
    {
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1')
            bfs(i - 1, j, grid);
        if (j - 1 >= 0 && grid[i][j - 1] == '1')
            bfs(i, j - 1, grid);
        if (i + 1 < m && grid[i + 1][j] == '1')
            bfs(i + 1, j, grid);
        if (j + 1 < n && grid[i][j + 1] == '1')
            bfs(i, j + 1, grid);
    }
};