#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
}

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}
string reverseWords(string s) {
    string ans;
    string a;
    trim(s);
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == ' '){
            ans = ans + ' ' + a;
            a = "";
        }else{
            a = s[i] + a;
        }
    }
    return ans;
}