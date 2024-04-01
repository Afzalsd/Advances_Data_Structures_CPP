#include <iostream>
#include <climits>
using namespace std;

#define MAX_VERTICES 10

int minDistanceIndex(int distances[], bool visited[], int numVertices) {
    int minDistance = INT_MAX, index;
    for (int i = 1; i <= numVertices; i++) {
        if (!visited[i] && distances[i] <= minDistance) {
            minDistance = distances[i];
            index = i;
        }
    }
    return index;
}

void printDistances(int distances[], int numVertices) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 1; i <= numVertices; i++) {
        cout << i << " \t\t\t" << distances[i] << endl;
    }
}

void dijkstraAlgorithm(int graph[MAX_VERTICES][MAX_VERTICES], int source, int numVertices) {
    int distances[numVertices];
    bool visited[numVertices];
    for (int i = 1; i <= numVertices; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    distances[source] = 0;
    for (int i = 0; i < numVertices - 1; i++) {
        int u = minDistanceIndex(distances, visited, numVertices);
        visited[u] = true;
        for (int v = 1; v <= numVertices; v++) {
            if (!visited[v] && graph[u][v] && distances[u] != INT_MAX && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
            }
        }
    }
    printDistances(distances, numVertices);
}

int main() {
    int numVertices, numEdges, sourceVertex;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            graph[i][j] = 0;
        }
    }
    cout << "Enter the number of edges: ";
    cin >> numEdges;
    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        cout << "Enter edge " << i + 1 << " (source destination weight): ";
        cin >> source >> destination >> weight;
        graph[source][destination] = weight;
    }
    cout << "Enter Source vertex: ";
    cin >> sourceVertex;
    dijkstraAlgorithm(graph, sourceVertex, numVertices);
    return 0;
}
