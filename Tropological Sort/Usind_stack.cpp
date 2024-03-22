#include<bits/stdc++.h>
using namespace std;

void performTopologicalSort(int vertex, vector<int> adjacency[], bool visited[], stack<int> &Stack) {
    visited[vertex] = true;
    for (auto it = adjacency[vertex].rbegin(); it != adjacency[vertex].rend(); ++it) {
        if (!visited[*it]) {
            performTopologicalSort(*it, adjacency, visited, Stack);
        }
    }
    Stack.push(vertex);
}

void topologicalSort(int num_nodes, vector<int> adjacency[]) {
    stack<int> Stack;
    bool *visited = new bool[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < num_nodes; i++) {
        if (visited[i] == false) {
            performTopologicalSort(i, adjacency, visited, Stack);
        }
    }

    cout << "Topological Sort: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;

    delete[] visited;
}

int main() {
    int num_nodes, num_edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> num_nodes >> num_edges;

    vector<int> adjacency[num_nodes];

    cout << "Enter the edges: ";
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        adjacency[u].push_back(v);
    }

    topologicalSort(num_nodes, adjacency);

    return 0;
}
