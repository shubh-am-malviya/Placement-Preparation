void BFS(int** edges, int n, int si, bool* visited) {
    queue<int> pending;
    pending.push(si);
    visited[si] = true;
    
    while (!pending.empty()) {
        int curr = pending.front();
        pending.pop();
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[curr][i]) {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}

bool isConnected(int** edges, int n) {
    bool* visited = new bool[n]();
    
    // Perform BFS or DFS
    BFS(edges, n, 0, visited);
    
    // Check if all nodes are visited
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    
    return true;
}
