#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class SeatManager
{
private:
    priority_queue<int, vector<int>, greater<int>()> pq;

public:
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            pq.push(i);
        }
    }

    int reserve()
    {
        int cur = pq.top();
        pq.pop();
        return cur;
    }

    void unreserve(int seatNumber)
    {
        pq.push(seatNumber);
    }
};