int getMedian(int arr1[], int arr2[], int n)
{
	int i = 0, j = 0, m1 = -1, m2 = -1;
	
	// If arr1 is smaller than arr2
	if (arr1[n-1] <= arr2[0]) {
	    m1 = arr1[n-1];
	    m2 = arr2[0];
	    
	    return (m1 + m2) / 2;
	}
	// If arr2 is smaller than arr1
	else if (arr1[0] > arr2[n-1]) {     
	    m1 = arr2[n-1];
	    m2 = arr1[0];
	    
	    return (m1 + m2) / 2;
	}
	
	
	for (int count = 0; count <= n; count++) {
	    
	    if (arr1[i] <= arr2[j]) {
	        m1 = m2;
	        m2 = arr1[i];
	        i++;
	    }
	    else {
	        m1 = m2;
	        m2 = arr2[j];
	        j++;
	    }
	}
	
	return (m1 + m2) / 2;
}
