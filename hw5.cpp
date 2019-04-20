// name: Tyler Andrews, tja0023
// partner: NONE
// filename: hw5.cpp
// due date: 10/5/2018
// collaboration: I did not use any external sources for this assignment.
// problem: Create a Trivia game that hard codes three questions and takes in user input for questions.
#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>
#include <cassert>
using namespace std;


struct TriviaNode {
   string question;
   string answer;
   int points;
   TriviaNode *next;

};
typedef TriviaNode* TriviaNodePt;
TriviaNodePt head = new TriviaNode;
int question_number;

//Prototypes
int insert_question(TriviaNodePt& list, string question, string answer, int points);
void harList(void);
void printList(TriviaNodePt head);
int add_question(void);
void test_askQuestion(void);
void test_hardlist(void);
void test_addquestion(void);
void test_insertquestion(void);

void hardList(void) { //Hard Codes 3 questions into the Trivia Game
   insert_question(head, "How long was the shortest war on record? (Hint: how many minutes)","38", 100);
   insert_question(head, "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)", "Bank of Italy", 50);
   insert_question(head, "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?", "Wii Sports", 20);
}


int add_question(void) { //Add's a question to the Trivia game created by the player
   string trivia_question, trivia_key;
   int trivia_point, error_code;
   
   cout << "Enter a question: ";
   getline(cin, trivia_question); //gets player question
   
   cout << "Enter an answer: ";
   getline(cin, trivia_key); //gets player answer
   
   cout << "Enter award points: ";
   cin >> trivia_point; //gets player points for question
   cin.clear();cin.ignore(INT_MAX, '\n');
   
   error_code = insert_question(head, trivia_question, trivia_key, trivia_point); //inserts the question, answer, and points into the game
   return 1;
   
   
   
   
   
  
}

int askQuestion(TriviaNodePt& head, int i) { //function that asks the questions to the player and tell the player if the answer is correct
  
   TriviaNode *currentNode = head;
   int player_points = 0;
   if (i == 0) { //issues a warning if there are no questions to be asked
      cout << "\nWarning: The number of trivia to be asked must equal to or larger than 1.";
   
   }
   if (i > question_number) { //issues a warning if i is greater than the number of questions
      cout << "\nWarning: There are only " << question_number << " trivia in the list.";
      return 0;
   }
   string panswer;
   for (int t = 0; t < i; t++) { 
      cout << "\nQuestion: " << currentNode -> question << "\nAnswer: ";
      getline(cin, panswer); //gets player answer
      if (currentNode -> answer == panswer) { //correct answer
         cout << "Correct! You recieve " << currentNode -> points << " points.";
         player_points += currentNode -> points;	
      }
      else { //wrong answer
         cout << "Sorry, but your answer is incorrect.  The correct answer is : " << currentNode -> answer;
      }
      cout << "\nYour Point Total Is: " << player_points << "\n"; //point total
      currentNode = currentNode -> next;
   }
   return player_points;  
  

}


int insert_question(TriviaNodePt& head, string question1, string answer1, int points1) { //inserts question into linked list at top of list

   TriviaNodePt nodelist; 
   nodelist = new TriviaNode;
   assert(nodelist != NULL);
   nodelist -> question = question1; //adds question
   nodelist -> answer = answer1; //adds answer
   nodelist -> points = points1;//adds points
   nodelist -> next = NULL;
   if (head == NULL) {
      head = nodelist;
   } 
   else {
      nodelist -> next = head;
      head = nodelist;
   }
   question_number++;
   return 1;
 

}

int main() {
#ifdef UNIT_TESTINGv //debugging version
cout << "*** This is a debugging version ***\n";
   test_askQuestion();
   test_hardlist();
   test_addquestion();
   test_insertquestion();
cout << "\n*** End of the Debugging Version ***";
#else //production version
   
   cout << "*** Welcome to Tyler's trivia quiz game ***\n";
   question_number = 0;  
   hardList(); //adds 3 hard coded questions
   add_question(); //adds user questions
   string Continue;
   cout << "Continue? (Yes/No): "; 
   getline(cin, Continue);
   while (Continue != "Yes" && Continue != "No") { //input not a Yes or No
      cout << "Please enter valid input (Yes/No): ";
      getline(cin, Continue); }
   if (Continue == "Yes") { //adds another question if there 
      do {
         add_question();
         cout << "Continue? (Yes/No): ";
         getline(cin, Continue);
      
         while (Continue != "Yes" && Continue != "No") {
            cout << "Please enter valid input (Yes/No): ";
            getline(cin, Continue); 
         }
      }
      while (Continue == "Yes");
   }
   askQuestion(head, question_number);
   cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
#endif
}

void test_askQuestion(void) {      TriviaNodePt head1 = new TriviaNode;
   
   cout << "Unit Test Case 1: Ask no question. The program should give a warning message.";
   askQuestion(head, 0);
   cout << "\nCase 1 Passed\n\n";
   
   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.";
   int points = askQuestion(head, 1);
   assert(0 == points);
   cout << "Case 2.1 Passed\n\n";
   points = 0;
   
   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.";
   points = askQuestion(head, 1);
   assert(20 == points);
   cout << "Case 2.2 Passed\n\n"; 
      
   cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list.";
   points = 0;
   points = askQuestion(head, question_number);
   assert(170 == points);
   cout << "Case 2.2 Passed\n\n"; 
   
   cout << "Unit Test Case 4: Ask five questions in the linked list.";
   askQuestion(head, 5);
   cout << "Case 4 passed\n\n";
   

   
   
}

void test_hardlist(void) {
   cout << "HardList function Test\n";
   hardList();
   assert(question_number == 3);
   cout << "Case passed\n\n";
   

}

void test_addquestion(void) {
   cout << "Add_Question function Test\n";
   int i = add_question();
   assert(i == 1);
   cout << "Case passed\n\n";
}

void test_insertquestion(void) {
   cout << "Insert_Question Test\n";
   string question = "What is my Name";
   string answer = "Tyler";
   int points = 10;
   TriviaNodePt test = new TriviaNode;
   int i = insert_question(test, question, answer, points);
   assert(i == 1);
   cout << "Case passed\n\n";
   
   
}

