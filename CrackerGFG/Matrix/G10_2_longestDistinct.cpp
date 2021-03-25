#include <bits/stdc++.h> 
using namespace std; 

int longestDistinctSubStr(string s) {
    int visited[256] = {0};
    
    for (int i = 0; i < s.length(); i++) {
        if (visited[s[i]] == 1) {
            return i;
        }
        
        visited[s[i]] = 1;
    }
    
    return s.length();
}


int longestDistinct(string str) 
{ 
    int longest = 1;
    
	for (int i = 0; i < str.length(); i++) {
	    int length = longestDistinctSubStr(str.substr(i));
	    
	    longest = max(longest, length);
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
