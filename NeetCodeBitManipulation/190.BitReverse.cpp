#include <bits/stdc++.h>
using namespace std;
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= n & 1;
            n >>= 1;
        }
        
        return result;
}
int missingNumber(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        ans = ans ^ i ^ nums[i];
    }       
    ans = ans ^ nums[n];
    return ans;
}

int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int temp = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && temp > 7)) {
                return 0;
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && temp < -8)) {
                return 0;
            }
            rev = rev * 10 + temp;
        }
        return rev;
    }
bool check(vector<int> a, vector<int> b){
    return a[0] < b[0];
}
int numberOfPoints(vector<vector<int>>& nums) {
    sort(nums.begin(), nums.end(), check);
    int n = nums.size();
    int curend = 0;
    int points = 0;
    for(int i = 0; i < n; i++){
        points += nums[i][1] - nums[i][0] + 1;
        points -=  min(curend, nums[i][1])- nums[i][0] + 1 > 0 ? min(curend, nums[i][1]) - nums[i][0] + 1 : 0;
        if(curend < nums[i][1])
            curend = nums[i][1];
         
    }
    return points;
}
/*
Input: sx = 2, sy = 4, fx = 7, fy = 7, t = 6
Output: true
Explanation: Starting at cell (2, 4), we can reach cell (7, 7) in exactly 6 seconds by going through the cells depicted in the picture above. 
*/
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

    int a = min((fx - sx),(fy - sy));
    int b = max((fx - sx),(fy - sy)) - min((fx - sx),(fy - sy));
    //bool a = sqrt((fx - sx) * (fx - sx) + (fy - sy) * (fy - sy));
    if(a + b > t)
        return false;
    else if(a + b == t)
        return true;
    else if(t = 1 && a+b == 0)
        return false;
    else return true;
}
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int dx = abs(fx - sx);
    int dy = abs(fy - sy);

        int a = min(dx,dy);
        int b = max(dx,dy) - min(dx,dy);
        //bool a = sqrt((fx - sx) * (fx - sx) + (fy - sy) * (fy - sy));
        if(a + b > t)
            return false;
        else if(a + b == t)
            return true;
        else if(t == 1 && a+b == 0)
            return false;
        else return true;
    }
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int dx = abs(fx - sx);
    int dy = abs(fy - sy);

        int a = min(dx,dy);
        int b = max(dx,dy) - min(dx,dy);
        //bool a = sqrt((fx - sx) * (fx - sx) + (fy - sy) * (fy - sy));
        if(a + b > t)
            return false;
        else if(a + b == t)
            return true;
        else if(t == 1 && a+b == 0)
            return false;
        else return true;
    }
int minimumMoves(vector<vector<int>>& grid) {
    vector<vector<int>> helperVector;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[i][j] == 0){

            }
        }
    }
}

int backTracking(vector<vector<int>>& grid, int i , int j)
{
    
}