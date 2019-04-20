#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cassert>
using namespace std;

int main() {
   int a = 10;
   int *pointer = &a;
   int *b = new int;
   b = pointer;
   
   
   cout << a << endl;
   cout << &a << endl;
   cout << pointer << endl;
   cout << *pointer << endl;
   cout << b << endl;
   cout << *b << endl;
   
}

