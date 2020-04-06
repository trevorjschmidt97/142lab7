/*
Trevor Schmidt
trevorjschmidt97@gmail.com
CS 142 Section 002 - Frank Jones

Main Lab 7 - Restaurants

This program helps to choose which restaurant one might want to go to.
You can add, remove, cut, shuffle and most importantly, battle your
restaurant choices.

Coded on Visual Studio and Zybooks



Test Case 1:
Input: (add, taco bell, display, quit)
Expected Output: (
Welcome to the restaurant battle!  Enter "options" to see options.

Enter your selection:

add
What is the name of the restaurant you want to add ?
taco bell
taco bell has been added.

Enter your selection:

display
Here are the current restaurants :

		"taco bell"

Enter your selection:

quit
Goodbye!)

Result: Passed

Test Case 2:

Input: (add, taco bell, add, mcdonalds, add, wendys, remove, wendys, display, quit)
Expected Output: (
Welcome to the restaurant battle!  Enter "options" to see options.

Enter your selection:

add
What is the name of the restaurant you want to add ?
taco bell
taco bell has been added.

Enter your selection:

add
What is the name of the restaurant you want to add ?
mcdonalds
mcdonalds has been added.

Enter your selection:

add
What is the name of the restaurant you want to add ?
wendys
wendys has been added.

Enter your selection:

remove
What is the name of the restaurant you want to remove?
wendys
wendys has been removed.

Enter your selection:

display
Here are the current restaurants :

		"taco bell"
		"mcdonalds"

Enter your selection:

quit
Goodbye!)

Result: Passed

Test Case 3:
Input: (add, taco bell, add, mcdonalds, battle, 1, quit)
Expected Output: (
Welcome to the restaurant battle!  Enter "options" to see options.

Enter your selection:

add
What is the name of the restaurant you want to add ?
taco bell
taco bell has been added.

Enter your selection:

add
What is the name of the restaurant you want to add ?
mcdonalds
mcdonalds has been added.

Enter your selection:

battle
Round: 1

Type "1" if you prefer taco bell or
type "2" if you prefer mcdonalds
Choice :
1
The winning restaurant is taco bell.

Enter your selection:

quit
Goodbye!)
Result: Passed

*/


#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

vector<string> restaurantList;

bool PowerOfTwo(int numberToCheck) {
	double powerCheck = numberToCheck;
	while (powerCheck > 1) {
		powerCheck /= 2;
	}
	if (powerCheck != 1) {
		return false;
	}
	return true;
}

void DisplayOption() {
	cout << "Here are the current restaurants : " << endl << endl;
	for (int i = 0; i < restaurantList.size(); ++i) {
		cout << "\t\"" << restaurantList.at(i) << "\"" << endl;
	}
	cout << endl;
	return;
}

void AddOption(int clearVal) {
	string newRest = " ";
	bool findName = false;
	cout << "What is the name of the restaurant you want to add ?" << endl;
	cin.clear();
	cin.ignore(clearVal, '\n');
	getline(cin, newRest);
	for (int i = 0; i < restaurantList.size(); ++i) {
		if (restaurantList.at(i) == newRest) {
			cout << "That restaurant is already on the list, you can not add it again." << endl << endl;
			findName = true;
		}
	}
	if (findName == false) {
		restaurantList.push_back(newRest);
		cout << newRest << " has been added." << endl << endl;
	}
	return;
}

void RemoveOption(int clearVal) {
	string restName = " ";
	bool findName = false;
	cout << "What is the name of the restaurant you want to remove?" << endl;
	cin.clear();
	cin.ignore(clearVal, '\n');
	getline(cin, restName);
	for (int i = 0; i < restaurantList.size(); ++i) {
		if (restaurantList.at(i) == restName) {
			restaurantList.erase(restaurantList.begin() + i);
			cout << restName << " has been removed." << endl << endl;
			findName = true;
		}
	}
	if (findName == false) {
		cout << "That restaurant is not on the list, you can not remove it." << endl << endl;
	}
	return;
}

void CutOption(int clearVal) {
	int cutNum = 0;
	cout << "How many restaurants should be taken from the top and put on the bottom?" << endl;
	cin.clear();
	cin.ignore(clearVal, '\n');
	cin >> cutNum;
	while (!cin || cutNum < 0 || cutNum >(restaurantList.size())) {
		cout << "The cut number must be between 0 and " << restaurantList.size() << endl;
		cout << "How many restaurants should be taken from the top and put on the bottom?" << endl;
		cin.clear();
		cin.ignore(clearVal, '\n');
		cin >> cutNum;
	}
	if (cutNum > 0) {
		for (int i = 0; i < cutNum; ++i) {
			restaurantList.push_back(restaurantList.at(0));
			restaurantList.erase(restaurantList.begin() + 0);
		}
	}
	cout << endl << endl;
	return;
}

void ShuffleOption(int clearVal) {
	vector<string> newList;
	int shuffleSize = restaurantList.size() / 2;
	if (PowerOfTwo(restaurantList.size()) == false) {
		cout << "The current tournament size(" << restaurantList.size() << ") is not a power of two(2, 4, 8...)." << endl;
		cout << "A shuffle is not possible.Please add or remove restaurants." << endl;
		cin.clear();
		cin.ignore(clearVal, '\n');
	}
	else {
		for (int i = 0; i < shuffleSize; ++i) {
			newList.push_back(restaurantList.at(shuffleSize + i));
			newList.push_back(restaurantList.at(i));
		}
		restaurantList = newList;
	}
	return;
}

void BattleOption(int clearVal) {
	vector<string> remainingList;
	if (PowerOfTwo(restaurantList.size()) == false) {
		cout << "The current tournament size (" << restaurantList.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A battle is not possible.Please add or remove restaurants." << endl;
		cin.clear();
		cin.ignore(clearVal, '\n');
	}
	else {
		remainingList = restaurantList;
		int numRounds = (restaurantList.size() / 2);
		int userChoice = 0;
		for (int i = 0; i < numRounds; ++i) {
			if (remainingList.size() == 1) {
				break;
			}
			cout << "Round: " << (i + 1) << endl << endl;
			for (int j = 0; j < remainingList.size(); ++j) {
				if (remainingList.size() == 1) {
					break;
				}
				cout << "Type \"1\" if you prefer " << remainingList.at(j) << " or" << endl;
				cout << "type \"2\" if you prefer " << remainingList.at(j + 1) << endl;
				cout << "Choice : " << endl;
				cin >> userChoice;
				if (userChoice == 1) {
					remainingList.erase(remainingList.begin() + (j + 1));
				}
				else if (userChoice == 2) {
					remainingList.erase(remainingList.begin() + j);
				}
				else {
					cout << "Invalid choice" << endl;
					--j;
					cin.clear();
					cin.ignore(clearVal, '\n');
				}
			}
		}
		cin.clear();
		cin.ignore(clearVal, '\n');
		cout << "The winning restaurant is " << remainingList.at(0) << "." << endl << endl;
	}
	return;
}

int main() {
	int clearVal = 256;
	string userInput = " ";

	cout << "Welcome to the restaurant battle!  Enter \"options\" to see options." << endl << endl;
	do {
		cout << "Enter your selection:" << endl << endl;
		cin >> userInput;
		if (userInput != "options" && userInput != "quit" && userInput != "display" && userInput != "add" && userInput != "remove" &&
			userInput != "cut" && userInput != "battle" && userInput != "shuffle") {
			cout << "Invalid Selection" << endl;
			cout << "Please select one of the following options : " << endl << endl;
			cout << "quit - Quit the program" << endl;
			cout << "display - Display all restaurants" << endl;
			cout << "add - Add a restaurant" << endl;
			cout << "remove - Remove a restaurant" << endl;
			cout << "cut - \"Cut\" the list of restaurants" << endl;
			cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
			cout << "battle - Begin the tournament" << endl;
			cout << "options - Print the options menu" << endl << endl;
			cin.clear();
			cin.ignore(clearVal, '\n');
		}
		else if (userInput == "options") {
			cout << "Please select one of the following options : " << endl << endl;
			cout << "quit - Quit the program" << endl;
			cout << "display - Display all restaurants" << endl;
			cout << "add - Add a restaurant" << endl;
			cout << "remove - Remove a restaurant" << endl;
			cout << "cut - \"Cut\" the list of restaurants" << endl;
			cout << "shuffle - \"Shuffle\" the list of restaurants" << endl;
			cout << "battle - Begin the tournament" << endl;
			cout << "options - Print the options menu" << endl << endl;
		}
		else if (userInput == "add") {
			AddOption(clearVal);
		}
		else if (userInput == "display") {
			DisplayOption();
		}
		else if (userInput == "remove") {
			RemoveOption(clearVal);
		}
		else if (userInput == "cut") {
			CutOption(clearVal);
		}
		else if (userInput == "shuffle") {
			ShuffleOption(clearVal);
		}
		else if (userInput == "battle") {
			BattleOption(clearVal);
		}
	} while (userInput != "quit");

	cout << "Goodbye!" << endl;

	//system("pause");
	return 0;
}