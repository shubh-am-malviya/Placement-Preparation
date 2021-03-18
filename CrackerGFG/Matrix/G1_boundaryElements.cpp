vector<int> BoundaryElements(vector<vector<int>>&matrix){
    vector<int> boundary;
    int r = matrix.size();
    int c = matrix[0].size();
    
    // For all elements of first row
    for (int i = 0; i < c; i++) {
        boundary.push_back(matrix[0][i]);
    }
    
    // For the first and last elements of rows between first and last row
    if (r >= 3) {
        for (int i = 1; i <= r-2; i++) {
            boundary.push_back(matrix[i][0]);
            boundary.push_back(matrix[i][c-1]);
        }
    }
    
    // For all elements of last row
    if (r >= 2) {
        for (int i = 0; i < c; i++) {
            boundary.push_back(matrix[r-1][i]);
        }
    } 
    
    return boundary;
}
