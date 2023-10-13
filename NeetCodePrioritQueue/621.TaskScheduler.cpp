#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
/*
621. Task Scheduler
Medium

9015

1834

Add to List

Share
Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task.
Tasks could be done in any order.
Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array),
that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.



Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation:
A -> B -> idle -> A -> B -> idle -> A -> B
There is at least 2 units of time between any two same tasks.
Example 2:

Input: tasks = ["A","A","A","B","B","B"], n = 0
Output: 6
Explanation: On this case any permutation of size 6 would work since n = 0.
["A","A","A","B","B","B"]
["A","B","A","B","A","B"]
["B","B","B","A","A","A"]
...
And so on.
Example 3:

Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
Output: 16
Explanation:
One possible solution is
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
*/
int leastInterval(vector<char> &tasks, int n)
{
    int k = tasks.size();
    vector<int> helperVector(26, 0);

    for (int i = 0; i < k; i++)
    {
        helperVector[tasks[i] - 'A']++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        count = max(count, helperVector[i]);
    }
    return count + (count - 1) * n;
}
int differenceOfSums(int n, int m)
{
    int num1 = 0;
    int num2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % m == 0)
        {
            num1 += i;
        }
        else
            num2 += i;
    }
    return num1 - num2;
}
int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
{
    sort(processorTime.begin(), processorTime.end());
    sort(tasks.begin(), tasks.end(), greater<int>());
    int n = processorTime.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ans = max(ans, processorTime[i] + tasks[i * 4 + j]);
        }
    }
    return ans;
}
/*
Input: s1 = "1100011000", s2 = "0101001010", x = 2
Output: 4
Explanation: We can do the following operations:
- Choose i = 3 and apply the second operation. The resulting string is s1 = "1101111000".
- Choose i = 4 and apply the second operation. The resulting string is s1 = "1101001000".
- Choose i = 0 and j = 8 and apply the first operation. The resulting string is s1 = "0101001010" = s2.
The total cost is 1 + 1 + 2 = 4. It can be shown that it is the minimum cost possible.
*/
int back(string s1, string s2, int x, int i)
{
    if (s1[i] == s2[i])
    {
        return 0 + back(s1, s2, x, i + 1);
    }
    else
    {
    }
}
int minOperations(string s1, string s2, int x)
{
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
    }
}