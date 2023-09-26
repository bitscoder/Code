//vector is an combination of array and list by that i mean
// in vector you get best of both worlds
//as we can access the vector element in o of n complexity 
// and there is no need to assign the size while intializing


//ELEMENT ACCESS
//at(), [], front(), back(), data()

//MODIFIERS:
//insert(), emplace(), push_back(), emplace_back(), pop_back(), resize(), swap(), erase(), clear()

#include<bits/stdc++.h>
using namespace std;

int main(){
    //Number of ways to declare an array
    vector<int> myArray1;
    vector<int> myArray2 = {1,2,3,4,5}; //intializer list
    vector<int> myArray3 {1,2,3,4,5}; //uniform intializer

    vector<int> myArray4;
    myArray4 = {1,2,3,4,5}; //Assign using initialier list

   vector<int> myArray1(5, 0); // basically make every element 0 i.e{0,0,0,0,0}

    // diff between [] and at()
    myArray1[8]; // this will give you some garbage value
    myArray1.at(8);// this will give you an exception

    // internally there is an issue with vector in terms of time taken
    // to address this issue we can just write command vector.reserve()

    myArray1.reserve(1000);
}