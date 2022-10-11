#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int cases, num, value, min, max;
    scanf("%d",&cases);
    while(cases--)
    {
        min = 99;
        max = 0;
        scanf("%d",&num);
        for (int i = 0; i < num; i++){
            scanf("%d",&value);
            if (value < min){
                min = value;
            }
            if (value > max){
                max = value;
            }
        }
        printf("%d\n", (max - min) * 2);
    }
}