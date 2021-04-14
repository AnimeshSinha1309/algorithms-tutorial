#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<lu> vu;
typedef vector<v> vv;
typedef vector<vu> vvu;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<set<ll>> vsll;
typedef set<pair<ll, ll>> spll;
typedef vector<spll> vspll;
typedef vector<pll> vpll;
typedef pair<lu, lu> puu;
typedef vector<puu> vpuu;
const ll MOD = 1000000007;
const ld PI = 2 * acos(0.0);
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define sz(x) (ll) x.size()
#define len(x) (ll) x.length()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
    if (f)       \
        yes else no;
#define noo        \
    {              \
        no return; \
    }

int heap[100000];
int num_elements = 0;

int get_left_child(int a)
{
    return 2 * a;
}

int get_right_child(int a)
{
    return 2 * a + 1;
}

int get_parent(int a)
{
    return a / 2;
}

void insert(int a)
{
    num_elements++;
    heap[num_elements] = a;
    int position = num_elements;
    while (true)
    {
        int par = get_parent(position);
        if (par != 0 && heap[par] < heap[position])
        {
            swap(heap[par], heap[position]);
        }
        else
            break;
        position = par;
    }
}

void del_top()
{
    if (num_elements == 0)
        return;
    swap(heap[1], heap[num_elements]);
    num_elements--;
    int position = 1;
    while (true)
    {
        int a = get_left_child(position);
        int b = get_right_child(position);
        int final_index;
        if (a > num_elements)
            break;
        else if (b > num_elements)
            final_index = a;
        else
            final_index = (heap[a] > heap[b]) ? a : b;
        if (heap[final_index] > heap[position])
            swap(heap[position], heap[final_index]);
        else
            break;
        position = final_index;
    }
}

void heapify()
{
    for (int i = num_elements; i >= 1; i--)
    {
        int position = i;
        while (true)
        {
            int a = get_left_child(position);
            int b = get_right_child(position);
            int final_index;
            if (a > num_elements)
                break;
            else if (b > num_elements)
                final_index = a;
            else
                final_index = (heap[a] > heap[b]) ? a : b;
            if (heap[final_index] > heap[position])
                swap(heap[position], heap[final_index]);
            else
                break;
            position = final_index;
        }
    }
}

int get_top()
{
    if (num_elements)
    {
        return heap[1];
    }
    else
    {
        return -1;
    }
}

void solve()
{
    // while (true)
    // {
    //     int a, type;
    //     cin >> type;
    //     if (!type)
    //     {
    //         cin >> a;
    //         insert(a);
    //     }
    //     else
    //         del_top();
    //     cout << get_top() << "\n";
    // }
    int n;
    cin >> n;
    num_elements = n;
    for (int i = 0; i < n; i++)
    {
        cin >> heap[i + 1];
    }
    heapify();
    for (ll i = 1; i < n + 1; i++)
    {
        cout << heap[i] << " ";
    }
}

int main(void)
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    solve();
    return 0;
}