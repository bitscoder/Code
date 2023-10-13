#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool back(vector<int> &pushed, vector<int> &popped, int i, int j, stack<int> helperStack)
{

    if (i == pushed.size() && j == popped.size())
    {
        return true;
    }
    else if (i == pushed.size())
    {
        if (popped[j] == helperStack.top())
        {
            helperStack.pop();
            return back(pushed, popped, i, j + 1, helperStack);
        }
        else
        {
            return false;
        }
    }
    else if (helperStack.size() == 0)
    {
        helperStack.push(pushed[i]);
        return back(pushed, popped, i + 1, j, helperStack);
    }
    else
    {
        helperStack.push(pushed[i]);
        bool pushBool = back(pushed, popped, i + 1, j, helperStack);
        helperStack.pop();
        if (popped[j] == helperStack.top())
        {
            helperStack.pop();
            bool popBool = back(pushed, popped, i, j + 1, helperStack);
            return popBool | pushBool;
        }
        else
        {
            return pushBool;
        }
    }
}

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> helperStack;
    return back(pushed, popped, 0, 0, helperStack);
}