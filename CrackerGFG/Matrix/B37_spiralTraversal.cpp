void printFirstRow(vector<int> &spiral, vector<vector<int> > matrix, int rs, int cs, int ce) {
    for (int i = cs; i <= ce; i++) {
        spiral.push_back(matrix[rs][i]);
    }
}

void printLastColumn(vector<int> &spiral, vector<vector<int> > matrix, int ce, int rs, int re) {
    for (int i = rs; i <= re; i++) {
        spiral.push_back(matrix[i][ce]);
    }
}

void printLastRow(vector<int> &spiral, vector<vector<int> > matrix, int re, int cs, int ce) {
    for (int i = ce; i >= cs; i--) {
        spiral.push_back(matrix[re][i]);
    }
}

void printFirstColumn(vector<int> &spiral, vector<vector<int> > matrix, int cs, int rs, int re) {
    for (int i = re; i >= rs; i--) {
        spiral.push_back(matrix[i][cs]);
    }
}

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    int cs = 0, ce = c-1;
    int rs = 0, re = r-1;
    
    vector<int> spiral;
    
    while (rs <= re && cs <= ce) {
        
        if (rs <= re && cs <= ce) {
            printFirstRow(spiral, matrix, rs, cs, ce);
            rs++;
        }
        
        if (rs <= re && cs <= ce) {
            printLastColumn(spiral, matrix, ce, rs, re);
            ce--;
        }
        
        if (rs <= re && cs <= ce) {
            printLastRow(spiral, matrix, re, cs, ce);
            re--;
        }
        
        if (rs <= re && cs <= ce) {
            printFirstColumn(spiral, matrix, cs, rs, re);
            cs++;
        }
    }
    
    return spiral;
}
