int getPairsCount(int arr[], int n, int k) {
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        int diff = k - arr[i];
        if (m.count(diff) > 0) {
            count += m[diff];
        }
        
        if (diff == arr[i]) {
            count--;
        }
    }
    
    return count/2;
}
