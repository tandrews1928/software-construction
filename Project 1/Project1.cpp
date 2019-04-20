// name: Tyler Andrews, tja0023
// partner: NONE\/ filename: Project1.cpp
// due date: 10/19/2018
// collaboration: I did not use any external sources for this assignment.
// problem: Create a doctor class and functions to access and mutate it.

#include <fstream> 
#include <iostream> 
#include <string>
#include <string.h>
using namespace std;

const int ARRAY_MAX = 10;

class Player {
public:
   Player();
   bool win();
   bool stillalive();
   int timeChange(int difference);
   int moneyChange(int difference);
   int intelligenceChange(int difference);
   int stepsDecrement();
   int getTime();
   int getMoney();
   int getIntelligence();
   int setName(string nameIn);
   string getName();
   int getStepsRemaining();
   int totalPoints(); 
private:
   string name;
   int stepsRemaining;
   int time;
   int money;
   int intelligence;
};

 
class Highscore {
public:
   Highscore();
   int fillArrays();
   int findMinimum();
   int addUser(string nameIn, int scoreIn);
   int readfile();
   int writefile(Player character);
   int sort();
private:
   string nameArray[ARRAY_MAX];
   int scoreArray[ARRAY_MAX];
   int minimum;
};

class Encounter {
public:
   Encounter();
   int chooseEncounter(Player& character);
   int choosePuzzle();
   int puzzleReward(Player& character);
   int puzzlePunishment(Player& character);
   int Puzzle(Player& character);
   int Professor(Player& character);
   int Student(Player& character);
   int GruntWork(Player& character);
   int PapersToGrade(Player& character);
   int encounterText(Player& character);
private:
   string answer;
};

class Menu {
public:
   Menu();
   int welcomeMessage();
   int optionsMenu();
   int startGame();
   int howToPlay();
   int optionsQuit();
   int welcomeQuit();
   int inGameOptions();
   int move();
   int readPaper();
   int pickpocket();
   int viewPlayer();
   int youLose();
   int youWin();
private:
   Encounter encounter;
   Highscore highscore;
   Player character;
   bool hasSpace;
   string name;
};

//Constructors

Player::Player() { 
   name = "No name";
   time = 30;
   intelligence = 20;
   money = 11;
   stepsRemaining = 20;
}

Menu::Menu() {
	
}


Encounter::Encounter() {
	
}

Highscore::Highscore() {
	
}

/*
Encounter member functions 
*/

int Encounter::chooseEncounter(Player& character) { //randomly decides which encounter will occur
   int chance = rand() % 100 + 1; // random number between 1 and 100

   character.timeChange(-1);
   cout << "\nYou move forward one step, and...\n\n";

   if (chance <= 25) {
      cout << "NOTHING HAPPENS!\n";
   }
   else if (chance <= 55 && chance > 25) {
      Puzzle(character);
   }
   else if (chance <= 65 && chance > 55) {
      Professor(character);
   }
   else if (chance <= 75 && chance > 65) {
      Student(character);
   }
   else if (chance <= 90 && chance > 75) {
      GruntWork(character);
   }
   else if (chance <= 100 && chance > 90) {
      PapersToGrade(character);
   }
   else {
   }

   return 0;
}

int Encounter::choosePuzzle() { //randomly chooses a puzzle
   int value = rand() % 24;

   switch (value) {
      case 0:
         cout << "When was Auburn founded?\n";
         cout << "Please answer with year.\n";
         answer = "1856";
         break;
      case 1:
         cout << "Who is the richest man alive?\n";
         cout << "Please answer with their full name.\n";
         answer = "jeff bezos";
         break;
      case 2:
         cout << "Who is the current president\n";
         cout << "Please answer with only their last name.\n";
         answer = "trump";
         break;
      case 3:
         cout << "Which president had the shortest term\n";
         cout << "Please answer with only their last name.\n";
         answer = "harrison";
         break;
      case 4:
         cout << "Solve the following equation: (2 + 10) * (2 * 3)\n";
         answer = "72";
         break;
      case 5:
         cout <<"What is the oldest country\n";
         answer = "san marino";
         break;
      case 6:
         cout << "Solve the following equation: 2 * 5 + 12 / 4 - 2\n";
         answer = "11";
         break;
      case 7:
         cout << "Solve the following equation: 100 / 4 - 10 / 2 + 2 * 3\n";
         answer = "26";
         break;
      case 8:
         cout << "Solve the following equation : 10 + 10 - 2 + (5 / 5)\n";
         answer = "19";
         break;
      case 9:
         cout << "Solve the following equation : 2^3\n";
         answer = "8";
         break;
      case 10:
         cout << "Solve the following equation: 5^3\n";
         answer = "125";
         break;
      case 11:
         cout << "I start with S and end with IT, and have you in the middle. What am I?\n";
         answer = "suit";
         break;
      case 12:
         cout << "What is often returned but is never borrowed?\n";
         answer = "thanks";
         break;
      case 13:
         cout << "I have cities but no houses, moutains but no trees, and water but no fish. What am I?\n";
         answer = "a map";
         break;
      case 14:
         cout << "What has hundreds of ears but can’t hear?\n";
         answer = "a corn field";
         break;
      case 15:
         cout << "What did the boy coffee say to the girl coffee?\n";
         answer = "i love you a latte";
         break;
      case 16:
         cout << "What month do all soldiers hate?\n";
         answer = "march";
         break;
      case 17:
         cout << "Where can you find success before work?\n";
         answer = "in the dictionary";
         break;
      case 18:
         cout << "Why is an island like the letter “T”?\n";
         answer = "because both are in the middle of the water";
         break;
      case 19:
         cout << "What do you call a three humped camel?\n";
         answer = "pregnant";
         break;
      case 20:
         cout << "What do you call a tick that loves math?\n";
         answer = "a arithmetic";
         break;
      case 21:
         cout << "Why do you never bring a Pokemon in the bathroom, with you?\n";
         answer = "they might pickachu";
         break;
      case 22:
         cout << "I’m often running yet I have no legs. You need me but I don’t need you. What am I?\n";
         answer = "water";
         break;
      case 23:
         cout << "Joe’s father had three son’s Snap, Crackle and?\n";
         answer = "joe";
         break;
   }

   return 0;
}


int Encounter::puzzleReward(Player& character) { //random awards for the puzzle
   int value = rand() % 9; // random number between 0 and 8

   switch (value) {
      case 0:
         character.intelligenceChange(2);
         cout << "You were rewarded with 2 intelligence!\n";
         break;
      case 1:
         character.intelligenceChange(3);
         cout << "You were rewarded with 3 intelligence!\n";
         break;
      case 2:
         character.intelligenceChange(4);
         cout << "You were rewarded with 4 intelligence!\n";
         break;
      case 3:
         character.moneyChange(4);
         cout << "You were rewarded with $4!\n";
         break;
      case 4:
         character.moneyChange(5);
         cout << "You were rewarded with $5!\n";
         break;
      case 5:
         character.moneyChange(6);
         cout << "You were rewarded with $6!\n";
         break;
      case 6:
         character.timeChange(1);
         cout << "You were rewarded with 1 extra minute!\n";
         break;
      case 7:
         character.timeChange(2);
         cout << "You were rewarded with 2 extra minutes!\n";
         break;
      case 8:
         character.timeChange(3);
         cout << "You were rewarded with 3 extra minutes!\n";
         break;
   }

   return 0;
}

int Encounter::puzzlePunishment(Player& character) { //random punishments for the puzzle
   int value = rand() % 9; // random number between 0 and 8

   switch (value) {
      case 0:
         character.intelligenceChange(-2);
         cout << "You lost 2 intelligence.\n";
         break;
      case 1:
         character.intelligenceChange(-3);
         cout << "You lost 3 intelligence.\n";
         break;
      case 2:
         character.intelligenceChange(-4);
         cout << "You lost 4 intelligence.\n";
         break;
      case 3:
         character.moneyChange(-4);
         cout << "You lost $4.\n";
         break;
      case 4:
         character.moneyChange(-5);
         cout << "You lost $5.\n";
         break;
      case 5:
         character.moneyChange(-6);
         cout << "You lost $6.\n";
         break;
      case 6:
         character.timeChange(-1);
         cout << "You lost 1 minute.\n";
         break;
      case 7:
         character.timeChange(-2);
         cout << "You lost 2 minutes.\n";
         break;
      case 8:
         character.timeChange(-3);
         cout << "You lost 3 minutes.\n";
         break;
   }

   return 0;
}

int Encounter::Puzzle(Player& character) {  //puzzle encounter
   string input;
   cout << "You encounter a puzzle! Make sure you type your answer in all lower case.\n\n";
	
   choosePuzzle();

   cin >> input;

   if (input == answer) {
      cout << "\nCORRECT!\n";
      puzzleReward(character);
   }
   else {
      cout << "\nINCORRECT!\n";
      puzzlePunishment(character);
      cout << "The correct answer is " << answer << endl;
   }
   return 0;
}

int Encounter::Professor(Player& character) { //professor encounter
   cout << "You encounter a professor! He begins a lecture...\n";
   int value = rand() % 4; // random number between 0 and 3

   switch (value) {
      case 0:
         cout << "\nYou didn't gain anything from that encounter.\n";
         break;
      case 1:
         character.intelligenceChange(1);
         cout << "\nYou gained 1 intelligence!\n";
         break;
      case 2:
         character.intelligenceChange(2);
         cout << "\nYou gained 2 intelligence!\n";
         break;
      case 3:
         character.intelligenceChange(3);
         cout << "\nYou gained 3 intelligence!\n";
         break;
   }

   return 0;
}

int Encounter::Student(Player& character) { //student encounter
   cout << "You encounter another student! He walks towards you... \n";
   int value = rand() % 3; // random number between 0 and 2

   switch (value) {
      case 0:
         cout << "\nThey walk right past you. Nothing happens.\n";
         break;
      case 1:
         character.timeChange(-1);
         cout << "\nThey stop and say Hi to you...\n";
         cout << "You lost 1 minute.\n";
         break;
      case 2:
         character.timeChange(-2);
         cout << "\nThey start a conversation with you...\n";
         cout << "You lost 2 minutes.\n";
         break;
   }

   return 0;
}

int Encounter::GruntWork(Player& character) { //gruntwork encounter
   cout << "You forgot that you have some grunt work that you need to take care of!\n";
   int value = rand() % 3; // random number between 0 and 2

   character.timeChange(-1);
   character.intelligenceChange(-1);
   cout << "\nIt takes a long time and you dont feel any smarter\n";
   cout << "You lost 1 intelligence and 1 minute.\n";
        
   return 0;
}

int Encounter::PapersToGrade(Player& character) { //papers have to be graded
   cout << "You forgot you had papers to grade.\n"; 
   character.moneyChange(3);
   character.timeChange(-2);
   cout << "\nYou got $3 but it took you 2 minutes\n";
   return 0;
}


//Player member functions 
 
int Player::stepsDecrement() { //decreases steps by 1
   stepsRemaining--;

   return 0;
}

int Player::getTime() { //returns time
   return time;
}

int Player::getMoney() {//returns money
   return money;
}

int Player::getIntelligence() {//returns intelligence
   return intelligence;
}

int Player::setName(string nameIn) {//sets the name
   name = nameIn;

   return 0;
}

string Player::getName() {//return name
   return name;
}

int Player::getStepsRemaining() {//return remaining steps
   return stepsRemaining;
}

int Player::totalPoints() {//calculates toalal points to be used for High Score
   int total;
	
   total = getTime() * getMoney() * getIntelligence();

   return total;
}

bool Player::win() {//if there are no more steps then the player wins
   bool result = false;

   if (stepsRemaining == 0) {
      result = true;
   }

   return result;
}

bool Player::stillalive() {//if none of the players attributes are zero then then the player is stil alive
   bool result = true;

   if (time <= 0 || money <= 0 || intelligence <= 0) {
      result = false;
   }

   return result;
}

int Player::timeChange(int difference) {//calculates the new amount of time left
   time = time + difference;

   return 0;
}

int Player::moneyChange(int difference) {//calculates the new amount of money left
   money = money + difference;

   return 0;
}

int Player::intelligenceChange(int difference) {//calculates the new amount of intelligence left
   intelligence = intelligence + difference;

   return 0;
}

  
  
/*
Menu member functions 
*/

int Menu::welcomeMessage() { //displays the welcome message
   cout << "\nWhat's your name?: ";
   cin >> name;
   
   character.setName(name);
   cout << "\n===========================================================\n";
   cout << "                     Welcome, " << name << endl;
   cout << "===========================================================\n";
      
   optionsMenu();

   return 0;
}

int Menu::optionsMenu() { //displays the options menu
   string input;
   int stringInput;
   bool repeat;

   cout << "\n1) Start a New Game";
   cout << "\n2) View High Scores";
   cout << "\n3) Quit";
   cout << "\nchoose ";
   

   do {
      cin >> input;
      stringInput = atoi(input.c_str());
      repeat = false;
   
      switch (stringInput) {
         case 1:
            startGame();
            break;
         case 2:
            highscore.readfile();
            repeat = true;
            cout << "\n1) Start a New Game";
            cout << "\n2) View High Scores";
            cout << "\n3) Quit";
            cout << "\n\nChoose an option (1, 2, 3): ";
            break;
         case 3:
            optionsQuit();
            break;
         default:
            cout << "Your input was invalid. Please enter a valid input (1, 2, or 3): ";
            repeat = true;
      }
   } while (repeat);

   return 0;
}

int Menu::startGame() { //starts the game
   cout << "\nEntering the Game...\n";
   inGameOptions();
   return 0;
}

 
int Menu::optionsQuit() { //quit from the options menu
   
   cout << "\nThanks for playing!\n";
   exit(1);

   return 0;
}

int Menu::welcomeQuit() { //quit from the welcome menu
   cout << "\nThanks for playing!\n";
   exit(1); 
   return 0;
}

int Menu::inGameOptions() { //ingameoptions menu
   string input;
   int stringInput;


   cout << "\nYou are " << character.getStepsRemaining() << " steps away from the goal.";
   cout << "\n\t1) Move forward";
   cout << "\n\t2) Read technical papers";
   cout << "\n\t3) Search for loose change";
   cout << "\n\t4) View character";
   cout << "\n\t5) Quit game";
   cout << "\n\nChoose an action: ";

   do {
      if (!character.stillalive()) {
         youLose();
      }
   
      cin >> input;
      stringInput = atoi(input.c_str());
   
      switch (stringInput) {
         case 1:
            move();
            character.stepsDecrement();
         
            if (character.getStepsRemaining() == 1) {
               if (!character.stillalive()) {
                  youLose();
               }
            
               cout << "\nYou're " << character.getStepsRemaining() << " step away from the goal.";
            }
            else if (character.getStepsRemaining() == 0) {
               if (!character.stillalive()) {
                  youLose();
               }
            
               cout << "\nCongratulations! You reached the end!";
               break;
            }
            else {
               if (!character.stillalive()) {
                  youLose();
               }
            
               cout << "\nYou're " << character.getStepsRemaining() << " steps away from the goal.";
            }
         
            cout << "\n\t1) Move forward";
            cout << "\n\t2) Read technical papers";
            cout << "\n\t3) Search for loose change";
            cout << "\n\t4) View character";
            cout << "\n\t5) Quit game";
            cout << "\n\nChoose an action: ";
            break;
         case 2:
            readPaper();
         
            if (!character.stillalive()) {
               youLose();
            }
         
            if (character.getStepsRemaining() == 1) {
               cout << "\nYou're " << character.getStepsRemaining() << " step away from the goal.";
            }
            else {
               cout << "\nYou're " << character.getStepsRemaining() << " steps away from the goal.";
            }
         
            cout << "\n\t1) Move forward";
            cout << "\n\t2) Read technical papers";
            cout << "\n\t3) Search for loose change";
            cout << "\n\t4) View character";
            cout << "\n\t5) Quit game";
            cout << "\n\nChoose an action: ";
            break;
         case 3:
            pickpocket();
         
            if (!character.stillalive()) {
               youLose();
            }
         
            if (character.getStepsRemaining() == 1) {
               cout << "\nYou're " << character.getStepsRemaining() << " step away from the goal.";
            }
            else {
               cout << "\nYou're " << character.getStepsRemaining() << " steps away from the goal.";
            }
         
            cout << "\n\t1) Move forward";
            cout << "\n\t2) Read technical papers";
            cout << "\n\t3) Search for loose change";
            cout << "\n\t4) View character";
            cout << "\n\t5) Quit game";
            cout << "\n\nChoose an action: ";
            break;
         case 4:
            viewPlayer();
            cout << "\nChoose an action: ";
            break;
         case 5: 
            
            cout << "\nThanks for playing!\n";
            exit(1);  
             
             
            
         default:
            cout << "Your input was invalid. Please enter a valid input (1, 2, 3, 4, or 5): ";
      } 
   } while (!character.win());

   youWin();

   return 0;
}

int Menu::move() { //player chooses to move
   encounter.chooseEncounter(character);
	
   return 0;
}

int Menu::readPaper() { //player chooses to read papers
	
   character.timeChange(-1);
   cout << "\nYou decide to read a couple of technical papers.\n";
   int value = rand() % 5; // random number between 0 and 4

   switch (value) {
      case 0:
         character.intelligenceChange(1);
         cout << "\nThe material is boring but you still learned something.\n";
         cout << "You earned 1 intelligence!\n";
         break;
      case 1:
         character.intelligenceChange(2);
         cout << "\nThe information is pretty useful.\n";
         cout << "You earned 2 intelligence!\n";
         break;
      case 2:
         character.intelligenceChange(3);
         cout << "\nYou information was very useful\n";
         cout << "You earned 3 intelligence!\n";
         break;
      default:
         cout << "\nERROR: THIS LINE IS OUT OF SCOPE.\n";
   }

   return 0;
}

int Menu::pickpocket() { //player chooses to search for loose change
   character.timeChange(-1);
   cout << "\nYou decide to pickpocket a student walking by...\n";
   int value = rand() % 8; // random number between 0 and 7

   switch (value) {
      case 0:
         cout << "\nYou reach into their pocket but they are a poor college student with no money.\n";
         cout << "You earned $0\n";
         break;
      case 1:
         character.moneyChange(1);
         cout << "\nYou take their wallet. There's only $1 inside.\n";
         cout << "You earned $1!\n";
         break;
      case 2:
         character.moneyChange(2);
         cout << "\nYou take their wallet. There's $2 inside.\n";
         cout << "You earned $2!\n";
         break;
      case 3:
         character.moneyChange(3);
         cout << "\nYou take their wallet. There's $3 inside.\n";
         cout << "You earned $3!\n";
         break;
      case 4:
         character.moneyChange(4);
         cout << "\nYou take their wallet. There's $4 inside.\n";
         cout << "You earned $4!\n";
         break;
   
      case 5:
         character.timeChange(-2);
         cout << "\nYou try to take their wallet. they notice you and yell at you.\n";
         cout << "You didnt get any money and youve wasted 2 minutes from being yelled at\n";
         break;
      default:
         cout << "\nERROR: THIS LINE IS OUT OF SCOPE\n";
   }

   return 0;
}

int Menu::viewPlayer() { //player chooses to view atributes 
   cout << "\nPlayer statistics:";
   cout << "\n\tIntelligence: " << character.getIntelligence(); 
   cout << "\n\tMoney: $" << character.getMoney();
   cout << "\n\tMinutes left: " << character.getTime() << "\n";
   return 0;
}

int Menu::youLose() { //you lose displays
   string input;
   bool repeat = true;
	
   if (character.getMoney() <= 0) {
      cout << "\nYou ran out of money! You cannot afford to go to Auburn anymore\n";
   }
   else if (character.getTime() <= 0) {
      cout << "\nYou ran out of time! You were late to your class and failed out of college\n";
   }
   else if (character.getIntelligence() <= 0) {
      cout << "\nYou ran out of intelligence! You are not smart enough to be at Auburn anymore\n";
   }

   cout << "\nYOU DROPPED OUT OF SCHOOL AND YOUR PARENTS WON'T LET YOU LIVE AT HOME, YOU SUCK.";
   cout << "\nReturn to main menu? (Y/N): ";

   do {
      cin >> input;
   
      if (input == "Y" || input == "y") {
         character = Player();
         cout << "\nReturning to main menu...\n";
         welcomeMessage();
         repeat = false;
      }
      else if (input == "N" || input == "n") {
         character = Player();
         welcomeQuit();
         repeat = false;
      }
      else {
         cout << "Please enter a valid input (Y or N): ";
      }
   } while (repeat);

   return 0;
}

int Menu::youWin() { //you win displays and your score is added to top 10 high scores if applicable
   string input;
   bool repeat = true;

   cout << "\nYOU WIN!";
   cout << "\nYour name: " << character.getName();
   cout << "\nYour score: " << character.totalPoints();

   highscore.fillArrays();
   highscore.addUser(character.getName(), character.totalPoints());
   highscore.writefile(character);
   cout << "\n";
   highscore.readfile();

   cout << "\nReturn to main menu? (Y/N): ";

   do {
      cin >> input;
   
      if (input == "Y" || input == "y") {
         character = Player();
         cout << "\nReturning to the options menu...\n";
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         welcomeMessage();
         repeat = false;
      }
      else if (input == "N" || input == "n") {
         character = Player();
         welcomeQuit();
         repeat = false;
      }
      else {
         cout << "Please enter a valid input (Y or N): ";
      }
   } while (repeat);

   return 0;
}


/*
Highscore member functions
*/

int Highscore::fillArrays() {
   ifstream inStream;
   inStream.open("highscores.txt");

   if (inStream.fail()) {
      return 0;
   }

   for (int i = 0; i < ARRAY_MAX; i++) {
      inStream >> nameArray[i] >> scoreArray[i];
   }

   return 0;
}

int Highscore::findMinimum() {
   minimum = scoreArray[0];

   for (int i = 1; i < ARRAY_MAX; ++i) {
      if (scoreArray[i] < minimum) {
         minimum = scoreArray[i];
      }
   }

   for (int j = 0; j < ARRAY_MAX; j++) {
      if (scoreArray[j] == minimum) {
         return j; // return index of minimum
      }
   }

   return 0;
}

int Highscore::addUser(string nameIn, int scoreIn) {
   int index = findMinimum();
   if (scoreIn > minimum) {
      scoreArray[index] = scoreIn;
      nameArray[index] = nameIn;
   }

   return 0;
}

int Highscore::readfile() {
   ifstream inStream;
   int numScores = 0;
   string line;

   inStream.open("highscores.txt");

   if (inStream.fail()) {
      cout << "\nHigh scores could not be read. Sorry!\n" << endl;
      return 0;
   }

   bool isEmpty = (inStream.peek() == ifstream::traits_type::eof());
   if (isEmpty) { 
      cout << "\nTop 10 High Scores:\n";
      cout << "\tNo scores have been recorded yet!\n";
      return 0;
   }

   cout << "\nTop 10 High Scores:\n";

   while (getline(inStream, line)) {
      numScores++;
      cout << "\t" << numScores << ". " << line << "\n";
   }

   inStream.close();
   return 0;
}


int Highscore::writefile(Player character) {
   ofstream outStream;

   sort();

   outStream.open("highscores.txt");

   for (int i = 0; i < ARRAY_MAX; i++) {
      outStream << nameArray[i] << "   " << scoreArray[i] << "\n";
   }

   outStream.close();
   return 0;
}

int Highscore::sort() {
   int tempScore;
   string tempName;

   for (int i = 0; i < ARRAY_MAX; i++) {
      for (int j = 0; j < ARRAY_MAX - 1; j++) {
         if (scoreArray[j] < scoreArray[j + 1]) {
         	// swap scores
            tempScore = scoreArray[j];
            scoreArray[j] = scoreArray[j + 1];
            scoreArray[j + 1] = tempScore;
         	// swap names as well
            tempName = nameArray[j];
            nameArray[j] = nameArray[j + 1];
            nameArray[j + 1] = tempName;
         }
      }
   }

   return 0;
}
  //test cases

void test_name_entry(void) {
   Menu menu = Menu();
   menu.welcomeMessage();
}

void test_options_menu(void) {
   Menu menu = Menu();
   menu.optionsMenu();
}

void test_ingame_options(void) {
   Menu menu = Menu();
   menu.inGameOptions();
}

void test_puzzle(void) {
   Encounter encounter = Encounter();
   Player character = Player();
   encounter.Puzzle(character); 
}

void test_end_of_game(void) {
   Menu menu = Menu();
   menu.youWin();
}


int main() {
   srand(time(NULL));
   Menu menu = Menu();
   menu.welcomeMessage();
   return 0;
}
