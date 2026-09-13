#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> &adj, int start)
{
    vector<bool> vested(adj.size(), false);
    queue<int> q;
    vested[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x;
        for (auto u : adj[x])
        {
            if (!vested[u])
            {
                vested[u] = true;
                q.push(u);
            }
        }
    }
}
int main()
{
    vector<vector<int>> adj;
    // كملو
}