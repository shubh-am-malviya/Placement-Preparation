// Using DFS

bool hasPath(int** edges, int n, int si, int ei, bool* visited) {
    if (edges[si][ei] == 1) {
        return true;
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && edges[si][i] == 1) {
            visited[i] = true;
            if (hasPath(edges, n, i, ei, visited)) {
                return true;
            }
        }
    }
    
    return false;
}
