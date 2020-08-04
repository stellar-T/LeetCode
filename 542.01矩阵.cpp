//多元路径广度优先搜索
class Solution
{
public:
    queue<vector<int> > po;
    vector<vector<int> > updateMatrix(vector<vector<int> > &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > ans(m, vector<int>(n, 0));
        int depth = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    ans[i][j] = 0;
                    if (i - 1 >= 0 && matrix[i - 1][j] == 1 && ans[i - 1][j] == 0)
                        po.push({i - 1, j});
                    if (j - 1 >= 0 && matrix[i][j - 1] == 1 && ans[i][j - 1] == 0)
                        po.push({i, j - 1});
                    if (i + 1 < m && matrix[i + 1][j] == 1 && ans[i + 1][j] == 0)
                        po.push({i + 1, j});
                    if (j + 1 < n && matrix[i][j + 1] == 1 && ans[i][j + 1] == 0)
                        po.push({i, j + 1});
                }
            }
        while (!po.empty())
        {
            int size = po.size();
            for (int k = 0; k < size; k++)
            {
                int i = po.front()[0], j = po.front()[1];
                po.pop();
                if (ans[i][j])
                    continue;
                ans[i][j] = depth;
                if (i - 1 >= 0 && matrix[i - 1][j] == 1 && ans[i - 1][j] == 0)
                    po.push({i - 1, j});
                if (j - 1 >= 0 && matrix[i][j - 1] == 1 && ans[i][j - 1] == 0)
                    po.push({i, j - 1});
                if (i + 1 < m && matrix[i + 1][j] == 1 && ans[i + 1][j] == 0)
                    po.push({i + 1, j});
                if (j + 1 < n && matrix[i][j + 1] == 1 && ans[i][j + 1] == 0)
                    po.push({i, j + 1});
            }
            depth++;
        }
        return ans;
    }
};