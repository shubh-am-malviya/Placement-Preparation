void merge(int arr1[], int arr2[], int n, int m) {
    int arr3[n+m];
    
    int k = 0;
    
    // Copying arr1 & arr2 to arr3
    for (int i = 0; i < n; i++) {
        arr3[k] = arr1[i];
        k++;
    }
    
    for (int i = 0; i < m; i++) {
        arr3[k] = arr2[i];
        k++;
    }
    
    // sorting arr3
    sort(arr3, arr3+n+m);
    
    // copying sorted arr3 to arr1 and arr2
    k = 0;
    
    for (int i = 0; i < n; i++) {
        arr1[i] = arr3[k];
        k++;
    }
    
    for (int i = 0; i < m; i++) {
        arr2[i] = arr3[k];
        k++;
    }
}
