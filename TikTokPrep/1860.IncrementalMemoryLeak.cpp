#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<int> memLeak(int memory1, int memory2)
{
    int secondsCount = 0;
    int curBit = memory1 >= memory2 ? 0 : 1;
    int i = 1;
    while ((curBit == 0 && (memory1 - i) >= 0) || (curBit == 1 && (memory2 - i) >= 0))
    {
        if (!curBit)
        {
            memory1 = memory1 - i;
        }
        else
        {
            memory2 = memory2 - i;
        }
        i++;
        curBit = memory1 >= memory2 ? 0 : 1;
    }
    return vector<int>({i, memory1, memory2});
}