int countOccurence(int arr[], int n, int k) {
    sort(arr, arr+n);
    
    int count = 0;
    int nByK = n/k;
    int i = 0;
    
    while (i < n) {
        
        int occ = 1;
        while (++i < n && arr[i] == arr[i-1]) {
            occ++;
        }
        
        if (occ > nByK) {
            count++;
        }
    }
    
    return count;
}
