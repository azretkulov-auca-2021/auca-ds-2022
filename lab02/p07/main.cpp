#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int a, b, x, y, z;
    while((cin>>a>>b))
    {
        if (a == -1 && b == -1) {
            return 0;
        }
        else if ( a == b && (a != -1 && b != -1) ) {
            x = 0; y = 0;
        }
        else if (a > b) {
            x = a - b;
            y = b + 100 - a;
        }
        else if (a < b) {
            x = b - a;
            y = a + 100 - b;
        }
        
        z = min(x,y);
        cout<<z<<endl;
    }
    return 0;
}
