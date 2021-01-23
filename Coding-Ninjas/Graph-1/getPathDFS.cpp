vector<int>* getPathDFS(int** edges, int n, int si, int ei, bool* visited) {
    vector<int>* path = NULL;
    
    if (si == ei) {
        path = new vector<int>;
        path->push_back(ei);
        return path;
    }
    
    visited[si] = true;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && edges[si][i] == 1) {
            visited[i] = true;
            path = getPathDFS(edges, n, i, ei, visited);
            
            if (path != NULL) {
                path->push_back(si);
                return path;
            }
        }
    }
    
    return path;
}
