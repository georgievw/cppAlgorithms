#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int foo(vector<vector<int>> &graph, int n)
{
    int time = 1, result = 0;
    int *in = new int[n]{};
    int *out = new int[n]{};
    stack<pair<int, int>> stk;
    stk.push(make_pair(0, -1));
    while (stk.size() != 0)
    {
        pair<int, int> curNode = stk.top();
        stk.pop();
        if (in[curNode.first] == 0)
        {   
            in[curNode.first] = time;
            out[curNode.first] = time;
            time++;
            for (auto nextNode : graph[curNode.first])
            {
                if (in[nextNode] == 0)
                {
                    stk.push(make_pair(curNode.first, nextNode));
                    stk.push(make_pair(nextNode, curNode.first));
                }
                else if (nextNode != curNode.second)
                {
                    out[curNode.first] = min(out[curNode.first], in[nextNode]);
                }
            }
        }
        else
        {
            out[curNode.first] = min(out[curNode.first], out[curNode.second]);
            if (out[curNode.second] > in[curNode.first])
            {
                int n_local = time - in[curNode.second];
                result += n_local*(n-n_local);
            }
        }

    }
    delete[] in;
    delete[] out;
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph;
    for (int i = 0; i < n; i++)
    {
        vector<int> node;
        graph.push_back(node);
    }
    for (int i = 0; i < m; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1-1].push_back(node2-1);
        graph[node2-1].push_back(node1-1);
    }

    cout << foo(graph, n) << endl;
    return 0;
}
