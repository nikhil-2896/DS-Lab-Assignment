#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
void BFS(vector<vector<int>> &adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void DFSIterative(vector<vector<int>> &adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);
    cout << "DFS Traversal (Iterative): ";
    while (!s.empty()) {
        int u = s.top(); s.pop();

        if (!visited[u]) {
            visited[u] = true;
            cout << u << " ";
        }
        for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
            if (!visited[*it]) s.push(*it);
        }
    }
    cout << endl;
}


int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> adj(n);

    cout << "Enter edges :\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(adj, start);
    DFSIterative(adj, start);

    return 0;
}
