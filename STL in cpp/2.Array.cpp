
//Syntax: std::array<int, n> arrayName;

//1. std::array is a container that encapsulates fixed size arrays.
//2. array size is needed at compile time.
//3. Assign by value is actually by value.
//4. Access Elements:
//   a. at() // will throw an exception
//   b. []
//   c. front()
//   d. back()
//   e. data() // gives access to the underlying array
#include<bits/stdc++.h>
using namespace std;

int main(){
    //Number of ways to declare an array
    array<int, 5> myArray1;
    array<int, 5> myArray2 = {1,2,3,4,5}; //intializer list
    array<int, 5> myArray3 {1,2,3,4,5}; //uniform intializer

    array<int, 5> myArray4;
    myArray4 = {1,2,3,4,5}; //Assign using initialier list

    myArray4.fill(0);// basically make every element 0 i.e{0,0,0,0,0}

}