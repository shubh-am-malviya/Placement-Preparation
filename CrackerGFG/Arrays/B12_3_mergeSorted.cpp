int nextGap(int gap) {
    if (gap <= 1){
        return 0;
    }
    
    return (gap/2 + gap%2);
}

void merge(int arr1[], int arr2[], int n, int m) {
    int gap = nextGap(n+m);
    
    while (gap > 0) {
        int i = 0, j = gap;
        
        // when i and j are in arr1
        for (; i < n && j < n; i++, j++) {
            if (arr1[i] > arr1[j]) {
                swap(arr1[i], arr1[j]);
            }
        }
        
        // when i is in arr1 and j is in arr2
        if (i < n && j>=n) {
            j = j-n;
            for (; i < n && j < m; i++, j++) {
                if (arr1[i] > arr2[j]) {
                    swap(arr1[i], arr2[j]);
                } 
            }
        }
        
        // when i and j are in arr2
        if (i >= n) {
            i = i - n;
            
            for (; i < m && j < m; i++, j++) {
                if (arr2[i] > arr2[j]) {
                    swap(arr2[i], arr2[j]);
                }
            }
        }
        
        gap = nextGap(gap);
    }
}
