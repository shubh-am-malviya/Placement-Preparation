int findMinOps(int arr[], int n) 
{ 
	int operations = 0;
	
	int i = 0, j = n-1;
	
	while (i <= j) {
	    if (arr[i] == arr[j]) {
	        i++;
	        j--;
	    }
	    else if (arr[i] > arr[j]) {
	        j--;
	        arr[j] = arr[j] + arr[j+1];
	        operations++;
	    }
	    else {
	        i++;
	        arr[i] = arr[i] + arr[i-1];
	        operations++;
	    }
	    
	}
	
	return operations;
}
