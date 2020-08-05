#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Create's account for user if they don't have one.
void createAccount() {
	string username;
	string password;
	cout << "Please enter a username >>> " << endl;
	cin >> username;
	cout << "Please enter a passowrd >>> " << endl;
	cin >> password;
	ofstream newaccount;
	newaccount.open("accounts.txt", ios::in);
	newaccount << "Username: " << username << "Password: " << password << endl;
	newaccount.close();
	cout << "Thank you, your account has now been created! \n"; 
}

// If user have a account they will be presented with this login screen. 
void login() {
	cout << "Please enter your details to access your bank details \n";
	string username;
	string password;
	ifstream userAccounts;
	userAccounts.open("accounts.txt", ios::out);
	cout << "Enter your username: " << endl;
	cin >> username;
	cout << "Enter your password: " << endl;
	cin >> password;
	string username2, password2;
	userAccounts >> username2 >> password2;
	userAccounts.close();
	if (username != username2 || password != password2)
		cout << "Login failed. Incorrect username or password. Please try again." << endl;
	else if (username == username2 || password == password2)
		cout << "Login Sucesful! \n" << endl;
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
	double balance = 750;

	string accountMade;
	cout << "Do you have an account: Y/N ";
	cin >> accountMade;

	if (accountMade == "Y" || accountMade == "y") {
		login();
	}
	else if (accountMade == "N" || accountMade == "n") {
		createAccount();
		login();
	}

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
