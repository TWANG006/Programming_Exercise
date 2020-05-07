/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
/*Solution 1: flood fill */
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int res = 0;
//         for (int i = 0; i < grid.size(); i++)
//             for (int j = 0; j < grid[0].size(); j++)
//                 res += sink(i, j, grid);
//         return res;
//     }

//     int sink(int i, int j, vector<vector<char>>& grid){
//         if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] == '0')
//             return 0;
//         else
//         {
//             grid[i][j] = '0';
//             sink(i + 1, j, grid);
//             sink(i - 1, j, grid);
//             sink(i, j + 1, grid);
//             sink(i, j - 1, grid);
//             return 1;
//         }
//     }
// };

/*Solution 2: Union&find*/
class UnionFind
{
public:
    UnionFind(vector<vector<char>> &g)
        : count(0), m_rank(g.size() * g[0].size(), 0), m_parent(g.size() * g[0].size(), -1)
    {
        auto m = g.size(), n = g[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] == '1')
                {
                    m_parent[i * n + j] = i * n + j;
                    ++count;
                }
            }
        }
    }

    int Find(int i)
    {
        if (m_parent[i] != i)
            m_parent[i] = Find(m_parent[i]);
        return m_parent[i];
    }

    void Union(int i, int j)
    {
        auto root_i = Find(i);
        auto root_j = Find(j);

        if (root_i != root_j)
        {
            if (m_rank[root_i] > m_rank[root_j])
                m_parent[root_j] = root_i;
            else if (m_rank[root_i] < m_rank[root_j])
                m_parent[root_i] = root_j;
            else
            {
                m_parent[root_i] = root_j;
                ++m_rank[root_j];
            }
            --count;
        }
    }

    int GetCount() const { return count; }

private:
    int count;
    vector<int> m_rank;
    vector<int> m_parent;
};

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;

        UnionFind uf(grid);

        auto m = grid.size(), n = grid[0].size();
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int r = i + dy[k];
                        int c = j + dx[k];
                        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1')
                        {
                            uf.Union(i * n + j, r * n + c);
                        }
                    }
                }
            }
        }

        return uf.GetCount();
    }
};

// @lc code=end
