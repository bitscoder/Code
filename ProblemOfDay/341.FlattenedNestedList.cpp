#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
}
class NestedInteger {
    public:

      bool isInteger() const;
      int getInteger() const;
      const vector<NestedInteger> &getList() const;
 };
class NestedIterator {
public:
    NestedIterator(const vector<NestedInteger> &nestedList) {
        NestedHelper(nestedList);
    }
    
    
    int next() {
        int front = helperQueue.front();
        helperQueue.pop();
        return front;
    }
    
    bool hasNext() {
        return !helperQueue.empty();
    }
private:
    queue<int> helperQueue;

    void NestedHelper(const vector<NestedInteger> &nestedList){
        for(auto i : nestedList){
            if(i.isInteger()){
                helperQueue.push(i.getInteger());
            }else{
                NestedHelper(i.getList());
            }
        }
    }
};