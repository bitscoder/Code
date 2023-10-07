#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str = "1,2,4;3,4.5";
    string s;

    stringstream ss(str);
    while (getline(ss, s, ';'))
    {
        cout << s << endl;
        stringstream ss2(s);
        string s2;
        while (getline(ss2, s2, ','))
        {
            cout << s2 << endl;
        }
    }
    cout << stoi("-12") << endl;
}
struct Product
{
    std::string Name;
    std::optional<double> Price;
    std::vector<std::string> Ingredients;
};

double MySolution(const std::string &target, const std::vector<Product> &products)
{
    int n = products.size();
    for (int i = 0; i < n; i++)
    {
        if (products[i].Name == target)
        {
            double cost = 0;
            int m = products[i].Ingredients.size();
            for (int j = 0; j < m; j++)
            {
                double val = MySolution(products[i].Ingredients[j], products);
                cost += val;
            }
            if (cost == 0)
                return *products[i].Price;
            if (products[i].Price)
                return cost;
            if (cost > products[i].Price)
                return *products[i].Price;
            else
                return cost;
        }
    }

    return -1;
}

int main()
{
    string line;
    vector<pair<int, double>> buyVector;
    vector<pair<int, double>> sellVector;
    getline(cin, line);
    stringstream ss(line);
    string s;
    int c = 0;
    int quant = 0;
    double price = 0;
    while (getline(ss, s, ' '))
    {
        if (c == 0)
        {
            quant = stoi(s);
            c = 1;
            continue;
        }
        else if (c == 1)
        {
            price = stod(s);
            buyVector.push_back({quant, price});
            c = 0;
        }
    }
    getline(cin, line);
    stringstream ss(line);
    string s;
    int c = 0;
    int quant = 0;
    double price = 0;
    while (getline(ss, s, ' '))
    {
        if (c == 0)
        {
            quant = stoi(s);
            c = 1;
            continue;
        }
        else if (c == 1)
        {
            price = stod(s);
            sellVector.push_back({quant, price});
            c = 0;
        }
    }
    double buyCarry = 0;
    double sellCarry = 0;
    while (getline(cin, line))
    {
        // cout << line << endl;
        stringstream ss(line);
        string s;
        int c = 0;
        int quant;
        double price;
        while (getline(ss, s, ' '))
        {
            if (c == 0)
            {
                quant = stoi(s);
                c = 1;
                continue;
            }
            else
            {
                price = stod(s);
                double amount = quant * price;

                if (amount < 0)
                {
                    amount += sellCarry;
                    sellCarry = amount - (int)amount;
                    int curAmount = abs((int)amount);
                    double ans = 0;
                    for (int i = 0; i < 3; i++)
                    {
                        if (sellVector[i].first >= curAmount)
                        {
                            ans += curAmount * sellVector[i].second;
                            sellVector[i].first = sellVector[i].first - curAmount;
                            curAmount = 0;
                            break;
                        }
                        else
                        {
                            ans += sellVector[i].first * sellVector[i].second;
                            curAmount = curAmount - sellVector[i].first;
                            sellVector[i].first = 0;
                        }
                    }
                    cout << amount << " " << ans / abs(amount) << endl;
                }
                else
                {
                    amount += buyCarry;
                    buyCarry = amount - (int)amount;
                    int curAmount = abs((int)amount);
                    double ans = 0;
                    for (int i = 0; i < 3; i++)
                    {
                        if (buyVector[i].first >= curAmount)
                        {
                            ans += curAmount * buyVector[i].second;
                            buyVector[i].first = buyVector[i].first - curAmount;
                            curAmount = 0;
                            break;
                        }
                        else
                        {
                            ans += buyVector[i].first * buyVector[i].second;
                            curAmount = curAmount - buyVector[i].first;
                            buyVector[i].first = 0;
                        }
                    }
                    cout << amount << " " << ans / abs(amount) << endl;
                }

                c = 0;
            }
        }
    }
}
