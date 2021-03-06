void rearrange(int arr[], int n) {
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            neg.push_back(arr[i]);
        } else {
            pos.push_back(arr[i]);
        }
    }

    int i = 0, j = 0, k = 0;
    while (i < pos.size() && j < neg.size()) {
        arr[k++] = pos[i++]; 
        arr[k++] = neg[j++]; 
    }

    while (i < pos.size()) {
        arr[k++] = pos[i++];
    }

    while (j < neg.size()) {
        arr[k++] = neg[j++]; 
    }
}
