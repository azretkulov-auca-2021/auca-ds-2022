#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Pair
{
    int myAsci, myValue;
    Pair(const int &asci, int value): myAsci(asci), myValue(value)
    {
    }
};

struct SortByValue
{
    bool operator()(const Pair &pOne, const Pair &pTwo)
    {
        if (pOne.myValue != pTwo.myValue)
        {
            return pOne.myValue < pTwo.myValue;
        }

        return pOne.myAsci > pTwo.myAsci;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    string l;
    int t = 0;

    while (getline(cin, l))
    {
        vector<Pair> p;
        vector<int> asciTable(127);

        if (t != 0)
        {
            cout << "\n";
        }

        for (auto c : l)
        {
            asciTable[c] += 1;
        }

        for (int i = 0; i < (int)asciTable.size(); ++i)
        {
            if (asciTable[i] != 0)
            {
                p.push_back(Pair((char)i, asciTable[i]));
            }
        }

        sort(begin(p), end(p), SortByValue());

        for (int i = 0; i < (int)p.size(); i++)
        {
            cout << p[i].myAsci << " " << p[i].myValue << "\n";
        }

        t++;
    }
}