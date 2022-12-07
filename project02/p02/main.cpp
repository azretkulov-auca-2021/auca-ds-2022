#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Skill
{
    int MyValue;
    string MyName;
    Skill(const string &name, int value)
        : MyName(name), MyValue(value)
        {
        }
};

struct SortByName
{
    bool operator()(const Skill &a, const Skill&b)
    {
        return a.MyName < b.MyName;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int M, N, number;
    string word;
    vector<Skill> s;

    cin >> M >> N;

    for (int i = 1; i <= M; ++i)
    {
        cin >> word >> number;
        s.push_back(Skill(word, number));
    }

    sort(begin(s), end(s), SortByName());

    for (int i = 1; i <= N; ++i)
    {
        int sum = 0;

        while (cin >> word && word != ".")
        {
            for (int j = 0; j < M; ++j)
            {
                if (word == s[j].MyName)
                {
                    sum += s[j].MyValue;
                }
            }
        }

        cout << sum << endl;
    }
}