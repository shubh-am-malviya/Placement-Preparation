void printDFS(int** edges, int n, int sv, bool* visited){
  cout << sv << endl;
  visited[sv] = true;
  
  for(int i=0; i<n; i++) {
    if(!visited[i] && edges[sv][i]==1){
      printDFS(edges, n, i, visited);
    }
  }
}
