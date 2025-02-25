#include <iostream>
#include <bits/stdc++.h>

using namespace std;


//Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Nikhil cout.tie(NULL);

//Aliases
using ll= long long;
using lld= long double;
using ull= unsigned long long;

//Constants
const lld pi= 3.141592653589793238;
const ll INF= LONG_LONG_MAX;
const ll mod=1e9+7;

//TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;

// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=n;i>=m;i--)
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()

//Debug

#define debug(x) cerr << #x<<" "; cerr<<x<<" "; cerr << endl;

// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
void printarr(ll arr[], ll n){fl(i,n) cout << arr[i] << " ";cout << "\n";}
template<typename T>
void printvec(vector<T>v){ll n=v.size();fl(i,n)cout<<v[i]<<" ";cout<<"\n";}
template<typename T>
ll sumvec(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}

// Mathematical functions
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd 
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}

//Graph-dfs
// bool gone[MN];
// vector<int> adj[MN];
// void dfs(int loc){
//     gone[loc]=true;
//     for(auto x:adj[loc])if(!gone[x])dfs(x);
// }

//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}

 int baseOR(int m) {
    if(m <= 1) return 0;
    int p = 31 - __builtin_clz(m - 1);
    return ((unsigned int)1 << (p + 1)) - 1;
}


//Code
void solve()
{
    ll n,x;
    cin>>n>>x;

    if( n==1){
        cout << x<< endl;
        return;
    }


    int max_bit_allowed = 0;
        while(true){
            if ((max_bit_allowed & ~x) != 0)
                break;
            max_bit_allowed++;
        }
        bool full = (((x + 1) & x) == 0);
 
        int default_size;      
        bool needs_update; 
        if(full) {
            
            if(n >= max_bit_allowed) {
                default_size = max_bit_allowed;
                needs_update = false;
            } else {
                if(baseOR(n) == x) {
                    default_size = n;
                    needs_update = false;
                } else {
                    default_size = n - 1;
                    needs_update = true;
                }
            }
        } else {
            if(n >= max_bit_allowed + 1) {
                default_size = max_bit_allowed;
                needs_update = true;
            } else {
                default_size = n - 1;
                needs_update = true;
            }
        }
 
        vector<int> ans;
        for (int i = 0; i < default_size; i++){
            ans.push_back(i);
        }
 
        if(needs_update){
            int patch = x & ~(baseOR(default_size));
            ans.push_back(patch);
        }
 
        while(ans.size() < n)
            ans.push_back(0);
 
        for(auto v : ans)
            cout << v << " ";
        cout << "\n";


    // int r = 0;
    // while(r < 31 && ((x >> r) & 1)) r++;
    // int r0 = max(r, 1); 

    // int m;

    // if(x == ((1 << r0) - 1)) {
    //     if(n >= (1 << r0)) m = 1 << r0; 
    //     else m = n; 
    // } else {
    //     int candidate = (1 << r0);
    //     if(n >= (1 << r0)) m = candidate;
    //     else m = n-1 ;
    // }

    // vector<int > result;

    // for(int i =0;i<m;i++){
    //    result.push_back(i);
    // }

    // unsigned int orBase = bitOR(m);
 
    // if(orBase != x){
    //     unsigned int v = x & (~orBase);
    //     result.push_back(v);
    // }

    // while(result.size() < n){
    //     result.push_back(0);
    // }

    // for(auto v : result)
    //         cout << v << " ";
    //     cout << "\n";
    // return;

    // vector<int> arr(64);
    // for (int i = 0; i < 64; ++i) {
    //     arr[i] = (n >> i) & 1;
    // }
    // ll startNumber =0;
    // for(int i =0;i<arr.size();i++){
    //     if(arr[i] ==1){
    //         startNumber += pow(2,i);
    //     }else{
    //         break;
    //     }
    // }

    

    // for(int i =0;i<n;i++) cou << result[i] << " ";
    // cout <<endl;
}
//Main
int main()
{
Code By Nikhil;
    ll t;
    cin>>t;
    fl(i,t)
    {
        solve();
    }
    return 0;
}
//End