#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int test;
    scanf("%d", &test);
    for (int i = 1; i <= test; i++)
    {
        int s1;
        int s2;
        int s3;
        int sum;
        scanf("%d %d %d", &s1, &s2, &s3);
        if ((s1 > s2 && s1 < s3) || (s1 > s3 && s1 < s2)){
            sum = s1;
        } else if ((s2 > s1 && s2 < s3) || (s2 > s3 && s2 < s1)){
            sum = s2;
        } else {
            sum = s3;
        }
        printf("Case %d: %d\n", i, sum);
    }
    return 0;
}