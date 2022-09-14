#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int solve(int a, int b) {
    if (a > b) {
        swap(a, b);
    }

int MaxLength = 0;
int nSteps = 0;
for(int i = a; i <= b; ++i)
{
    int cur = i;
    int nSteps = 1;
    while (cur != 1) {
        cur = cur % 2 == 0 
    }
    
    
}
}


int main()
{
    for (int a, b; cin >> a >> b;)
    iostream::sync_with_stdio(false);
}