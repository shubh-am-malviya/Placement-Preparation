vector<int> getComponentByBFS(int** edges, int n, int si, bool* visited) {
    vector<int> component;
    
    queue<int> pending;
    pending.push(si);
    visited[si] = true;
    
    while (!pending.empty()) {
        int curr = pending.front();
        pending.pop();
        
        component.push_back(curr);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[curr][i] == 1) {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
    
    return component;
}

vector<vector<int>> getComponents(int** edges, int n) {
    bool* visited = new bool[n]();
    vector<vector<int>> components;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> comp = getComponentByBFS(edges, n, i, visited);
            sort(comp.begin(), comp.end());             // As asked in prob to give comp elements in increasing order
            
            components.push_back(comp);
        }
    }
    
    return components;
}
