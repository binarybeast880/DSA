#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> result;
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        string path = "";
        backtrack(m, 0, 0, path);
        sort(result.begin(), result.end());
        return result;
    }

    void backtrack(vector<vector<int>> &grid, int r, int c, string &path)
    {
        if (r < 0 || c < 0 || r > grid.size() - 1 || c > grid[0].size() - 1 || grid[r][c] == 0 || grid[r][c] == -1)
        {
            path.pop_back();
            return;
        }
        int val = grid[r][c];
        grid[r][c] = -1;
        path += 'U';
        backtrack(grid, r - 1, c, path);
        path += 'R';
        backtrack(grid, r, c + 1, path);
        path += 'L';
        backtrack(grid, r, c - 1, path);
        path += 'D';
        backtrack(grid, r + 1, c, path);
        if (r == grid.size() - 1 && c == grid[0].size() - 1)
            result.push_back(path);
        path.pop_back();
        grid[r][c] = val;
    }
};
main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
}