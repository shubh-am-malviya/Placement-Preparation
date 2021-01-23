vector<int>* setPath(int si, int ei, map<int, int> m) {
    vector<int>* path = new vector<int>;
    path->push_back(ei);
    
    int temp = m[ei];
    
    while (temp != si) {
        path->push_back(temp);
        temp = m[temp];
    }
    
    path->push_back(temp);
    
    return path;
}

vector<int>* getPathBFS(int** edges, int n, int si, int ei, bool* visited) {
    vector<int>* path = NULL;
    
    if (si == ei) {
        vector<int>* path = new vector<int>;
        path->push_back(ei);
        return path;
    }
    
    queue<int> pending;
    pending.push(si);
    visited[si] = true;
    
    map<int, int> m;                // for keeping track of the path
    
    while (!pending.empty()) {
        int curr = pending.front();
        pending.pop();
        
        for (int i = 0; i < n; i++) {
            if (!visited[i] && edges[curr][i]) {
                pending.push(i);
                m[i] = curr;                // tracking the element getting inserted in the queue
                visited[i] = true;
                
                if (i == ei) {
                    path = setPath(si, ei, m);
                    return path;
                }
            }
        }
    }
    
    return path;
}
