// https://informatics.msk.ru/mod/statements/view.php?chapterid=1005#1

#include <iostream>
#include <limits>
#include <vector>
#include <set>

using namespace std;

long int INF = numeric_limits<long int>::max();

vector<long int> dijkstra(vector<vector<vector<long int>>>& graph, long int s)
{
    vector<long int> dist(graph.size(), INF);
    dist[s] = 0;
    vector<bool> visited(graph.size(), false);
    set<pair<long int, long int>> mins {{0, s}};
    while (mins.size() != 0)
    {
        auto min_item = *mins.begin();
        long int min_index = min_item.second;
        mins.erase(min_item);
        visited[min_index] = true;
        for (auto next_node : graph[min_index])
        {
            if (!visited[next_node[0]] && next_node[1] >= dist[min_index] && dist[next_node[0]] > next_node[2])
            {
                mins.erase(make_pair(dist[next_node[0]], next_node[0]));
                dist[next_node[0]] = next_node[2];
                mins.insert(make_pair(dist[next_node[0]], next_node[0]));
            }
        }
    }
    return dist;
}

int main()
{
    long int n, m, e;
    cin >> n >> e >> m;
    vector<vector<vector<long int>>> graph(n, vector<vector<long int>>());
    long int k;
    for (long int i = 0; i < m; i++)
    {
        cin >> k;
        long int time1, time2, town1, town2;
        cin >> town1 >> time1;
        for (long int j = 0; j < k-1; j++)
        {
            cin >> town2 >> time2;
            graph[town1-1].push_back({town2-1, time1, time2});
            time1 = time2;
            town1 = town2;
        }
    }

    auto dist = dijkstra(graph, 0);

    long int result = dist[e-1];
    if (result == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result << endl;
    }
    return 0;
}