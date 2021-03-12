int countOccurence(int arr[], int n, int k) {
    map<int, int> m;
    
    for (int i = 0;  i < n; i++) {
        m[arr[i]]++;
    }
    
    int nByK = n/k;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (m.count(arr[i]) > 0 && m[arr[i]] > nByK) {
            count++;
            m.erase(arr[i]);
        }
    }
    
    return count;
}
