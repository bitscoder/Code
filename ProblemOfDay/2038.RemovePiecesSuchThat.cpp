#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool winnerOfGame(string colors)
{
    int countA = 0;
    int countB = 0;
    int n = colors.size();
    for (int i = 1; i < n - 1; i++)
    {
        if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
        {
            countA++;
        }
        if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
        {
            countB++;
        }
    }
    if (countA > countB)
        return true;
    else
        return false;
}
/*
Input: colors = "AAABABB"
Output: true
Explanation:
AAABABB -> AABABB
Alice moves first.
She removes the second 'A' from the left since that is the only 'A' whose neighbors are both 'A'.

Now it's Bob's turn.
Bob cannot make a move on his turn since there are no 'B's whose neighbors are both 'B'.
Thus, Alice wins, so return true.
*/