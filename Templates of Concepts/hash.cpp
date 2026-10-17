//Bismillah
/*
The world rewards those who are willing to be bad at something long enough to become
great at it!
*/
/*
We are not here to win. We are here... to make our deaths matter.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define hazrat ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);int tt = 1;
#define int long long
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define nl cout << "\n";
#define yes cout << "YES\n"
#define no cout << "NO\n"

const int MOD = 1e9+7;
const int INF = 1e9;


// ================= CUSTOM HASH =================

struct custom_hash {

    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + RANDOM);
    }

    size_t operator()(const pii &p) const {
        static const uint64_t RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(p.first + RANDOM) ^
               (splitmix64(p.second + RANDOM) >> 1);
    }

    size_t operator()(const vi &v) const {
        uint64_t hash = v.size();
        for (auto x : v) {
            hash ^= splitmix64(x + 0x9e3779b97f4a7c15 +
                    (hash << 6) + (hash >> 2));
        }
        return hash;
    }
};


// ================= SOLVE =================

void solve() {

    // int key
    unordered_map<int,int,custom_hash> mp1;
    mp1[5]++;

    cout << mp1[5]; nl;

    // pair key
    unordered_map<pii,int,custom_hash> mp2;
    mp2[{1,2}] = 10;

    cout << mp2[{1,2}]; nl;

    // vector key
    unordered_map<vi,int,custom_hash> mp3;
    vi v = {1,2,3};
    mp3[v] = 100;

    cout << mp3[v]; nl;
}


// ================= MAIN =================

signed main() {

    hazrat;

    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}