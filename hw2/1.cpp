#include <iostream>
#include <vector>

using namespace std;

int INF = 1000000000;

void WFI(vector<vector<int>>&matrix, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(n, INF));

    int s, e, l;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e >> l;
        matrix[s-1][e-1] = l;
        matrix[e-1][s-1] = l;
    }
    for (int i =0; i < n; i++) matrix[i][i] = 0;

    WFI(matrix, n);

    int graphCenter = 0, minMaxDist = INF;
    for (int i = 0; i < n; i++)
    {
        int maxDist = 0;
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > maxDist)
            {
                maxDist = matrix[i][j];
            }
        }
        if (maxDist < minMaxDist)
        {
            graphCenter = i;
            minMaxDist = maxDist;
        }
    }

    cout << graphCenter+1 << endl;

    return 0;
}