long long merge(long long arr[], int left, int mid, int right) {
    int  n1 = mid+1-left, n2 = right-mid;
    long long arr1[n1], arr2[n2];
    
    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[left + i];
    }
    
    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }
    
    
    int i = 0, j = 0, k = left;
    long long inversions = 0;
    
    while (i < n1 && j < n2) {
        
        if (arr1[i] <= arr2[j]) {
            arr[k++] = arr1[i++];
        }
        else {
            arr[k++] = arr2[j++];
            inversions += n1 - i;
        }
        
    }
    
    while (i < n1) {
        arr[k++] = arr1[i++];
    }
    
    while (j < n2) {
        arr[k++] = arr2[j++];
    }
    
    return inversions;
}

long long _mergeSort(long long arr[], int left, int right) {
    
    long long inversions = 0;
    
    if (left < right) {
        
        int mid = left + (right - left)/2;
        
        inversions += _mergeSort(arr, left, mid);
        inversions += _mergeSort(arr, mid+1, right);
        
        inversions += merge(arr, left, mid, right);
    }
    
    return inversions;
}

long long int inversionCount(long long arr[], long long N)
{
    long  long inversions = _mergeSort(arr, 0, N-1);

    return inversions;
}
