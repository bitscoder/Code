#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

bool isRobotBounded(string instructions)
{
    int dirX = 0;
    int dirY = 1;

    int curX = 0;
    int curY = 0;

    for (auto i : instructions)
    {
        if (i == 'G')
        {
            curX = curX + dirX;
            curY = curY + dirY;
        }
        else if (i == 'L')
        {
            int temp = dirX;
            dirX = -1 * dirY;
            dirY = temp;
        }
        else
        {
            int temp = dirX;
            dirX = dirY;
            dirY = -1 * temp;
        }
    }
    if (curX == 0 && curY == 0)
    {
        return true;
    }
    else if (!(dirX == 0 && dirY == 1))
    {
        return true;
    }
    return false;
}