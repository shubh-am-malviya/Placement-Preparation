#include <bits/stdc++.h>
using namespace std;

int getMinWeightIndex(bool* visited, int* weight, int n) {
    int minWeightIndex = -1;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (minWeightIndex == -1 || weight[i] < weight[minWeightIndex])) {
            minWeightIndex = i;
        }
    }
    
    return minWeightIndex;
}

void prims(int** edges, int v, int e) {
    bool* visited = new bool[v]();
    int* parent = new int[v];
    int* weight = new int[v];
    for (int i = 0; i < v; i++) {
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    parent[0] = -1;
    
    for (int i = 0; i < v-1; i++) {
        
        // Getting index of unvisited vertex with least weight
        int minIndex = getMinWeightIndex(visited, weight, v);
        visited[minIndex] = true;
        
        // Exploring the vertex with least weight and updating the weight of adjacent vertices
        for (int j = 0; j < v; j++) {
            if (!visited[j] && edges[minIndex][j] != 0 && weight[j] > edges[minIndex][j]) {
                weight[j] = edges[minIndex][j];
                parent[j] = minIndex;
            }
        }
    }
    
    // Printing the edges of MST with weight
    for (int i = 1; i < v; i++) {
        cout << min(parent[i], i) << " " << max(parent[i], i) << " " << weight[i] << endl;
    }
    
}


int main()
{
    int v, e;
    cin >> v >> e;
    
    int** edges = new int*[v];
    for (int i = 0; i < v; i++) {
      edges[i] = new int[v];
      for (int j = 0; j < v; j++)
      edges[i][j] = 0;
    }
    
    for (int i = 0; i < e; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        edges[v1][v2] = w;
        edges[v2][v1] = w;
    }
    
    prims(edges, v, e);
    
    
    return 0;
}
