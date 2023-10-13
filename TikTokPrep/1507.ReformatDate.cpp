#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

string reformatDate(string date)
{
    std::unordered_map<std::string, std::string> months = {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
    string year = "";
    string month = "";
    string num = "";
    int c = 0;
    for (int i = date.size(); i >= 0; i++)
    {
        if (c == 0)
        {
            if (date[i] == ' ')
            {
                c = 1;
            }
            else
            {
                year += date[i];
            }
        }
        else if (c == 1)
        {
            if (date[i] == ' ')
            {
                c = 2;
                month = months[month];
            }
            else
            {
                month += date[i];
            }
        }
        else
        {
            if (i == 9 || i == 10)
                continue;
            else
                num += date[i];
        }
    }
    return year + '-' + month + '-' + ((num.size() == 1) ? ("0" + num) : num);
}