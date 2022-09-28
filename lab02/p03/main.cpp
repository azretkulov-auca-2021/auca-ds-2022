#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int a, b, c;
    cin >> a;

    while (a--)
    {
        cin >> b >> c;
        int result = (b / 3) * (c / 3);
        
        cout << result << "\n";
    }
}