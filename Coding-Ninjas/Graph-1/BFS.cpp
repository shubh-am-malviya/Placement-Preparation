void printBFS(int** edges, int n, int sv, bool* visited) {
    queue<int> pending;
    pending.push(sv);
    visited[sv] = true;
    
    while (!pending.empty()) {
        int curr = pending.front();
        pending.pop();
        
        cout << curr << " ";
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[curr][i] == 1) {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}
