vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    vector <int> common;
    
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2 && k < n3) {
        
        if (A[i] == B[j] && B[j] == C[k]) {
            common.push_back(A[i]);
            i++;
            j++;
            k++;
            
            // If next element is same as previous
            // move ahead the pointers to prevent duplicate elements comparison
            moveAheadForSame(A, i, n1);
            moveAheadForSame(B, j, n2);
            moveAheadForSame(C, k, n3);
        }
        else if (A[i] > B[j] || A[i] > C[k]) {
            j = A[i] > B[j] ? j+1 : j;
            k = A[i] > C[k] ? k+1 : k;
            
        }
        else if (B[j] > A[i] || B[j] > C[k]) {
            i = B[j] > A[i] ? i+1 : i;
            k = B[j] > C[k] ? k+1 : k;
        } 
        else if (C[k] > A[i] || C[k] > B[j]) {
            i = C[k] > A[i] ? i+1 : i;
            j = C[k] > B[j] ? j+1 : j;
        }
        
    }
    
    return common;
}
