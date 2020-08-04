class Solution
{
public:
    vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor)
    {
        stack<vector<int> > po;
        po.push({sr, sc});
        int m = image.size(), n = image[0].size(), color = image[sr][sc];
        if (color == newColor)
            return image;
        while (!po.empty())
        {
            int i = po.top()[0], j = po.top()[1];
            po.pop();
            image[i][j] = newColor;
            if (i - 1 >= 0 && image[i - 1][j] == color)
                po.push({i - 1, j});
            if (j - 1 >= 0 && image[i][j - 1] == color)
                po.push({i, j - 1});
            if (i + 1 < m && image[i + 1][j] == color)
                po.push({i + 1, j});
            if (j + 1 < n && image[i][j + 1] == color)
                po.push({i, j + 1});
        }
        return image;
    }
};
class Solution
{
public:
    int color = -1;
    vector<vector<int> > floodFill(vector<vector<int> > &image, int sr, int sc, int newColor)
    {
        int m = image.size(), n = image[0].size();
        if (color == -1)
            color = image[sr][sc];
        if (color == newColor)
            return image;
        image[sr][sc] = newColor;
        if (sr - 1 >= 0 && image[sr - 1][sc] == color)
            floodFill(image, sr - 1, sc, newColor);
        if (sc - 1 >= 0 && image[sr][sc - 1] == color)
            floodFill(image, sr, sc - 1, newColor);
        if (sr + 1 < m && image[sr + 1][sc] == color)
            floodFill(image, sr + 1, sc, newColor);
        if (sc + 1 < n && image[sr][sc + 1] == color)
            floodFill(image, sr, sc + 1, newColor);
        return image;
    }
};