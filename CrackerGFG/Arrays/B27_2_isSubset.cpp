string isSubset(int a1[], int a2[], int n, int m) {
    if (m > n) {
        return "No";
    }
    
    set<int> hashSet;
    
    for (int i = 0; i < n; i++) {
        hashSet.insert(a1[i]);
    }
    
    for (int i = 0; i < m; i++) {
        if (hashSet.count(a2[i]) == 0) {
            return "No";
        }
    }
    
    return "Yes";
}
