#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int numOfWalls;
    int cases;
    int sizeOfWalls[50];

    scanf("%d",&cases);
    for(int i = 1; i <= cases; i++) {
        scanf("%d",&numOfWalls);
        for (int j = 0; j < numOfWalls; j++) {
            scanf("%d",&sizeOfWalls[j]);
        }
        int lowJump = 0;
        int highJump = 0;
        for (int k = 0; k < numOfWalls - 1; k++) {
            if (sizeOfWalls[k + 1] < sizeOfWalls[k]) {
                lowJump++;
            } else if (sizeOfWalls[k + 1] > sizeOfWalls[k]){
                highJump++;
            }
        }
        printf("Case %d: %d %d\n", i, highJump, lowJump);
    }
    return 0;
}