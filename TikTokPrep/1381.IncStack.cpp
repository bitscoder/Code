#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class CustomStack
{
public:
    CustomStack(int maxSize)
    {
        helperVector = vector<int>(1001, 0);
        i = -1;
        size = maxSize;
    }

    void push(int x)
    {
        if (i == size)
            return;
        cout << "push" << endl;
        helperVector[++i] = x;
    }

    int pop()
    {
        if (i == -1)
            return -1;
        cout << "pop" << endl;
        return helperVector[i--];
    }

    void increment(int k, int val)
    {
        for (int d = 0; d <= k; d++)
        {
            cout << helperVector[d] << endl;
        }
        cout << "inc" << endl;
        for (int j = 0; j < k && j <= i; j++)
        {
            helperVector[j] += val;
        }
    }

private:
    vector<int> helperVector;
    int i;
    int size;
};
