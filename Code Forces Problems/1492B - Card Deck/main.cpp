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


const ll Keeber = 1e5+5;
const int MOD = 1e9 + 7;
using namespace std;



int summation_from_X_to_Y (int SmallerNumber, int GreaterNumber)
{
    if ( GreaterNumber == SmallerNumber)
        return GreaterNumber ;
    else
    {
        return GreaterNumber + summation_from_X_to_Y(SmallerNumber,GreaterNumber-1);
    }
}

int FastPower_rec(int base, int power)
{
    if (power == 0 )
        return 1 ;
    int value = FastPower_rec(base, power/2);
    if (power % 2 == 0)
    {
        return value * value;
    }
    else
    {
        return base * value * value;
    }
}
class comp {
public:
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

 
ll FastPowerIterative(ll base, ll power)
{
    ll result = 1;
    while (power > 0)
    {
        if (power % 2 == 1)
            result *= base;
        base *= base;
        power /= 2;
    }
    return result;
}

int FastPowerIterativeExpo(int base, int power, int M)
{
    int result = 1;
    while (power > 0)
    {
        if (power % 2 == 1)
            result = (result * base) % M;
        base = (base * base) % M;
        power /= 2;
    }
    return result;
}

void binary_generation (int x)
{
    if (x == 0)
        return;
    else
    {
        binary_generation(x/2);
        x%=2;
        cout << x;
    }
}

ll sum_of_an_array (ll array[],ll size)
{
    ll sum = 0;
    for (int i =0; i < size ; i++)
        sum+=array[i];
    return sum;
}

ll factorial(ll n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

/*MODULAR ARITHMETIC*/

ll mod_add(ll a, ll b, ll m)
{
    return ((a % m) + (b % m)) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    return ((a % m) * (b % m)) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    return (((a % m) - (b % m)) % m + m) % m;
}

vector<ll> divisors(ll x) {
    vector<ll> vec;
    for (ll i = 1 ; i*i <= x ; i++) {
        if (x % i == 0){
            vec.push_back(i);
            if (x / i != i)
                vec.push_back(x/i);
        }

    }
    sort(vec.begin(), vec.end());
    return vec;
}

vector<ll> primeFactors(ll x) {
    ll sq = sqrt(x);
    vector<ll> res;
    for (ll i = 2 ; i*i <= x ; i++) {  // Loop up to sqrt(x)
        while (x % i == 0) {  // While x is divisible by i
            x /= i;  // Divide x by i
            res.push_back(i);  // Add i as a prime factor
        }
    }
    if (x > 1) {
        res.push_back(x);
    }
    return res;
}

ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}

ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}

ll iterativeExtendedEuclidean (ll a , ll b , ll &x , ll &y) {
    x = 1 , y = 0 ;
    ll a1 = a , b1 = b ,x1 = 0 , y1 = 1;
    while (b1) {
        ll q = a / b ;
        tie(x1,x) = make_tuple(x - q*x1 , x1);
        tie(y1 , y)= make_tuple(y - q *y1 , y1);
        tie(a1,b1) = make_tuple(b1 , a1 % b1);
    }
    return a1;
}

// a modulus b = a - b * floor ( a / b) ;

/*
fact[0] = 1;
int arr_size = 1 ;
for (int i = 2 ; i<= t ; i++)
    arr_size = bigInt_factorial(i,fact, arr_size ) ;

for (int i = arr_size - 1 ; i >= 0 ; i--)
    cout << fact[i];
7ot dol fe el main lw bigInt_factorial

int fact[500]  ;
int bigInt_factorial(int num, int arr[], int arr_size) {
    int curr_res  , carry = 0 ;

    for(int i = 0 ; i < arr_size ; i++) {
        curr_res = fact[i] * num + carry ;
        arr[i] = curr_res % 10 ;
        carry = curr_res / 10 ;
    }

    while (carry) {
        fact[arr_size] = carry % 10 ;
        carry /= 10 ;
        arr_size++;
    }
    return arr_size;
}
*/
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        vector<int> main(x);
        for (int i = 0; i < x; i++)
            cin >> main[i];

        // store (value, index)
        vector<pair<int,int>> vp;
        for (int i = 0; i < x; i++)
            vp.push_back({main[i], i});

        // sort by value descending
        sort(vp.begin(), vp.end(),
             [&](auto &a, auto &b){ return a.first > b.first; });

        vector<int> newMain;

        int last = x;

        for (auto &p : vp) {
            int idx = p.second;

            if (idx < last) {
                for (int i = idx; i < last; i++)
                    newMain.push_back(main[i]);

                last = idx;
            }
        }

        for (int v : newMain)
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}
