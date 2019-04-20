// name: Tyler Andrews, tja0023
// partner: NONE
// filename: hw01.cpp
// due date: 08/31/2018
// collaboration: I did not use any external sources for this assignment.
// problem: determine how much diet soda it is possible to drink without dying as a result

#include <iostream>
using namespace std;
const double RATIO = 0.001;

int main() {
   double lethal_amount, mouse_weight, your_weight, threshold;
   // get lethal amount
   cout << "What is the amount of artificial sweetener needed to kill a mouse: ";
   cout << "\n";
   cin >> lethal_amount;
   cout << "\n";
   // get mouse weight
   cout << "What is the weight of the mouse: ";
   cin >> mouse_weight;
   cout << "\n";
   // get dieter weight
   cout << "What is the weight of the dieter: ";
   cin  >> your_weight;
   cout << "\n"; 
   // compute amount of diet soda that can be drank
   threshold = (lethal_amount / mouse_weight) * (your_weight / RATIO);
   // output amount of diet soda that can be drank
   cout << "You can drink " << threshold << " diet soda without dying as a result.";
}
