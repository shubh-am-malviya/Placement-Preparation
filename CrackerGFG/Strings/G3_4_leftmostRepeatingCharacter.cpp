#define NO_OF_CHARS 256 


int firstRepeating(string& str) 
{ 
	bool visited[NO_OF_CHARS] = {false};
	
	int leftMostRepeating = -1;
	
	for (int i = str.length()-1; i >= 0; i--) {
	    
	    if (visited[str[i]]) {
	        leftMostRepeating = i;
	    } else {
	        visited[str[i]] = true;
	    }
	}
	
	return leftMostRepeating;
} 
