void RearrangePosNeg(int arr[], int n) {
    // I find negative element
    // II shift back to correct position
    
    int negIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
    
            // shifting
            int j = i;
            while (j != negIndex+1) {
                swap(arr[j], arr[j-1]);
                j--;
            }
            negIndex++;
        }
    }
}
