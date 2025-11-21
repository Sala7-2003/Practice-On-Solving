#include <bits/stdc++.h>
#include <tuple>
#include <vector>
#define ll long long
#define yes cout<<"yes\n";
#define YES cout <<"YES\n";
#define no cout <<"no\n";
#define NO cout << "NO\n";
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define Sum(X , Y) ((X)+(Y))


const ll Keeber = 1e5+5;
const int MOD = 1e9 + 7;
using namespace std;



int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;
    deque<ll> dq;
    priority_queue<ll,vector<ll>,greater<ll>> ms;
    
        while (t--) {
            ll n , x;
            cin >> n;

            if (n  == 1) {
                cin >> x ;
                dq.push_back(x);
            } else if(n==2){
                if(!ms.empty()) {
                    cout << ms.top() << '\n';
                    ms.pop();
                }else {

                    cout << dq.front() << '\n';
                    dq.pop_front();
                }
            }else {
               while(!dq.empty()) {
                   ms.push(dq.front());
                   dq.pop_front();
               }
            }
        }
        return 0;
    }
