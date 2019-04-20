// name: Tyler Andrews, tja0023
// partner: NONE
// filename: hw4.cpp
// due date: 09/21/2018
// collaboration: I did not use any external sources for this assignment.
// problem: Write a program that merges the numbers in two files and writes all the numbers into a third file.

#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib> //for exit()
using namespace std;
int readfile(int inputArray[], ifstream& inStream);
int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile(int outputArray[], int outputArray_size, ofstream &outStream);

const int MAX_SIZE = 1000;


void test1_sort(void) {

   
   int inputArray1_size;
   int inputArray2_size;
   int outputArray_size;
   int inputArray1[MAX_SIZE];
   int inputArray2[MAX_SIZE];
   int outputArray[MAX_SIZE];
   
   cout <<"Unit Test Case 1: Sort()\n";
   cout <<"\t\tCase 1.1: input array1 = (4, 13, 14, 17, 23, 89) input array2 = (3, 7, 9, 14, 15, 5)\n";
  
  //Array1
   inputArray1[0] = 4;
   inputArray1[1] = 13;
   inputArray1[2] = 14;
   inputArray1[3] = 17;
   inputArray1[4] = 23;
   inputArray1[5] = 89;
   inputArray1_size = 6;
   
   //Array2
   
   inputArray2[0] = 3;
   inputArray2[1] = 7;
   inputArray2[2] = 9;
   inputArray2[3] = 14;
   inputArray2[4] = 15;
   inputArray2_size = 5;
   
   outputArray_size = sort(inputArray1, inputArray1_size, inputArray2, inputArray2_size, outputArray);
   
   //Testing...
   
   assert(outputArray[0] == 3);
   assert(outputArray[1] == 4);
   assert(outputArray[2] == 7);
   assert(outputArray[3] == 9);
   assert(outputArray[4] == 13);
   assert(outputArray[5] == 14);
   assert(outputArray[6] == 14);
   assert(outputArray[7] == 15);
   assert(outputArray[8] == 17);
   assert(outputArray[9] == 23);
   assert(outputArray[10] == 89);
   
   cout << "\t\tCase 1.1 passed.\n";
   
   
   
  
}

void test2_sort(void) {

   
   int inputArray1_size = 3;
   int inputArray2_size = 1;
   int outputArray_size;
   int inputArray1[MAX_SIZE];
   int inputArray2[MAX_SIZE];
   int outputArray[MAX_SIZE];
   
   cout <<"\t\tCase 1.2: input array1 = (3, 6, 10) input array2 = (2)\n";
  
  //Array1
   inputArray1[0] = 3;
   inputArray1[1] = 6;
   inputArray1[2] = 10;
   
   //Array2
   
   inputArray2[0] = 2;
   
   
   outputArray_size = sort(inputArray1, inputArray1_size, inputArray2, inputArray2_size, outputArray);
   
   //Testing...
   
   assert(outputArray[0] == 2);
   assert(outputArray[1] == 3);
   assert(outputArray[2] == 6);
   assert(outputArray[3] == 10);
  
   
   cout << "\t\tCase 1.2 passed.\n";
   
   
   
  
}

void test_readfile(void) {
   cout <<"Unit Test Case 2: readfile()\n";
   cout <<"\t\tCase 1.1: input Array of 4 integers\n";
   ifstream in1;
   ifstream in2;
   string inFile;
   int iArray1[MAX_SIZE];
   int iArray1_size = 0;
   int iArray2[MAX_SIZE];
   int iArray2_size = 0;
   string int1 = "input3.txt";
   string int2 = "input4.txt";
   in1.open(int1.c_str());
   iArray1_size = readfile(iArray1, in1);
   assert(iArray1_size);
   in1.close();
   cout << "\t\tCase 1.1 passed.\n";
   cout <<"\t\tCase 1.2: input Array of 15 integers\n";
   in2.open(int2.c_str());
   iArray2_size = readfile(iArray2, in2);
   assert(iArray2_size);
   in2.close();
   cout <<"\t\tCase 1.2 passed.\n";



   
   




}


  
  

int main( ) {

   int iArray1[MAX_SIZE];
   int iArray1_size = 0;
   int iArray2[MAX_SIZE];
   int iArray2_size = 0;
   int sorted_array[MAX_SIZE];
   int sorted_array_size;
   string developer("Tyler Andrews");
   string inFile;
   string inFile2;
   string inFile3;
   ifstream in1;
   ifstream in2;
   ofstream o1;
   cout << "*** Unit Test Cases ***\n";
   test1_sort();
   test2_sort();
   cout << "Press any key to continue...\n";
   cin.ignore().get();
   test_readfile();
   cout << "Press any key to continue...\n";
   cin.ignore().get();
   
 
   cout << "*** Welcome to " << developer << "'s sorting program ***\n"
      << "Enter the first input file name: ";
   cin >> inFile;
   in1.open((char*)inFile.c_str());
   iArray1_size = readfile(iArray1, in1);
   in1.close();
   cout << "The list of "<< iArray1_size + 1 << " numbers in file " << inFile << " is:\n";
   for (int i = 0; i <= iArray1_size; i++) {
      cout << iArray1[i] << "\n";
   }
   
   cout << "\nEnter the second input file name: ";
   cin >> inFile2;
   in2.open((char*)inFile2.c_str());
   
   iArray2_size = readfile(iArray2, in2);
   in2.close();
   cout << "The list of "<< iArray2_size + 1 << " numbers in file " << inFile << " is:\n";
   for (int i = 0; i <= iArray2_size; i++) {
      cout << iArray2[i] << "\n";
   }

   
   sorted_array_size = sort(iArray1, iArray1_size + 1, iArray2, iArray2_size + 1, sorted_array);
   sorted_array_size = iArray1_size + iArray2_size + 2;
   cout << "\nThe sorted list of " << sorted_array_size << " numbers is: ";
   for (int i = 0; i <= iArray2_size + iArray1_size + 1; i++) {
      cout << sorted_array[i] << " ";
   }   
   ofstream outStream;
   cout << "\nEnter the output file name: ";
   cin >> inFile3;
   outStream.open((char *) inFile3.c_str());
   if (outStream.fail()) {
      cout << "Output file opening failed.";
      exit(1);
   }
   writefile(sorted_array, sorted_array_size, outStream);
   cout << "*** Please check the new file - " << inFile3 << " ***\n";
   cout << "*** Goodbye ***";
   
   
   
   
   
}

void writefile(int outputArray[], int outputArray_size, ofstream &outStream)
// Input: Array of combined data from two input files
//        Size of the output array
// Output: Creates file containing the sorted output array
{
   for (int i = 0; i < outputArray_size; i++) {
      outStream << outputArray[i] << endl;
   }
}

int readfile(int inputArray[], ifstream& inStream){
   if (inStream.fail()) {
      cout << "Input file opening failed." << endl;
      exit(1);
   }
   
   int index = 0;
   inStream >> inputArray[index];
   while (! inStream.eof()) {
      index++;
      inStream >> inputArray[index];
   }

   return index;
}

int sort(int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
   int outputArray_size = inputArray1_size + inputArray2_size; 
   int index1 = 0;
   int index2 = 0;
   int index3 = 0;
   while(index1 < inputArray1_size && index2 < inputArray2_size) {
   
      if (inputArray1[index1] < inputArray2[index2]) {
         outputArray[index3] = inputArray1[index1];
         index1++;
         index3++;
         
      }
      else {
         outputArray[index3] = inputArray2[index2];
         index2++;
         index3++;
      }
   
   }
   
   if (index1 == inputArray1_size) {
      while (index2 < inputArray2_size) {
         outputArray[index3] = inputArray2[index2];
         index2++;
         index3++;
      }
   }
   else {
      while (index1 < inputArray1_size) {
         outputArray[index3] = inputArray1[index1];
         index1++;
         index3++;
      }
   }
   
}
   




