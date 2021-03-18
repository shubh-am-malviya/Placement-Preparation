int getMedian(int ar1[], int ar2[], int n)
{
    int j = 0;
    int i = n - 1;
    
    while (ar1[i] > ar2[j] && j < n && i > -1) {
        swap(ar1[i--], ar2[j++]);
    }
    
    sort(ar1, ar1 + n);
    sort(ar2, ar2 + n);
    return (ar1[n - 1] + ar2[0]) / 2;
}
