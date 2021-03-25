#include <bits/stdc++.h> 
using namespace std; 

int longestDistinct(string str) 
{ 
	vector<int> previous(256, -1);
	int longest = 0;
	int start = 0;
	
	for (int i = 0; i < str.length(); i++) {
	    int prevOcc = previous[str[i]];
	    start = max(start, prevOcc+1);      // substring window start
	    
	    int length = i - start + 1;
	    
	    longest = max(longest, length);
	    
	    previous[str[i]] = i;
	}
	
	return longest;
} 

int main() 
{ 
	string str = "geeksforgeeks"; 
	int len = longestDistinct(str); 
	cout << "The length of the longest distinct characters substring is "<< len; 
	return 0; 
} 
