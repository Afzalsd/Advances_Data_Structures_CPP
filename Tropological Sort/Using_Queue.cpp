#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<int> adjacency_list[vertices];
    vector<int> indegree_count(vertices, 0);

    cout << "Enter the edges: ";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjacency_list[u].push_back(v);
        indegree_count[v]++;
    }

    queue<int> queue_nodes;
    for (int i = 0; i < vertices; i++) {
        if (indegree_count[i] == 0) {
            queue_nodes.push(i);
        }
    }

    vector<int> topological_order;
    while (!queue_nodes.empty()) {
        int node = queue_nodes.front();
        queue_nodes.pop();
        topological_order.push_back(node);

        for (auto it : adjacency_list[node]) {
            indegree_count[it]--;
            if (indegree_count[it] == 0) {
                queue_nodes.push(it);
            }
        }
    }

    cout << "Topological Sort: ";
    for (auto it : topological_order) {
        cout << it << " ";
    }
    return 0;
}
