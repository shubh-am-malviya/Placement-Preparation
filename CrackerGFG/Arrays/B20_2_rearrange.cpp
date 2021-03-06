void rearrange(int arr[], int n)
{
    // (I) Arrange all negative on left and positive on right
    int i = 0, j = n-1;
    while (i < j) {
        while (i < n && arr[i] < 0) {
            i++;
        }
        
        while (j >= 0 && arr[j] >= 0) {
            j--;
        }
        
        if (i < n && j >= 0 && i < j) {
            swap(arr[i], arr[j]);
        }
    }
    
    
    // (II) Finding odd index with negative element
    // and even index with positive element
    int neg = -1, pos = -1;
    
    for (int i = 1; i < n; i += 2) {                    // finding negative number at odd index
        if (arr[i] < 0) {
            neg = i;
            break;
        }
    }
    
    for (int i = 0; i < n; i += 2) {                    // finding positive number at even index
        if (arr[i] >= 0) {
            pos = i;
            break;
        }
    }
    
    // (III) Keep Swapping negative at odd index with positive at even index
    
    if (neg != -1 && pos != -1) {
        while (arr[neg] < 0 &&  pos < n) {
            swap(arr[neg], arr[pos]);
            neg += 2;
            pos += 2;
        }
    }
}
