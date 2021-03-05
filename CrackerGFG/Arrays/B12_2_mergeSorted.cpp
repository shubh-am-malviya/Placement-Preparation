void arrange(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

void merge(int arr1[], int arr2[], int n, int m) {

    for (int i = 0; i < n; i++) {
        if (arr1[i] > arr2[0]) {
            
            // swapping
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;
            
            // arranging arr2 after swapping
            arrange(arr2, m);
        }
    }
}

(I) Compare elements of arr1 to first element of arr2
    (i) If arr1 element is greater then swap
    (ii) After swapping, arrange arr2
