#include <stdio.h> 

// A binary search based function that returns index of a peak element 
int findPeakUtil(int arr[], int low, int high, int n) 
{ 
	while (low <= high) {
	    int mid = low + (high - low)/2;
	    
	    if (mid == 0 && arr[1] < arr[0]) return arr[0];
	    
	    if (mid == n-1 && arr[mid-1] < arr[mid]) return arr[mid];
	    
	    if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return arr[mid];
	    
	    if (arr[mid-1] > arr[mid]) {
	        high = mid-1;
	    } else {
	        low = mid+1;
	    }
	}
} 

// A wrapper over iterative function findPeakUtil() 
int findPeak(int arr[], int n) 
{ 
    if (n == 1) {
        return arr[0];    
    }
    
	return findPeakUtil(arr, 0, n-1, n); 
} 

int main() 
{ 
	int arr[] = {1, 3, 20, 4, 1, 0}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printf("Index of a peak point is %d", findPeak(arr, n)); 
	return 0; 
} 
