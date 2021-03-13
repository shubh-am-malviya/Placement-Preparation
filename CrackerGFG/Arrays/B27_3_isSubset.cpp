string isSubset(int a1[], int a2[], int n, int m) {
    
    if (n < m) {
        return "No";
    }
    
    sort(a1, a1+n);
    sort(a2, a2+m);
    
    int i = 0, j = 0;
    
    while (i < n && j < m) {
        
        if (a1[i] == a2[j]) {
            i++;
            j++;
        }
        else if (a1[i] < a2[j]) {
            i++;
        } else if (a1[i] > a2[j]) {
            return "No";
        }
    }
    
    return "Yes";
}
