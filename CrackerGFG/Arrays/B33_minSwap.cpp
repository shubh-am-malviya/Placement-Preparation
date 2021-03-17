int minSwap(int *arr, int n, int k) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            count++;
        }
    }
    
    int minBad = n+1;
    
    // Making first window and counting bad
    int left = 0, right = 0;
    int bad = 0;
    while (right < count) {
        if (arr[right] > k) {
            bad++;
        }
        
        right++;
    }
    
    minBad = min(bad, minBad);
    
    
    // Moving window and keeping track of minimum bad count
    while (right < n) {
        
        if (arr[left] > k) {
            bad--;
        }
        left++;
        
        if (arr[right] > k) {
            bad++;
        }
        
        minBad = min(bad, minBad);
        
        right++;
    }
    
    return minBad;
}
