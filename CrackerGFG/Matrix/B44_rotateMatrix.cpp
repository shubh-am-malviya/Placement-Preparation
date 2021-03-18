void rotate90Clockwise(int a[N][N])
{
    // Transpose the array
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }
    
    // Swapping the colums
    int i = 0, j = N-1;
    
    while (i < j) {
        for (int k = 0; k < N; k++) {
            swap(a[k][i], a[k][j]);
        }
        i++;
        j--;
    }
}
