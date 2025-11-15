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


const ll Keeber = 1e5+5;
const int MOD = 1e9 + 7;
using namespace std;
typedef vector<vector<int>> GRAPH ;


void addDirectedGraph(GRAPH &g , int from , int to) {
    g[from].push_back(to);
}

bool traverseGraph(GRAPH &g , int f) {
    for(int i = 1 ; i < g.size() ;) {
        int num = g[i][0];
        if(num == f ) {
            return true;
        }
        else if (num > f)
            return false;
        i = g[i][0];
    }
    return false;
}
int main() {

    int x , y , f ,t =1  ;
    cin >> x >> y ;
    GRAPH g (x);
    x--;
    while(x >= 1) {
        cin >> f ;
        addDirectedGraph(g, t,t+f);
        t++;
        x-- ;
    }

    if (traverseGraph(g,y))
        YES
    else NO


    return 0;
}