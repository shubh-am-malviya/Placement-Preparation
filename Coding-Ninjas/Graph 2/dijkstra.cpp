#include <bits/stdc++.h>
using namespace std;

int getMinimumDistanceVertex(bool* visited, int* distance, int n) {
    int minimumDistVertex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (minimumDistVertex == -1 || distance[minimumDistVertex] > distance[i])) {
            minimumDistVertex = i;
        }
    }
    
    return minimumDistVertex;
}

void dijkstra(int** edges, int v, int e, int sv) {
    bool* visited = new bool[v]();      // I
    int* distance = new int[v];         // II
    for (int i = 0; i < v; i++) {
        distance[i] = INT_MAX;
    }
    distance[sv] = 0;
    
    for (int i = 0; i < v-1; i++) {     // III
        int minimumDistVertex = getMinimumDistanceVertex(visited, distance, v);
        visited[minimumDistVertex] = true;
        
        // Exploring the unvisited neighbours of minimum distance vertex
        for (int j = 0; j < v; j++) {
            if (!visited[j] && edges[minimumDistVertex][j] != 0) {
                if (distance[minimumDistVertex] + edges[minimumDistVertex][j] < distance[j]) {
                    // updating the distance for neighbour
                    distance[j] = distance[minimumDistVertex] + edges[minimumDistVertex][j];
                }
            }
        }
    }
    
    // Priniting the minimum distance of vertices from starting vertex (sv)
    for (int i = 0; i < v; i++) {
        cout << i << " " << distance[i] << endl;
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    
    int** edges = new int*[v];
    for (int i = 0; i < v; i++) {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++) {
            edges[i][j] = 0;
        }
    }
    
    for (int i = 0; i < e; i++) {
        int src, dest, dist;
        cin >> src >> dest >> dist;
        edges[src][dest] = dist;
        edges[dest][src] = dist;
    }
    
    dijkstra(edges, v, e, 0);
}
