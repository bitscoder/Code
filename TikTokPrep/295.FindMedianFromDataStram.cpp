#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class MedianFinder
{
public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (leftHeap.size() == 0 && rightHeap.size() == 0)
        {
            rightHeap.push(num);
            return;
        }
        if (num < rightHeap.top())
        {
            if (rightHeap.size() == leftHeap.size())
            {
                rightHeap.push(num);
            }
            else
            {
                leftHeap.push(num);
            }
            return;
        }
        else
        {
            rightHeap.push(num);
            if (rightHeap.size() - leftHeap.size() == 2)
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
            }
            return;
        }
    }

    double findMedian()
    {
        if (leftHeap.size() == rightHeap.size())
        {
            return (double)(leftHeap.top() + rightHeap.top()) / 2;
        }
        else
        {
            rightHeap.top();
        }
    }

private:
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
};