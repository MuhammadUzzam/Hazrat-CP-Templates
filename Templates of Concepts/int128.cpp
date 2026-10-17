#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Define shorter aliases for convenience
using int128 = __int128;
using uint128 = unsigned __int128;

// Overload cin >> for __int128
istream& operator>>(istream& is, int128& v) {
    string s;
    if (!(is >> s)) return is;
    v = 0;
    bool neg = false;
    int i = 0;
    if (s[i] == '-') { neg = true; i++; }
    else if (s[i] == '+') { i++; }
    for (; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            v = v * 10 + (s[i] - '0');
        }
    }
    if (neg) v = -v;
    return is;
}

// Overload cout << for __int128
ostream& operator<<(ostream& os, int128 v) {
    if (v == 0) return os << "0";
    if (v < 0) { os << "-"; v = -v; }
    string s;
    while (v > 0) {
        s += (char)('0' + (v % 10));
        v /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int128 a, b;
    // Read __int128 directly using cin
    if (cin >> a >> b) {
        int128 result = a * b;
        // Print __int128 directly using cout
        cout << result << "\n";
    }

    return 0;
}
