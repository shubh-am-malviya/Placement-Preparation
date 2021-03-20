#define NO_OF_CHARS 256 


int firstRepeating(string& str) 
{ 
	int occurence[NO_OF_CHARS] = {-1};
	
	int leftMost = INT_MAX;
	
	for (int i = 0; i < str.length(); i++) {
	    
	    if (occurence[str[i]] == -1) {
	        occurence[str[i]] = i;
	    } else {
	        leftMost = min(leftMost, occurence[str[i]]);
	    }
	}
	
	if (leftMost == INT_MAX)
	    return -1;
	
	return leftMost;
} 
