#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> map;
    string line;
    int dxy[4][2] { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        map.push_back(line);
    }

    int n_lands = 0;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            if (map[x][y] == '+')
            {
                n_lands++;
                queue<int> q;
                q.push(x);
                q.push(y);
                while (q.size() != 0)
                {
                    int i = q.front();
                    q.pop();
                    int j = q.front();
                    q.pop();
                    map[i][j] = '-';
                    for (int i_dxy = 0; i_dxy < 4; i_dxy++)
                    {
                        int dx = dxy[i_dxy][0], dy = dxy[i_dxy][1];
                        if (i+dx >= 0 && i+dx < n && j+dy >= 0 && j+dy < m && map[i+dx][j+dy] == '+')
                        {
                            q.push(i+dx);
                            q.push(j+dy);
                        }
                    }
                }
            }
        }
    }
    cout << n_lands << endl;
    return 0;
}
