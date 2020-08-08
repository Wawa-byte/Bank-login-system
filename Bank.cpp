#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;

class User {
public:
	string username;
	string password;
};
list<User> applicationUsers;

// Create's account for user if they don't have one.
User createAccount() {
	string username;
	string password;
	cout << "Please enter a username >>> " << endl;
	cin >> username;
	cout << "Please enter a passowrd >>> " << endl;
	cin >> password;
	cout << "Thank you " << username << ", your account has now been created! \n";

	User user;
	user.username = username;
	user.password = password;
	return user;
}

// If user have a account they will be presented with this login screen.
bool login() {
	string username;
	string password;
	cout << "Enter your username: " << endl;
	cin >> username;
	cout << "Enter your password: " << endl;
	cin >> password;

	for (User applicationUser : applicationUsers) { // Foreach loop it iterates all the elements of applicationUsers list
		if (applicationUser.username == username) // When it finds user with that username, it should check password to see if they match
		{
			if (applicationUser.password == password) {
				cout << "Login Successful!" << endl;
				return true;
			}
		}
	}
	// If user enters incorrect details 
	cout << "Login failed. Please try again." << endl;
	return false;
}

void showMenu() {
	cout << "************MENU************" << endl;
	cout << "1. Check Balance" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Exit program" << endl;
	cout << "****************************" << endl;
}

int main() {
	int option;
	double balance = 500;
	bool userLogedIn = false;
	char hasAccount;

	do // User can't access bank until they are registered and logged in
	{
		do
		{
			cout << "Do you have an account: Y/N ";
			cin >> hasAccount;
			hasAccount = ::tolower(hasAccount); // Converts input to lowercase
		} while (hasAccount != 'y' && hasAccount != 'n');


		if (hasAccount == 'n') {
			User createdUser = createAccount();
			applicationUsers.push_back(createdUser);
			hasAccount = 'y';
		}

		if (hasAccount == 'y')
			userLogedIn = login();

	} while (!userLogedIn);

	// Once the user is registered they can access their bank inforamtion

	do {
		showMenu();
		cout << "Please choose an option >>> ";
		cin >> option;
		system("cls");
		// cls clears the console after user selects an option

		switch (option) {
		case 1:cout << "Balance is €" << balance << endl; break;

		case 2:cout << "Deposit amount: ";
			double depositAmount;
			cin >> depositAmount;
			balance += depositAmount;
			break;

		case 3:cout << "Withdraw amount: ";
			double withdrawAmount;
			cin >> withdrawAmount;
			if (withdrawAmount <= balance)
				balance -= withdrawAmount;
			else
				cout << "Not enough money in the bank account" << endl;
			break;

		}

	} while (option != 4);
}
