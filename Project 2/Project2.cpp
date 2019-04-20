// name: Tyler Andrews, tja0023
// partner: NONE\/ filename: Project2.cpp
// due date: 12/79/2018
// collaboration: I did not use any external sources for this assignment.
// problem: Create a Bank Teller.

#include <cstdlib>
#include <fstream> 
#include <iostream> 
#include <sstream>
#include <string>

using namespace std;

const int MAX = 100;


//User Structure
struct User {
   User();
   string username;
   string password;
   string role;
};
  //Client Structure
struct Client {
   Client();
   string name;
   string address;
   string social_security_number;
   string employer;
   string income;
};
//Account Structure
struct Account {
   Account();
   string name;
   string account_number;
   string account_type;
   string balance;
};

//FileManagement Class
class FileManagement {
public:
   FileManagement();
   int writeClientfile();
   int writeAccountfile();
   int writeUserfile();
   int print(string nameIn);
   int update(string nameIn);
   int addClient(Client client);
   int addAccount(Account account);
   int addUser(User user);
   int deleteUser(string nameIn);
   int changePassword(string usernameIn, string passwordIn);
   bool accountExists(string nameIn);
   bool adminExists(string usernameIn, string passwordIn);
   bool staffExists(string usernameIn, string passwordIn);
   bool clientExists(string clientNameIn);
   bool isAccount(string account_numberIn);
   bool userExists(string usernameIn);
   string getName(string account_numberIn);
   int deposit(string account_numberIn, int amount);
   int withdraw(string account_numberIn, int amount);
   int printUserArray();
   int fillArray();

private:
   Account accountArray[MAX];
   User userArray[MAX];
   Client clientArray[MAX];
}; 
//Member Class
class Member {
public:
   Member();
   int setUsername(string usernameIn);
   int setPassword(string usernameIn);
   string getUsername();
   string getPassword();
   int addClient(FileManagement &filemanagement);
   int addAccount(FileManagement &filemanagement);
   int editClientInfo(FileManagement &filemanagement);
   int manageAccount(FileManagement &filemanagement);
   int saveInfo(FileManagement &filemanagement);
   int changePassword(string passwordIn, FileManagement &filemanagement);
private:
   string username;
   string password;
   Client client;
   Account account;
};
//Admin Class
class Admin : public Member { // inherits from member class
public:
   Admin();
   int addUser(FileManagement &filemanagement);
   int deleteUser(FileManagement &filemanagement);
   int displayUsers(FileManagement &filemanagement);
private:
   string username;
   string password;
   User user;
};

//Menu Class
class Menu {
public:
   Menu();
   int loginOptions();
   int login();
   int quit();
   int adminOptions();
   int clientManagement();
   int backToAdminOptions(); 
   int backToLogin();
   int staffOptions();
   int backToMemberOptions();
   int Initialize();
private:
   FileManagement filemanagement;
   Member staff;
   Admin admin;
};

/*
CONSTRUCTORS
*/

Client::Client() {
   name = "";
   address = "";
   social_security_number = "";
   employer = "";
   income = "";
}

Account::Account() {
   name = "";
   account_number = "";
   account_type = "";
   balance = "";
}

User::User() {
   username = "";
   password = "";
   role = "";
}

Menu::Menu() {
	//empty
}

FileManagement::FileManagement() {
	//empty
}

Member::Member() {
   username = "";
   password = "";
}

Admin::Admin() {
   username = "";
   password = "";
}

 /*
FileManagement member functions 
*/

//account exists
bool FileManagement::accountExists(string nameIn) {
   for (int i = 0; i < MAX; i++) {
      if (accountArray[i].name == nameIn) {
         return true;
      }
   }
   return false;
}
//admin exists
bool FileManagement::adminExists(string usernameIn, string passwordIn) {
   for (int i = 0; i < MAX; i++) {
      string user = userArray[i].username;
      string pass = userArray[i].password;
      string rle = userArray[i].role;
   
   
      if (user == usernameIn && pass == passwordIn) {
         if (rle == "System Administrator") {
            return true;
         }
      }
   }

   return false;
}
//staff exists
bool FileManagement::staffExists(string usernameIn, string passwordIn) {
   for (int i = 0; i < MAX; i++) {
      string user = userArray[i].username;
      string pass = userArray[i].password;
      string rle = userArray[i].role;
      if (user == usernameIn && pass == passwordIn) {
         if (rle == "Branch Member") {
            return true;
         }
      }
   }
   return false;
}
//client exists
bool FileManagement::clientExists(string clientNameIn) {
   for (int i = 0; i < MAX; i++) {
      string nme = clientArray[i].name;
      if (nme == clientNameIn) {
         return true;
      }
   }
   return false;
}
//account exists
bool FileManagement::isAccount(string account_numberIn) {
   for (int i = 0; i < MAX; i++) {
      string nme = accountArray[i].account_number;
      if (nme == account_numberIn) {
         return true;
      }
   }
   return false;
}
//user exists
bool FileManagement::userExists(string usernameIn) {
   for (int i = 0; i < MAX; i++) {
      if (userArray[i].username == usernameIn) {
         return true;
      }
   }
   return false;
}
//get Name
string FileManagement::getName(string account_numberIn) {
   for (int i = 0; i < MAX; i++) {
      if (accountArray[i].account_number == account_numberIn) {
         return accountArray[i].name;
      }
   }
   return "UNKNOWN";
}
//deposit
int FileManagement::deposit(string account_numberIn, int amount) {
   int balanceInt;
   for (int i = 0; i < MAX; i++) {
   
      if (accountArray[i].account_number == account_numberIn) {
         balanceInt = atoi(accountArray[i].balance.c_str());
         balanceInt += amount;
      
         accountArray[i].balance = static_cast<ostringstream*>(&(ostringstream() << balanceInt))->str();
         cout << "Balance of account " << accountArray[i].account_number << " is: " << accountArray[i].balance << "\n\n";
         return 0;
      }
   }
   return 0;
}
//withdraw
int FileManagement::withdraw(string account_numberIn, int amount) {
   int balanceInt;
   for (int i = 0; i < MAX; i++) {
      if (accountArray[i].account_number == account_numberIn) {
         balanceInt = atoi(accountArray[i].balance.c_str());
         balanceInt -= amount;
      
         if (balanceInt < 0) {
            cout << "ERROR: Withdraw amount exceeds balance!";
            cout << "\nNo money was withdrawn from " << accountArray[i].name << "'s account.\n\n";
            return 0;
         }
      
         accountArray[i].balance = static_cast<ostringstream*>(&(ostringstream() << balanceInt))->str();
         cout << "Balance of account " << accountArray[i].account_number << " is: " << accountArray[i].balance << "\n\n";
         return 0;
      }
   }
   return 0;
}
//print user array
int FileManagement::printUserArray() {
   int numUsers = 0;

   for (int i = 0; i < MAX; i++) {
      if (userArray[i].username == "") {
         break;
      }
      if (userArray[i].username == "") {
         break;
      }
      numUsers++;
   }

   cout << "\nThere are " << numUsers << " users in the system.";

   for (int i = 0; i < numUsers; i++) {
      if (i == 0) {
         cout << "\n\t1) Username: admin\t\tRole: System Administrator";
      }
      else {
         cout << "\n\t" << (i + 1) << ") Username: " << userArray[i].username << "\t\tRole: " << userArray[i].role;
      }
   }
	
   cout << "\n\n";
   return 0;
}
//fill array
int FileManagement::fillArray() {
   ifstream inStream3;
      
   inStream3.open("staff.txt");

   if (inStream3.fail()) {
      cout << "ERROR: COULD NOT BE LOADED !\n";
      return 0;
   }

   for (int i = 0; i < MAX; i++) {
      getline(inStream3, userArray[i].username);
   
     
      getline(inStream3, userArray[i].password);
      getline(inStream3, userArray[i].role);
   }

   inStream3.close(); 


   ifstream inStream;
   inStream.open("client.txt");

   if (inStream.fail()) {
      cout << "\nERROR: COULD NOT BE LOADED!\n";
      return 0; }
   

   for (int i = 0; i < MAX; i++) {
      getline(inStream, clientArray[i].name);
      getline(inStream, clientArray[i].address);
      getline(inStream, clientArray[i].social_security_number);
      getline(inStream, clientArray[i].employer);
      getline(inStream, clientArray[i].income);
   }

   inStream.close(); 
   
   
   ifstream inStream2;
   inStream2.open("account.txt");

   if (inStream.fail()) {
      cout << "ERROR: COULD NOT BE LOADED\n";
      return 0;
   }

   for (int i = 0; i < MAX; i++) {
      getline(inStream2, accountArray[i].name);
      getline(inStream2, accountArray[i].account_number);
      getline(inStream2, accountArray[i].account_type);
      getline(inStream2, accountArray[i].balance);
   }

   inStream2.close();
  
      
   return 0;
}
//write client file
int FileManagement::writeClientfile() {
   ofstream outStream;
   outStream.open("client.txt");

   for (int i = 0; i < MAX; i++) {
      outStream << clientArray[i].name << endl;
      outStream << clientArray[i].address << endl;
      outStream << clientArray[i].social_security_number << endl;
      outStream << clientArray[i].employer << endl;
      outStream << clientArray[i].income << endl;
   }
   outStream.close();
   return 0;
}
//write account file
int FileManagement::writeAccountfile() {
   ofstream outStream;
   outStream.open("account.txt");

   for (int i = 0; i < MAX; i++) {
      outStream << accountArray[i].name << endl;
      outStream << accountArray[i].account_number << endl;
      outStream << accountArray[i].account_type << endl;
      outStream << accountArray[i].balance << endl;
   }
   outStream.close();
   return 0;
}
//write user file
int FileManagement::writeUserfile() {
   ofstream outStream;
   outStream.open("staff.txt");

   for (int i = 0; i < MAX; i++) {
      outStream << userArray[i].username << endl;
      outStream << userArray[i].password << endl;
      outStream << userArray[i].role << endl;
   }
   outStream.close();
   return 0;
}
//print
int FileManagement::print(string nameIn) {
   for (int i = 0; i < MAX; i++) {
      if (clientArray[i].name == nameIn) {
         cout << "\n\tAddress: " << clientArray[i].address;
         cout << "\n\tSocial security number: " << clientArray[i].social_security_number;
         cout << "\n\tEmployer: " << clientArray[i].employer;
         cout << "\n\tAnnual income: " << clientArray[i].income << endl;
      }
   }
   return 0;
}
//update 
int FileManagement::update(string nameIn) {
   for (int i = 0; i < MAX; i++) {
      if (clientArray[i].name == nameIn) {
         cout << "\nPlease fill out " << clientArray[i].name << "'s updated information...\n";
         cout << "Address: ";
         getline(cin, clientArray[i].address);
         getline(cin, clientArray[i].address);
         cout << "Social security number: ";
         getline(cin, clientArray[i].social_security_number);
         cout << "Employer: ";
         getline(cin, clientArray[i].employer);
         cout << "Annual income: ";
         getline(cin, clientArray[i].income);
         cout << "Client " << clientArray[i].name << "'s information was updated!\n\n";
      }
   }
   return 0;
}
//add client
int FileManagement::addClient(Client client) {
   int count = 0;

   for (int i = 0; i < MAX; i++) {
      if (clientArray[i].name != "") {
         count++;
      }
   }

   if (count >= 99) {
      cout << "ERROR: You can't add any more clients because the database is full!\n\n";
      return 0;
   }

   clientArray[count] = client;
   cout << "A new client was added!\n\n";
   return 0;
}
//add account
int FileManagement::addAccount(Account account) {
   int count = 0;

   for (int i = 0; i < MAX; i++) {
      if (accountArray[i].name != "") {
         count++;
      }
   }

   if (count >= 99) {
      cout << "ERROR: You can't add any more accounts because the database is full!\n\n";
   }

   accountArray[count] = account;
   cout << "A new account was created for " << account.name << "!\n\n";
   return 0;
}
//add user
int FileManagement::addUser(User user) {
   int count = 0;

   for (int i = 0; i < MAX; i++) {
      if (userArray[i].username != "") {
         count++;
      }
   }

   if (count >= 99) {
      cout << "ERROR: You can't add any more users because the database is full!\n\n";
   }

   userArray[count] = user;
   return 0;
}
//delete user
int FileManagement::deleteUser(string nameIn) {
   for (int i = 0; i < MAX; i++) {
      if (userArray[i].username == nameIn) {
         userArray[i] = User();
      
         for (int j = i + 1; j < MAX; j++) {
            userArray[j - 1].username = userArray[j].username;
            userArray[j - 1].password = userArray[j].password;
            userArray[j - 1].role = userArray[j].role;
         }
      }
   }
   return 0;
}
//change password
int FileManagement::changePassword(string usernameIn, string passwordIn) {
   if (usernameIn == "admin") {
      userArray[0].password = passwordIn;
      return 0;
   }
   for (int i = 0; i < MAX; i++) {
      if (userArray[i].username == usernameIn) {
         userArray[i].password = passwordIn;
      }
   }
   return 0;
}

 
/*
Menu member functions 
*/
//login options
int Menu::loginOptions() {
   string input;
   int inputInt;
   bool repeat;
//three options
   cout << "\n\tWelcome to the Auburn Branch of Tiger Bank!\n";
   cout << "1) Login\n";
   cout << "2) Quit\n";
   cout << "\tPlease choose an option: ";

   do {
      cin >> input;
      inputInt = atoi(input.c_str());
      repeat = false;
   
      switch (inputInt) {
         case 1:
            login();
            break;
         case 2:
            quit();
            break;
      
         default: //invalid input
            cout << "Please enter a valid input (1 or 2): ";
            repeat = true;
      }
   } while (repeat);

   return 0;
}

//login
int Menu::login() {
   string name, pw;
   bool repeat;

   cout << "\n\tLogin to Access the Teller Terminal System\n";

   do {
      repeat = false;
      cout << "Username: ";
      cin >> name;
      cout << "Password: ";
      cin >> pw;
   
      if (filemanagement.adminExists(name, pw)) {
         staff = Member();
         admin.setUsername(name);
         admin.setPassword(pw);
         adminOptions();
      }
      else if (filemanagement.staffExists(name, pw)) {
         admin = Admin();
         staff.setUsername(name);
         staff.setPassword(pw);
         staffOptions();
      }
      else { //invalid input
         cout << "Incorrect. Try again!\n\n";
         repeat = true;
      }
   
   } while (repeat);

   return 0;
}
//quit
int Menu::quit() {
   string input;
   bool repeat;

   cout << "\nAre you sure you want to quit? (Y/N): ";

   do {
      repeat = false;
      cin >> input;
   
      if (input == "Y" || input == "y") {
         cout << "\nThank you for using the Teller Terminal System!\n";
         cout << "Exiting program... \n";
         exit(1);
      }
      else if (input == "N" || input == "n") {
         loginOptions();
      }
      else { //invalid input
         cout << "Please enter a valid input (Y or N): ";
         repeat = true;
      }
   } while (repeat);

   return 0;
}
//admin options
int Menu::adminOptions() {
   string input;
   int inputInt;
   bool repeat;

   cout << "\n\tTeller Terminal System - System Administration\n";
   cout << "1) Client and Account Management\n";
   cout << "2) Add a branch staff member\n";
   cout << "3) Delete a branch staff member\n";
   cout << "4) Display branch staff\n";
   cout << "5) Change password\n";
   cout << "6) Save and logout\n";
   cout << "\tPlease choose an option: ";

   do {
      cin >> input;
      inputInt = atoi(input.c_str());
      repeat = false;
   
      switch (inputInt) {
         case 1:
            clientManagement();
            break;
         case 2:
            admin.addUser(filemanagement);
            repeat = true;
            cout << "1) Client and Account Management\n";
            cout << "2) Add a branch staff member\n";
            cout << "3) Delete a branch staff member\n";
            cout << "4) Display branch staff\n";
            cout << "5) Change password\n";
            cout << "6) Save and logout\n";
            cout << "\tPlease choose an option: ";
            break;
         case 3:
            admin.deleteUser(filemanagement);
            repeat = true;
            cout << "1) Client and Account Management\n";
            cout << "2) Add a branch staff member\n";
            cout << "3) Delete a branch staff member\n";
            cout << "4) Display branch staff\n";
            cout << "5) Change password\n";
            cout << "6) Save and logout\n";
            cout << "\tPlease choose an option: ";
            break;
         case 4:
            admin.displayUsers(filemanagement);
            repeat = true;
            cout << "1) Client and Account Management\n";
            cout << "2) Add a branch staff member\n";
            cout << "3) Delete a branch staff member\n";
            cout << "4) Display branch staff\n";
            cout << "5) Change password\n";
            cout << "6) Save and logout\n";
            cout << "\tPlease choose an option: ";
            break;
         case 5:
            admin.changePassword(admin.getPassword(), filemanagement); 
            repeat = true;
            cout << "1) Client and Account Management\n";
            cout << "2) Add a branch staff member\n";
            cout << "3) Delete a branch staff member\n";
            cout << "4) Display branch staff\n";
            cout << "5) Change password\n";
            cout << "6) Save and logout\n";
            cout << "\tPlease choose an option: ";
            break;
         case 6:
            backToLogin();
            repeat = true;
            cout << "1) Client and Account Management\n";
            cout << "2) Add a branch staff member\n";
            cout << "3) Delete a branch staff member\n";
            cout << "4) Display branch staff\n";
            cout << "5) Change password\n";
            cout << "6) Save and logout\n";
            cout << "\tPlease choose an option: ";
            break;
         default: //invalid input
            cout << "Please enter a valid input (1, 2, 3, 4, 5, or 6): ";
            repeat = true;
      }
   } while (repeat);

   return 0;
}
//client management
int Menu::clientManagement() {
   string input;
   int inputInt;
   bool repeat;

   cout << "\n\tTeller Terminal System - Client and Account Management\n";
   cout << "1) Add a client\n";
   cout << "2) Add an account\n";
   cout << "3) Edit client information\n";
   cout << "4) Manage an account\n";
   cout << "5) Save client and account information\n";
   cout << "6) Exit\n";
   cout << "\tPlease choose an option: ";

   do {
      cin >> input;
      inputInt = atoi(input.c_str());
      repeat = false;
   
      switch (inputInt) {
         case 1:
            staff.addClient(filemanagement);
            repeat = true;
            cout << "1) Add a client\n";
            cout << "2) Add an account\n";
            cout << "3) Edit client information\n";
            cout << "4) Manage an account\n";
            cout << "5) Save client and account information\n";
            cout << "6) Exit\n";
            cout << "\tPlease choose an option: ";
            break;
         case 2:
            staff.addAccount(filemanagement);
            repeat = true;
            cout << "1) Add a client\n";
            cout << "2) Add an account\n";
            cout << "3) Edit client information\n";
            cout << "4) Manage an account\n";
            cout << "5) Save client and account information\n";
            cout << "6) Exit\n";
            cout << "\tPlease choose an option: ";
            break;
         case 3:
            staff.editClientInfo(filemanagement);
            repeat = true;
            cout << "1) Add a client\n";
            cout << "2) Add an account\n";
            cout << "3) Edit client information\n";
            cout << "4) Manage an account\n";
            cout << "5) Save client and account information\n";
            cout << "6) Exit\n";
            cout << "\tPlease choose an option: ";
            break;
         case 4:
            staff.manageAccount(filemanagement);
            repeat = true;
            cout << "1) Add a client\n";
            cout << "2) Add an account\n";
            cout << "3) Edit client information\n";
            cout << "4) Manage an account\n";
            cout << "5) Save client and account information\n";
            cout << "6) Exit\n";
            cout << "\tPlease choose an option: ";
            break;
         case 5:
            staff.saveInfo(filemanagement);
            repeat = true;
            cout << "1) Add a client\n";
            cout << "2) Add an account\n";
            cout << "3) Edit client information\n";
            cout << "4) Manage an account\n";
            cout << "5) Save client and account information\n";
            cout << "6) Exit\n";
            cout << "\tPlease choose an option: ";
            break;
         case 6:
            if (filemanagement.adminExists(admin.getUsername(), admin.getPassword())) {
               backToAdminOptions();
            }
            else {
               backToMemberOptions();
            }
         
            repeat = true;
            cout << "1) Add a client\n";
            cout << "2) Add an account\n";
            cout << "3) Edit client information\n";
            cout << "4) Manage an account\n";
            cout << "5) Save client and account information\n";
            cout << "6) Exit\n";
            cout << "\tPlease choose an option: ";
            break;
         default: //inavlid input
            cout << "Please enter a valid input (1, 2, 3, 4, 5, or 6): ";
            repeat = true;
      }
   } while (repeat);

   return 0;
}
//back to admin options
int Menu::backToAdminOptions() {
   string input;
   bool repeat;

   cout << "\nAre you sure you want to go back to the system administrator options menu? (Y/N): ";

   do {
      repeat = false;
      cin >> input;
   
      if (input == "Y" || input == "y") {
         adminOptions();
      }
      else if (input == "N" || input == "n") {
         cout << "\n";
         return 0;
      }
      else { //invalid input
         cout << "Please enter a valid input (Y or N): ";
         repeat = true;
      }
   } while (repeat);

   return 0;
}
//back to login
int Menu::backToLogin() {
   string input;
   bool repeat;

   cout << "Are you sure you want to logout? (Y/N): ";

   do {
      repeat = false;
      cin >> input;
   
      if (input == "Y" || input == "y") {
         if (filemanagement.adminExists(admin.getUsername(), admin.getPassword())) {
            cout << "User information has been saved in the staff file.\n";
         }
         cout << "Logging off...\n";
         filemanagement.writeUserfile();
         loginOptions();
      }
      else if (input == "N" || input == "n") {
         cout << "\n";
         return 0;
      }
      else { //invalid input
         cout << "Please enter a valid input (Y or N): ";
         repeat = true;
      }
   } while (repeat);

   return 0;
}
//staff options
int Menu::staffOptions() {
   string input;
   int inputInt;
   bool repeat;

   cout << "\n\tTeller Terminal System - Branch Member \n";
   cout << "1) Client and Account Management\n";
   cout << "2) Change Password\n";
   cout << "3) Save and logout\n";
   cout << "\tPlease choose an option: ";

   do {
      cin >> input;
      inputInt = atoi(input.c_str());
      repeat = false;
   
      switch (inputInt) {
         case 1:
            clientManagement();
            repeat = true; 
            break;
         case 2:
            staff.changePassword(staff.getPassword(), filemanagement);
            repeat = true;
            cout << "1) Client and Account Management\n";
            cout << "2) Change Password\n";
            cout << "3) Save and logout\n";
            cout << "\tPlease choose an option: ";
            break;
         case 3:
            backToLogin();
            repeat = true;
            cout << "1) Client and Account Management\n";
            cout << "2) Change Password\n";
            cout << "3) Save and logout\n";
            cout << "\tPlease choose an option: ";
            break;
         default: //invalid input
            cout << "Please enter a valid input (1, 2 or 3): ";
            repeat = true;
      }
   } while (repeat);

   return 0;
}
//back to member options
int Menu::backToMemberOptions() {
   string input;
   bool repeat;

   cout << "\nAre you sure you want to go back to the branch staff options menu? (Y/N): ";

   do {
      repeat = false;
      cin >> input;
   
      if (input == "Y" || input == "y") {
         staffOptions();
      }
      else if (input == "N" || input == "n") {
         return 0;
      }
      else { //invalid input
         cout << "Please enter a valid input (Y or N): ";
         repeat = true;
      }
   } while (repeat);

   return 0;
}

int Menu::Initialize() {
   filemanagement.fillArray();

   loginOptions();

   return 0;
}
   /*
Member member functions 
*/
//set username
int Member::setUsername(string usernameIn) {
   username = usernameIn;
   return 0;
}
//set password
int Member::setPassword(string passwordIn) {
   password = passwordIn;
   return 0;
}
//get username
string Member::getUsername() {
   return username;
}
//get password
string Member::getPassword() {
   return password;
}
//add client
int Member::addClient(FileManagement &filemanagement) {
   cout << "\nA new client will be added...";
   cout << "\nClient name: ";
   getline(cin, client.name);
   getline(cin, client.name);
   if (filemanagement.clientExists(client.name)) {
      cout << "ERROR: There is already a client with this name!\n\n";
      return 0;
   }

   cout << "Address: ";
   getline(cin, client.address);
   cout << "Social security number: ";
   getline(cin, client.social_security_number);
   cout << "Employer: ";
   getline(cin, client.employer);
   cout << "Annual income: ";
   getline(cin, client.income);

   filemanagement.addClient(client);

   return 0;
}
//add account
int Member::addAccount(FileManagement &filemanagement) {
   string name;
   cout << "\nChoose a client: ";
   getline(cin, name);
   getline(cin, name);
   if (filemanagement.clientExists(name) && !filemanagement.accountExists(name)) {
      account.name = name;
      cout << "A new account will be created for " << account.name << "...\n";
      cout << "Account number: ";
      getline(cin, account.account_number);
      cout << "Account type: ";
      getline(cin, account.account_type);
      cout << "Balance: ";
      getline(cin, account.balance);
   
      filemanagement.addAccount(account);
   }
   else {
      cout << "ERROR: Either client was not found in the system or client already has an account!\n\n";
   }

   return 0;
}
//edit client info
int Member::editClientInfo(FileManagement &filemanagement) {
   string name, input;
   bool repeat = true;
	
   cout << "\nChoose a client: ";
   getline(cin, name);
   getline(cin, name);
   if (!filemanagement.clientExists(name)) {
      cout << "ERROR: Client not found!\n\n";
      return 0;
   }

   cout << "\nDisplaying " << name << "'s Information: ";

   filemanagement.print(name);

   cout << "\nClient " << name << "'s information will be updated...";
   cout << "\n1) Confirm";
   cout << "\n2) Cancel";
   cout << "\n\tPlease choose an option: ";

   do {
      repeat = false;
      cin >> input;
   	
      int inputInt = atoi(input.c_str());
   
      switch (inputInt) {
         case 1:
            if (filemanagement.clientExists(name)) {
               filemanagement.update(name);
            }
            else {
               cout << "ERROR: Client not found!\n\n";
            }
            break;
         case 2:
            cout << "Going back to client management menu...\n\n";
            return 0;
            break;
         default:
            cout << "Your input was invalid. Please enter a valid input (1 or 2): ";
            repeat = true;
      }
   
   } while (repeat);

   return 0;
}
//manage account
int Member::manageAccount(FileManagement &filemanagement) {
   string account_number, input;
   int inputInt, amount;
   bool repeat;

   cout << "\nEnter the number of the account to be managed: ";
   cin >> account_number;

   if (!filemanagement.isAccount(account_number)) {
      cout << "ERROR: There is no account with this number in the database!\n\n";
      return 0;
   }

   cout << "\nNow managing account " << account_number << " for " << filemanagement.getName(account_number) << ": \n";
   cout << "1) Deposit\n";
   cout << "2) Withdraw\n";
   cout << "3) Cancel\n";
   cout << "\tPlease choose an option: ";

   do {
      repeat = false;
      amount = 0;
   
      cin >> input;
      inputInt = atoi(input.c_str());
   
      switch (inputInt) {
         case 1:
            cout << "Deposit amount: ";
            cin >> amount;
            filemanagement.deposit(account_number, amount);
            repeat = true;
            cout << "1) Deposit\n";
            cout << "2) Withdraw\n";
            cout << "3) Cancel\n";
            cout << "\tPlease choose an option: ";
            break;
         case 2:
            cout << "Withdraw amount: ";
            cin >> amount;
            filemanagement.withdraw(account_number, amount);
            repeat = true;
            cout << "1) Deposit\n";
            cout << "2) Withdraw\n";
            cout << "3) Cancel\n";
            cout << "\tPlease choose an option: ";
            break;
         case 3:
            cout << "Returning to menu...\n\n";
            return 0;
            break;
         default:
            cout << "Your input was invalid. Please enter a valid input (1, 2 or 3): ";
            repeat = true;
      }
   } while (repeat);

   return 0;
}
//save info
int Member::saveInfo(FileManagement &filemanagement) {
   filemanagement.writeClientfile();
   cout << "\nClient information has been saved in the client file.\n";
   filemanagement.writeAccountfile();
   cout << "Account information has been saved in the account file.\n\n";
   return 0;
}
//change password
int Member::changePassword(string passwordIn, FileManagement &filemanagement) {
   string newPassword;
   bool repeat = true;

   do {
      cout << "New password (use any character except spaces): ";
      cin >> newPassword;
   
      if (newPassword == passwordIn) {
         cout << "ERROR: Your new password can't be the same as your old password!\n\n";
      }
      else {
         setPassword(newPassword);
         filemanagement.changePassword(getUsername(), getPassword());
         cout << "Password was changed!\n\n";
         repeat = false;
      }
   } while (repeat);

   return 0;
}

/*
Admin member functions 
*/
//add user
int Admin::addUser(FileManagement &filemanagement) {
   string name, pw, role;
   bool repeat = true;

   cout << "\nUsername: ";
   getline(cin, name);
   getline(cin, name);
   if (filemanagement.userExists(name)) {
      cout << "ERROR: User is already in the system!\n\n";
      return 0;
   }

   cout << "Password: ";
   getline(cin, pw);

   user.username = name;
   user.password = pw;

   do {
      cout << "Role (1 - Administrator;1 2 - Branch Member): ";
      getline(cin, role);
      int roleInt = atoi(role.c_str());
   
      switch (roleInt) {
         case 1:
            user.role = "System Administrator";
            filemanagement.addUser(user);
            cout << "A new admin was added\n\n";
            repeat = false;
            break;
         case 2:
            user.role = "Branch Member";
            filemanagement.addUser(user);
            cout << "A staff member was added!\n\n";
            repeat = false;
            break;
         default:
            cout << "Invalid input! Please enter 1 or 2.\n";
      }
   } while (repeat);

   return 0;
}
//delete user
int Admin::deleteUser(FileManagement &filemanagement) {
   string name, input;
   bool repeat = true;

   cout << "\nPlease enter username of user to be deleted: ";
   getline(cin, name);
   getline(cin, name);

   if (name == "admin") {
      cout << "ERROR: The main system administrator cannot be deleted!\n\n";
      return 0;
   }

   if (name == getUsername()) {
      cout << "ERROR: You cannot delete the user that is currently using the system!\n\n";
      return 0;
   }

   if (!filemanagement.userExists(name)) {
      cout << "ERROR: User is not in the system!\n\n";
      return 0;
   }

   cout << "1) Confirm\n";
   cout << "2) Cancel\n";
   cout << "\tPlease choose an option: ";
   do {
      getline(cin, input);
      int inputInt = atoi(input.c_str());
   
      switch (inputInt) {
         case 1:
            filemanagement.deleteUser(name);
            cout << "User was deleted from the system.\n\n";
            repeat = false;
            break;
         case 2:
            cout << "Returning to system administration main menu...\n\n";
            return 0;
         default:
            cout << "Your input was invalid. Please enter a valid input (1 or 2): ";
      }
   } while (repeat);

   return 0;
}
//display users
int Admin::displayUsers(FileManagement &filemanagement) {
   filemanagement.printUserArray();
   return 0;
}

  
int main() {
   Menu menu = Menu();
   menu.Initialize();
   return 0;
}
  //tests the branch staff menu
void test_branch_staff_menu(void) {
   Menu menu = Menu();
   menu.staffOptions(); // select 1, 2, 3, or an invalid input
}
//tests the client and account managment menu
void test_client_and_account_management(void) {
   Menu menu = Menu();
   menu.clientManagement(); // select 1, 2, 3, 4, 5, 6, or an invalid input
}

//tests the login process
void test_login_process(void) {
   Menu menu = Menu();
   menu.loginOptions(); // select 1, 2, or an invalid input.
}
//tests the system admin menu
void test_system_admin_menu(void) {
   Menu menu = Menu();
   menu.adminOptions(); // select 1, 2, 3, 4, 5, 6, or an invalid input
}
