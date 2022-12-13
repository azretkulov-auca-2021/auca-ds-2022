#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
// void line(vector<string>& v) {
//     int maxlen = 0;
//     for(auto i : v) {
//         if(i.length() > maxlen) {
//             maxlen = i.length();
//         }
//     }
// }

int main()
{
    iostream::sync_with_stdio(false);

    string s;
    vector<string> vs;

    while (getline(cin, s))
    {
        if (s == "")
        {
            cout << endl;
        }
        vs.push_back(s);
    }

    sort(begin(vs), end(vs),
        [](string s1, string s2)
        { reverse(begin(s1), end(s1));
          reverse(begin(s2), end(s2));
          return s1 < s2; }); 
}