#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5

void printCommonElements(int mat[M][N])
{
	unordered_map<int, int> mp;

    // Hashing first row
	for (int j = 0; j < N; j++) {
	    mp[mat[0][j]] = 1;
	}
	
	// Traversing over matrix row wise & updating hash values of element which apper in previous row
	for (int i = 1; i < M; i++) {
	    for (int j = 0; j < N; j++) {
	        if (mp.count(mat[i][j]) > 0 && mp[mat[i][j]] == i) {
	            mp[mat[i][j]] = i+1;
	        }
	    }
	}
	
	
	for (int i = 0; i < N; i++) {
	    if (mp[mat[0][i]] == M) {
	        cout << mat[0][i] << " ";
	        
	        mp[mat[0][i]] = 0;  // for preventing double printing of duplicate elements in first row
	    }
	}
}

// driver program to test above function
int main()
{
	int mat[M][N] =
	{
		{1, 2, 1, 4, 8},
		{3, 7, 8, 5, 1},
		{8, 7, 7, 3, 1},
		{8, 1, 2, 7, 9},
	};

	printCommonElements(mat);

	return 0;
}
