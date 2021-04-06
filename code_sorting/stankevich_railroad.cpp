// https://codeforces.com/gym/100201/ Problem I


#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef long double ld;
typedef vector<long double> vld;
typedef vector<vector<long double>> mld;
typedef vector<bool> vbl;
typedef vector<vector<bool>> mbl;
#define minimize(a, b) (a = min(a, b))
#define maximize(a, b) (a = max(a, b))
const long long MOD = 1e9 + 7;
 
template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}
template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    return out;
}
 
int main() {
    freopen("railsort.in", "r", stdin);
    freopen("railsort.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vll a(1 << n);
    cin >> a;
    for (int i = 0; i < (1 << n); i++)
        a[i]--;
    for (int i = 0; i < n; i++) {
        vll b(1 << n);
        int k = 0;
        stack<ll> st;
        for (int block = 0; block < (1 << i); block++) {
            for (int j = block * (1 << (n - i));
                 j < (block + 1) * (1 << (n - i)); j++) {
                cout << a[j] + 1 << ' ';
                if (!(a[j] & (1 << (n - 1 - i)))) {
                    b[k++] = a[j], cout << a[j] + 1 << ' ';
                } else {
                    st.push(a[j]);
                }
            }
            while (!st.empty()) {
                b[k++] = st.top();
                cout << st.top() + 1 << ' ';
                st.pop();
            }
        }
        a = b;
        // cout << endl << '@' << ' ' << b << endl;
    }
    cout << endl;
}

