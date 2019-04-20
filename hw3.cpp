// name: Tyler Andrews, tja0023
// partner: NONE
// filename: hw3.cpp
// due date: 09/14/2018
// collaboration: I did not use any external sources for this assignment.
// problem: Write a program that tests two dueling strategies against each other to 
// figure out which strategy is most effective.

# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <time.h>
#include <conio.h>
const int SIM_NUM = 10000;
const int A_RATE = 100;
const int B_RATE = 50;
const int PERCENT = 100;
//prototypes
void Aaron_shoots1(bool&, bool&);
void Aaron_shoots2(bool&, bool&);
void Bob_shoots(bool&, bool&);
void Charlie_shoots(bool&, bool&);
void test_Aaron_shoots();
void test_Bob_shoots();
void test_Charlie_shoots();
void test_Aaron_shoots2();
void test_at_least_two_alive();

using namespace std;

bool at_least_two_alive(bool a_alive, bool b_alive, bool c_alive) {
/* Input: a_alive indicates whether Aaron is alive */
/* b_alive indicates whether Bob is alive */
/* c_alive indicates whether Charlie is alive */
/* Return: true if at least two are alive */
/* otherwise return false */
   

   if (a_alive == true && b_alive == true && c_alive == true) { //all three are alive
      return true;
   }
   else if (a_alive == true && b_alive == true) { //two alive
      return true;
   }
   else if (a_alive == true && c_alive == true) { //two alive
      return true;
   }
   else if (b_alive == true && c_alive == true) { //two alive
      return true;
   }
   else { 
      return false; //one or less alive
   }

}
void Aaron_shoots1(bool &b_alive, bool &c_alive) {
/* Strategy 1: Use call by reference
* Input: b_alive indicates whether Bob alive or dead
* c_alive indicates whether Charlie is alive or dead
* Return: Change b_alive into false if Bob is killed.
* Change c_alive into false if Charlie is killed.
*/ 
      
   if (c_alive == true) {
      
      int shoot_target_result = rand() % 300; //generates a random number between 0 and 300
      if (shoot_target_result <= A_RATE) { //checks if random number is less that 100
         c_alive = false;
      }
   }
   else if (b_alive == true) { 
      
      int shoot_target_result = rand() % 300; //generates a random number between 0 and 300
      if (shoot_target_result <= A_RATE) {  //checks if random number is less that 100
         b_alive = false;
      }
   
   }
   
   
   


}
void Bob_shoots(bool &a_alive, bool &c_alive) {
/* Call by reference
* Input: a_alive indicates if Aaron is alive or dead
* c_alive indicates whether Charlie is alive or dead
* Return: Change a_alive into false if Aaron is killed.
* Change c_alive into false if Charlie is killed.
*/
   
  
   
   if (c_alive == true) {
      
      int shoot_target_result = rand() % 100; //generates a random number between 0 and 100
      if (shoot_target_result <= B_RATE) { //checks if random number is less than 50
         c_alive = false;
      }
   }
   else if (a_alive == true) {
   
      int shoot_target_result = rand() % 100; //generates a random number between 0 and 100
      if (shoot_target_result <= B_RATE) { //checks if random number is less that 50
         a_alive = false;
      }
   
   }


}
void Charlie_shoots(bool &a_alive, bool &b_alive)  {
/* Call by reference
* Input: a_alive indicates if Aaron is alive or dead
* b_alive indicates whether Bob is alive or dead
* Return: Change a_alive into false if Aaron is killed.
* Change b_alive into false if Bob is killed.
*/
   
   
   if (b_alive == true) { //checks if Bob is alive
   
      b_alive = false;
      
   }
   else if (a_alive == true) { //checks if Aaron is alive
      a_alive = false;
      
   
   }

}
void Aaron_shoots2(bool &b_alive, bool &c_alive)  {
/* Strategy 2: Use call by reference
* Input: b_alive indicates whether Bob alive or dead
* c_alive indicates whether Charlie is alive or dead
* Return: Change b_alive into false if Bob is killed.
* Change c_alive into false if Charlie is killed.
*/   

   
   if (b_alive == true && c_alive == true) { //if both are alive intentionally misses shot
      b_alive = true;
      c_alive = true;
   }
   else {
      Aaron_shoots1(b_alive, c_alive); //if only one other is alive takes the shot
   }
}

int main() {
   
  
   cout << "*** Welcome to Puzzlevania’s Duel Simulator ***\n";
   cout << "Unit Testing 1: Function – at_least_two_alive()\n";
   test_at_least_two_alive(); //tests the at_least_two_alive method
   cout << "Press any key to continue...\n";
   cin.ignore().get();
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   test_Aaron_shoots(); //tests the Aaron_shoots1 method
   cout << "Press any key to continue...\n";
   cin.ignore().get();
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   test_Bob_shoots(); //tests the Bob_shoots method
   cout << "Press any key to continue...\n";
   cin.ignore().get();
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   test_Charlie_shoots(); //tests the Charlie_shoots method
   cout << "Press any key to continue...\n";
   cin.ignore().get(); 
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   test_Aaron_shoots2(); //tests the Aaron_shoots2 method
   cout << "Press any key to continue...\n";
   cin.ignore().get();
   
   srand(time(0)); 
   double a_win = 0;
   double b_win = 0;
   double c_win = 0;
   
   cout << "Ready to test strategy 1 (run 10000 times): \n";
   cout << "Press any key to continue...\n";
   cin.ignore().get();
   cout << "...\n...\n...\n\n";
   
   for (int i = 0; i < SIM_NUM; i++) { //runs 10,000 simulations of Strategy 1
      bool a_alive = true; 
      bool b_alive = true;
      bool c_alive = true;
      while (at_least_two_alive(a_alive, b_alive, c_alive)) { //runs the simulation until only one shooter remains
         if (a_alive == true) {
            Aaron_shoots1(b_alive, c_alive); 
         }
         if (b_alive == true) {
            Bob_shoots(a_alive, c_alive);
         }
         if (c_alive == true) {
            Charlie_shoots(a_alive, b_alive);
         }
      
      
         if (a_alive == true && b_alive == false && c_alive == false) { //checks to see if Aaron is the last man standing
            a_win++;
         }
         if (b_alive == true && a_alive == false && c_alive == false) { //checks to see if Bob is the last man standing
            b_win++;
         }
         if (c_alive == true && b_alive == false && a_alive == false) { //checks to see if Charlie is the last man standing
            c_win++;
         }
         
      }
   }
   double A_percent = (a_win / SIM_NUM) * PERCENT; //calculates how many simulations were won by each person
   double B_percent = (b_win / SIM_NUM) * PERCENT;
   double C_percent = (c_win / SIM_NUM) * PERCENT;
   cout << "Aaron won " << a_win << "/" << SIM_NUM << " duels or " << A_percent << "%\n";
   cout << "Bob won " << b_win << "/" << SIM_NUM << " duels or " << B_percent << "%\n";
   cout << "Charlie won " << c_win << "/" << SIM_NUM << " duels or " << C_percent << "%\n";
      
   double a_win2 = 0;
   double b_win2 = 0;
   double c_win2 = 0;
   
   cout << "\nReady to test strategy 2 (run 10000 times): \n";
   cout << "Press any key to continue...\n";
   cin.ignore().get();
   cout << "...\n...\n...\n\n";
   
   for (int i = 0; i < SIM_NUM; i++) { //runs 10,000 simulations of Strategy 2
      bool a_alive = true;
      bool b_alive = true;
      bool c_alive = true;
      while (at_least_two_alive(a_alive, b_alive, c_alive)) { //runs the simulation until only one shooter remains
         if (a_alive == true) {
            Aaron_shoots2(b_alive, c_alive); 
         }
         if (b_alive == true) {
            Bob_shoots(a_alive, c_alive);
         }
         if (c_alive == true) {
            Charlie_shoots(a_alive, b_alive);
         }
      
      
         if (a_alive == true && b_alive == false && c_alive == false) { //checks to see if Aaron is the last man standing
            a_win2++;
         }
         if (b_alive == true && a_alive == false && c_alive == false) { //checks to see if Bob is the last man standing
            b_win2++;
         }
         if (c_alive == true && b_alive == false && a_alive == false) { //checks to see if Charlie is the last man standing
            c_win2++;
         }
         
      }
   }
   A_percent = (a_win2 / SIM_NUM) * PERCENT;
   B_percent = (b_win2 / SIM_NUM) * PERCENT;
   C_percent = (c_win2 / SIM_NUM) * PERCENT;
   cout << "Aaron won " << a_win2 << "/" << SIM_NUM << " duels or " << A_percent << "%\n";
   cout << "Bob won " << b_win2 << "/" << SIM_NUM << " duels or " << B_percent << "%\n";
   cout << "Charlie won " << c_win2 << "/" << SIM_NUM << " duels or " << C_percent << "%\n";
   //determines which strategy is better
   if (a_win > a_win2) {
      cout << "\nStrategy 1 is better than strategy 2.";
   }
   else {
      cout << "\nStrategy 2 is better than strategy 1.";
   }
   
   return 0;

}
void test_at_least_two_alive(void) { //test for at_least_two_alive method
   bool a_alive;
   bool b_alive;
   bool c_alive;
   cout << "\t\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\t\tCase passed ...\n";
   cout << "\t\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\t\tCase passed ...\n";
   cout << "\t\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\t\tCase passed ...\n"; 
   cout << "\t\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\t\tCase passed ...\n";
   cout << "\t\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\t\tCase passed ...\n";
   cout << "\t\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\t\tCase passed ...\n";
   cout << "\t\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\t\tCase passed ...\n";
   cout << "\t\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\t\tCase passed ...\n";

}

void test_Aaron_shoots(void) { //test for Aaron_shoots1 method
   bool b_alive;
   bool c_alive;
   b_alive = true;
   c_alive = true;
   cout << "\t\tCase 1: Bob alive, Charlie alive\n";
   Aaron_shoots1(b_alive, c_alive);
   cout << "\t\t\t\tAaron is shooting at Charlie\n";
   b_alive = false;
   c_alive = true;
   cout << "\t\tCase 2: Bob dead, Charlie alive\n";
   Aaron_shoots1(b_alive, c_alive);
   cout << "\t\t\t\tAaron is shooting at Charlie\n";
   b_alive = true;
   c_alive = false;
   cout << "\t\tCase 3: Bob alive, Charlie dead\n";
   Aaron_shoots1(b_alive, c_alive);
   cout << "\t\t\t\tAaron is shooting at Bob\n";
   b_alive = false;
   c_alive = false;
   Aaron_shoots1(b_alive, c_alive);
}

void test_Bob_shoots(void) { //test for Bob_shoots method
   bool a_alive;
   bool c_alive;
   a_alive = true;
   c_alive = true;
   cout << "\t\tCase 1: Aaron alive, Charlie alive\n";
   Bob_shoots(a_alive, c_alive);
   cout << "\t\t\t\tBob is shooting at Charlie\n";
   a_alive = false;
   c_alive = true;
   cout << "\t\tCase 2: Aaron dead, Charlie alive\n";
   Bob_shoots(a_alive, c_alive);
   cout << "\t\t\t\tBob is shooting at Charlie\n";
   a_alive = true;
   c_alive = false;
   cout << "\t\tCase 3: Aaron alive, Charlie dead\n";
   Bob_shoots(a_alive, c_alive);
   cout << "\t\t\t\tBob is shooting at Aaron\n";
   a_alive = false;
   c_alive = false;
   Bob_shoots(a_alive, c_alive);
}

void test_Charlie_shoots(void) { //test for Charlie_shoots method
   bool a_alive;
   bool b_alive;
   a_alive = true;
   b_alive = true;
   cout << "\t\tCase 1: Aaron alive, Bob alive\n";
   Charlie_shoots(a_alive, b_alive);
   cout << "\t\t\t\tCharlie is shooting at Bob\n";
   a_alive = false;
   b_alive = true;
   cout << "\t\tCase 2: Aaron dead, Bob alive\n";
   Charlie_shoots(a_alive, b_alive);
   cout << "\t\t\t\tCharlie is shooting at Bob\n";
   a_alive = true;
   b_alive = false;
   cout << "\t\tCase 3: Aaron alive, Bob dead\n";
   Charlie_shoots(a_alive, b_alive);
   cout << "\t\t\t\tCharlie is shooting at Aaron\n";
   a_alive = false;
   b_alive = false;
   Charlie_shoots(a_alive, b_alive);
}

void test_Aaron_shoots2(void) { //test for Aaron_shoots2 method
   bool b_alive;
   bool c_alive;
   b_alive = true;
   c_alive = true;
   cout << "\t\tCase 1: Bob alive, Charlie alive\n";
   Aaron_shoots2(b_alive, c_alive);
   cout << "\t\t\t\tAaron intentionally misses his first shot\n";
   cout << "\t\t\t\tBoth Bob and Charlie are alive.\n";
   b_alive = false;
   c_alive = true;
   cout << "\t\tCase 2: Bob dead, Charlie alive\n";
   Aaron_shoots2(b_alive, c_alive);
   cout << "\t\t\t\tAaron is shooting at Charlie\n";
   b_alive = true;
   c_alive = false;
   cout << "\t\tCase 3: Bob alive, Charlie dead\n";
   Aaron_shoots2(b_alive, c_alive);
   cout << "\t\t\t\tAaron is shooting at Bob\n";
   b_alive = false;
   c_alive = false;
   Aaron_shoots2(b_alive, c_alive);
}



