#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int roads;
    int naming;
    for (int i = 1;;i++) {
    scanf("%d %d", &roads, &naming);
    if (roads == 0 && naming == 0){
        return 0;
    }
    printf("Case %d: ", i);
    int res = roads / naming;
    if (res > 26 && (((roads % naming) != 0) || ((roads % naming) == 0))){
        printf("impossible\n");
    }else if ((roads % naming) == 0){
        res -= 1;
        printf("%d\n", res);
    } else {
        printf("%d\n", res);
    } 
    }
    return 0;
}