void RearrangePosNeg(int arr[], int n) {
    
    // Copy elements to another array
    int arr2[n];
    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];
    }
    
    // Copy negatives then copy positive in same order
    int i = 0;
    
    for (int j = 0; j < n; j++) {
        if (arr2[j] < 0) {
            arr[i] = arr2[j];
            i++;
        }
    }
    
    for (int j = 0; j < n; j++) {
        if (arr2[j] >= 0) {
            arr[i] = arr2[j];
            i++;
        }
    }
    
}
