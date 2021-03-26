#include <bits/stdc++.h> 
using namespace std; 

int binarySearch(int arr[], int low, int high, int key) 
{ 
    if (high < low) 
    	return -1; 
    	
    int mid = (low + high)/2; /*low + (high - low)/2;*/
    if (key == arr[mid]) 
    	return mid; 
    	
    if (key > arr[mid]) 
    	return binarySearch(arr, (mid + 1), high, key); 
    	
    // else 
    	return binarySearch(arr, low, (mid -1), key); 
} 

/* Function to get pivot. For array 3, 4, 5, 6, 1, 2 
it returns 3 (index of 6) */
int findPivot(int arr[], int low, int high) 
{ 
    int n = high;
    
    while (low <= high) {
        int  mid = low + (high-low)/2;
        
        if (mid == n) return -1;
        
        if (arr[mid+1] < arr[mid]) return mid;
        
        if (arr[mid] > arr[low]) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    
    return -1;
} 


int pivotedBinarySearch(int arr[], int n, int key) 
{ 
    int pivot = findPivot(arr, 0, n-1);
    
    // If pivot is not found, means array is fully sorted
    if (pivot == -1) {
        return binarySearch(arr, 0, n-1, key);
    }
    
    if (key >= arr[0] && key <= arr[pivot]) {
        return binarySearch(arr, 0, pivot, key);
    } else {
        return binarySearch(arr, pivot+1, n-1, key);
    }
} 


int main() 
{ 
    
    int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}; 
    int n = sizeof(arr1)/sizeof(arr1[0]); 
    int key = 3; 
    	
    
    cout << "Index of the element is : " << 
    		pivotedBinarySearch(arr1, n, key); 
    			
    return 0; 
} 
