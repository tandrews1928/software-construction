// name: Tyler Andrews, tja0023
// partner: NONE\/ filename: hw6.cpp
// due date: 10/19/2018
// collaboration: I did not use any external sources for this assignment.
// problem: Create a doctor class and functions to access and mutate it.

#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cassert>
using namespace std;

void test_AddPatient(void);
void test_userinput(void);
void test_output(void);
void test_reset(void);


class Doctor {
private:
   string name; //the name of the Doctor
   unsigned int numPatients; //the number of patients the Doctor has
   unsigned int array_size; //the size of the array
   string* patientList; //Dynamic Array for the list of patients
   int count; //keeps track of how many patients are on the list
  
public:

   //Constructor
   Doctor(string nameInput, unsigned int array_size);
   //Destructor
   ~Doctor();
   
   
   // Adds a patient and checks that patient array is not full
   // returns true if patient is added
   // return false if patient cannot be added   
   bool AddPatient(string patientname, unsigned int array_size) {
      if (count >= array_size) { //makes sure there are not more patinets being added than the size of the list
         return false;
      }
      else {
         patientList[count] = patientname; //adds the patient
         count++;
         return true;
      }
   }
   
   int userinput() {
      cout << "What is the doctor's name?: ";
      getline(cin, name); //gets the doctors name
      cout << endl;
      
      cout << "Enter the number of patients the Doctor has: ";
      cin >> numPatients; //gets the number of patients
      cout << endl;
      if (numPatients == 0) { //checks to see if there are no patients
         cout << "There are no patients\n";
         return 0;
      }
      cin.clear();cin.ignore(INT_MAX, '\n');
   Doctor:Doctor(name, numPatients); //sets the dynamic array via the constructor
      
      cout << "Enter each patient's name.\n\n";
      int i = 0;S
         
         for (i = 0; i < numPatients; i++) {
         cout << "Patient " << i + 1 << ": "; 
         getline(cin, patientList[i]); //gets the name of the patient
         AddPatient(patientList[i], numPatients); //adds the patient to the dynamic array
         cout << endl;
         }
         cout << endl;
      return i;
      
   }
   
   bool output() {
      if (numPatients == 0) { //checks to see if there are no patients in the array
         cout << name << " has no patients";
         cout << endl;
         return false;
      }
      cout << "The List of Patients for Dr. " << name << " is";
      cout << endl;
      for (int i = 0; i < numPatients; i++) { //outputs the list of patients
         cout << "Patient " << i + 1 << ": ";
         cout << patientList[i];
         cout << endl;
      }   
      return true;
   
   }
   
   int reset() { //resets the array to 0
      numPatients = 0;
   Doctor:Doctor(name, numPatients);
      return numPatients;
   
   }
   
   Doctor& Doctor::operator =(const Doctor& docSource) {
      int i;
      if (this == &docSource) {
         return *this;
      }
      else {
         name.assign(docSource.name);
         numPatients = docSource.numPatients;
      //Create a dynamic array for the target doctor
         delete [] patientList; //delete dynamic array first
         patientList = new string[numPatients];
      //Deep copy patientArray
         for (i = 0; i < numPatients; i++)
            patientList[i].assign(docSource.patientList[i]);
         return *this;
      }
   }
   
   
      
   
   
   

};

Doctor::Doctor(string nameInput, unsigned int array_size) { //constructor defintion
   name = nameInput;
   numPatients = array_size;
   patientList = new string[array_size];
   count = 0;
}

Doctor::~Doctor() { //destructor 
   delete []  patientList;
}

int main() {
 
   #ifdef UNIT_TESTING_ADDPATIENT
   test_AddPatient();
   #endif
   #ifdef UNIT_TESTING_OUTPUT
   test_output();
   #endif
   #ifdef UNIT_TESTING_RESET
   test_reset();
   #endif
   #ifdef UNIT_TESTING_USERINPUT
   test_userinput();
   #endif
  #ifdef Product
   Doctor d("Tyler", 1000);
   d.userinput();
   d.output();
   #endif
   
}   

void test_AddPatient() {

//Test Case 1: add patient to a list of size 10
   bool test;
   string name = "Tyler";
   cout << "AddPatient Test";
   cout << endl;
   cout << "Test Case 1: add patient to a empty list of size 10";
   cout << endl;
   int size = 10;
   Doctor d("Doctor", size);
   test = d.AddPatient(name, size);
   assert(test == true);
   cout << "Case Passed";
   cout << endl;
   cout << endl;
   
   cout << "Test Case 2: add patient to an almost full list of size 3";
   cout << endl;
   size = 3;
   Doctor p("Doctor", size);
   p.AddPatient(name, size);
   p.AddPatient(name, size);
   test = p.AddPatient(name, size);
   assert(test == true);
   cout << "Case Passed";
   cout << endl;
   cout << endl;
   
   cout << "Test Case 3: add patient to a full list of size 3";
   cout << endl;
   size = 3;
   Doctor h("Doctor", size);
   h.AddPatient(name, size);
   h.AddPatient(name, size);
   h.AddPatient(name, size);
   test = h.AddPatient(name, size);
   assert(test == false);
   cout << "Case Passed";
   cout << endl;
   cout << endl;
  
   


}

void test_userinput() {

   Doctor d("Doctor", 10);
   int test;
   string name = "Tyler";
   cout << "userinput Test";
   cout << endl;
   cout << "Test Case 1: list with 3 patients";
   cout << endl;
   test = d.userinput();
   assert(test == 3);
   cout << "Case Passed";
   cout << endl;
   cout << endl;
   
   
   cout << "Test Case 2: list with 10 patients";
   cout << endl;
   test = d.userinput();
   assert(test == 10);
   cout << "Case Passed";
   cout << endl;
   cout << endl;
   
   cout << "Test Case 2: list with 0 patients";
   cout << endl;
   test = d.userinput();
   assert(test == 0);
   cout << "Case Passed";
   cout << endl;
   cout << endl;

}

void test_output() {
   bool test;
   cout << "AddPatient Test";
   cout << endl;
   cout << "Test Case 1: output a list of size 3";
   cout << endl;
   int size = 3;
   Doctor d("Doctor", size);
   d.AddPatient("Tyler", size);
   d.AddPatient("Jay", size);
   d.AddPatient("Jack", size);
   test = d.output();
   assert(test == true);
   cout << "Case Passed";
   cout << endl;
   cout << endl;
   
   cout << "Test Case 2: output a list of size 0";
   cout << endl;
   size = 0;
   Doctor e("Doctor", size);
   test = e.output();
   assert(test == false);
   cout << "Case Passed";
   cout << endl;
   cout << endl;




}

void test_reset() {
   bool test;
   cout << "reset Test";
   cout << endl;
   cout << "Test Case 1: reset a list of size 3";
   cout << endl;
   int size = 3;
   Doctor d("Doctor", size);
   d.AddPatient("Tyler", size);
   d.AddPatient("Jay", size);
   d.AddPatient("Jack", size);
   d.reset();
   test = d.output();
   assert(test == 0);
   cout << "Case Passed";
   cout << endl;
   cout << endl;
   
   cout << "Test Case 2: reset a list of size 10";
   cout << endl;
   size = 10;
   Doctor g("Doctor", size);
   g.AddPatient("Tyler", size);
   g.AddPatient("Jay", size);
   g.AddPatient("Jack", size);
   g.AddPatient("James", size);
   g.AddPatient("Jake", size);
   g.AddPatient("Paul", size);
   g.AddPatient("Ryan", size);
   g.AddPatient("Larry", size);
   g.AddPatient("Lucy", size);
   g.AddPatient("John", size);
   g.reset();
   test = g.output();
   assert(test == 0);
   cout << "Case Passed";
   cout << endl;
   cout << endl;


}






   



   

