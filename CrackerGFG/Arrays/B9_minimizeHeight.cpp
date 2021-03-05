int getMinDiff(int arr[], int n, int k) {
    
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        if (arr[i] - k >= 0) {
            v.push_back({arr[i]-k, i});
        }
        v.push_back({arr[i]+k, i});
    }
    
    sort(v.begin(), v.end());
    
    int ele = 0, left = 0, right = 0;
    int visited[n] = {0};
    
    // Creating first window
    while (ele < n && right < v.size()) {
        if (visited[v[right].second] == 0) {
            ele++;
        }
        visited[v[right].second]++;
        right++;
    }
    
    int minDiff = v[right-1].first - v[left].first;
    
    
    // moving left pointer and Again completing window and checking minimum difference
    while (right < v.size()) {
        
        // Moving left pointer of the window
        if (visited[v[left].second] == 1) {
            ele--;
        }
        visited[v[left].second]--;
        left++;
        
        // Again creating window
        while (ele < n && right < v.size()) {
            if (visited[v[right].second] == 0) {
                ele++;
            }
            visited[v[right].second]++;
            right++;
        }
        
        // checking minimum difference
        if (ele == n) {
            minDiff = min(minDiff, v[right-1].first - v[left].first);
        }
        else {
            break;
        }
        
    }
    
    return minDiff;
}
