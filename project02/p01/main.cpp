#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
int M;

struct SortByModulo
{
    bool operator()(int a, int b)
    {
        if (a % M != b % M)
        {
            return a % M < b % M;
        }
        if (a % 2 != 0)
        {
            if (b % 2 != 0)
            {
                return a > b;
            }
            return true;
        }
        if (b % 2 != 0)
        {
            return false;
        }

        return a < b;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int N;
    vector <int> numbers;

    while (cin >> N >> M, cout << N << " " << M << "\n", N)
    {
        for (int i = 1; i <= N; i++)
        {
            int x;
            cin >> x;
            numbers.push_back(x);
        }

        sort(begin(numbers), end(numbers), SortByModulo());

        for (int i = 0; i < N; i++)
        {
            cout << numbers[i] << endl;
        }

        numbers = vector<int>();
    }
}