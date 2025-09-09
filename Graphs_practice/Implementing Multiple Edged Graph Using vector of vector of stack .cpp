#include <bits/stdc++.h>
#include <tuple>
#include <vector>
#define ll long long
#define yes cout<<"yes\n";
#define YES cout <<"YES";
#define no cout <<"no\n";
#define NO cout << "NO";
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


typedef vector<vector<stack<int>>> Multiple_Edged_GRAPH;
void addEdgeDirected(Multiple_Edged_GRAPH &g , int f , int t , int cost) {
    g[f][t].push(cost);
}

void addEdgeUndirected(GRAPH &g , int f , int t) {
    g[f].push_back(t);
    g[t].push_back(f);
}



int printGraph(Multiple_Edged_GRAPH &g) {
    set<int> s;
    int nodes = g.size();
    for (int i = 0 ; i < nodes ; i++){
        for(int j = 0 ; j < nodes ; j++)
            if(!g[i][j].empty()) {
                while ( !g[i][j].empty()) {
                    cout << "From " << i << " to " << j << " cost -->  " << g[i][j].top() << '\n';
                    g[i][j].pop();
                }
            }


    }
    return g.size();
}


int main() {

    int nodes , edges;
    cin >> nodes >> edges ;

    Multiple_Edged_GRAPH g(nodes ,vector<stack<int>>(nodes));

    for(int i = 0 ; i < edges ; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        addEdgeDirected(g, from, to, cost);
    }

    printGraph(g);



    return 0;
}
