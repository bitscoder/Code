#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<vector<int>> generateMatrix(int n)
{

    int dirX = 1;
    int dirY = 0;

    int l = 0;
    int r = 1;

    vector<vector<int>> ansVector(n, vector<int>(n, 0));
    int index = 1;
    while (index != (n * n) + 1)
    {
        int nrow = l + dirX;
        int ncol = r + dirY;
        if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= n || ansVector[nrow][ncol] != 0)
        {
            int temp = dirX;
            dirX = dirY;
            dirY = -1 * temp;
        }
        else
        {
            l = nrow;
            r = ncol;
            ansVector[l][r] = index++;
        }
    }
    return ansVector;
}

vector<int> addToArrayForm(vector<int> &num, int k)
{
    string tempNum = "";
    for (auto i : num)
    {
        tempNum = tempNum + (char)(i + '0');
    }
    int cur = stoi(tempNum) + k;
    vector<int> ansVector;
    while (cur != 0)
    {
        ansVector.push_back(cur % 10);
        cur = cur / 10;
    }
    reverse(ansVector.begin(), ansVector.end());
    return ansVector;
}