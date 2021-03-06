bool findNegativeAndArrange(int arr[], int n, int ind) {
    int neg = -1;
    
    for (int i = ind+1; i < n; i++) {
        if (arr[i] < 0) {
            neg = i;
            break;
        }
    }
    
    if (neg == -1) return false;
    
    for (int i = neg; i > ind; i--) {
        swap(arr[i], arr[i-1]);
    }
    
    return true;
}

bool findPositiveAndArrange(int arr[], int n, int ind) {
    int pos = -1;
    
    for (int i = ind+1; i < n; i++) {
        if (arr[i] >= 0) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) return false;
    
    for (int i = pos; i > ind; i--) {
        swap(arr[i], arr[i-1]);
    }
    
    return true;
}

void rearrange(int arr[], int n) {
    bool isDone = false;
    
    for (int i = 0; i < n; i++) {
        
        if (i%2 == 0 && arr[i] >= 0) {
            isDone = findNegativeAndArrange(arr, n, i);
            if (!isDone) return;
        }
        else if (i%2 != 0 && arr[i] < 0) {
            isDone = findPositiveAndArrange(arr, n, i);
            if (!isDone) return;
        }
        
    }
}
