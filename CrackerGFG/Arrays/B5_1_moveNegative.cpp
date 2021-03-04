void RearrangePosNeg(int arr[], int n) {
    int negIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negIndex++;
            swap(arr[i], arr[negIndex]);
        } 
    }
}
