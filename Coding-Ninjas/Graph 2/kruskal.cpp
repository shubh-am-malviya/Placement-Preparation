#include <bits/stdc++.h>
using namespace std;

class Edge {
    public:
    int src;
    int dest;
    int weight;
};

bool campareEdges(Edge* e1, Edge* e2) {
    return e1->weight < e2->weight;
}

int getParent(int v, int* parent) {
    int p = parent[v];
    while (p != parent[p]) {
        p = parent[p];
    }
    return p;
}

bool willFormCycle(int v1, int v2, int* parent) { // using Union Find Algo 
    int parent1 = getParent(v1, parent);
    int parent2 = getParent(v2, parent);
    
    // updating parent of a vertex with their top most parent
    parent[v1] = parent1;
    parent[v2] = parent2;
    
    return (parent1 == parent2);
}

Edge** kruskal(Edge** edges, int e, int v) {
    sort(edges, edges + e, campareEdges);
    
    int count = 0;
    int parent[v];
    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }
    Edge** mst = new Edge*[v-1];
    
    int i = 0;
    
    while(count < v-1) {
        Edge* e = edges[i];
        
        if (!willFormCycle(e->src, e->dest, parent)) {
            mst[count] = e;
            count++;
            
            // updating parent of parent
            parent[parent[e->dest]] = parent[parent[e->src]];
            
            // don't do this... parent[e->dest] = parent[e->src];
        }
        
        i++;
    }
    
    return mst;
}

int main() {
    int v, e;
    cin >> v >> e;
    
    Edge** edges = new Edge*[e];
    for (int i = 0; i<e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        edges[i] = new Edge();
        edges[i]->src = s;
        edges[i]->dest = d;
        edges[i]->weight = w;
    }
    
    Edge** mst = kruskal(edges, e, v);
    
    for (int i = 0; i < v-1; i++) {
        cout << min(mst[i]->src, mst[i]->dest) << " " << max(mst[i]->src, mst[i]->dest) << " " << mst[i]->weight << endl;
    }
}
