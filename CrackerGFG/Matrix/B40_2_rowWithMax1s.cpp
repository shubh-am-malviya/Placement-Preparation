int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int max1Row = -1;

    int i = 0, j = m-1;

    while (i < n && j >= 0) {
        if (arr[i][j] == 1) {
            max1Row = i;

            j--;
        } else {
            i++;
        }
    }

    return max1Row;

}
