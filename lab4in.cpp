//Channing Babb
//Lab 4 in
//Creates a form for inputting/validating information

#include <iostream>
#include <string>
#include <cctype>
#include "graph1.h"

using namespace std;

//Prototypes are below
string getString(string prompt);
bool validateName(string name);
bool validateAddress(string address);
bool validatePhone(string phone);
string convertToUpper(string string);
void displayFields(string name, string address, string phone);


int main()
{
	//Variable Declaration/Initialization
	string name = "";
	string address = "";
	string phone = "";
	string upperName = "";
	bool res = false;
	bool repeat = 1;

	//Display graphics window
	displayGraphics();

	do {
		//Process name info
		do
		{
			//Prompt for the name - 
			name = getString("Enter Name: ");

			//validate the name
			res = validateName(name);

		} while (!res);

		//Process the address info
		do
		{
			//Get the address
			address = getString("Enter Address: ");

			//validate the address
			res = validateAddress(address);

		} while (!res);

		//Process phone info
		do
		{
			//Get the phone
			phone = getString("Enter Phone: ");

			//validate the phone
			res = validatePhone(phone);

		} while (!res);



		//Convert the name to all uppercase
		upperName = convertToUpper(name);

		//Display the fields
		displayFields(name, address, phone);
		cout << "Would you like to repeat the program: ";
		cin >> repeat;

	} while (repeat == 1);


	return 0;
}




//Prompts for input based on input parameter prompt
string getString(string prompt)
{
	//Prompt user for name using getline (prompt contains the message displayed to user))
	string user_prompt;
	cout << prompt;
	getline(cin, user_prompt);
	return user_prompt;

}

//Validates characters of name
bool validateName(string name)
{
	bool result = true;
	for (int i = 0; i < (int)name.length(); i++) {
		if (!isalpha(name[i]) && !isspace(name[i])) {
			cout << "The name entered is not valid, please re-enter: " << endl;
			result = false;
			break;
		}
	}
	return result;
	//Validate the name – return true if valid, false if not
}

//Validates characters of address
bool validateAddress(string address)
{

	bool result = true;
	for (int i = 0; i < (int)address.length(); i++) {
		if (!isalpha(address[i]) && !isspace(address[i]) && !isdigit(address[i])) {
			cout << "The address entered is not valid, please re-enter: " << endl;
			result = false;
			break;
		}
	}
	return result;	//Validate the address – return true if valid, false if not
}



//Validates characters of phone number
bool validatePhone(string phone)
{
	bool result = true;
	if ((int)phone.length() != 10) {
		cout << "The phone number entered is not valid, please re-enter: " << endl;
		result = false;
	}
	for (int i = 0; i < (int)phone.length(); i++) {
		if (!isdigit(phone[i])) {
			cout << "The phone number entered is not valid, please re-enter: " << endl;
			result = false;
			break;
		}
	}
	return result;
}

//Converts text to uppercase
string convertToUpper(string input)
{
	//Convert input to all uppercase
	for (int i = 0; (int)input.length(); i++) {
		input[i] = toupper(input[i]);
	}
	return input;
}

//Displays the information in graphics window
void displayFields(string name, string address, string phone)
{
	//Draw the form (rectangles)
	int nameRect = drawRect(230, 85, 170, 20);
	int addressRect = drawRect(230, 125, 325, 20);
	int phoneRect = drawRect(230, 165, 125, 20);

	setColor(nameRect, 128, 128, 128);
	setColor(addressRect, 128, 128, 128);
	setColor(phoneRect, 128, 128, 128);


	gout << setPos(150, 100) << setColor(0, 255, 0) << "Name:" << endg;
	gout << setPos(230, 85) << setColor(0, 255, 0) << name << endg;


	gout << setPos(150, 140) << setColor(0, 255, 0) << "Address:" << endg;
	gout << setPos(230, 125) << setColor(0, 255, 0) << address << endg;

	gout << setPos(150, 180) << setColor(0, 255, 0) << "Phone:" << endg;
	gout << setPos(230, 165) << setColor(0, 255, 0) << phone << endg;
	//Display the fields
}
