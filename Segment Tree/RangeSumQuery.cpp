#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200001ll // Take care of this

vector<ll> arr(N);

class segmentTree
{

public:
    vector<ll> seg;
    segmentTree()
    {
        seg.resize(4 * N, 0ll);
    }
    void build(ll idx, ll low, ll high)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        ll mid = (low + high) / 2;
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    ll query(ll idx, ll low, ll high, ll l, ll r)
    {
        if (l > high || r < low) // No overlap
        {
            return 0ll;
        }
        if (low >= l && high <= r) // Complete overlap
        {
            return seg[idx];
        }
        ll mid = (low + high) / 2;
        ll left = query(2 * idx + 1, low, mid, l, r);
        ll right = query(2 * idx + 2, mid + 1, high, l, r);
        return left + right;
    }
};

int main()
{
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    segmentTree obj;
    obj.build(0, 0, n - 1);
    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        cout << obj.query(0, 0, n - 1, a - 1, b - 1) << endl;
    }
}
