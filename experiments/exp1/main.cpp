#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string line;
    getline(cin, line);

    int n = stoi (line);
    for(int i = 0; i < n; i++) {
        getline(cin, line);
        istringstream sinp(line);

        int nWords = 0;
        for(string w; sinp >> w;) {
                nWords++;
        }
        cout << nWords << endl;
    }
}