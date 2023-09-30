#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
class Solution
{
public:
    std::string decodeAtIndex(string s, int k)
    {
        long long length = 0;
        int i = 0;

        while (length < k)
        {
            if (isdigit(s[i]))
            {
                length *= s[i] - '0';
            }
            else
            {
                length++;
            }
            i++;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            if (isdigit(s[j]))
            {
                length /= s[j] - '0';
                k %= length;
            }
            else
            {
                if (k == 0 || k == length)
                {
                    return std::string(1, s[j]);
                }
                length--;
            }
        }

        return "";
    }
};