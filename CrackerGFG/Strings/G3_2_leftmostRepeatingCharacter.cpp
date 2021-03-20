#define NO_OF_CHARS 256 


int firstRepeating(string& str) 
{ 
	int count[NO_OF_CHARS] = {0};
	
	for (char c : str) {
	    count[c]++;
	}
	
	for (int i = 0; i < str.length(); i++) {
	    if (count[str[i]] >= 2) {
	        return i;
	    }
	}
	
	return  -1;
}
