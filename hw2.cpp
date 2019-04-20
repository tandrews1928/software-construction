// name: Tyler Andrews, tja0023
// partner: NONE
// filename: hw2.cpp
// due date: 09/07/2018
// collaboration: I did not use any external sources for this assignment.
// problem: Write a program that will tell you how many months it will take you to pay off this loan
// in particular and any loan in general.

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  
  
   double interest, monthly_payments, balance, interest_rate, principal, rate, total_interest = 0;
   int month = 0;
   cout << "Loan Amount: ";
   cin >> balance; // get loan amount
   cout << "Interest Rate (% per year): ";
   cin >> rate; // get interest rate
   cout << "Monthly Payments: ";
   cin >> monthly_payments; // get monthly payments
   
   if (monthly_payments < rate) {
      cout << "Error: monthly payment is less than interest."; // prints error if monthly payments are less that the interest rate
      return 0;
   }
   
   rate = rate / 12; // converts yearly rate to monthly rate
   interest_rate = rate * .01;
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << "\n******************************************************\n";
   cout << "      Amortization Table\n";
   cout << "******************************************************\n";
   cout << "Month Balance    Payment  Rate  Interest  Principal\n";
   cout << left << setw(6) << month << "$";
   cout << left << setw(10) << balance << "$";
   cout << left << setw(8) << monthly_payments;
   cout << left << setw(6) << "N/A";
   cout << left << setw(10) << "N/A";
   cout << "N/A";
   cout << "\n";

   
   while (balance > 0)  {
      if (balance > monthly_payments) {
         interest = balance * interest_rate; // calculates interest
         principal = monthly_payments - interest; // calculates pricipal
         balance = balance - principal; // calculates balance after payment
         
      }
      else { //last payment
         interest = balance * interest_rate; // calculates interest
         monthly_payments = balance + interest; // calculates monthly payment for the last payment
         principal = monthly_payments - interest; // calculates principal
         balance = 0;
      }
      total_interest = total_interest + interest; // calculates total interest
      month++;   
      cout << left << setw(6) << month << "$";
      cout << left << setw(10) << balance << "$";
      cout << left << setw(8) << monthly_payments;
      cout << left << setw(6) << rate << "$";
      cout << left << setw(9) << interest << "$";
      cout << principal;
      cout << "\n"; 
      
      
      
   }
   cout << "******************************************************\n\n";
   cout << "It takes " << month << " months to pay off the loan." << "\n";
   cout << "Total interest paid is: $" << total_interest; 
}
