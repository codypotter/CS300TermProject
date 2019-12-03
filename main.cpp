/**
 * Created by Bela, Cody Potter, Corbin Stark, Dan Scott, Forest Pearson, Max VanRaden
 */

#include <iostream>
#include "Database.h"
using namespace std;

void printHeader(char target) {
	switch(target)
	{
		case 'c':
			cout <<  " __        __   __" << endl;
			cout << "/  ` |__| /  \\ /  `  /\\  |\\ |" << endl;
			cout << "\\__, |  | \\__/ \\__, /~~\\ | \\|" << endl << endl;
			break;
		case 'm':
			cout << "   __  ___                              ______              _           __" << endl;
			cout << "  /  |/  /__  ___  ___  ___  ___ ____  /_  __/__ ______ _  (_)__  ___ _/ /" << endl;
			cout << " / /|_/ / _ `/ _ \\/ _ `/ _ `/ -_) __/   / / / -_) __/  ' \\/ / _ \\/ _ `/ /" << endl;
			cout << "/_/  /_/\\_,_/_//_/\\_,_/\\_, /\\__/_/     /_/  \\__/_/ /_/_/_/_/_//_/\\_,_/_/" << endl;
			break;
		case 'p':
			cout << " ___             _    _           _____              _           _ " << endl;
			cout << "| _ \\_ _ _____ _(_)__| |___ _ _  |_   _|__ _ _ _ __ (_)_ _  __ _| |" << endl;
			cout << "|  _/ '_/ _ \\ V / / _` / -_) '_|   | |/ -_) '_| '  \\| | ' \\/ _` | |" << endl;
			cout << "|_| |_| \\___/\\_/|_\\__,_\\___|_|     |_|\\___|_| |_|_|_|_|_||_\\__,_|_|" << endl;
			break;
	}
}

int main(int argc, char** argv) {
	printHeader('c');
	Database database((char*) "data/sample-db.json");

	cout << "Welcome to the ChocAn Simulator." << endl;
	cout << "Would you like to simulate the (m)anager terminal or the (p)rovider terminal?" << endl;
	char res = 0;
	while(res != 'm' && res != 'p') {
		cin >> res;
		if(res != 'm' && res != 'p')
			cout << "Invalid input. Type 'm' for the manager terminal or 'p' for the provider terminal." << endl;
	}

	char choice = 0;
	if(res == 'm') {
		do {
			cout << "Welcome to the manager terminal. Please select an option." << endl;
			cout << "(a) Add a new provider" << endl;
			cout << "(b) Add a new member" << endl;
			cout << "(c) Edit a provider or member" << endl;
			cout << "(d) Delete a provider or member" << endl;
			cout << "(x) Exit" << endl;
			cin >> choice;
		}
		while(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice !='x');

		switch(choice) {
			case 'a':
				break;
			case 'b':
				break;
			case 'c':
				break;
			case 'd':
				break;
			case 'x':
				break;
		}
	}

	if(res == 'p') {
		string provID = "";
		cout << "Please enter provider number: (9 digits)" << endl;
		cin >> provID;
		if(database.providers.find(provID) == database.providers.end())
		{
			cout << "Invalid provider ID" << endl;
			return 0;
		}
		printHeader(res);
		do {
			cout << "Welcome to the provider terminal" << endl;
			cout << "(a) View the provider directory" << endl;
			cout << "(b) Provide service" << endl;
			cout << "(x) Exit" << endl;
			cin >> choice;
		}
		while(choice != 'a' && choice != 'b' && choice != 'x');

		switch(choice) {
			case 'a':				
				cout << "List of services:" << endl;
				for(auto pair : database.directory)
				{
					cout << "Service Code: " << pair.first << endl;
					cout << "Name: " << pair.second.name << endl;
					cout << "Fee: " << pair.second.fee << endl << endl;
				}
				break;
			case 'b':
				{
					string memID = "";
					cout << "Provide a Service:" << endl;					
					cout << "Please enter member ID number: (9 digits)" << endl;
					cin >> memID;
					if(database.members.find(memID) == database.members.end())
					{
						cout << "Invalid member ID, please try again";
						break;
					}
					if(database.members.at(memID).isValid != true)
					{
						cout << "Member status invalid, cannot recieve services" << endl;
						break;
					}
					string servCode = "";
					cout << "Enter a service code: (6 digits)" << endl;
					cin >> servCode;
					if(database.directory.find(servCode) == database.directory.end())
					{
						cout << "Invalid service code" << endl;
						break;
					}
					else
					{
						string currDate = "";
						string servDate = "";
						cout << "Enter the current date: (mm/dd/yyyy)" << endl;
						cin >> currDate;
						cout << "Enter the expected service date: (mm/dd/yyyy)" << endl;
						cin >> servDate;

						cout << "Service Summary:" << endl;
						cout << "Date of Service: " << servDate << endl;
						cout << "Date of Submission: " << currDate << endl;
						cout << "Member ID: " << memID << endl;
						cout << "Provider ID: " << provID << endl;
						cout << "Service ID: " << servCode << endl;
						cout << "Fee: " << database.directory.at(servCode).fee << endl;
						database.addService(servDate, currDate, memID, provID, servCode, database.directory.at(servCode).fee);
						database.update();
					}
				}
				break;
			case 'x':
				break;
		}
	}

	return 0;
}
